// Goblin invasion of Soleil
// Original Coder: Unknown
// Edited: Laoise, 2005

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("armour");
  SetShort("a suit of leather armour");
  SetId( ({ "armour","armour" }) );
  SetAdjectives( ({ "leather","suit" }) );
  SetLong(
    "This is a suit of leather armour. It is boiled into shape with "
    "wax and has seen lots of use. It is scarred around the front and "
    "sides. It is a dark brown in color that is made from having been "
    "exposed to the weather for years.");
  SetArmourType(A_ARMOUR);
  SetVendorType(VT_ARMOUR);
    SetArmourClass(ARMOUR_LEATHER);
  SetValue(75);
  SetMass(250);
  SetWarmth(15);
  SetDamagePoints(550);
  SetMaterial( ({ "leather" }) );
  SetRepairSkills( ([ 
    "leather working" : 2,
    "armor smithing" :  1,
  ]) );
  SetRepairDifficulty(2);
 }
 
