#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shinkickers");
  SetId(( {"boots","shinkickers" } ));
  SetShort("a pair of shinkickers");
  SetAdjectives( ({"pair of"}) );
  SetLong(
    "These sturdy leather boots are a well crafted combination of durability and "
    "comfort. The black leather reaches well past the ankle, and the soles are "
    "made of softer leather interlaced with steel cleats for gripping. A solid "
    "toe of steel is sewn into the toe of the boots to protect the wearer from "
    "mishaps."
  );
  SetProperty("multiples", 1);
  SetMass(125);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_REINFORCED);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({"leather","metal"}) );
  SetWarmth(5);
  SetRepairDifficulty(70);
  SetValue(2500);
  SetDamagePoints(25000);
  SetArmourType(A_BOOT);
  SetWear("Your toes poke against unyielding steel.");
}

