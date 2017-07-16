#include <lib.h>
#include "../caves.h"

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("goblin guard");
    SetId( ({"goblin", "guard"}) );
    SetAdjectives("guard");
    SetShort("a goblin guard");
    SetLong("This goblin is larger and looks better fed than the rest, he "
            "appears to be one of the chief's personal guard.");
    SetRace("goblin");
    SetClass("fighter");
    SetLevel(10);
    
    SetGender("male");
    SetMorality(-75);
    SetInventory( ([
    		CAVES_OBJ + "falchion" : "wield sword",
        CAVES_OBJ + "lvest"    : "wear vest",
        CAVES_OBJ + "lshield"  : "wear shield on left arm"]) );
    SetCurrency( ([
      "senones" : 36,
               ]) );
    SetFriends( ({"goblin guard", "goblin chief", "goblin shamaness"}) );
}
