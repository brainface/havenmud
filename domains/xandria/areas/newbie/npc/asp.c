//Selket@Haven
//2006
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("asp");
  SetId( ({"asp", "snake"}) );
  SetShort("an asp");

  SetRace("snake");
  SetClass("animal");
  SetLevel(3);
  SetGender("male");
  SetLong(
    "This is a slow-moving black asp. Although poisonous, he "
    "seems generally harmless, minding his own business.");
  SetAction(6, ({ 
     "!emote slithers.",
     "!emote hisses softly.",
  }) );
}
