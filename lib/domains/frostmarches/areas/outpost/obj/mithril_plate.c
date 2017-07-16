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
  SetAdjectives( ({"mithril", "plate", "mail"}) );
  SetShort("a suit of mithril platemail armour");
  SetLong("This suit of mithril platemail armour covers most of the body, "
          "leaving very little exposed to danger. It is lined with fine "
          "silk, providing comfort to the wearer as well as superiour "
          "protection. Only master dwarven armourers could have forged "
          "this full suit of platemail armour from mithril.");
  SetMass(1200);
  SetMaterial( ({
    "mithril",
    }) );
  SetRepairDifficulty(90);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetWarmth(4);
  SetSize(SIZE_MEDIUM);
  SetValue(8000);
  SetDamagePoints(5000);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_ARMOUR); 
}
