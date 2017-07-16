// Treasure by Urien@Haven 011413
// Player request Bill 
// Queen Xarthinel - There is two types of xarthinel class
//                   gem this one is the pure/higher grade.
#include <lib.h>
#include <vendor_types.h>
#include <loot.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("xarthinel gem");
  SetShort("a pure black xarthinel gem");
  SetId( ({ "pure", "gem", "xarthinel" }) );
  SetAdjectives( ({ "pure", "black" }) );
  SetLong("This pure stone can be identified as the "
          "rare xarthinel gem. It is small in size, but "
          "incredibly dense. The surface of the stone "
          "displays no impurities and would suggest "
          "that this would fetch a price in the right "
          "market.");
  SetMass(40);
  SetValue(1500);
  SetDamagePoints(600);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
}

