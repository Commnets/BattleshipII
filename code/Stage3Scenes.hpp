/** \ingroup BSII */
/*@{*/

/**	
 *	@file	
 *	File: Scenes.hpp \n
 *	Game: Battleship II \n
 *	Author: Ignacio Cea Forniés (Community Networks) \n
 *	Creation Date: 28/11/2020 \n
 *	Description: Defines the base for all scenes in Battleship II game \n
 *	Versions: 1.0 Initial
 */

#ifndef __BATTLESHIPII_STAGE3SCENES__
#define __BATTLESHIPII_STAGE3SCENES__

#include "Defs.hpp"
#include <BattleshipLike/bsinclude.hpp>

namespace BattleshipII
{
	/** Base for Stage 3 Scenes */
	class Stage3Scene : public BATTLESHIP::TimeLimitScene
	{
		public:
		Stage3Scene (int c, const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: BATTLESHIP::TimeLimitScene (c, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** Stage 3 Scene 1 */
	class Stage3Scene1 : public Stage3Scene
	{
		public:
		Stage3Scene1 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: Stage3Scene (__BATTLESHIPII_STAGE3SCENE1__, m, cn, p, ePL)
							{ }
	};

	/** Stage 3 Scene 2 */
	class Stage3Scene2 : public Stage3Scene
	{
		public:
		Stage3Scene2 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: Stage3Scene (__BATTLESHIPII_STAGE3SCENE2__, m, cn, p, ePL)
							{ }
	};

	/** Stage 3 Scene 3 */
	class Stage3Scene3 : public Stage3Scene
	{
		public:
		Stage3Scene3 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: Stage3Scene (__BATTLESHIPII_STAGE3SCENE3__, m, cn, p, ePL)
							{ }
	};
}

#endif

// End of the file
/*@}*/
