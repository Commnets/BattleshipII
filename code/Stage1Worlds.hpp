/** \ingroup BSII */
/*@{*/

/**	
 *	@file	
 *	File: Worlds.hpp \n
 *	Game: Battleship II \n
 *	Author: Ignacio Cea Forni�s (Community Networks) \n
 *	Creation Date: 27/03/2020 \n
 *	Description: Defines the base for all worlds in Battleship II game  \n
 *	Versions: 1.0 Initial
 */

#ifndef __BATTLESHIPII_STAGE1WORLDS__
#define __BATTLESHIPII_STAGE1WORLDS__

#include "Defs.hpp"
#include <BattleshipLike/bsinclude.hpp>

namespace BattleshipII
{
	/** Class to define common funtionality to any world in a Battleship II game. */
	class Stage1World : public BATTLESHIP::World
	{
		public:
		Stage1World (const QGAMES::Scenes& scns, 
				const QGAMES::WorldProperties& prps = QGAMES::WorldProperties ())
			: BATTLESHIP::World (__BATTLESHIPII_STAGE1WORLDID__, scns, prps)
							{ }

		/** @see parent. */
		virtual void initialize ();
		virtual void finalize ();

		protected:
	};
}

#endif

// End of the file
/*@}*/
