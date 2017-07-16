#include <lib.h>

inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("turtle");
  SetMorality(200);
  SetId( ({"bog turtle"}) );
  SetShort("a bog turtle");
  SetLong("A bog turtle is here sunning itself on a rotting log."
    "  He is small in size only about three inches in length."
    "  He is brown much like his environment.",
);
  SetAdjectives( ({"bog"}) );
  SetRace("tortoise");
  SetClass("animal");
  SetLevel(1);
  SetGender("male");
  SetAction(10, ({
    "The bog turtle suns himself on a log.",
}) );
SetCombatAction(10, ({
    "The bog turtle slides off the log into the water.",
}) );
}
