#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shield");
  SetShort("a medium wooden shield");
  SetId( ({ "shield", "wooden shield" }) );
  SetAdjectives( ({ "wooden", "medium" }) );
  SetLong("This is a medium wooden shield.  It might take some pounds "
          "before it breaks, but probably could be cut through easily.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_SHIELD);
  SetMass(175);
  SetValue(75);
  SetDamagePoints(400);
  SetSize(SIZE_MEDIUM);
 }
