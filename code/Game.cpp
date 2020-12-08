#include "Game.hpp"

// ---
BattleshipII::DataGame::DataGame ()
	: BATTLESHIP::DataGame ()
{
	_numberOfUFOTypes									= 5; // Plus UFO4 y UFO5 defined here...
}

// ---
BattleshipII::Game::Game ()
	: BATTLESHIP::Game (),
	  _showFPS (false) // Not to show by default...
{ 
	delete (_theDataGame);

	_theDataGame = new BattleshipII::DataGame;
}

// ---
void BattleshipII::Game::Conf::adjustToPlayers (int nP)
{
	BATTLESHIP::Game::Conf::adjustToPlayers (nP);
	for (int i = 1; i <= numberPlayers (); setNumberLives (i++, _maxLives)); // Set the number of lives per player...
}

// ---
void BattleshipII::Game::setShowFPS (bool s)
{
	_showFPS = s;

	QGAMES::AdvancedGameStateControl* gCS = 
		dynamic_cast <QGAMES::AdvancedGameStateControl*> 
			(gameStateBuilder () -> gameState (__BATTLESHIP_STANDARDCONTROLGAMESTATE__));
	assert (gCS);

	gCS -> setOverlay 
		(_showFPS ? game () -> state (__QGAMES_GAMESTATEFPSNAME__) : NULL); 
}

// ---
void BattleshipII::Game::processEvent (const QGAMES::Event& evnt)
{
	if (evnt.code () == __QGAMES_KEYBOARDEVENT__)
	{
		QGAMES::KeyBoardEventData* dt = (QGAMES::KeyBoardEventData*) evnt.data ();
		if (dt -> _internalCode == QGAMES::KeyCode::QGAMES_F1 && !dt -> _on)
			setShowFPS (!_showFPS); 
	}

	BATTLESHIP::Game::processEvent (evnt);
}

// ---
QGAMES::Game::Configuration* BattleshipII::Game::createConfiguration ()
{ 
	return (new Conf 
		(1 /** Default players */, std::atoi (parameter (__BATTLESHIPII_MAXNUMBEROFLIVESPARAMETER__).c_str ()))); 
}

// ---
std::string BattleshipII::Game::defaultParameter (const std::string& p) const
{
	std::string result (__NULL_STRING__);
	if (p == std::string (__BATTLESHIPII_MAXNUMBEROFLIVESPARAMETER__))
		result = std::string (__BATTLESHIPII_DEFAULTMAXNUMBEROFLIVESPARAMETER__);
	else
	if (p == std::string (__BATTLESHIPII_SHOWFPSPARAMETER__))
		result = std::string (__BATTLESHIPII_DEFAULTSHOWFPSPARAMETER__);
	else
		result = BATTLESHIP::Game::defaultParameter (p);
	return (result);
}

// ---
void BattleshipII::Game::initialize ()
{
	if (isInitialized ())
		return; // Only once...

	BATTLESHIP::Game::initialize ();

	if (!isInitialized ())
		return;

	// The standard builders do everything related with the screen...
	// In terms of position, size, name and even icon to represent it...

	// The entities and world has to be initialized using the method
	// "initializeWorldsAndEntities" or using the gameState "InitializeDragonWindGameState"
	// In the example the second option has been choosen

	// Add all game states from the definition file...
	addMainStatesFromBuilder (); 
	// ...and start to play with the main one...
	QGAMES::AdvancedGameStateControl* gCS = 
		dynamic_cast <QGAMES::AdvancedGameStateControl*> 
			(gameStateBuilder () -> gameState (__BATTLESHIP_STANDARDCONTROLGAMESTATE__));
	assert (gCS);

#ifndef NDEBUG
	setShowFPS (true);
#else
	std::string sfps = parameter (std::string (__BATTLESHIPII_SHOWFPSPARAMETER__));
	setShowFPS (QGAMES::toUpper (QGAMES::trim (sfps)) == std::string (__YES_STRING__));
#endif

	setState (gCS); // To start...

	observe (inputHandler ());
}

// ---
void BattleshipII::Game::finalize ()
{
	unObserve (inputHandler ());

	BATTLESHIP::Game::finalize ();
}
