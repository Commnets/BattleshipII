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
	/** To create the special curves of this game. */
	class CurveBuilder : public QGAMES::CurveTemplateBuilder
	{
		public:
		/** @see parent. */
		virtual QGAMES::FollowingACurveMovement::CurveTemplate* createCurve 
			(int t, const std::map <int, double>& prms) override final; // No extension possible...
	};

	/** To create the movements of the game.
		The previous curve factory has to be taken into account. */
	class MovementBuilder : public BATTLESHIP::MovementBuilder
	{
		public:
		MovementBuilder (const std::string& fDef)
			: BATTLESHIP::MovementBuilder (fDef, new CurveBuilder) // Needs the curves of this type of game...
								{ }

		// But no special movements have been added...
	};

	/** The extension to create worlds. */
	class WorldBuilder : public BATTLESHIP::WorldBuilder
	{
		public: 
		WorldBuilder (const std::string& eDef, QGAMES::MapBuilder* mB)
			: BATTLESHIP::WorldBuilder (eDef, mB)
							{ }

		private:
		/** @see parent. */
		virtual QGAMES::World* createWorldObject (int no, const QGAMES::Scenes& s, 
			const QGAMES::WorldProperties& p) override final;
		virtual QGAMES::Scene* createSceneObject (int ns, const QGAMES::Maps& m, 
			const QGAMES::Scene::Connections& cn, 
			const QGAMES::SceneProperties& p, const QGAMES::EntitiesPerLayer& ePL) override final;
		virtual QGAMES::SceneActionBlock* createSceneActionBlockObject (int nAB, 
			const QGAMES::SceneActionBlockProperties& prps) override final;
	};
}

#endif
  
// End of the file
/*@}*/