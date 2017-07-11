#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("stallion");
    SetId( ({"stallion" }) ); 
    SetShort("a white stallion");
    SetAdjectives( ({ "beautiful","white" }) );
    SetLong("This beautiful white stallion is a masterpiece of "
            "breeding, and appears to be a regal, wondrous animal.");
    SetRace("horse");
    SetClass("animal");
    SetGender("male");
    SetLevel(15);
    
}
