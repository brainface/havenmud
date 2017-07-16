#include <lib.h>
#include "../caves.h"

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("goblin");
    SetId("goblin");
    SetAdjectives("typical");
    SetShort("a typical goblin");
    SetLong("This is a typical wretched goblin. He is covered "
            "in filth and looks around evily.");
    SetRace("goblin");
    SetClass("fighter");
    SetLevel(5);
    
    SetGender("male");
    SetMorality(-50);
    SetInventory( ([
      CAVES_OBJ + "falchion" : "wield sword",
                ]) );
    SetCurrency( ([
      "imperials" : 13,
               ]) );
}
