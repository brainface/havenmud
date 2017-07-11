/*  Thick Shirt - Bridge Builder - Level #2 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h> 
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("thick shirt");
  SetId( ({ "thick shirt", "shirt" }) );
  SetAdjectives( ({ "thick" }) );
  SetShort("a thick shirt");
  SetLong(
    "The thick shirt is made from thick cloth for severe working "
    "conditions. It offers some protection to the environment, and "
    "although it chaffs the skin it is a very well woven shirt."
  );
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_SHIRT);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(40);
  SetValue(35);
  SetDamagePoints(50);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetWarmth(10);
  SetRepairSkills( ([ 
    "textile working" : 1,
  ]) );
  SetRepairDifficulty(5);
}
