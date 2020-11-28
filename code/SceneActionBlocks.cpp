#include "SceneActionBlocks.hpp"

// ---
QGAMES::Position BattleshipII::CurveAndInitialPositionFactory::initialPositionFor (int i , 
	BATTLESHIP::UFO* ufo, BATTLESHIP::StdUFOSceneActionBlock::Properties* prps)
{
	assert (ufo);
	assert (prps);

	QGAMES::Position result = QGAMES::Position::_cero;

	// Which is the max visual movement zone?
	// Just to be considered in the case a initial position has'n been defined in the properties list.
	int mW, mH, mD;
	ufo -> maxVisualDimensions (mW, mH, mD);
	QGAMES::Rectangle mZ = ufo -> getMovingZone ();

	// A couple of instructions to conserve the spirit of deciding a random position
	// when it's not defined in the conf file (as happens in the parent class).
	std::vector <int> mT {__BATTLESHIPII_SINUSOIDE1UFOSMOVEMENT__, __BATTLESHIPII_SINUSOIDE2UFOSMOVEMENT__ };
	for (int i = 0; i < __BATTLESHIP_NUMBEROFSTDATTACKS__; mT.push_back (i++));
	switch ((prps -> _movementType == -1) 
		? mT [(rand () % (__BATTLESHIP_NUMBEROFSTDATTACKS__ + 2  /** Two elements more. */))] : prps -> _movementType)
	{
		// Position should be defined...
		// Otherwise a random position (relative) in the visual zone is choosen:
		case __BATTLESHIPII_SINUSOIDE1UFOSMOVEMENT__:
		case __BATTLESHIPII_SINUSOIDE2UFOSMOVEMENT__:
			if (prps -> _initialPosition == QGAMES::Position::_noPoint)
				result = mZ.pos1 () + 
					QGAMES::Position (__BD (((rand () % 80) + 10) / __BD 100), // Between 10 and 90%
									  __BD (((rand () % 80) + 10) / __BD 100), __BD 0);
			else
				result = mZ.pos1 () + 
					QGAMES::Position (mZ.width () * prps -> _initialPosition.posX (),
									  mZ.height () * prps -> _initialPosition.posY (), __BD 0);
			break;

		default:
			result = BATTLESHIP::StdUFOSceneActionBlock::CurveAndInitialPositionFactory::initialPositionFor (i, ufo, prps);
			break;
	}

	return (result);
}

// ---
QGAMES::FollowingACurveMovement::CurveTemplate* BattleshipII::CurveAndInitialPositionFactory::curveFor 
	(int i, BATTLESHIP::UFO* ufo, BATTLESHIP::StdUFOSceneActionBlock::Properties* prps, std::map <int, double>& crvprms)
{
	assert (ufo);
	assert (prps);
	
	QGAMES::FollowingACurveMovement::CurveTemplate* result = NULL;

	BATTLESHIP::Game::Conf* cfg = 
		dynamic_cast <BATTLESHIP::Game::Conf*> (QGAMES::Game::game () -> configuration ());
	assert (cfg);

	QGAMES::AdvancedMovementBuilder* bld = 
		dynamic_cast <QGAMES::AdvancedMovementBuilder*> (ufo -> game () -> movementBuilder ());
	assert (bld);

	QGAMES::FollowingACurveMovement* mov = 
		dynamic_cast <QGAMES::FollowingACurveMovement*> (ufo -> currentMovement ());
	assert (mov);

	QGAMES::Rectangle mZ = ufo -> getMovingZone ();
	QGAMES::bdata f = (prps -> _speed < __BD 0) 
		? __BD ((rand () % ((int) -prps -> _speed)) + 1) : prps -> _speed;
	f += (__BD cfg -> difficulty () * __BD 1.5); 
	// Regarding the difficulty level thge speed is increment a little bit more...
	// This follows also the spirit of the things defined at parent level!

	// A couple of more instructions just to follow the rule that when -1
	// The movement to execute has to be selected from a list of them!
	std::vector <int> mT {__BATTLESHIPII_SINUSOIDE1UFOSMOVEMENT__, __BATTLESHIPII_SINUSOIDE2UFOSMOVEMENT__ };
	for (int i = 0; i < __BATTLESHIP_NUMBEROFSTDATTACKS__; mT.push_back (i++));
	switch ((prps -> _movementType == -1) 
		? mT [(rand () % (__BATTLESHIP_NUMBEROFSTDATTACKS__ + 2 /** Two elements more. */))] : prps -> _movementType)
	{
		case __BATTLESHIPII_SINUSOIDE1UFOSMOVEMENT__ :
			{
				if (!crvprms.empty () && crvprms.size () == 8) // 8 parameters needed minimum, if any...
					result = bld -> curveBuilder () -> createCurve (__BATTLESHIPII_SINUSOIDEGOANDBACK__, crvprms);
				else
				{
					result = bld -> curveBuilder () -> createCurve (__BATTLESHIPII_SINUSOIDEGOANDBACK__,
						crvprms = std::map <int, double> 
							{ { 0, 70.0f },
							  { 1, 70.0f },
							  { 2, (double) f },
							  { 3, 0.0 }, { 4, 0.0 }, { 5, 1.0 }, // XY Plane...
							  { 6, 0.0 },
							  { 7, (double) ((__BD 2 * __PI) + (__BD 2 * __PI)) }
							});
				}
			}

			break;

		case __BATTLESHIPII_SINUSOIDE2UFOSMOVEMENT__ :
			{
				if (!crvprms.empty () && crvprms.size () == 8) // 8 parameters needed minimum, if any...
					result = bld -> curveBuilder () -> createCurve (__BATTLESHIPII_SINUSOIDEGOANDBACK__, crvprms);
				else
				{
					result = bld -> curveBuilder () -> createCurve (__BATTLESHIPII_SINUSOIDEGOANDBACK__,
						crvprms = std::map <int, double> 
							{ { 0, 70.0f },
							  { 1, 70.0f },
							  { 2, (double) f },
							  { 3, 0.0 }, { 4, 0.0 }, { 5, 1.0 }, // XY Plane...
							  { 6, (double) (__PI / __BD 2) },
							  { 7, (double) ((__BD 5 * __PI / __BD 2) + (__BD 2 * __PI)) }
							});
				}
			}

			break;

		case __BATTLESHIPII_SINUSOIDE3UFOSMOVEMENT__ :
			{
				if (!crvprms.empty () && crvprms.size () == 8) // 8 parameters needed minimum, if any...
					result = bld -> curveBuilder () -> createCurve (__BATTLESHIPII_SINUSOIDEGOANDBACK__, crvprms);
				else
				{
					result = bld -> curveBuilder () -> createCurve (__BATTLESHIPII_SINUSOIDEGOANDBACK__,
						crvprms = std::map <int, double> 
							{ { 0, 70.0f },
							  { 1, 70.0f },
							  { 2, (double) f },
							  { 3, 0.0 }, { 4, 0.0 }, { 5, 1.0 }, // XY Plane...
							  { 6, 0.0 },
							  { 7, (double) (__BD 2 * __PI) }
							});
				}

				result -> rotate (QGAMES::Vector::_zNormal, -__PI);
			}

			break;

		case __BATTLESHIPII_SINUSOIDE4UFOSMOVEMENT__ :
			{
				if (!crvprms.empty () && crvprms.size () == 8) // 8 parameters needed minimum, if any...
					result = bld -> curveBuilder () -> createCurve (__BATTLESHIPII_SINUSOIDEGOANDBACK__, crvprms);
				else
				{
					result = bld -> curveBuilder () -> createCurve (__BATTLESHIPII_SINUSOIDEGOANDBACK__,
						crvprms = std::map <int, double> 
							{ { 0, 70.0f },
							  { 1, 70.0f },
							  { 2, (double) f },
							  { 3, 0.0 }, { 4, 0.0 }, { 5, 1.0 }, // XY Plane...
							  { 6, (double) (__PI / __BD 2) },
							  { 7, (double) (__BD 3 * __PI / __BD 2) }
							});
				}

				result -> rotate (QGAMES::Vector::_zNormal, -__PI);
			}

			break;

		default:
			result = BATTLESHIP::StdUFOSceneActionBlock::CurveAndInitialPositionFactory::curveFor (i, ufo, prps, crvprms);
			break;
	}

	return (result);
}

