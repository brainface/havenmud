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
  SetShort("a pair of black bone boots");
  SetLong("These boots are made of a strong mix of bones.  They cover "
  "the entire foot, all the way up to the knee. They are sprayed with a "
  "black lacquer to help make them much more durable. They appear to offer "
  "very good protection as well as being extremely comfortable. ");
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
  SetDamagePoints(10000);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BOOT);
  SetProtectionBonus(COLD,10);
  SetProtectionBonus(HEAT,10);
  SetProtectionBonus(MAGIC,10);
  SetProtectionBonus(SHOCK,10);
}

