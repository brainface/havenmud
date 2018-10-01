#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("eagle");
    SetId( ({"eagle" }) ); 
    SetAdjectives( ({ "golden", "graceful" }) );
    SetShort("a graceful golden eagle");
    SetRace("bird");
    SetGender("male");
    SetClass("animal");
    SetLevel(random(6)+2);
    SetLong("The eagle perches upon a nearby boulder, studying its "
            "surroundings intensely. The form of this regal bird "
            "seems to impress itself upon the area. It has a "
            "fierce face, powerful eyes, and talons as long as a "
            "human finger. Its feathers seem to gleam, as if "
            "it hadn't moved since morning dew.");
}
