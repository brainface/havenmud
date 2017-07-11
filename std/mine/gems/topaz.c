/*  Treasure by Davantalus */
/*20000222*/
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("topaz");
  SetShort("a smoky topaz");
  SetId( ({ "topaz", "gem" }) );
  SetAdjectives( ({ "smoky" }) );
  SetLong("This is a topaz of decent quality. It is somewhat hard and "
  				"cut in a fine manner as to bring out its smoky brown color."
  				);
  SetMass(3);
  SetValue(500);
  SetDamagePoints(2500);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
  }
