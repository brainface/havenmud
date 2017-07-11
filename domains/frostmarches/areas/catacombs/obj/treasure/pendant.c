#include <lib.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("pendant");
  SetShort("a heart-shaped silver pendant");
  SetId( ({"pendant"}) );
  SetAdjectives( ({ "heart-shaped", "heart", "silver"}) );
  SetLong("The design of this pendant dates it back"
          " hundreds of years, yet it shines like new."
          " The chain is made from solid silver and a"
          " heart-shaped charm dangles from it.");
  SetMass(30);
  SetValue(3000);
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_AMULET);
  SetVendorType(VT_TREASURE);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(700);
  SetMaterials("metal");
  SetRepairDifficulty(25);
}
