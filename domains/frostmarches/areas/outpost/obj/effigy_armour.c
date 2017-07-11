#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("plate mail armour");
  SetId( ({"armour", "suit"}) );
  SetAdjectives( ({"golden", "plate", "mail","suit"}) );
  SetShort("a suit of golden plate mail armour");
  SetLong("This suit of golden plate mail armour looks to have been created "
          "by a master armourer. This plate mail armour seems to protect "
          "most of the wearer's body from injury. The armour gives off a "
          "glow." );
  SetMass(2500);
  SetMaterial( ({
    "metal",
    }) );
  SetRepairDifficulty(60);
  SetArmourClass(ARMOUR_PLATE);
  SetWarmth(0);
  SetSize(SIZE_LARGE);
  SetValue(5000);
  SetRadiantLight(10);
  SetDamagePoints(5000);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_ARMOUR);
}
