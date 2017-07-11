/*  Treasure by Davantalus */
/*20000222*/
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("ruby");
  SetShort("a crimson ruby");
  SetId( ({ "ruby", "gem" }) );
  SetAdjectives( ({ "crimson" }) );
  SetLong("This is a ruby of great value. It is extremely hard and "
  				"cut in a brilliant manner as to bring out its blood red color."
  				);
  SetMass(7);
  SetValue(2000);
  SetDamagePoints(7000);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
  }
