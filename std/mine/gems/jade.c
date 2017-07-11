/*  Treasure by Davantalus */
/*20000222*/
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("jade");
  SetShort("a gleaming jade");
  SetId( ({ "jade", "gem" }) );
  SetAdjectives( ({ "gleaming" }) );
  SetLong("This is a jade of decent quality. It is somewhat hard and "
  				"cut in a fine manner as to bring out its dirty green color."
  				);
  SetMass(3);
  SetValue(600);
  SetDamagePoints(2000);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
  }
