// by Dahaka
// Auh 2004

#include <lib.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("tail spike");
  SetId( ({ "spike" }) );
  SetAdjectives( ({ "metal", "tail" }) );
  SetShort("a metal tail spike");
  SetLong(
     "This spike is a simple piece of metal that raps around the user's tail. "
     "It appears to be nothing more than a circular object with spikes coming "
     "out of it, almost like a collar of sorts. "
     );
  SetArmourType(A_TAIL);
  SetRestrictLimbs("tail");
  SetValue(120);
  SetMass(40);
  SetDamagePoints(1000);
  SetArmourClass(ARMOUR_PLATE);
  SetVendorType(VT_ARMOUR);
  SetRepairDifficulty(30);
  SetRepairSkills( ([
     "armour smithing" : 13,
     "metal working"   : 13,
     ]) );
  SetMaterial( ({ "metal" }) );
}                   