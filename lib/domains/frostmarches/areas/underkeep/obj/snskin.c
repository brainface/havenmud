#include <lib.h>
#include <vendor_types.h>
  
 inherit LIB_ITEM;
static void create() {
  item::create();
  SetShort("a huge snakeskin");
  SetLong("This is the discarded skin of some giant, serpentine "
    "creature. Whatever used to be in that skin, it is huge; "
    "these tattered remains are almost unbelievably long.");
  SetKeyName("snakeskin");
  SetId( ({"snakeskin","skin"}) );
    SetAdjectives("huge");
  SetMass(10);
  SetDamagePoints(5);
  SetVendorType(VT_TREASURE);
    SetValue(70);
    SetRepairSkills( ({
      "natural working",
      }) );
    SetMaterial("natural");
    SetRepairDifficulty(10);
}
