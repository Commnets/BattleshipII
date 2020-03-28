#include "Builders.hpp"
#include "Worlds.hpp"
#include "Scenes.hpp"

// ---
QGAMES::World* BattleshipII::WorldBuilder::createWorldObject (int no, const QGAMES::Scenes& s, 
		const QGAMES::WorldProperties& p)
{
	QGAMES::World* result = NULL;

	if (no == __BATTLESHIPII_STAGE1WORLDID__)
		result = new BattleshipII::Stage1World (s, p);
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

	if (ns == __BATTLESHIPII_STAGE1SCENE1__)
		result = new BattleshipII::Stage1Scene1 (m, cn, p, ePL);
	else
	if (ns == __BATTLESHIPII_STAGE1SCENE2__)
		result = new BattleshipII::Stage1Scene2 (m, cn, p, ePL);
	else
	if (ns == __BATTLESHIPII_STAGE1SCENE3__)
		result = new BattleshipII::Stage1Scene3 (m, cn, p, ePL);
	else
		result = BATTLESHIP::WorldBuilder::createSceneObject (ns, m, cn, p, ePL);

	return (result);
}
