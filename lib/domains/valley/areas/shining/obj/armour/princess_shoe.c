#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("slippers");
  SetId( ({"slippers", "pearl slippers", "pearl colored slippers"}) );
  SetShort("a pair of pearl colored slippers");
  SetLong("The pair of pearl colored slippers are very thin. There are "
          "laced designs all over them. They seem to have a very strange "
          "glow to them. ");
  SetAdjectives( ({"natural"}) );
  SetMass(250);
  SetProperty("multiples", 1);
  SetValue(1000);
  SetSize(SIZE_VERY_SMALL);
  SetArmourClass(ARMOUR_NATURAL);
  SetMaterial( ({"natural"}) );
  SetWarmth(5);
  SetRepairSkills( ([
     "armour smithing" : 30,
     "mithril working" : 30,
  ]) );
  SetRepairDifficulty(20);
  SetDamagePoints(1000);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BOOT);
  SetProtectionBonus(COLD,20);
  SetProtectionBonus(HEAT,20);
  SetProtectionBonus(MAGIC,20);
  SetProtectionBonus(SHOCK,20);
}





