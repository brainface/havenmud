/*   Portia  12-20-98
     The evoker leader.
     Modified by Gaby 08/16/99 to add spheres
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_LEADER;

 static void create() {
 leader::create();
 SetKeyName("aniana");
 SetShort("Aniana, the High Evoker");
 SetId( ({"aniana", "high", "evoker"}) );
 SetLong("Aniana is descended from a long line "
   "of powerful evokers. She has trained most of "
   "the evokers of Malveillant.");
 SetGender("female");
 SetClass("evoker");
 SetLevel(30);
 SetTown("Malveillant");
 SetRace("dark-elf");
 SetReligion("Soirin","Soirin");
 SetMorality(-250);
 SetFreeEquip( ([
    "/std/weapon/pole/staff" : 1,
    ]) );
 SetInventory( ([
   MAL_OBJ3 + "lead_robe" : "wear robe",
   MAL_OBJ3 + "lead_pole" : "wield staff",
   ]) );
 SetSpellBook( ([
    "paralysis" : 100,
    "fireball"  : 100,
    "shock"     : 100,
    "sphere"    : 100,
    ]) );
  SetCombatAction(40, ({
    "!cast paralysis",
    "!cast fireball",
    "!cast shock",
    "!cast sphere",
    }) );
 SetAction(5,
    "!say i could teach you to be powerful.");
  SetPlayerTitles( ([
    "newbie" : "the Apprentice Evoker of Malveillant",
    "mortal" : "the Evoker of Malveillant",
    "hm" 		 : "the Master Evoker of Malveillant",
    "legend" : "the High Evoker of Malveillant",
    "avatar" : "the High Lord of Evokation",
    ]) );
 SetTaughtSpheres( ({
 		"clerical evokation",
 		"magical evokation",
    }) );
 }
