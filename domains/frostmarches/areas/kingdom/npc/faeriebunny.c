
/* faerie bunny
   Elasandria 4/15/98
*/
#include <lib.h>
#include "../kingdom.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("faerie bunny");
  SetShort("a faerie bunny");
  SetId( ({"bunny","faerie bunny","lop"}) );
  SetAdjectives( ({"adorable","little","white"}) );
  SetLong("This adorable little lop has a white pelt, dark brown ears, and "
       "beautiful iridescent wings.");
  SetGender("female");
  SetRace("rodent","rabbit");
  SetClass("animal");
  SetSkill("conjuring", 1, 1);
  SetSkill("evokation", 1, 1);
  SetLevel(5);
  SetAction(5,
       ({"!emote suddenly leaps in your direction, does a full turn in the "
       "air and then stretches contentedly at your feet.",
       "The bunny suddenly leaps in your direction, does a full turn in the "
       "air and then stretches contentedly at your feet."})
       );
  SetInventory( ([
       ]) );
  SetSpellBook( ([
       "buffer" : 25,
       ]) );
  SetCombatAction(8, ({
  		 "!cast buffer"})
       );
}
