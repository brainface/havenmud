#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("eagle");
    SetId( ({"eagle" }) ); 
    SetAdjectives( ({ "golden", "graceful" }) );
    SetShort("a graceful golden eagle");
    SetLong("The eagle perches upon a nearby boulder, studying its "
            "surroundings intensely. Its feathers seem to gleam, as if "
            "it hadn't moved since morning dew.");
    SetRace("bird");
    SetGender("male");
    SetClass("animal");
    SetLevel(random(6)+2);
   
}


/* Approved by Zaxan on Wed Apr  1 03:41:10 1998. */
