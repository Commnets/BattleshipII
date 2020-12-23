#include "SceneActionBlocks.hpp"
#include "Game.hpp"

// ---
BattleshipII::SinusoideFromLeftBlockCombatFormationFactory::SinusoideFromLeftBlockCombatFormationFactory  
		(BATTLESHIP::StdUFOSceneActionBlock::CurveAndInitialPositionFactory* cF, QGAMES::bdata sBE,
		 const BATTLESHIP::StdSetUFOsSceneActionBlock::CombatFormationFactory::SingleActionBlockFunction& eABlock)
	: BATTLESHIP::StdSetUFOsSceneActionBlock::StayAndAttackOneByOneCombatFormationFactory 
		(cF, _SAMEPOSITION, _SAMETIME, eABlock, _NOMOVEMENTCURVE),
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
		(BATTLESHIP::StdUFOSceneActionBlock::CurveAndInitialPositionFactory* cF, QGAMES::bdata sBE,
		 const BATTLESHIP::StdSetUFOsSceneActionBlock::CombatFormationFactory::SingleActionBlockFunction& eABlock)
	: BATTLESHIP::StdSetUFOsSceneActionBlock::StayAndAttackOneByOneCombatFormationFactory 
		(cF, _SAMEPOSITION, _SAMETIME, eABlock, _NOMOVEMENTCURVE),
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
