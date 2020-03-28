#include "Stage1Scenes.hpp"

// ---
void BattleshipII::Stage1Scene::initialize ()
{
	setBackgroundMap (__BATTLESHIP_TRANSPARENTMAPID__); 

	setMap (__BATTLESHIP_COMPLEXSTARTSMOVINGBACKGROUNDMAP1ID__);

	BATTLESHIP::TimeLimitScene::initialize ();
}
