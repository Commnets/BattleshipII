#include "Stage5Scenes.hpp"

// ---
void BattleshipII::Stage5Scene::initialize ()
{
	setBackgroundMap (__BATTLESHIP_TRANSPARENTMAPID__); 

	setMap (__BATTLESHIP_COMPLEXSTARTSMOVINGBACKGROUNDMAP5ID__);

	BATTLESHIP::TimeLimitScene::initialize ();
}
