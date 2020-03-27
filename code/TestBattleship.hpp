/** \ingroup BSII */
/*@{*/

/**	
 *	@file	
 *	File: Battleship II.hpp \n
 *	Framework: Commty Game Library (CGL) \n
 *	Author: Ignacio Cea Forni�s (Community Networks) \n
 *	Creation Date: 23/03/2020 \n
 *	Description: Very simple and basic Battleship game. \n
 *	Versions: 1.0 Initial
 */

#ifndef __BATTLESHIPIIGAME__
#define __BATTLESHIPIIGAME__

#include "Defs.hpp"
#include <BattleshipLike/bsinclude.hpp>

namespace BattleshipII
{
	// -------The world, scenes and maps-------------------------------------------------------------------------
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
	// --------------------------------------------------------------------------------

	// -------The Game-------------------------------------------------------------------------
	class Game : public BATTLESHIP::Game
	{
		public:
		class Conf : public BATTLESHIP::Game::Conf
		{
			public:
			Conf (int nP, int mL = 3)
				: BATTLESHIP::Game::Conf (nP, __BATTLESHIP_EXAMPLEWORLDID__, __BATTLESHIP_EXAMPLESCENEID__),
				  _maxLives (mL)
							{ adjustToPlayers (nP); }

			/** @see parent. */
			virtual Configuration* clone () const
							{ Conf* result = new Conf (*this); 
							  result -> cloneImplementation (this); 
							  return (result); }

			protected:
			/** @see parent. */
			virtual void adjustToPlayers (int nP);

			private:
			/** The max number of lives defined in configuration. */
			int _maxLives;
		};

		Game ()
			: BATTLESHIP::Game (),
			  _showFPS (false) // Not to show by default...
							{ }

		/** To switch the visualization of the fPS. */
		void setShowFPS (bool s);

		/** @see parent. */
		virtual void processEvent (const QGAMES::Event& evnt);

		private:
		/** see parent. */
		virtual QGAMES::InputHandler* createInputHandler ()
							{ return (implementation () -> createInputHandler (new BATTLESHIP::InputHandlerBehaviour ())); }
		virtual QGAMES::WorldBuilder* createWorldBuilder ()
							{ return (new WorldBuilder (parameter (__GAME_PROPERTYWORLDSFILE__), 
								mapBuilder ())); }
		virtual QGAMES::CharacterControlStepsMonitorBuilder* createCharacterMonitorBuilder ()
							{ return (new QGAMES::CharacterControlStepsMonitorBuilder 
								(parameter (__GAME_PROPERTUCHARACTERMONITORFILE__))); }

		/** @see parent. */
		virtual Configuration* createConfiguration ();

		/** @see parent. */
		virtual std::string defaultParameter (const std::string& p) const;

		/** @see parent. */
		virtual void initialize ();
		virtual void finalize ();

		private:
		/** To show or not the FPS in the right bottom corner. */
		bool _showFPS;
	};
	// --------------------------------------------------------------------------------
}

#endif
  
// End of the file
/*@}*/