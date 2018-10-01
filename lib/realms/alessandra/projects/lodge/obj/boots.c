#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ARMOUR;

static void create() {
  armour::create();

  SetKeyName("boots");
  SetId( ({"boots"}) );
  SetShort("a pair a mithril boots");
  SetLong(
     ""
     );
  SetAdjectives( ({"mithril"}) );
  SetMass(500);
  SetValue(500);
  SetMaterial( ({"mithril"}) );
  SetWarmth(5);
  SetRepairSkills( ([
     "armour smithing" : 10,
     "metal working" : 10,
  ]) );
  SetRepairDifficulty(10);
  SetDamagePoints(800);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BOOT);
  SetProtection(SLASH,15);
  SetProtection(BLUNT,13);
  SetProtection(PIERCE,13);
  SetProtection(COLD,10);
  SetProtection(HEAT,10);
  SetProtection(MAGIC,5);
  SetProtection(SHOCK,7);
  SetProtection(ACID,9);
}
