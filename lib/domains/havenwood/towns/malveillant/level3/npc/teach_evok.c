/*   Portia  12-20-98
     The evoker teacher.
     Modified by Gaby 08/16/99 to add spheres
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_LEADER;

 static void create() {
 leader::create();
 SetKeyName("pallar");
 SetShort("Pallar, the Apprentice Evoker");
 SetId( ({"woman"}) );
 SetAdjectives( ({"beautiful"}) );
 SetLong("A certain power radiates from this "
   "beautiful creature. Her hair cascades down her "
   "shoulders and she doesn't look nearly old "
   "enough to have such power. Her eyes sparkle as if she "
   "might be able to teach someone the ways of evokation.");
 SetNoJoin(1);
 SetRace("dark-elf");
 SetClass("evoker");
 SetLevel(13);
 SetGender("female");

 SetReligion("Soirin","Soirin");
 SetMorality(-250);
 SetInventory( ([
   MAL_OBJ3 + "teach_robe" : "wear robe",
   MAL_OBJ3 + "teach_pole" : "wield staff",
   ]) );
 SetSpellBook( ([
  "shock"    : 100,
  "missile"  : 100,
  "capsule"  : 100,
  "ice ball" : 100,
   ]) );
  SetCombatAction(50, ({
    "!cast shock",
    "!cast capsule",
    "!cast missile",
    "!cast ice ball",
    }) );
 SetAction(5,
   "!emote looks at you with glowing green eyes.");
 SetTaughtSpheres( ({
 		"magical evokation",
 		"clerical evokation",
    }) );
 }
