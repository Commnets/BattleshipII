/** \ingroup BSII */
/*@{*/

/**	
 *	@file	
 *	File: Artists.hpp \n
 *	Game: Battleship II \n
 *	Author: Ignacio Cea Forniés (Community Networks) \n
 *	Creation Date: 08/12/2020 \n
 *	Description: The specific artists (Ufos, battleships, and so on) this game needs. \n
 *	Versions: 1.0 Initial
 */

#ifndef __BATTLESHIPII_ARTISTS__
#define __BATTLESHIPII_ARTISTS__

#include "Defs.hpp"
#include <BattleshipLike/bsinclude.hpp>

namespace BattleshipII
{
	/** Just to add more types. */
	class UFO : public BATTLESHIP::UFO
	{
		public:
		#define __BATTLESHIPII_UFO4STATESID BATTLESHIP::UFO::StatesId \
			(6, __BATTLESHIP_ENEMYBLANKSTATE__, 7, __BATTLESHIP_ENEMYEXPLODINGSTATE__, __BATTLESHIP_ENEMYBLANKSTATE__)
		#define __BATTLESHIPII_UFO5STATESID BATTLESHIP::UFO::StatesId \
			(8, __BATTLESHIP_ENEMYBLANKSTATE__, 9, __BATTLESHIP_ENEMYEXPLODINGSTATE__, __BATTLESHIP_ENEMYBLANKSTATE__)

		UFO (int cId, 
				BATTLESHIP::UFO::Behaviour* bhv = new BATTLESHIP::UFO::Behaviour (true, false, __BD 0, __BD 50, 100, __BD 3, 0), 
				const QGAMES::Forms& f = QGAMES::Forms (), 
				const QGAMES::Entity::Data& d = QGAMES::Entity::Data ())
			: BATTLESHIP::UFO (cId, bhv, f, d)
							{ }

		/** @see parent. */
		virtual QGAMES::Entity* clone () const;

		protected:
		/** @see parent. */
		virtual StatesId statesIdForType (int t);
	};

	/** This big UFO ahoots from many different places at the same time. \n
		and can only be killed when all the power forces are also killed. \n
		The power positions are defined taking into account the "basic" form of the mothership, 
		they have to be recalculated as the motherhips moves. */
	class MothershipUFO : public BATTLESHIP::UFO
	{
		public:
		MothershipUFO (int cId, 
				BATTLESHIP::UFO::Behaviour* bhv = new BATTLESHIP::UFO::Behaviour (true, false, __BD 0, __BD 50, 100, __BD 3, 0), 
				const QGAMES::Forms& f = QGAMES::Forms (), 
				const QGAMES::Entity::Data& d = QGAMES::Entity::Data ())
			: BATTLESHIP::UFO (cId, bhv, f, d)
							{ }

		/** @see parent. */
		virtual QGAMES::Entity* clone () const override final;

		protected:
		/** @see parent. */
		virtual StatesId statesIdForType (int t) override final;
	};
}

#endif
  
// End of the file
/*@}*/
