//Illura@Haven
//Sept 2009
//moorwalker
#include <lib.h>
#include "../taiga.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("moorwalker");
  SetId( ({ "moorwalker" }) );
  SetAdjectives( ({ "shaggy" }) );
  SetShort("a shaggy moorwalker");
  SetLong(
    "This is the rare moorwalker, an enormous mammal with shaggy "
    "white hair, enormous curving tusks, and huge horned feet. "
    "The sound of the moorwalker moving across the taiga is "
    "like an earthquake. Not much is known about these creatures "
    "except that they undergo unexpected bouts of rage. "
  );
  SetGender("male");
  SetClass("animal");
  SetLevel(60);
  SetRace("elephant");
    SetAction(5, ({
    "!emote turns his head sharply, shearing a tree down with his tusks.",
    "!emote groans sagely.",
    "!emote lifts his long snout to sound a cry to his long-dead mate.",
        }) );
  SetCombatAction(10, ({
    "The moorwalker stampedes at you!",
    "The moorwalker raises his tusks, preparing to gore you.",
    }) );
  SetCorpseItems( ([
    TAIGA_OBJ "tusk" : 2,
  ]) );
}
