/*   Portia  12-20-98
     The necromancer leader.
     Modified by Gaby 08/16/99 to add spheres
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_LEADER;

 static void create() {
 leader::create();
 SetKeyName("muero");
 SetShort("Muero, the Necromancer");
 SetId( ({"man", "muero", "necromancer"}) );
 SetLong("Muero is the most feared man in Malveillant. "
   "His reputation is that of the most powerful evil in "
   "any of the citizens' memories.");
 SetGender("male");
 SetClass("necromancer");
 SetLevel(30);
 SetTown("Malveillant");
 SetMorality(-1000);
 SetRace("dark-elf");
 SetReligion("Soirin");
 SetFreeEquip( ([
    "/std/weapon/pole/staff" : 1,
    ]) );
 SetInventory( ([
   	MAL_OBJ3 + "lead_robe" : "wear robe",
   	MAL_OBJ3 + "lead_pole" : "wield staff",
   	]) );
 SetSpellBook( ([
    "drain soul" 				 : 100,
    "cloud kill"         : 100,
    "necromantic shield" : 100,
    "acid blast" 				 : 100,
    "acid rain" 			   : 100,
    ]) );
  SetCombatAction(60, ({
    "!cast drain soul",
    "!cast cloud kill",
    "!cast necromantic shield",
    "!cast acid rain",
    "!cast acid blast",
    }) );
 SetAction(5,
   "!say i could teach you the ways of evil.");
  SetPlayerTitles( ([
    "newbie"   : "the Dark One of Malveillant",
    "mortal"   : "the Necromancer of Malveillant",
    "hm"       : "the High Necromancer of Malveillant",
    "legend"   : "the Supreme Necromancer",
    "avatar"   : "the Bringer of Death",
    "cavalier" : "the Dark Protector of Malveillant",
    ]) );
 SetTaughtSpheres( ({
 		"clerical necromancy",
 		"magical necromancy",
    }) );
 }
