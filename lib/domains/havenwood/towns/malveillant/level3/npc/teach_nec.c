/*   Portia  12-20-98
     The necromancy teacher.
     Modified by Gaby 08/16/99 to add spheres
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_TRAINER;

 static void create() {
 ::create();
 SetKeyName("xievien");
 SetLimit(1);
 SetShort("Xievien, the Teacher of Magicks");
 SetId( ({ "xievien", "teacher" }) );
 SetAdjectives( ({ "magicks" }) );
 SetLong("This tall man is quite fearsome. "
 			   "His grey robe makes his skin seem pasty and "
   			 "he appears to be quite powerful. If asked he may be "
   			 "willing to teach someone the ways of necromancy.");
 SetRace("dark-elf");
 SetGender("male");
 SetClass("necromancer");
 SetLevel(35);
 
 SetReligion("Soirin","Soirin");
 SetMorality(-500);
 SetInventory( ([
   	MAL_OBJ3 + "teach_robe" : "wear robe",
   	MAL_OBJ3 + "teach_pole" : "wield staff",
   	]) );
 SetSpellBook( ([
    "necromantic shield" : 100,
    "acid rain" 				 : 100,
    "acid splash" 			 : 100,
    "acid blast" 				 : 100,
    "cloudkill"				   : 100,
    "wound" 					   : 100,
    ]) );
  SetCombatAction(60, ({ 
  	"!cast necromantic shield",
    "!cast acid rain",
    "!cast acid splash",
    "!cast acid blast",
    "!cast cloudkill",
    "!cast wound",
    }) );
 SetAction(5,
    "!emote looks at you with an ominous glare.");
 SetTrainingSkills( ({
    }) );
 }
