#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("armour");
  SetId( ({"platemail", "suit"}) );
  SetAdjectives( ({"silver", "plate", "mail"}) );
  SetShort("a suit of well-polished platemail armour");
  SetLong("This suit of platemail armour made of well-polished steel "
          "covers most of the body, leaving very little exposed to danger. "
          "It is lined with fine silk, providing comfort to the wearer as "
          "well as superiour protection."  );
  SetMass(2000);
  SetMaterial( ({
    "metal",
    }) );
  SetRepairDifficulty(90);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetWarmth(4);
  SetSize(SIZE_SMALL);
  SetValue(4000);
  SetDamagePoints(4000);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_ARMOUR); 
}
