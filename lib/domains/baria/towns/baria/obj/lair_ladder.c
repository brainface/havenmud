//

// Summary: ladder to enter draco lair
// Created by: Rhakz@Haven -- Angel Cazares
// For Baria
// Date: 29/01/99
//
#include <lib.h>
#include <climb.h>
#include "../jungle.h"
inherit LIB_ITEM;
inherit LIB_CLIMB;

static void create() {
    item::create();
    SetId( ({ "ladder" }) );
    SetShort("a ladder");
    SetInvis(1);
    SetLong("This is a wooden ladder one could climb.");
   SetPreventGet("You cannot pick that up!");
    SetAdjectives(({"wooden"}));
    SetClimb(BARIA_ROOM + "shrine_1",CLIMB_UP);
}

