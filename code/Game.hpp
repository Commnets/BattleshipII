/** \ingroup BSII */
/*@{*/

/**	
 *	@file	
 *	File: Game.hpp \n
 *	Game: Battleship II \n
 *	Author: Ignacio Cea Forniés (Community Networks) \n
 *	Creation Date: 23/03/2020 \n
 *	Description: To manipulate the very basics of the Battleship II game. \n
 *	Versions: 1.0 Initial
 */

#ifndef __BATTLESHIPII_GAME__
#define __BATTLESHIPII_GAME__

#include "Defs.hpp"
#include "Builders.hpp"
#include <BattleshipLike/bsinclude.hpp>

namespace BattleshipII
{
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
}

#endif
  
// End of the file
/*@}*/