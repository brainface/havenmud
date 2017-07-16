
/* Drab grey newbie shirt */
#include <armour_types.h>
#include <vendor_types.h>
#include <lib.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("drab shirt");
  SetShort("a drab grey shirt");
  SetId( ({ "shirt" }) );
  SetAdjectives( ({ "drab", "grey" }) );
  SetLong("This is a drab grey shirt. It is not much to "
          "look at, but it does cover the flesh.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_SHIRT);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(40);
  SetValue(0);
  SetDamagePoints(250);
  SetSize(SIZE_MEDIUM);
  }
