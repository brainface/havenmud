#include <lib.h>
#include "../caves.h"

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("female goblin");
    SetId("goblin");
    SetAdjectives("female");
    SetShort("a female goblin");
    SetLong("This female goblin is covered in filth, she appears to be "
            "eyeing the area suspicously.");
    
    SetRace("goblin");
    SetClass("fighter");
    SetLevel(4);
    SetGender("female");
    SetMorality(-50);
    SetInventory( ([
      CAVES_OBJ + "falchion" : "wield sword",
                ]) );
    SetCurrency( ([
      "senones" : 9,
               ]) );
   
}
