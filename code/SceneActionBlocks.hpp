/** \ingroup BSII */
/*@{*/

/**	
 *	@file	
 *	File: SceneActionBlocks.hpp \n
 *	Game: Battleship II \n
 *	Author: Ignacio Cea Forniés (Community Networks) \n
 *	Creation Date: 21/11/2020 \n
 *	Description: Defines the specific action blocks in Battleship II \n
 *	Versions: 1.0 Initial
 */

#ifndef __BATTLESHIPII_SCENEACTIONBLOCKS__
#define __BATTLESHIPII_SCENEACTIONBLOCKS__

#include "Defs.hpp"
#include <BattleshipLike/bsinclude.hpp>
#include <BattleshipLike/bsactionblocks.hpp>

namespace BattleshipII
{
	/** A factory for the curves used (and also defined) in the blocks of this game. */
	class CurveAndInitialPositionFactory : 
		public BATTLESHIP::StdUFOSceneActionBlock::CurveAndInitialPositionFactory
	{
		public:
		/** @see parant. */
		virtual BATTLESHIP::StdUFOSceneActionBlock::CurveAndInitialPositionFactory* clone () override final
				{ return (new CurveAndInitialPositionFactory); }

		/** @see parent. */
		virtual QGAMES::Position initialPositionFor (int i , BATTLESHIP::UFO* ufo, 
			BATTLESHIP::StdUFOSceneActionBlock::Properties* prps) override final;
		virtual QGAMES::FollowingACurveMovement::CurveTemplate* curveFor 
			(int i, BATTLESHIP::UFO* ufo, BATTLESHIP::StdUFOSceneActionBlock::Properties* prps, 
			 std::map <int, double>& crvprms) override final;
	};

	/** A new type of combat block. 
		The ufos appear in the left side of the screen, and then move from the left to the right
		each of them with PI/2 radians of delay. 
		The closest pattern to follow is "all followinf the leader". */
	class SinusoideFromLeftBlockCombatFormationFactory : 
		public BATTLESHIP::StdSetUFOsSceneActionBlock::StayAndAttackOneByOneCombatFormationFactory
	{
		public:
		/** 
			* To create a queue of UFO following the first:
			* @param cF:	The curve and position factory used to create individual action blocks.
			* @param t:	The time between the UFOS when starting to move. 
			*/
		SinusoideFromLeftBlockCombatFormationFactory 
			(BATTLESHIP::StdUFOSceneActionBlock::CurveAndInitialPositionFactory* cF, QGAMES::bdata sBE = 0.05);

		/** @see parent. */
		virtual bool forCombatType (int t) const
						{ return (t == __BATTLESHIPII_STAYANDMOVESINFROMLEFTTORIGHT__); }

		private:
		/** The separattion between elements. */
		QGAMES::bdata _separationBetweenElements;
	};

	/** Similar to the previous one but starting from the right. */
	class SinusoideFromRightBlockCombatFormationFactory : 
		public BATTLESHIP::StdSetUFOsSceneActionBlock::StayAndAttackOneByOneCombatFormationFactory
	{
		public:
		/** 
			* To create a queue of UFO following the first:
			* @param cF:	The curve and position factory used to create individual action blocks.
			* @param t:	The time between the UFOS when starting to move. 
			*/
		SinusoideFromRightBlockCombatFormationFactory 
			(BATTLESHIP::StdUFOSceneActionBlock::CurveAndInitialPositionFactory* cF, QGAMES::bdata sBE = 0.05);

		/** @see parent. */
		virtual bool forCombatType (int t) const
						{ return (t == __BATTLESHIPII_STAYANDMOVESINFROMRIGHTTOLEFT__); }

		private:
		QGAMES::bdata _separationBetweenElements;
	};
}

#endif
  
// End of the file
/*@}*/
