#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetShort("a well-fed sheep");
    SetLong(
      "This smelly creature is one of the sheep that has helped to maintain the state of the grass.");
    SetRace("sheep");
    SetGender("female");
    SetClass("animal");
    SetKeyName("well-fed sheep");
    SetId(({"sheep"}));
    SetAdjectives( ({ "well", "fed" }) );
    SetAction(5, ({
      "!emote bleats.",
      "The sheep bows its head and munches.  Munch munch.",
    }));
    SetLevel(8);
}
