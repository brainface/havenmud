/*  Sturdy Boots - Bridge Builder - Level #2 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h> 
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("sturdy boots");
  SetId( ({ "sturdy boots", "boots" }) );
  SetAdjectives( ({ "sturdy", "leather", "thick" }) );
  SetShort("a pair of sturdy boots");
  SetLong(
    "These sturdy boots are of very good craftmanship. Made of thick "
    "leather gives them good support and gives the wearer good foot "
    "protection for whatever one is doing."
  );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BOOT);
  SetArmourClass(ARMOUR_LEATHER);
  SetMass(40);
  SetValue(60);
  SetDamagePoints(300);
  SetSize(SIZE_MEDIUM);
  SetMaterial("leather");
  SetWarmth(4);
  SetRepairSkills( ([ 
    "leather working" : 3,
  ]) );
  SetRepairDifficulty(5);
}
