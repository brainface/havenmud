#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("piglet");
    SetId( ({"piglet" }) ); 
    SetAdjectives( ({ "small" }) );
    SetRace("pig");
    SetGender("male");
    SetClass("animal");
    SetLevel(2);
    SetShort("a small piglet");
    SetLong("This is a small piglet, with a tiny little curled tail. "
            "His body is covered in soft pink fur that is thin enough "
            "to show his soft skin beneath. His eyes are large and "
            "trusting. It is playful, cute, and surprisingly not "
            "dirty.");
   SetAction(5, ({ "The pig oinks and runs in circles." }) );
}
