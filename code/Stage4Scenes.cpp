#include "Stage4Scenes.hpp"

// ---
void BattleshipII::Stage4Scene::initialize ()
{
	setBackgroundMap (__BATTLESHIP_TRANSPARENTMAPID__); 

	setMap (__BATTLESHIP_COMPLEXSTARTSMOVINGBACKGROUNDMAP4ID__);

	BATTLESHIP::TimeLimitScene::initialize ();
}
