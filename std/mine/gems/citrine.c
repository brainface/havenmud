/*  Treasure by Davantalus */
/*20000222*/
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("citrine");
  SetShort("a polished citrine");
  SetId( ({ "citrine", "gem" }) );
  SetAdjectives( ({ "polished"}) );
  SetLong("This is a citrine of small value. It is somewhat hard and "
  				"cut in a fine manner as to bring out its yellow hue."
  				);
  SetMass(2);
  SetValue(500);
  SetDamagePoints(2500);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
  }
