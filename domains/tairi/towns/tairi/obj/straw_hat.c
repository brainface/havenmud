// straw hat for ferry captain
#include <armour_types.h>
#include <vendor_types.h>
#include <lib.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("straw hat");
  SetShort("a conical straw hat");
  SetId( ({ "hat" }) );
  SetAdjectives( ({ "straw", "conical" }) );
  SetLong(
    "This had is made of woven straw, with a cloth chin strap to keep it "
    "attached to the wearers head. Its size nearly obscures the wearers "
    "face when worn and would provide great protection from the sun."
  );  
  SetVendorType(VT_CLOTHING);
  SetMaterial("natural");
  SetRepairDifficulty(10);
  SetArmourType(A_HELMET);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(40);
  SetValue(300);
  SetDamagePoints(300);
  SetSize(SIZE_MEDIUM);
}

