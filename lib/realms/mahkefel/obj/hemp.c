/* Mahkefel 2017
 * hemp bjorn cain't smoke
 *
 */

#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("hemp");
  SetShort("a stalk of hemp");
  SetId( ({ "hemp", "stalk" }) );
  SetAdjectives( ({"stalk","of" }) );
  SetLong("It is fiberous stalk of hemp.");
  SetMass(5);
  SetValue(50);
  // it's not REALLY food but i assume farmers would buy/sell it.
  SetVendorType(VT_FOOD|VT_PLANT);
}