// ---
BattleshipII::SinusoideFromLeftBlockCombatFormationFactory::SinusoideFromLeftBlockCombatFormationFactory  
		(BATTLESHIP::StdUFOSceneActionBlock::CurveAndInitialPositionFactory* cF, QGAMES::bdata sBE)
	: BATTLESHIP::StdSetUFOsSceneActionBlock::StayAndAttackOneByOneCombatFormationFactory (cF),
	  _separationBetweenElements (sBE)
{
	// The UFOS are located one beneath the other...
	_positionFunction = [=](int i, BATTLESHIP::StdSetUFOsSceneActionBlock::Properties* prps) -> QGAMES::Position 
		{ 
			assert (prps);

			QGAMES::bdata sBE = ((int) prps -> _combatFormationAttrs.size () >= 1) 
				? prps -> _combatFormationAttrs [0] : _separationBetweenElements;

			return (QGAMES::Position (__BD 0, __BD i * __BD sBE, __BD 0)); 
		};

	// There is no time among the UFOs when starting to move, so the defaut time function is enough

	// The curve to follow is different depending whether the UFO id is odd or even
	_curveFunction = [=](int i, BATTLESHIP::StdSetUFOsSceneActionBlock::Properties*) 
		-> int { return ((i % 2 == 0)
			? __BATTLESHIPII_SINUSOIDE1UFOSMOVEMENT__ : __BATTLESHIPII_SINUSOIDE2UFOSMOVEMENT__); };
}

// ---
BattleshipII::SinusoideFromRightBlockCombatFormationFactory::SinusoideFromRightBlockCombatFormationFactory 
		(BATTLESHIP::StdUFOSceneActionBlock::CurveAndInitialPositionFactory* cF, QGAMES::bdata sBE)
	: BATTLESHIP::StdSetUFOsSceneActionBlock::StayAndAttackOneByOneCombatFormationFactory (cF),
	  _separationBetweenElements (sBE)
{
	// The UFOS are located one beneath the other...
	_positionFunction = [=](int i, BATTLESHIP::StdSetUFOsSceneActionBlock::Properties* prps) -> QGAMES::Position 
		{ 
			assert (prps);

			QGAMES::bdata sBE = ((int) prps -> _combatFormationAttrs.size () >= 1) 
				? prps -> _combatFormationAttrs [0] : _separationBetweenElements;

			return (QGAMES::Position (__BD 0, __BD i * __BD sBE, __BD 0)); 
		};

	// There is no time among the UFOs when starting to move, so the defaut time function is enough

	// The curve to follow is different depending whether the UFO id is odd or even
	_curveFunction = [=](int i, BATTLESHIP::StdSetUFOsSceneActionBlock::Properties*) 
		-> int { return ((i % 2 == 0)
			? __BATTLESHIPII_SINUSOIDE3UFOSMOVEMENT__ : __BATTLESHIPII_SINUSOIDE4UFOSMOVEMENT__); };
}
