/*  Treasure by Davantalus */
/*20000222*/
//mahkefel 20001111: added unique id
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("diamond");
  SetShort("a fiery diamond");
  SetId( ({ "diamond", "gem", "mining_diamond" }) );
  SetAdjectives( ({ "fiery"}) );
  SetLong("This is a diamond of great value. It is extremely hard "
                                "and cut in a brilliant manner as to bring out its fiery sparkles."
                                );
  SetMass(8);
  SetValue(3000);
  SetDamagePoints(10000);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
  }

