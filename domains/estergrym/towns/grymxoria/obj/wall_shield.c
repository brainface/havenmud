#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shield");
  SetId( ({ "shield", }) );
  SetAdjectives( ({ "wall", "blood", "red" }) );
  SetShort("a blood red wall shield");
  SetLong(
    "A wall shield is a large rectangle of metal about "
    "four feet tall. This one has blood red coloring and "
    "markings setting it off as a piece from Grymxoria."
  );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_SHIELD);
  SetArmourClass(ARMOUR_PLATE);
  SetMass(500);
  SetValue(180);
  SetDamagePoints(1600);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([ 
    "armour smithing" : 3,
    "metal working"   : 3,
  ]) );
  SetRepairDifficulty(11);

    // SetProtection(BLUNT,  15);
    // SetProtection(SLASH,  15);
    // SetProtection(PIERCE, 15);
    // SetProtection(HEAT,    1);
    // SetProtection(SHOCK,   2);
    // SetProtection(ACID,    4);
}
