#include "Artists.hpp"

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
