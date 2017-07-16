//coded by Syra 8/97

#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("deer mouse");
    SetId( ({"mouse"}) ); 
    SetAdjectives( ({"brown","deer"}) );
    SetShort("a deer mouse");
    SetLong("This brown deer mouse stands on its hind feet and looks "
            "around with huge, adorable brown eyes.");
    SetRace("rodent");
    SetGender("male");
    SetClass("animal");
    SetLevel(1);
    
}


/* Approved by Amelia on Sun Sep 14 16:29:50 1997. */