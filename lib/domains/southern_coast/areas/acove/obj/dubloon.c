  /* dubloons
  Zara 8/14/98
*/

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("dubloon");
  SetShort("gold dubloon");
  SetId( ({"gold","dubloon","dubloons"}) );
  SetAdjectives( ({"glittering","gold","treasure"}) );
  SetLong("This glittering gold dubloon is part of the "
          "pirate treasure.");
  SetMass(3);
  SetValue(500);
  SetVendorType(VT_TREASURE);
}
