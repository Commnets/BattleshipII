#include "Stage5Scenes.hpp"
#include "Artists.hpp"

// ---
void BattleshipII::Stage5Scene::initialize ()
{
	setBackgroundMap (__BATTLESHIP_TRANSPARENTMAPID__); 

	setMap (__BATTLESHIP_COMPLEXSTARTSMOVINGBACKGROUNDMAP5ID__);

	BATTLESHIP::TimeLimitScene::initialize ();
}

// ---
void BattleshipII::Stage5Scene1::initialize ()
{
	setBackgroundMap (__BATTLESHIP_TRANSPARENTMAPID__); 

	setMap (__BATTLESHIP_COMPLEXSTARTSMOVINGBACKGROUNDMAP5ID__);

	BATTLESHIP::FocusingInOneElementScene::initialize ();
}

// ---
void BattleshipII::Stage5Scene1::processEvent (const QGAMES::Event& evnt)
{
	BATTLESHIP::FocusingInOneElementScene::processEvent (evnt);

	if (evnt.code () == __BATTLESHIP_SPACEELEMENTACTIONBLOCKELMNTMEMERGED__ && 
		focusedElement () == NULL) // Nothing adjusted still!
	{
		BATTLESHIP::StdUFOSceneActionBlock* ufoblk = 
			static_cast <BATTLESHIP::StdUFOSceneActionBlock*> (evnt.data ());
		assert (!ufoblk -> spaceElementsControlled ().empty ());
		if (dynamic_cast <BattleshipII::MothershipUFO*> (ufoblk -> spaceElementsControlled ()[0]) != NULL)
			setFocusedElement (ufoblk -> spaceElementsControlled ()[0]);
	}
}
