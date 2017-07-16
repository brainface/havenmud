// by Dahaka
// Aug 2004

#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>

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
  SetMass(200);
  SetDamagePoints(1050);
  SetArmourClass(ARMOUR_CHAIN);
  SetVendorType(VT_ARMOUR);
  SetRepairDifficulty(25);
  SetRepairSkills( ([
     "armour smithing" : 13,
     "metal working"   : 13,
     ]) );
  SetMaterial( ({"metal"}) );
  SetWarmth(0);
}
