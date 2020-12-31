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
	/** This big UFO ahoots from many different places at the same time. \n
		and can only be killed when all the power forces are also killed. \n
		The power positions are defined taking into account the "basic" form of the mothership, 
		they have to be recalculated as the motherhips moves. */
	class MothershipUFO : public BATTLESHIP::BigUFO
	{
		public:
		MothershipUFO (int cId, 
				BATTLESHIP::UFO::Behaviour* bhv = new BATTLESHIP::UFO::Behaviour (true, false, __BD 0, __BD 50, 100, __BD 3, 0), 
				const QGAMES::Forms& f = QGAMES::Forms (), 
				const QGAMES::Entity::Data& d = QGAMES::Entity::Data ())
			: BATTLESHIP::BigUFO (cId, bhv, f, d)
							{ }

		/** @see parent. */
		virtual QGAMES::Entity* clone () const override final;

		/** @see parent. */
		virtual bool toShoot (int f = 1, 
			const QGAMES::Vector& d = QGAMES::Vector (__BD 0, __BD -1, __BD 0), int nP = 0) override final;

		/** @see parent. */
		virtual QGAMES::Position shootingPosition (int nS, int tS, int nP = 0) const override final;

		protected:
		/** @see parent. */
		virtual QGAMES::Positions calculateCentralShootingPositionsForFormAndAspect (int f, int a) const;
		virtual QGAMES::Rectangles calculateWeakAreasForFormAndAspect (int f, int a) const;
	};
}

#endif
  
// End of the file
/*@}*/
