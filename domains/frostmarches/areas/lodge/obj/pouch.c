#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include "../lodge.h"
inherit LIB_STORAGE;
static void create() {
  ::create();
  SetKeyName("pouch");
  SetMaxCarry(25);
  SetId( ({"pouch"}) );
  SetShort("a small pouch");
  SetLong("This pouch can be worn on a belt.  It is small enough to hold "
  "small objects. Take a look inside.");
  SetAdjectives( ({"small"}) );
  SetMass(100);
  SetValue(150);
  SetMaterial( ({"leather"}) );
  SetDamagePoints(550);
  SetVendorType(VT_ARMOUR);
  }
