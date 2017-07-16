/*  Treasure by Davantalus */
/*20000222*/
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("garnet");
  SetShort("a blood-red garnet");
  SetId( ({ "garnet", "gem" }) );
  SetAdjectives( ({ "blood", "red" }) );
  SetLong("This is a garnet of decent quality. It is somewhat hard and "
  				"cut in a fine manner as to bring out its blood-red color."
  				);
  SetMass(3);
  SetValue(600);
  SetDamagePoints(2000);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
  }
