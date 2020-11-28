#include "Builders.hpp"
#include "Worlds.hpp"
#include "Scenes.hpp"
#include "SceneActionBlocks.hpp"

// ---
QGAMES::FollowingACurveMovement::CurveTemplate* BattleshipII::CurveBuilder::createCurve 
			(int t, const std::map <int, double>& prms)
{
	QGAMES::FollowingACurveMovement::CurveTemplate* result = NULL;

	if (t == __BATTLESHIPII_SINUSOIDEGOANDBACK__)
	{
		assert (prms.find (0) != prms.end () && // The range of the trace...
				prms.find (1) != prms.end () && // The period of the trace...
				prms.find (2) != prms.end () && // The speed factor. 
												// The bigger the number is the lesser the final speed will be...
				prms.find (3) != prms.end () && // x coordinate to the orientation
				prms.find (4) != prms.end () && // y
				prms.find (5) != prms.end () && // z
				prms.find (6) != prms.end () && // initial angle (in radians)
				prms.find (7) != prms.end () );  // final
		assert ((*prms.find (2)).second != __BD 0); // Not possible speed reduction factor be 0...

		QGAMES::FollowingACurveMovement::CurveTemplate* crv1 = createCurve (__QGAMES_SINUSOIDALCURVEMOVEMENTTRACE__, prms);

		std::map <int, double> oPrms = prms;
		double t = oPrms [6]; oPrms [6] = oPrms [7]; oPrms [7] = t; // The opposite
		QGAMES::FollowingACurveMovement::CurveTemplate* crv2 = createCurve (__QGAMES_SINUSOIDALCURVEMOVEMENTTRACE__, oPrms);

		QGAMES::FollowingACurveMovement::CurveTemplates crvs;
		crvs.push_back (crv1), crvs.push_back (crv2);

		result = new QGAMES::FollowingACurveMovement::ComplexCurveTemplate (crvs);
	}
	else
		result = QGAMES::CurveTemplateBuilder::createCurve (t, prms);

	return (result);
}

// ---
QGAMES::World* BattleshipII::WorldBuilder::createWorldObject (int no, const QGAMES::Scenes& s, 
		const QGAMES::WorldProperties& p)
{
	QGAMES::World* result = NULL;

	if (no == __BATTLESHIPII_STAGE1WORLDID__)
		result = new BattleshipII::Stage1World (s, p);
	else
	if (no == __BATTLESHIPII_STAGE2WORLDID__)
		result = new BattleshipII::Stage2World (s, p);
	else
		result = BATTLESHIP::WorldBuilder::createWorldObject (no, s, p);

	return (result);
}

// ---
QGAMES::Scene* BattleshipII::WorldBuilder::createSceneObject (int ns, const QGAMES::Maps& m, 
		const QGAMES::Scene::Connections& cn, 
		const QGAMES::SceneProperties& p, const QGAMES::EntitiesPerLayer& ePL)
{
	QGAMES::Scene* result = NULL;

	// World Stage 1...
	if (ns == __BATTLESHIPII_STAGE1SCENE1__)
		result = new BattleshipII::Stage1Scene1 (m, cn, p, ePL);
	else
	if (ns == __BATTLESHIPII_STAGE1SCENE2__)
		result = new BattleshipII::Stage1Scene2 (m, cn, p, ePL);
	else
	if (ns == __BATTLESHIPII_STAGE1SCENE3__)
		result = new BattleshipII::Stage1Scene3 (m, cn, p, ePL);
	else
	// World Stage 2...
	if (ns == __BATTLESHIPII_STAGE2SCENE1__)
		result = new BattleshipII::Stage2Scene1 (m, cn, p, ePL);
	else
	if (ns == __BATTLESHIPII_STAGE2SCENE2__)
		result = new BattleshipII::Stage2Scene2 (m, cn, p, ePL);
	else
	if (ns == __BATTLESHIPII_STAGE2SCENE3__)
		result = new BattleshipII::Stage2Scene3 (m, cn, p, ePL);
	else
		result = BATTLESHIP::WorldBuilder::createSceneObject (ns, m, cn, p, ePL);


	return (result);
}

// ---
QGAMES::SceneActionBlock* BattleshipII::WorldBuilder::createSceneActionBlockObject (int nAB, 
			const QGAMES::SceneActionBlockProperties& prps)
{
	QGAMES::SceneActionBlock* result = NULL;

	// If what is required is a set of UFOs action block, then the combat factories list needed is
	// a little bit fferent that the default one, because the new curve and position factory is needed...
	if (nAB >= __BATTLESHIP_ACTIONBLOCKSETUFOSBASEID__ && 
		nAB < (__BATTLESHIP_ACTIONBLOCKSETUFOSBASEID__ + __BATTLESHIP_ACTIONBLOCKSETUFOSNUMBER__))
		result = new BATTLESHIP::StdSetUFOsSceneActionBlock 
			(nAB, new BATTLESHIP::StdSetUFOsSceneActionBlock::Properties (prps),
				new BATTLESHIP::StdSetUFOsSceneActionBlock::CombatFormationFactories 
					({ new BATTLESHIP::StdSetUFOsSceneActionBlock::BlockCombatFormationFactory 
							(new BattleshipII::CurveAndInitialPositionFactory), // Old combat formation with the new factory...
						new BATTLESHIP::StdSetUFOsSceneActionBlock::QueueCombatFormationFactory 
							(new BattleshipII::CurveAndInitialPositionFactory), // Old combat formation with the new factory...
						new BATTLESHIP::StdSetUFOsSceneActionBlock::SolidLinearBlockCombatFormationFactory 
							(new BattleshipII::CurveAndInitialPositionFactory), // Old combat formation with the new factory...
						new BattleshipII::SinusoideFromLeftBlockCombatFormationFactory
							(new BattleshipII::CurveAndInitialPositionFactory),
						new BattleshipII::SinusoideFromRightBlockCombatFormationFactory
							(new BattleshipII::CurveAndInitialPositionFactory) })); 
	else
		result = BATTLESHIP::WorldBuilder::createSceneActionBlockObject (nAB, prps);

	return (result);
}
