/*   Portia  12-20-98
     The diviner teacher.
     Modified by Gaby 08/16/99 to add spheres
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_LEADER;

 static void create() {
 leader::create();
 SetKeyName("fallar");
 SetShort("Fallar, the Apprentice Evoker");
 SetId( ({"man"}) );
 SetAdjectives( ({"bright", "young"}) );
 SetLong("Though not very old, this man seems to "
   "posess wisdom beyond his years. "
   "He could teach someone the ways of magic "
   "very easily.");
 SetNoJoin(1);
 SetGender("male");
 SetClass("evoker");
 SetSkill("blunt combat",1,2);
 SetLevel(13);
 SetRace("dark-elf");
 SetReligion("Soirin","Soirin");
 SetMorality(-250);
 SetInventory( ([
   	MAL_OBJ3 + "teach_robe" : "wear robe",
   	MAL_OBJ3 + "teach_mace" : "wield mace",
   	]) );
 SetSpellBook( ([
  	"shock" 	 : 100,
  	"capsule"  : 100,
  	"ice ball" : 100,
  	"missile"  : 100,
    ]) );
  SetCombatAction(40,({
    "!cast shock",
    "!cast capsule",
    "!cast ice ball",
    "!cast missile",
    }) );
 SetAction(5,
   "!emote looks at you with a knowing glance.");
 SetTaughtSpheres( ({ }) );
 }
