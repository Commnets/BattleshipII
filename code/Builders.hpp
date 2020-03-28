/** \ingroup BSII */
/*@{*/

/**	
 *	@file	
 *	File: Builders.hpp \n
 *	Game: Battleship II \n
 *	Author: Ignacio Cea Forniés (Community Networks) \n
 *	Creation Date: 23/03/2020 \n
 *	Description: The constructors that the Battleship II game needs. \n
 *	Versions: 1.0 Initial
 */

#ifndef __BATTLESHIPII_BUILDERS__
#define __BATTLESHIPII_BUILDERS__

#include "Defs.hpp"
#include <BattleshipLike/bsinclude.hpp>

namespace BattleshipII
{
	/** The extension to create worlds. */
	class WorldBuilder : public BATTLESHIP::WorldBuilder
	{
		public: 
		WorldBuilder (const std::string& eDef, QGAMES::MapBuilder* mB)
			: BATTLESHIP::WorldBuilder (eDef, mB)
							{ }

		private:
		virtual QGAMES::World* createWorldObject (int no, const QGAMES::Scenes& s, 
			const QGAMES::WorldProperties& p);
		virtual QGAMES::Scene* createSceneObject (int ns, const QGAMES::Maps& m, 
			const QGAMES::Scene::Connections& cn, 
			const QGAMES::SceneProperties& p, const QGAMES::EntitiesPerLayer& ePL);
	};
}

#endif
  
// End of the file
/*@}*/