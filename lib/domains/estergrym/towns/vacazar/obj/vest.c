// Coded by Zeratul
// 3-17-2000

#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include "../vacazar.h"
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("vest");
  SetId( ({"vest","chainmail vest"}) );
  SetAdjectives( ({"chainmail"}) );
  SetShort("a chainmail vest");
  SetLong(
     "The chain links in this vest appear to be shiny and freshly polished. "
     "The links themselves are linked close together, providing good protection "
     "from physical attacks. "
  );
  SetArmourType(A_VEST);
  SetValue(300);
  SetArmourClass(ARMOUR_CHAIN);
  SetSize(SIZE_MEDIUM);
  SetMass(200);
  SetDamagePoints(1050);
  // SetProtection(SLASH, 22);
  // SetProtection(PIERCE, 20);
  // SetProtection(BLUNT, 19);
  SetVendorType(VT_ARMOUR);
  SetRepairDifficulty(25);
  SetRepairSkills( ([
     "armour smithing" : 13,
     "metal working" : 13,
  ]) );
  SetMaterial( ({"metal"}) );
  SetWarmth(0);
  }
