// Treasure by Urien@Haven 011413
// Player request Bill 
// Lucenthia gem

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("lucenthia gem");
  SetShort("a sparkling lucenthia gem");
  SetId( ({ "gem", "lucenthia", "lucenthia gem" }) );
  SetAdjectives( ({ "sparkling","lucenthia" }) );
  SetLong("This lucenthia gem is very identifiable due to the red, "
          "green and black striations along the surface. It is "
          "very small, like the size of a small pebble. This appears "
          "like any pure gem, with no inclusion at all. The overall "
          "gem itself is clear but the striations give it a "
          "more appealing look.");
  SetMass(11);
  SetValue(random(50)+1400);
  SetDamagePoints(700);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
}

