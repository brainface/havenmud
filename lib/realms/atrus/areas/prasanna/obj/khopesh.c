#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("khopesh sword");
  SetRepairDifficulty(22);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working" : 6,
    "weapon smithing" : 6,
     ]) );
  SetShort("a wicked looking khopesh sword");
  SetAdjectives( ({ "wicked","wicked looking","long","curved","khopesh" }) );
  SetId( ({ "khopesh", "sword" }) );
  SetLong("This long curved sword looks as if it were engineered solely to "
          "inflict deep wounds upon its target. Its long steel blade "
          "is polished to perfection and looks perfect for slashing.");
  SetClass(14);
  SetDamagePoints(800);
  SetValue(200);
  SetMass(150);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  }
