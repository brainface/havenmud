#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include "../rook.h"

inherit LIB_STORAGE;

static void create()
{
::create();
SetKeyName("pouch");
SetId( ({ "pouch","dart pouch" }) );
SetAdjectives( ({ "dart" }) );
SetShort("a dart pouch");
SetLong("This is a small pouch designed to be "
  "puncture resistant.  These types of pouches "
  "are often created to hold something that "
  "is poisonous.");
SetMass(5);
SetValue(0);
SetMaxCarry(15);
SetInventory( ([
  R_OBJ + "dart" : 3,
]) );
}
