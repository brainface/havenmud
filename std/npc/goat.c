#include <lib.h>
inherit LIB_NPC;
static void create(){
    npc::create();
    SetShort("an ornery billy goat");
    SetLong("This smelly creature has two large swirling horns and a surplus "
      "of swaggy, stinking hair.");
    SetRace("cow","goat");
    SetGender("male");
    SetClass("animal");
    SetKeyName("goat");
    SetId(({"goat"}));
    SetAdjectives( ({"ornery","billy"}));
  SetLevel(10);
  SetAction(5, ({
    "!emote climbs on top of something.",
    "!emote stares at you with bloodshot eyes.",
    "!emote twitches his horns dangerously at you.",
  }) );
}

