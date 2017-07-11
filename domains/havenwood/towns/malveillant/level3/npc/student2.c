/*   Portia  12-17-98
    A student for the Ring of Magic.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_NPC;

 static void create() {
 npc::create();
 SetShort("a thoughtful student");
 SetKeyName("student");
 SetId( ({ "student" }) );
 SetAdjectives( ({"thoughtful", "looking"}) );
 SetLong("This student seems to be rather thoughtful. "
         "She looks as though she may be right on the verge of "
         "understanding something for the first time.");
 SetGender("female");
 SetRace("dark-elf");
 SetClass("necromancer");
 SetLevel(3);
 SetReligion("Soirin","Soirin");
 SetMorality(-250);
 SetInventory( ([
   	MAL_OBJ3 + "stud_pole" : "wield staff",
   	MAL_OBJ3 + "stud_robe" : "wear robe",
   	]) );
 SetAction(6, 
   	"!emote closes her eyes in thought.");
 SetSpellBook( ([
   	"acid splash" : 100,
   	"shroud" 		  : 100,
   	]) );
 SetCombatAction(25, ({
    "!cast shroud",
    "!cast acid splash",
   	}) );
 }
