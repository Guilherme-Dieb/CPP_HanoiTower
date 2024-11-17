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
    isRunning = true;

    while (isRunning)
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
    isRunning = !AreYouSureYouWantToQuitScreen();
}

void Game::AutoSolveScreen()
{
    Debug::Log("Are You Sure You Want To Auto Solve? (" + std::string(1, Config::Yes()) + " - Yes / " + std::string(1, Config::No()) + " - No))");
    char character = InputManager::GetChar();

    if(character == Config::Yes())
    {
        Analyze();
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

void Game::UpdateScreen()
{
    char character = '0';
    int origin = -1;
    int destiny = -1;

    PrintComands();

    PrintTowers();

    if(HasThePlayerWon())
    {
        Debug::Log("You Have Won! Press Anything To Continue!");
        InputManager::GetChar();
        ChangeGameState(CONTINUE);
        return;
    }

    character = InputManager::GetChar();

    if(character == Config::Quit())
    {
        ChangeGameState(END);
        return;
    }

    if(character == Config::Auto())
    {
        ChangeGameState(AUTO);
        return;
    }

    origin = InputManager::GetInt(character);

    if(!IsTowerIDValid(origin))
    {
        Debug::Log("Invalid TowerID! Press Anything to Continue!");
        InputManager::GetChar();
        return;
    }

    Debug::Print(Config::TowerIDtoPrintConnector());

    character = InputManager::GetChar();

    destiny = InputManager::GetInt(character);

    if(!IsTowerIDValid(destiny))
    {
        Debug::Log("Invalid TowerID! Press Anything to Continue!");
        InputManager::GetChar();
        return;
    }

    Move(origin, destiny);
}

bool Game::AreYouSureYouWantToQuitScreen()
{
     Debug::Log("Are You Sure You Want to Quit? (" + std::string(1, Config::Yes()) + " - Yes / " + std::string(1, Config::No()) + " - No))");
    char character = InputManager::GetChar();

    if(character == Config::Yes())
    {
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

void Game::Move(int origin, int destiny)
{
    _commands.LoadAndExecuteCommand(_towers, origin, destiny);
}

void Game::AddMove(int origin, int destiny)
{
    _commands.LoadCommand(origin, destiny);
}

void Game::ExecuteAllMoves()
{
    _commands.ExecuteAllCommands(_towers);
}

void Game::ExecuteMove()
{
    _commands.ExecuteCurrentCommand(_towers);
}

void Game::PrintComands()
{
    _commands.PrintCommands();
}

void Game::ChangeMove(int origin, int destiny)
{
    _commands.OverwriteCommand( origin, destiny );
}

void Game::UndoMove()
{
    _commands.UndoCommand(_towers);
}

void Game::UndoAllMoves()
{
    _commands.UndoAllCommands(_towers);
}

void Game::Analyze()
{
    Analyzer analyzer = Analyzer(_towerMaxSize);
    analyzer.Analyze(_towers);
    analyzer.PrintData();
    analyzer.GenerateSolution(&_commands);
    analyzer.PrintData();
    _commands.PrintCommands();
    _commands.ExecuteAllCommands(_towers);
}