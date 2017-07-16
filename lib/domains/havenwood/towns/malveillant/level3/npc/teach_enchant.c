/*   Portia  12-20-98
     The enchanter teacher.
     Modified by Gaby 08/16/99 to add spheres
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_LEADER;

 static void create() {
 leader::create();
 SetKeyName("toranalla");
 SetShort("Toranalla, the Apprentice Enchantress");
 SetId( ({"woman"}) );
 SetAdjectives( ({"petite"}) );
 SetLong("Though this woman is small in stature "
   "there is a glimmer in her eyes that could "
   "entrance almost anyone. Her demeanor suggests she may be able "
   "to teach someone a few things aobut the ways of enchantment.");
 SetNoJoin(1);
 SetRace("dark-elf");
 SetGender("female");
 SetClass("enchanter");
 SetLevel(13);
 
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
    "!emote looks at you with a knowing smirk.");
 SetTaughtSpheres( ({
 		"magical enchantment",
 		"clerical enchantment",
    }) );
 }
