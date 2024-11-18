#include "header/ht_game.hpp"

using namespace HanoiTower;

//GETTERS


//SETTERS


//CONSTRUCTOR
Game::Game()
{
    _towerMaxSize = 0;

    _towers.reserve(_numberOfTowers);

    _towers.push_back(new Tower());
    _towers.push_back(new Tower());
    _towers.push_back(new Tower());

    _previousGameState = NOSTATE;
    _gameState = INITIALIZE;

    _areCommandsHidden = false;
    _isRunning = true;
}

//DESTRUCTOR
Game::~Game()
{
    Debug::Log("Game destroyed!");
    for(Tower* t:_towers)
    {
        delete t;
    }
}

//FUNCTIONS
void Game::InitializeTowers(int numberOfDisks)
{
    if(IsNumberOfDisksValid(numberOfDisks))
    {
        Debug::Log("Game Initialization Error! Invalid Number of Disks");
    }

    _towerMaxSize = numberOfDisks;

    _commands.FlushCommands();
    FlushTowers();

    _towers[0]->FillTower(numberOfDisks);
}

void Game::Run()
{
    while (_isRunning)
    {
        Debug::Clear();
        switch (_gameState)
        {
        case CONTINUE:
            Continue();
            break;
        case INITIALIZE:
            Initialize();
            break;
        case UPDATE:
            Update();
            break;
        case AUTO:
            Auto();
            break;
        case END:
            End();
            break;
        default:
            break;
        }
    }
}

void Game::Continue()
{
    Debug::Log("CONTINUE SCREEN");
    DoYouWishToPlayAgainScreen();
}

void Game::Initialize()
{
    Debug::Log("INITIALIZATION SCREEN");
    InitializationScreen();
}

void Game::Update()
{
    Debug::Log("UPDATE SCREEN");
    UpdateScreen();
}

void Game::Auto()
{
    Debug::Log("AUTO SCREEN");
    AutoSolveScreen();
}

void Game::End()
{
    Debug::Log("END SCREEN");
    _isRunning = !AreYouSureYouWantToQuitScreen();
}

void Game::AutoSolveScreen()
{
    Debug::Log("Are You Sure You Want To Auto Solve? (" + std::string(1, Config::Yes()) + " - Yes / " + std::string(1, Config::No()) + " - No))");
    char character = InputManager::GetChar();

    if(character == Config::Yes())
    {
        AutoSolve();
        ChangeGameState(CONTINUE);
    }

    if(character == Config::No())
    {
        ChangeGameState(_previousGameState);
    }
}

void Game::DoYouWishToPlayAgainScreen()
{
    Debug::Log("Do You Wish To Play Again? (" + std::string(1, Config::Yes()) + " - Yes / " + std::string(1, Config::No()) + " - No))");
    char character = InputManager::GetChar();

    if(character == Config::Yes())
    {
        ChangeGameState(INITIALIZE);
        return;
    }

    if(character == Config::No())
    {
        ChangeGameState(END);
        return;
    }
}

void Game::InitializationScreen()
{
    int numberOfDisks = InputManager::GetIntBuffer();
    char character;

    Debug::Log("How Many Disks in the Game? (Value must be bigger than 0)");
    if(numberOfDisks != 0)
    {
        Debug::Print(std::to_string(numberOfDisks));
    }

    character = InputManager::GetChar();

    if(character != Config::Enter())
    {
        InputManager::AddCharInIntBuffer(character);
        return;
    }

    if(numberOfDisks <= 0)
    {
        return;
    }

    InitializeTowers(numberOfDisks);

    ChangeGameState(UPDATE);
}

void Game::PrintCommands()
{
    if(_areCommandsHidden)
    {
        _commands.PrintCommands();
    }
}

void Game::UpdateScreen()
{
    int origin = -1;
    int destiny = -1;

    bool hasThePlayerWon = HasThePlayerWon();

    PrintCommands();
    
    PrintTowers();

    if(hasThePlayerWon)
    {
        Debug::Log("You Have Won! Press Anything To Continue!");
    }else
    {
        Debug::Log("Use towers ID's to move disks! (a - to solve; q - to quit the game; h - to toggle commands visibility)");
    }

    char input = InputManager::GetChar();

    if(hasThePlayerWon)
    {
        ChangeGameState(CONTINUE);
        return;
    }

    if(input == Config::Quit())
    {
        ChangeGameState(END);
        return;
    }

    if(input == Config::Auto())
    {
        ChangeGameState(AUTO);
        return;
    }

    if(input == Config::Hide())
    {
        ToggleCommandsVisibility();
        return;
    }

    origin = InputManager::GetInt(input);

    if(!IsTowerIDValid(origin))
    {
        Debug::Log("Invalid TowerID! Press Anything to Continue!");
        InputManager::GetChar();
        return;
    }

    Debug::Print(Config::TowerIDtoPrintConnector());

    input = InputManager::GetChar();

    destiny = InputManager::GetInt(input);

    if(!IsTowerIDValid(destiny))
    {
        Debug::Log("Invalid TowerID! Press Anything to Continue!");
        InputManager::GetChar();
        return;
    }

    _commands.LoadAndExecuteCommand(_towers, origin, destiny);
}

bool Game::AreYouSureYouWantToQuitScreen()
{
     Debug::Log("Are You Sure You Want to Quit? (" + std::string(1, Config::Yes()) + " - Yes / " + std::string(1, Config::No()) + " - No))");
    char character = InputManager::GetChar();

    if(character == Config::Yes())
    {
        Debug::Log("\n");
        return true;
    }

    if(character == Config::No())
    {
        ChangeGameState(_previousGameState);
    }

    return false;
}

void Game::FlushTowers()
{
    for(Tower* t:_towers)
    {
        t->FlushTower();
    }
}

void Game::PrintTowers()
{
    int towerNumber = 0;
    for(Tower* t:_towers)
    {
        Debug::Print(std::to_string(towerNumber) + Config::TowerIDtoPrintConnector());
        t->PrintTower();
        towerNumber++;
    }
    Debug::Log("");
}

void Game::ChangeGameState(GameState gameState)
{
    _previousGameState = _gameState;
    _gameState = gameState;
}

bool Game::IsNumberOfDisksValid(int numberOfDisks)
{
    return numberOfDisks > 0;
}

bool Game::IsTowerIDValid(int towerID)
{
    return (towerID >= 0 && towerID <= 2);
}

bool Game::HasThePlayerWon()
{
    return (_towers[DESTINYTOWER]->GetSize() == _towerMaxSize);
}

void Game::ToggleCommandsVisibility()
{
    _areCommandsHidden = !_areCommandsHidden;
}

void Game::AutoSolve()
{
    Analyzer analyzer = Analyzer(_towerMaxSize);
    analyzer.Analyze(_towers);
    analyzer.GenerateSolution(&_commands);
    analyzer.PrintData();
    PrintCommands();
    _commands.ExecuteAndPrintAllCommands(_towers);
    Debug::Log("\nGame Solved! Press Any Key To Continue!");
    InputManager::GetChar();
}