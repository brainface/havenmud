/*  Plate Mail Armour for the Knights */
#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("leather vest");
  SetShort("a vest of leather armour");
  SetId( ({ "leather", "armour", "vest" }) );
  SetAdjectives( ({ "vest", "leather" }) );
  SetLong(
    "This is a vest of leather armour. It offers little protection "
    "to anything except the torso, but does protect very well "
    "over the areas it covers."
  );
  SetArmourType(A_VEST);
    SetArmourClass(ARMOUR_LEATHER);
  SetValue(100);
  SetMass(200);
  SetDamagePoints(650);
  SetMaterials( ({ "leather" }) );
  SetRepairDifficulty(10);
  SetRepairSkills( ([
    "leather working" : 1,
    "armour smithing" : 1,
    ]) );
  SetProperty("history", "This armour is from the bandits near the HavenWood.");
}
