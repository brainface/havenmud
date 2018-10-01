#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>
#include <armour_class.h>
 
inherit LIB_ARMOUR;
int CheckReligion();
 
static void create()
{
  ::create();
  SetKeyName("medallion");
  SetId( ({ "medallion" }) );
  SetAdjectives( ({ "oak" }) );
  SetShort("an oak medallion");
  SetLong("This medallion appears to have been made from "
          "a high quality oak wood. The medallion disk is "
          "round with an engraved picture of a leaf in the "
          "surface. It is roughly a finger width thick "
          "to a small dwarf and a brown satin ribbon creates "
          "a loop for it to be worn properly. The back of "
          "the disk reveals a high detail of wood grain along "
          "with some minimal scratches.");
  SetWear( (:CheckReligion:) );
  SetMass(15);
  SetMaterial("wood");
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_SMALL);
  SetWarmth(5);
  SetValue(random(50)+200);
  SetDamagePoints(700);
  SetArmourType(A_AMULET);
  SetVendorType(VT_ARMOUR);
  SetRepairDifficulty(50);
  SetProtectionBonus(BLUNT, 3);
  SetProtectionBonus(PIERCE, 3);
}

int CheckReligion() {
  if (this_player()->GetReligion() == "Eclat" ) {
    send_messages("wear", 
      "$agent_name $agent_verb a medallion.",
      this_player(), 0, environment(this_player()) );
    return 1;
  }
  message("system", 
    "The medallion can only be worn by members of the Eclat faith.",
    this_player() );
  return 0;
  }