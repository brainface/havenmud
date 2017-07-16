#include <lib.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("waders");
  SetShort("short waders");
  SetId( ({ "short", "waders", "short waders" }) );
  SetAdjectives( ({ "tight", "short" }) );
  SetLong("The waders are short, yet lean. They are made of "
          "soft leather and are water tight.");
  SetArmourType(A_PANTS);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_LEATHER);
  SetValue(30);
  SetMass(50);
  SetDamagePoints(150);
  SetSize(SIZE_MEDIUM);
}
