/*  Treasure by Davantalus */
/*20000222*/
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("aquamarine");
  SetShort("a shiny aquamarine");
  SetId( ({ "aquamarine", "gem" }) );
  SetAdjectives( ({ "shiny" }) );
  SetLong("This is a aquamarine of great value. It is somewhat hard and "
  				"cut in a fine manner as to bring out its blue-green shine."
  				);
  SetMass(3);
  SetValue(750);
  SetDamagePoints(2500);
  SetMaterial( ({ "natural" }) );
//  SetVendorType(VT_TREASURE);
  SetVendorType(VT_GEM|VT_TREASURE);
}
