/*   Portia  12-17-98
    A student for the Ring of Magic.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_NPC;

 static void create() {
 npc::create();
 SetShort("a confused looking student");
 SetKeyName("student");
 SetId( ({ "student" }) );
 SetAdjectives( ({"confused", "looking"}) );
 SetLong("This student seems to be rather confused. "
   			 "He keeps looking at a book and mumbling to himself.");
 SetGender("male");
 SetRace("dark-elf");
 
 SetClass("evoker");
 SetLevel(1);
 SetReligion("Soirin","Soirin");
 SetMorality(-250);
 SetInventory( ([
   	MAL_OBJ3 + "stud_pole" : "wield staff",
  	MAL_OBJ3 + "stud_robe" : "wear robe",
   	]) );
 SetAction(5, 
   	"!emote shakes his head in frustration.");
 SetSpellBook( ([
   	"missile"  : 100,
   	"ice ball" : 100,
   	"aura" 		 : 100,
   	]) );
 SetCombatAction(30, ({
    "!cast ice ball",
    "!cast aura",
    "!cast missile",
    }) );
 }
