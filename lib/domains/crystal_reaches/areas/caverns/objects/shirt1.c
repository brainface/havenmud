/*  Shirt - Gnome - Level #1 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h> 
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shirt");
  SetId( ({ "shirt", "thin shirt" }) );
  SetAdjectives( ({ "thin", "blue", "deep blue", "relaxed", "comfortable",
                    "very comfortable" }) );
  SetShort("a thin shirt");
  SetLong(
    "The thin shirt is a deep blue in color and allows the air to flow "
    "through and over the skin. This is a very relaxed shirt, good for "
    "sitting around all day and doing nothing. In that way, it is a "
    "very comfortable shirt."
  );
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_SHIRT);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(35);
  SetValue(30);
  SetDamagePoints(60);
  SetSize(SIZE_SMALL);
  SetMaterial("textile");
  SetWarmth(10);
  SetRepairSkills( ([ "textile working" : 2 ]) );
  SetRepairDifficulty(5);
}
