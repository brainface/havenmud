#include <lib.h>
#include "../caves.h"

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("goblin shamaness");
    SetId( ({"goblin", "shamaness"}) );
    SetAdjectives("shamaness");
    SetShort("a goblin shamaness");
    SetLong("Evil radiates from this goblin, who is dresses in ritual garb "
            "and gestures periodicly. She has an almost skeletal figure "
            "but something implies she gets her power elsewhere.");
    
     SetRace("goblin");
    SetClass("shaman");
    SetLevel(10);
    SetReligion("Kuthar","Kuthar");
    SetGender("female");
    SetMorality(-100);
    SetInventory( ([CAVES_OBJ + "sgarb" : "wear garb",
                    CAVES_OBJ + "sstaff" : "wield staff" ]) );
    SetCurrency( ([
      "senones" : 90,
               ]) );
    SetFriends("goblin chief");
    SetCombatAction(60, ({
      "!cast missile",
      "!cast acid splash",
      "!cast buffer",
                   }) );
    SetSpellBook( ([
      "missile" : 100,
      "acid splash" : 100,
      "buffer" : 100,
                ]) );
}
