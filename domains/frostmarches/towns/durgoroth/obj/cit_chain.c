#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("chainmail suit");
  SetShort("a suit of daemonic chainmail");
  SetId( ({ "chainmail", "suit", "armour", }) );
  SetAdjectives( ({ "daemonic", "chainmail" }) );
  SetLong("Tough and rigid, this chainmail looks"
          " extremely durable even if it does not"
          " appear to be of the best craftsmanship.");
  SetVendorType(VT_ARMOUR);
  SetDamagePoints(1200);
  SetArmourClass(ARMOUR_CHAIN);
  SetValue(900);
  SetMass(120);
  SetArmourType(A_BODY_ARMOUR);
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(25);
  SetSize(SIZE_LARGE);
  }
