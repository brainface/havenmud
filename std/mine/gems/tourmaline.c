/*  Treasure by Davantalus */
/*20000222*/
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("tourmaline");
  SetShort("a pink tourmaline");
  SetId( ({ "tourmaline", "gem" }) );
  SetAdjectives( ({ "pink" }) );
  SetLong("This is a tourmaline of decent quality. It is somewhat hard "
  				"and cut in a fine manner as to bring out its striking color. "
  				"This gem glows with a life of its own."
  				);
  SetMass(2);
  SetValue(200);
  SetDamagePoints(1200);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
  }
