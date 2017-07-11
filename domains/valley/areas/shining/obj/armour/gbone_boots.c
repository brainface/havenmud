#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("boots");
  SetId( ({"boots"}) );
  SetShort("a pair of green bone boots");
  SetLong("The green boots are made up of a strong set of bones. They cover "
          "the entire foot. The boots have almost a mirror-like reflection "
          "to them. They were obviously coated with some sort of liquid. "
          "The small carvings in the bones resemble many seen around the "
          "forest. They appear to be part out a full outfit. ");
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
  SetDamagePoints(5000);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BOOT);
  SetProtectionBonus(BLUNT,20);
  SetProtectionBonus(COLD,20);
  SetProtectionBonus(HEAT,20);
  SetProtectionBonus(MAGIC,20);
  SetProtectionBonus(SHOCK,20);
}
