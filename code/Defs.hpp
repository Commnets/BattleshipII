/** \ingroup BSII */
/*@{*/

/**	
 *	@file	
 *	File: Defs.hpp \n
 *	Game: Battleship II \n
 *	Author: Ignacio Cea Forniés (Community Networks) \n
 *	Creation Date: 27/03/2020 \n
 *	Description: Defines and general includes of BattleshipII game
 *	Versions: 1.0 Initial
 */

#ifndef __BATTLESHIPII_DEFINES__
#define __BATTLESHIPII_DEFINES__

#include <BattleshipLike/bsinclude.hpp>

// A standard configuration parameter to declare the number of lives
#define __BATTLESHIPII_MAXNUMBEROFLIVESPARAMETER__			"LIVES"
#define __BATTLESHIPII_DEFAULTMAXNUMBEROFLIVESPARAMETER__	"3"
// same related with showing or not the FPS
#define __BATTLESHIPII_SHOWFPSPARAMETER__					"FPS"
#define __BATTLESHIPII_DEFAULTSHOWFPSPARAMETER__			"NO"

// The worlds of the game (stages)
#define __BATTLESHIPII_STAGE1WORLDID__						50001 // Asteroids
#define __BATTLESHIPII_STAGE2WORLDID__						50002 // UFOs

// The scenes of the game
// Scenes for the stage 1
#define __BATTLESHIPII_STAGE1SCENE1__						70000
#define __BATTLESHIPII_STAGE1SCENE2__						70001
#define __BATTLESHIPII_STAGE1SCENE3__						70002
// Scenes for the stage 2
#define __BATTLESHIPII_STAGE2SCENE1__						70010
#define __BATTLESHIPII_STAGE2SCENE2__						70011
#define __BATTLESHIPII_STAGE2SCENE3__						70012

#endif
  
// End of the file
/*@}*/