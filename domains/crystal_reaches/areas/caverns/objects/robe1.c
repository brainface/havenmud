/*  Robe - Old Hag - Level #2 Caverns */

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h> 
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("robe");
  SetId( ({ "robe", "voluminous robe" }) );
  SetAdjectives( ({ "voluminous", "strange" }) );
  SetShort("a voluminous robe");
  SetLong(
    "The voluminous robe allows plenty of room for almost any type of "
    "person to wear it. The strangest thing about the robe is the "
    "material that it is made from. It is a strong, yet flexible "
    "cloth, it may even provide protection in combat."
  );
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_BODY_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(60);
  SetValue(75);
  SetDamagePoints(300);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetWarmth(20);
  SetRepairSkills( ([ "textile working"  :  7,
  ]) );
  SetRepairDifficulty(20);
}
