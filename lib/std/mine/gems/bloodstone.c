
/*  Treasure by Davantalus */
/*20000222*/
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("bloodstone");
  SetShort("a dark bloodstone");
  SetId( ({ "bloodstone", "gem" }) );
  SetAdjectives( ({ "dark" }) );
  SetLong("This is a bloodstone of small value. It is somewhat hard and "
  				"cut in a fine manner as to bring out its dark green shine. This "
  				"bloodstone glows through small orange spots on it's surface."
  				);
  SetMass(2);
  SetValue(500);
  SetDamagePoints(2500);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
  }

