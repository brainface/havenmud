// Treasure by Urien@Haven 011413
// Player request Bill 
// Green Valis stone

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("valis stone");
  SetShort("a shimmering green valis stone");
  SetId( ({ "valis","stone" }) );
  SetAdjectives( ({ "shimmering", "green" }) );
  SetLong("The green valis stone softly shines. It is a "
          "rather tiny and rare stone that is valued to "
          "some. This particular stone is a decent size "
          "relative to its class and purity. It has a "
          "fine quality and would fetch a decent value.");
  SetMass(10);
  SetValue(1500);
  SetDamagePoints(600);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
}

