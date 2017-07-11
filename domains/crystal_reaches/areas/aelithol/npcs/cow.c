#include <lib.h>
#include "../aelithol.h"
inherit LIB_NPC;

    static void create() {
    npc::create();
    SetKeyName("cow");
    SetId( ({ "cow", "lost cow", "a lost cow" }) );
    SetAdjectives( ({"brown", "white"}) );
    SetShort("a lost cow");
    SetLong("The cow is brown with a white face.  It stands "
      "around quietly grazing and is unaware that it is "
      "away from its home pasture.");                
   
    SetRace("cow");
    SetClass("animal");
    SetLevel(2);
    SetGender("female");
    SetMorality(0);  
    SetAction(3, ({ "The cow chews its cud." }));
}
