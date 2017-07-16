//Selket@Haven
//2006
#include <lib.h>
inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("bull");
    SetId( ({ "bull", "apis", "cow" }) );
    SetShort("Apis the Friendly Bull");
    SetAdjectives( ({ "friendly" }) );
    SetLong("Apis is a huge black bull who appears content with "
          "his life here with the sheep.");
    SetRace("cow");
    SetClass("animal");
    SetLevel(10);
    SetGender("male");
    SetAction(5, ({
    "!snort",
    "!emote bellows.",
    }) );
}

