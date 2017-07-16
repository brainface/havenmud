
/* enchanted frog
   Elasandria 4/15/98
*/

#include <lib.h>
#include "../kingdom.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("frog");
  SetShort("an enchanted frog");
  SetId( ({"frog"}) );
  SetAdjectives( ({"green","enchanted","slimy","wet","shimmery"}) );
  SetLong("This green frog looks kind of slimy and wet. It has large yellow "
       "eyes. There is a peculiar shimmery cast to its skin.");
  SetGender("male");
  SetRace("amphibian");
  SetClass("animal");
  SetSkill("conjuring",1,1);
  SetSkill("evokation",1,1);
  SetLevel(3);
  SetAction(5,
       ({"!emote looks at you consideringly with an intelligent gleam in "
       "its eyes.",
       "The frog looks at you consideringly with an intelligent gleam in "
       "its eyes."})
       );
  SetInventory( ([
       ]) );
  SetSpellBook( ([
       "buffer" : 25,
       ]) );
  SetCombatAction(10, ({
  		 "!cast buffer"})
       );
}
