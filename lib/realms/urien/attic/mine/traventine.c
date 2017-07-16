// Treasure by Urien@Haven 011413
// Player request Bill 
// Traventine gem

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("traventine gem");
  SetShort("a dull traventine gem");
  SetId( ({ "gem", "traventine" }) );
  SetAdjectives( ({ "dull","traventine" }) );
  SetLong("The surface of the traventine gem is dull and "
          "reflects light poorly. The quality of this gem "
          "is pure and contains no inclusions at all. This "
          "is a gem with a heavy density with a turquoise "
          "colour. Black flakes which have wedged itself "
          "in formation now create a non chipping surface "
          "with a dull finish.");
  SetMass(30);
  SetValue(random(50)+700);
  SetDamagePoints(400);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
}

