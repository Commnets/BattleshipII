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

// ---
bool BattleshipII::MothershipUFO::toShoot (int f, const QGAMES::Vector& d, int nP)
{
	bool result = true;
	int j = 0;
	for (auto i : centralShootingPositionsForFormAndAspect (currentForm () -> id (), currentAspect ()))
	{
		if (__2IN3PROBABLE__)
			result &= BATTLESHIP::BigUFO::toShoot 
				(f, (i - QGAMES::Position::_cero).normalize (), j);
		j++;
	}
	
	return (result);
}

// ---
QGAMES::Position BattleshipII::MothershipUFO::shootingPosition (int nS, int tS, int nP) const
{
	assert (tS > nS && nS >= 0);

	QGAMES::bdata spc = __BD 20; // The total separation...
	QGAMES::Position iPos	= centerPosition () +
		centralShootingPositionsForFormAndAspect (currentForm () -> id (), currentAspect ())[nP];
	if (tS > 1)
		iPos += ((-spc / __BD 2) + (spc * __BD nS / __BD (tS - 1))) * 
			iPos.crossProduct (QGAMES::Vector::_zNormal).normalize ();
	
	return (iPos);
}

// ---
QGAMES::Positions BattleshipII::MothershipUFO::calculateCentralShootingPositionsForFormAndAspect (int f, int a) const
{
	// The position of the shooting zones are the same for the aspect...
	QGAMES::bdata ang = __BD (4 * a);
	QGAMES::bdata fct = __PI / __BD 180;
	return (QGAMES::Positions 
		{ __BD 280 * -QGAMES::Position::_yNormal, 
		  __BD 280 * -QGAMES::Position::_yNormal.rotate 
			(QGAMES::Position::_cero, QGAMES::Position::_zNormal, (__BD 24.0 + ang) * fct),
		  __BD 280 * -QGAMES::Position::_yNormal.rotate 
			(QGAMES::Position::_cero, QGAMES::Position::_zNormal, (__BD 48.0 + ang) * fct),
		  __BD 280 * -QGAMES::Position::_yNormal.rotate 
			(QGAMES::Position::_cero, QGAMES::Position::_zNormal, (__BD 72.0 + ang) * fct),
		  __BD 280 * -QGAMES::Position::_yNormal.rotate 
			(QGAMES::Position::_cero, QGAMES::Position::_zNormal, (__BD 96.0 + ang) * fct),
		  __BD 280 * -QGAMES::Position::_yNormal.rotate 
			(QGAMES::Position::_cero, QGAMES::Position::_zNormal, (__BD 120.0 + ang) * fct),
		  __BD 280 * -QGAMES::Position::_yNormal.rotate 
			(QGAMES::Position::_cero, QGAMES::Position::_zNormal, (__BD 144.0 + ang) * fct),
		  __BD 280 * -QGAMES::Position::_yNormal.rotate 
			(QGAMES::Position::_cero, QGAMES::Position::_zNormal, (__BD 168.0 + ang) * fct),
		  __BD 280 * -QGAMES::Position::_yNormal.rotate 
			(QGAMES::Position::_cero, QGAMES::Position::_zNormal, (__BD 192.0 + ang) * fct),
		  __BD 280 * -QGAMES::Position::_yNormal.rotate 
			(QGAMES::Position::_cero, QGAMES::Position::_zNormal, (__BD 216.0 + ang) * fct),
		  __BD 280 * -QGAMES::Position::_yNormal.rotate 
			(QGAMES::Position::_cero, QGAMES::Position::_zNormal, (__BD 240.0 + ang) * fct),
		  __BD 280 * -QGAMES::Position::_yNormal.rotate 
			(QGAMES::Position::_cero, QGAMES::Position::_zNormal, (__BD 264.0 + ang) * fct),
		  __BD 280 * -QGAMES::Position::_yNormal.rotate 
			(QGAMES::Position::_cero, QGAMES::Position::_zNormal, (__BD 288.0 + ang) * fct),
		  __BD 280 * -QGAMES::Position::_yNormal.rotate 
			(QGAMES::Position::_cero, QGAMES::Position::_zNormal, (__BD 312.0 + ang) * fct),
		  __BD 280 * -QGAMES::Position::_yNormal.rotate 
			(QGAMES::Position::_cero, QGAMES::Position::_zNormal, (__BD 336.0 + ang) * fct),
		}
	);
}

// --
QGAMES::Rectangles BattleshipII::MothershipUFO::calculateWeakAreasForFormAndAspect (int f, int a) const
{
	QGAMES::Positions cPos = centralShootingPositionsForFormAndAspect (f, a);

	QGAMES::Rectangles result;
	QGAMES::Vector d (__BD 20, __BD 20, __BD 0);
	for (auto i : cPos)
		result.push_back (QGAMES::Rectangle (i - d, i + d));

	return (result);
}
