#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("piglet");
    SetId( ({"piglet" }) ); 
    SetAdjectives( ({ "small" }) );
    SetShort("a small piglet");
    SetLong("This is a small piglet, with a tiny little curled tail. "
            "It is playful, cute, and surprisingly not dirty.");
    SetRace("pig");
    SetGender("male");
    SetClass("animal");
    SetLevel(2);
    
    SetAction(5, ({ "The pig oinks and runs in circles." }) );
}

