#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ARMOUR;
static void create() {
  armour::create();
  SetKeyName("boots");
  SetId( ({"boots"}) );
  SetShort("a pair a mithril boots");
  SetLong("These boots are made of strong, thick mithril.  They cover "
  "the whole foot and all the way up to mid-shin.  They release a dull "
  "shine and do not look too comfortable but they seem great for a foot "
  "protection.");
  SetAdjectives( ({"mithril"}) );
  SetMass(500);
  SetProperty("multiples", 1);
  SetValue(500);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetMaterial( ({"mithril"}) );
  SetWarmth(5);
  SetRepairSkills( ([
     "armour smithing" : 10,
     "mithril working" : 10,
  ]) );
  SetRepairDifficulty(10);
  SetDamagePoints(800);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BOOT);
  // SetProtection(SLASH,15);
  // SetProtection(BLUNT,13);
  // SetProtection(PIERCE,13);
  // SetProtection(COLD,10);
  // SetProtection(HEAT,10);
  // SetProtection(MAGIC,5);
  // SetProtection(SHOCK,7);
  // SetProtection(ACID,9);
}
