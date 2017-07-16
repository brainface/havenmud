//Illura@Haven
//Sept 2009
//hippo
#include "../taiga.h"
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("hippogryph");
  SetId( ({ "hippogryph", "griffin" }) );
  SetAdjectives( ({ "aged" }) );
  SetShort("an aged hippogryph");
  SetLong(
    "The yellowed beak and silvery-gray feathers of this spotted "
    "tundra hippogryph show its advanced age. The body is that "
    "of a great white lioness, and its head is aquiline, with golden "
    "eyes clouded with age. She has guarded this bridge for "
    "countless generations and knows no other purpose. "
  );
  SetGender("female");
  SetClass("animal");
  SetLevel(60);
  SetRace("griffin");
  SetFirstCommands( ({"guard north"}) );
    SetAction(5, ({
    "!emote screeches warningly.",
     "!emote clatters her beak together in anticipation.",
     "!emote looks upward to the warmer aeries above, dreaming of bygone days.",
                })  );
  SetCombatAction(10, ({
    "The hippogryph swoops at you in a flurry of feathers and claws",
    "The hippogryph charges, talons outstretched.",
    }) );
}
