/*  Treasure by Davantalus */
/*20000222*/
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("onyx");
  SetShort("a shadowy onyx");
  SetId( ({ "onyx", "gem" }) );
  SetAdjectives( ({ "shadowy" }) );
  SetLong("This is a onyx of great value. It is quite hard and cut in "
  				"a fine manner as to bring out its jet black shadowing."
  				);
  SetMass(5);
  SetValue(750);
  SetDamagePoints(3500);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
}