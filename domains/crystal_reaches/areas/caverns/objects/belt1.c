/*  Leather Belt - Made for Gnome - Level #1 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h> 
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("belt");
  SetId( ({ "belt", "leather belt" }) );
  SetAdjectives( ({ "leather", "dark", "brown" }) );
  SetShort("a leather belt");
  SetLong(
    "The leather belt is dark brown in color and has a brass buckle.  "
    "The belt has been kept in very good shape and appears to be oiled "
    "and cleaned regularly."
  );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BELT);
  SetArmourClass(ARMOUR_LEATHER);
  SetMass(8);
  SetValue(20);
  SetDamagePoints(250);
  SetSize(SIZE_SMALL);
  SetMaterial("leather");
  SetWarmth(2);
  SetRepairSkills( ([ 
    "leather working"  :  1,
    "metal working"  :  1,
  ]) );
  SetRepairDifficulty(7);
}
