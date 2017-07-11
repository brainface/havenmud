//Illura@Haven
//Sept 2009
//skymetal
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("skymetal");
  SetShort("a zaffre bit of skymetal");
  SetId( ({ "skymetal", "metal", "bit" }) );
  SetAdjectives( ({ "sky", "zaffre"}) );
  SetLong("This is a deep blue piece of a star flung to Kailie from "
    "high in the heavens. It shimmers and sparkles."
  );
  SetMass(8);
  SetValue(3000);
  SetMaterial( ({ "mithril" }) );
  SetVendorType(VT_GEM);
  }
