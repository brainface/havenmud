/*  Plate Mail Armour for the Knights */
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("platemail armour");
  SetId( ({ "suit", "armour" }) );
  SetAdjectives( ({ "plate", "platemail" }) );
  SetShort("a suit of platemail armour");
  SetLong(
    "This is a thick, heavy suit of the hardest plate metal armour."
  );
  SetArmourType(A_BODY_ARMOUR);
    SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetMass(1200);
  SetValue(1500);
  SetDamagePoints(4000);
  SetProperty("magic", "This armour resists magic.");
  SetProperty("history", "This armour was fashioned for the Paladins of Kylin.");
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(50);
  SetRepairSkills( ([
    "metal working" : 1,
    "armour smithing" : 1,
  ]) );
}
