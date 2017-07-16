#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include "../rook.h"

inherit LIB_STORAGE;

static void create()
{
::create();
SetKeyName("dart pouch");
SetId( ({ "pouch","dart pouch" }) );
SetAdjectives( ({ "dart" }) );
SetShort("a dart pouch");
SetLong("This is a small pouch designed to be "
  "puncture resistant.  These types of pouches "
  "are often created to hold something that "
  "is poisonous.");
SetMass(5);
SetValue(0);
  SetVendorType(VT_CLOTHING);
  SetDamagePoints(400);
  SetMaterial( ({ "textile" }) );
SetMaxCarry(15);
SetInventory( ([
]) );
}
