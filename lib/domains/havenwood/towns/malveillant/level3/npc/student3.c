/*   Portia  12-17-98
    A student for the Ring of Magic.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_NPC;

 static void create() {
 npc::create();
 SetShort("a student of enchantment");
 SetKeyName("student");
 SetId( ({ "student" }) );
 SetLong("This student seems to be rather thoughtful. "
   			 "She seems to be trying to gather information beyond "
   			 "the common person's knowledge.");
 SetGender("female");
 SetRace("dark-elf");
 SetClass("enchanter");
 SetSkill("blunt combat",1,2);
 SetLevel(3);
 SetReligion("Soirin","Soirin");
 SetMorality(-250);
 SetInventory( ([
   MAL_OBJ3 + "stud_mace" : "wield mace",
   MAL_OBJ3 + "stud_robe" : "wear robe",
   ]) );
 SetAction(6, 
   "!emote closes her eyes in thought.");
 SetSpellBook( ([
   "buffer"  : 100,
   "missile" : 100,
   ]) );
 SetCombatAction(25, ({
   "!cast buffer",
   "!cast missile",
   }) );
 }
