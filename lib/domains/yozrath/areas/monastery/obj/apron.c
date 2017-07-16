// Monastery
// Aerelus
// 07/05/2006

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetArmourClass(ARMOUR_CLOTH);
  SetKeyName("apron");
  SetShort("a dirty apron");
  SetId( ({"apron"}) );
  SetAdjectives( ({ "dirty", "white" }) );
  SetLong(
    "This dirty apron is covered with burn marks and other general cooking "
    "stains. It looks like it has little use for most purposes, other than "
    "keeping the wearer clean whilst cooking food. It looks as if it could "
    "have been white, originally, but years of use have hidden the color "
    "well."
  );
  SetMass(20);
  SetValue(15);
  SetDamagePoints(30);
  SetWarmth(30);
  SetMaterial("textile");
  SetRepairDifficulty(5);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_VEST);
}
