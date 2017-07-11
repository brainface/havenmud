// Undead invasion of Haven

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("banded mail");
  SetShort("an aged suit of banded mail");
  SetId( ({ "mail", "armour" }) );
  SetAdjectives( ({ "banded" }) );
  SetLong(
    "This torso and arm covering is banded mail, a lesser form of "
    "plate armour designed to offer maximum protection without "
    "inhibiting movement."
  );
    SetArmourClass(ARMOUR_CHAIN);
  SetMass(240);
  SetDamagePoints(750);
  SetValue(400);
  SetArmourType(A_BODY_ARMOUR);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "armour smithing" : 3,
     "metal working" : 3,
  ]) );
  SetRepairDifficulty(20);
}
