/*   Portia  12-17-98
    A student for the Ring of Magic.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_NPC;

 static void create() {
 npc::create();
 SetShort("a beautiful student of magic");
 SetKeyName("student");
 SetId( ({ "student" }) );
 SetAdjectives( ({"beautiful"}) );
 SetLong("This beautiful student seems to be quite intent "
   			 "on learning her trade.");
 SetGender("female");
 SetRace("dark-elf");
 SetClass("enchanter");
 SetReligion("Soirin","Soirin");
 SetMorality(-250); 
  
 SetLevel(4);

 SetInventory( ([
   	MAL_OBJ3 + "stud_pole" : "wield staff",
   	MAL_OBJ3 + "stud_robe" : "wear robe",
   	]) );
 SetAction(6, 
   	"!emote closes her eyes in thought.");
 SetSpellBook( ([
   	"buffer"   : 100,
   	"ice ball" : 100,
   	"aura" 		 : 100,
   	"missile"  : 100,
   	]) );
 SetCombatAction(35, ({
    "!cast aura",
    "!cast ice ball",
    "!cast buffer",
    "!cast missile",
   	}) );
 }
