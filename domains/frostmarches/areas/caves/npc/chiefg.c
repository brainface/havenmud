#include <lib.h>
#include "../caves.h"

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("goblin chief");
    SetId( ({"goblin", "chief"}) );
    SetAdjectives("chief");
    SetShort("a goblin chief");
    SetLong("This goblin is larger and stronger than all others, he appears "
            "to be their chief. The goblin has scars from prior battles.");
    SetRace("goblin");
    SetClass("fighter");
    SetLevel(15);
    
    SetGender("male");
    SetMorality(-200);
    SetInventory( ([ CAVES_OBJ + "longsword" : "wield sword",
                     CAVES_OBJ + "mcap"      : "wear cap",
                     CAVES_OBJ + "lshield"   : "wear shield on left arm",
                     CAVES_OBJ + "ringmail"  : "wear mail" ]) );
    SetCurrency( ([
      "senones" : 155,
               ]) );
}
