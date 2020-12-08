/** \ingroup BSII */
/*@{*/

/**	
 *	@file	
 *	File: Scenes.hpp \n
 *	Game: Battleship II \n
 *	Author: Ignacio Cea Forniés (Community Networks) \n
 *	Creation Date: 24/03/2020 \n
 *	Description: Defines the base for all scenes in Battleship II game \n
 *	Versions: 1.0 Initial
 */

#ifndef __BATTLESHIPII_STAGE1SCENES__
#define __BATTLESHIPII_STAGE1SCENES__

#include "Defs.hpp"
#include <BattleshipLike/bsinclude.hpp>

namespace BattleshipII
{
	/** Base for Stage 1 Scenes */
	class Stage1Scene : public BATTLESHIP::TimeLimitScene
	{
		public:
		Stage1Scene (int c, const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: BATTLESHIP::TimeLimitScene (c, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize () override final;
	};

	/** Stage 1 Scene 1 */
	class Stage1Scene1 : public Stage1Scene
	{
		public:
		Stage1Scene1 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: Stage1Scene (__BATTLESHIPII_STAGE1SCENE1__, m, cn, p, ePL)
							{ }
	};

	/** Stage 1 Scene 2 */
	class Stage1Scene2 : public Stage1Scene
	{
		public:
		Stage1Scene2 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: Stage1Scene (__BATTLESHIPII_STAGE1SCENE2__, m, cn, p, ePL)
							{ }
	};

	/** Stage 1 Scene 3 */
	class Stage1Scene3 : public Stage1Scene
	{
		public:
		Stage1Scene3 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: Stage1Scene (__BATTLESHIPII_STAGE1SCENE3__, m, cn, p, ePL)
							{ }
	};
}

#endif

// End of the file
/*@}*/
