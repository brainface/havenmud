#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("pants");
  SetId( ({"pants"}) );
  SetAdjectives( ({"leather", "pair", "of"}) );
  SetShort("a pair of leather pants");
  SetLong(
     "This pair of leather pants are look like standard issue for town "
     "watch. The pants are dyed in black with a red an equilateral triangle, "
     "consisting of three overlapping lines, with one of the points facing "
     "down embroided onto the left thigh."
     );
  SetMass(20);
  SetValue(20);
  SetDamagePoints(350);
  SetWarmth(25);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_PANTS);
  SetMaterial( ({"leather"}) );
  SetRepairSkills( ([
     "leather working" : 2,
     ]) );
  SetRepairDifficulty(3);
  }
