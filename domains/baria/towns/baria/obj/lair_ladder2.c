//
// Summary: ladder to enter draco lair
// Created by: Rhakz@Haven -- Angel Cazares
// For Baria
// Date: 31/01/99
//
#include <lib.h>
#include <climb.h>
#include "../jungle.h"
inherit LIB_ITEM;
inherit LIB_CLIMB;

static void create() {
    item::create();
  SetKeyName("ladder");
    SetId( ({ "ladder" }) );
    SetShort("a ladder");
  SetInvis(1);
    SetLong("This is a wooden ladder one could climb.");
    SetAdjectives(({"wooden"}));
   SetPreventGet("You cannot pick that up!");
    SetClimb(BARIA_ROOM + "shrine_2",CLIMB_UP);
    SetClimb(BARIA_LAIR + "entrance",CLIMB_DOWN);
}
