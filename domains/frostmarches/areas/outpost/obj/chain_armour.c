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
  SetId( ({"chainmail", "suit"}) );
  SetAdjectives( ({ "chain", "mail"}) );
  SetShort("a suit of chainmail armour");
  SetLong(
    "This suit of well-polished chainmail was made by master dwarven armourers "
    "of Glimmerdin for the Kylin Inquisitors. The suit provides provides "
    "substantial protection to the parts of the body that it covers."  );
  SetMass(1200);
  SetMaterial( ({"metal"}) );
  SetRepairDifficulty(60);
  SetArmourClass(ARMOUR_CHAIN);
  SetWarmth(0);
  SetSize(SIZE_MEDIUM);
  SetValue(4000);
  SetDamagePoints(5000);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_ARMOUR);
  SetProtectionBonus(MAGIC, 20);
  SetProtectionBonus(HEAT, 20);
  SetProtectionBonus(SHOCK, 20);
  SetProperty("magic","This armour was blessed by the Kylin clergy and enchanters "
              "to give more protection for the wearer to withstand magic and some "
              "of the elements.");
  }