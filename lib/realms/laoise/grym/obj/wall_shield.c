#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shield");
  SetShort("a blood red wall shield");
  SetLong(
    "A wall shield is a large rectangle of metal about "
    "4 feet tall. This one has blood red coloring and "
    "markings setting it off as a piece from Grymxoria."
  );
  SetId( ({ "shield", }) );
  SetAdjectives( ({ "wall", "blood", "red" }) );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_SHIELD);
  SetMass(500);
  SetValue(180);
  SetDamagePoints(1600);
  SetProtection(BLUNT,  15);
  SetProtection(SLASH,  15);
  SetProtection(PIERCE, 15);
  SetProtection(HEAT,    1);
  SetProtection(SHOCK,   2);
  SetProtection(ACID,    4);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([ 
    "armour smithing" : 3,
    "metal working"   : 3,
  ]) );
  SetRepairDifficulty(11);
}
