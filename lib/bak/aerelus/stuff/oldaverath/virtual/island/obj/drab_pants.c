
/* Drab grey newbie pants */
#include <armour_types.h>
#include <vendor_types.h>
#include <lib.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("drab pants");
  SetShort("a pair of drab grey pants");
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "drab", "grey" }) );
  SetLong("This is a pair of drab grey pants. They are not much to "
          "look at, but they do cover the flesh.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_PANTS);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(40);
  SetValue(0);
  SetDamagePoints(250);
  SetSize(SIZE_MEDIUM);
  }
