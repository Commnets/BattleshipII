#include "Builders.hpp"
#include "Worlds.hpp"
#include "Artists.hpp"
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
BATTLESHIP::Spaceship* BattleshipII::EntityBuilder::createSpaceship (const QGAMES::EntityBuilder::EntityDefinition& def)
{
	BATTLESHIP::Spaceship* result = NULL;
	if (def._id >= __BATTLESHIPII_UFOBASEID__ && 
		def._id < (__BATTLESHIPII_UFOBASEID__ + __BATTLESHIPII_MAXNUMBERUFOS__))
		result = new BattleshipII::UFO (def._id); 
	else
	if (def._id >= __BATTLESHIPII_MOTHERSHIPBASEID__ &&
		def._id < (__BATTLESHIPII_MOTHERSHIPBASEID__ + __BATTLESHIPII_MAXNUMBERMOTHERSHIPS__))
		result = new BattleshipII::MothershipUFO (def._id); 

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
	if (no == __BATTLESHIPII_STAGE3WORLDID__)
		result = new BattleshipII::Stage3World (s, p);
	else
	if (no == __BATTLESHIPII_STAGE4WORLDID__)
		result = new BattleshipII::Stage4World (s, p);
	else
	if (no == __BATTLESHIPII_STAGE5WORLDID__)
		result = new BattleshipII::Stage5World (s, p);
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

	// World Stage 3...
	if (ns == __BATTLESHIPII_STAGE3SCENE1__)
		result = new BattleshipII::Stage3Scene1 (m, cn, p, ePL);
	else
	if (ns == __BATTLESHIPII_STAGE3SCENE2__)
		result = new BattleshipII::Stage3Scene2 (m, cn, p, ePL);
	else
	if (ns == __BATTLESHIPII_STAGE3SCENE3__)
		result = new BattleshipII::Stage3Scene3 (m, cn, p, ePL);
	else

	// World Stage 4...
	if (ns == __BATTLESHIPII_STAGE4SCENE1__)
		result = new BattleshipII::Stage4Scene1 (m, cn, p, ePL);
	else
	if (ns == __BATTLESHIPII_STAGE4SCENE2__)
		result = new BattleshipII::Stage4Scene2 (m, cn, p, ePL);
	else
	if (ns == __BATTLESHIPII_STAGE4SCENE3__)
		result = new BattleshipII::Stage4Scene3 (m, cn, p, ePL);
	else

	// World Stage 5...
	if (ns == __BATTLESHIPII_STAGE5SCENE1__)
		result = new BattleshipII::Stage5Scene1 (m, cn, p, ePL);
	else
	if (ns == __BATTLESHIPII_STAGE5SCENE2__)
		result = new BattleshipII::Stage5Scene2 (m, cn, p, ePL);
	else
	if (ns == __BATTLESHIPII_STAGE5SCENE3__)
		result = new BattleshipII::Stage5Scene3 (m, cn, p, ePL);

	// Any other
	else
		result = BATTLESHIP::WorldBuilder::createSceneObject (ns, m, cn, p, ePL);


	return (result);
}

// ---
QGAMES::SceneActionBlock* BattleshipII::WorldBuilder::createSceneActionBlockObject (int nAB, 
			const QGAMES::SceneActionBlockProperties& prps)
{
	QGAMES::SceneActionBlock* result = NULL;

	// The ation blocks used for any type of enemies, now are splitted into two
	// one set for controlling UFOs, and the other one for controlling MothershipUFOs...
	if (nAB >= __BATTLESHIPII_ACTIONBLOCKUFOBASEID__ && 
			nAB < (__BATTLESHIPII_ACTIONBLOCKUFOBASEID__ + __BATTLESHIPII_ACTIONBLOCKUFONUMBER__))
		result = new BattleshipII::UFOSceneActionBlock 
			(nAB, new BATTLESHIP::StdUFOSceneActionBlock::Properties (prps),
				new BattleshipII::CurveAndInitialPositionFactory); // Considering the new curve factory 
	else 
	if (nAB >= __BATTLESHIPII_ACTIONBLOCKMOTHERSHIPUFOBASEID__ && 
			nAB < (__BATTLESHIPII_ACTIONBLOCKMOTHERSHIPUFOBASEID__ + __BATTLESHIPII_ACTIONBLOCKMOTHERSHIPUFONUMBER__))
		result = new BattleshipII::MothershipUFOSceneActionBlock 
			(nAB, new BATTLESHIP::StdUFOSceneActionBlock::Properties (prps),
				new BattleshipII::CurveAndInitialPositionFactory); // A new action block only for motherships, and 
																   // considering the new curving factory!
	else
	// The action blocks used for set of UFOS are still valid, but with a different curve factory...
	if (nAB >= __BATTLESHIP_ACTIONBLOCKSETUFOSBASEID__ && 
		nAB < (__BATTLESHIP_ACTIONBLOCKSETUFOSBASEID__ + __BATTLESHIP_ACTIONBLOCKSETUFOSNUMBER__))
	{
		std::function <BATTLESHIP::StdUFOSceneActionBlock* 
			(int, BATTLESHIP::StdUFOSceneActionBlock::CurveAndInitialPositionFactory*)> eABlock = 
				[](int i, BATTLESHIP::StdUFOSceneActionBlock::CurveAndInitialPositionFactory* cF) -> BATTLESHIP::StdUFOSceneActionBlock* 
					{ return (new BattleshipII::UFOSceneActionBlock // Including the new action block...
						(i, new BATTLESHIP::StdUFOSceneActionBlock::Properties (), cF -> clone ())); };

		result = new BATTLESHIP::StdSetUFOsSceneActionBlock 
			(nAB, new BATTLESHIP::StdSetUFOsSceneActionBlock::Properties (prps),
				new BATTLESHIP::StdSetUFOsSceneActionBlock::CombatFormationFactories 
					({ new BATTLESHIP::StdSetUFOsSceneActionBlock::BlockCombatFormationFactory 
							(new BattleshipII::CurveAndInitialPositionFactory, 7, __BD 0.08, eABlock), 
							// Old combat formation with the new factory, and the new function to create basic UFO action blocks
						new BATTLESHIP::StdSetUFOsSceneActionBlock::QueueCombatFormationFactory 
							(new BattleshipII::CurveAndInitialPositionFactory, __BD 0.3, eABlock), 
							// Old combat formation with the new factory, and the new function to create basic UFO action blocks
						new BATTLESHIP::StdSetUFOsSceneActionBlock::SolidLinearBlockCombatFormationFactory 
							(new BattleshipII::CurveAndInitialPositionFactory, 10, eABlock), 
							// Old combat formation with the new factory, and the new function to create basic UFO action blocks
						new BattleshipII::SinusoideFromLeftBlockCombatFormationFactory
							(new BattleshipII::CurveAndInitialPositionFactory, __BD 0.5, eABlock),
						new BattleshipII::SinusoideFromRightBlockCombatFormationFactory
							(new BattleshipII::CurveAndInitialPositionFactory, __BD 0.5, eABlock) })); 
	}
	else
		result = BATTLESHIP::WorldBuilder::createSceneActionBlockObject (nAB, prps);

	return (result);
}
