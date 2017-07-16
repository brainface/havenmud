/*  Invasion Armour */

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("chainmail shirt");
  SetShort("a fine chainmail shirt");
  SetId( ({ "shirt" }) );
  SetAdjectives( ({ "fine", "chainmail" }) );
  SetLong(
    "This exquisitily woven chainmail shirt appears "
    "to be of the highest quality, obviously made to "
    "protect the soldiers of a nation in times of war."
  );
  SetArmourType(A_SHIRT);
    SetArmourClass(ARMOUR_CHAIN);
  SetProperty("magic", "This chainmail provides some magical defense.");
  SetProperty("history", "This chainmail was made for the Templars of Kylin.");
  SetDamagePoints(2000);
  SetValue(800);
  SetMass(600);
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(60);
  SetRepairSkills( ([
    "metal working" : 1,
    "armour smithing" : 1,
  ]) );
}
