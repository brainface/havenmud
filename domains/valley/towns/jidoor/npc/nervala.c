/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: nervala.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Sept 17th, 1998
// Abstract: Nevala the cleric of the Magildan Faith.
// Revision History: Orignally created by Zaxan@Haven 
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <daemons.h>
#include "../jidoor.h"

inherit LIB_LEADER;
static void create() {
 leader::create();
  SetKeyName("nervala");
  SetShort("Nervala the Magildan Mystic");
  SetId( ({ "nervala", "mystic","jidoor_npc", }) );
  SetAdjectives( ({ "magildan" }) );
  SetRace("sprite");
  SetNoMulti(1);
  SetClass("mystic");
  SetGender("female");
  SetLong("This gentle lady stands here as a general resource "
          "for the Magildan religion. She seems solemn and "
          "and consumed with thoughts about her faith.");
  SetMorality(60);
  SetLevel(75);
  SetReligion("Magildan","Magildan");
  
  SetAction(1, ({
                  "!speak There are various spell teachers around "
                  "Jidoor who will help you with your magical "
                  "powers.",
                  "!speak Glory to the Gods of Energy!",
                  "!emote mutters a little prayer.",
                  "!emote mutters a little prayer.",
                  }) );
  SetReligion("Magildan","Magildan");
  SetTown("Jidoor");
  SetSpellBook( ([
			"wall of wood"   : 100,
			"natural charge" : 100,
			"ice storm"      : 100,
			"heat"           : 100,
			"disintegrate"   : 100,
			"energy wall"    : 100,
  		]) );
  SetCombatAction(80 , ({
  		"!cast wall of wood",
  		"!cast energy wall",
  		"!cast natural charge",
  		"!cast disintegrate",
  		"!cast heat",
  		"!cast ice storm",
  		}) );  		
  SetPlayerTitles( ([
     "newbie" : "the Acolyte Magildan Mystic",
     "mortal" : "the Magildan Mystic",
     "hm"     : "the High Magildan Mystic",
     "legend" : "the Protector of Energy",
     "avatar" : "the Weaver of Energy",
     ]) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/vs_mystic_robe" : "wear robe",
      JID_OBJ + "/clothing/vs_sandals" : "wear sandals",
   ]) );
  }
