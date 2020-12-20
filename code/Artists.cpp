#include "Artists.hpp"

// ---
QGAMES::Entity* BattleshipII::UFO::clone () const
{
	QGAMES::Entity* result = new BattleshipII::UFO 
		(_id, dynamic_cast <BATTLESHIP::Spaceship::Behaviour*> (_behaviour -> clone ()), _forms, _data);

	result -> setMovements (movements ());
	result -> setAnimations (cloneAnimations ());
	result -> setStates (cloneStates ());

	return (result);
}

// ---
BATTLESHIP::UFO::StatesId BattleshipII::UFO::statesIdForType (int t)
{
	 BATTLESHIP::UFO::StatesId result;

	 switch (t)
	 {
		case __BATTLESHIPII_ENEMTYTYPE3__:
			result = __BATTLESHIPII_UFO4STATESID;
			break;
		
		case __BATTLESHIPII_ENEMTYTYPE4__:
			result = __BATTLESHIPII_UFO5STATESID;
			break;
		
		default:
			result = BATTLESHIP::UFO::statesIdForType (t);
			break;
	 }

	 return (result);
}

// ---
QGAMES::Entity* BattleshipII::MothershipUFO::clone () const
{
	QGAMES::Entity* result = new BattleshipII::MothershipUFO 
		(_id, dynamic_cast <BATTLESHIP::Spaceship::Behaviour*> (_behaviour -> clone ()), _forms, _data);

	result -> setMovements (movements ());
	result -> setAnimations (cloneAnimations ());
	result -> setStates (cloneStates ());

	return (result);
}

// ---
BATTLESHIP::UFO::StatesId BattleshipII::MothershipUFO::statesIdForType (int t)
{
	// TODO

	return (BATTLESHIP::UFO::statesIdForType (t));
}
