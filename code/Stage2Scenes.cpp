#include "Stage2Scenes.hpp"

// ---
void BattleshipII::Stage2Scene::initialize ()
{
	setBackgroundMap (__BATTLESHIP_TRANSPARENTMAPID__); 

	setMap (__BATTLESHIP_COMPLEXSTARTSMOVINGBACKGROUNDMAP2ID__);

	BATTLESHIP::SequentialActionBlocksScene::initialize ();
}
