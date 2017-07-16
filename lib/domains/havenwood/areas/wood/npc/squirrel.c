//coded by Syra 8/97

#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("squirrel");
    SetId( ({"squirrel" }) ); 
    SetAdjectives( ({"brown","furry","chittering"}) );
    SetShort("a chittering squirrel");
    SetLong("Brown and furry, the squirrel chitters at you "
            "as it scampers about. He has a beautifully long "
            "tail and sharp foreclaws.");
    SetRace("rodent");
    SetGender("male");
    SetClass("animal");
    SetLevel(random(2)+2);
   
}


/* Approved by Amelia on Sun Sep 14 20:59:12 1997. */