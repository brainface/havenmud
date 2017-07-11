/*  Treasure by Davantalus */
/*20000222*/
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("amethyst");
  SetShort("a purple amethyst");
  SetId( ({ "amethyst", "gem" }) );
  SetAdjectives( ({ "purple" }) );
  SetLong("This is a amethyst of small value. It is somewhat hard and "
  				"cut in a fine manner as to bring out its purplish shine. This "
  				"amethyst glows with a gentle bluish purple light."
  				);
  SetMass(2);
  SetValue(250);
  SetDamagePoints(2500);
  SetMaterial( ({ "natural" }) );
//  SetVendorType(VT_TREASURE);
  SetVendorType(VT_GEM|VT_TREASURE);
  }
