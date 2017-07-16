#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("breastplate");
  SetId( ({"breastplate"}) );
  SetAdjectives( ({"metal"}) );
  SetShort("a metal breastplate");
  SetLong(
     "This metal breastplate is battered and dented but looks to be in "
     "serviceable condition. The wearer of this armour must have been"
     "in one mean fight.");
  SetMass(100);
  SetValue(15);
  SetDamagePoints(800);
  SetArmourClass(ARMOUR_PLATE);
  SetArmourType(A_VEST);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
     "armour smithing" : 2,
     "metal working"   : 2,
     ]) );
  SetRepairDifficulty(8);
}
