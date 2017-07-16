/*  Tough Pants - Bridge Builder - Level #2 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h> 
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("tough pants");
  SetId( ({ "tough pants", "pants" }) );
  SetAdjectives( ({ "tough" }) );
  SetShort("a pair of tough pants");
  SetLong(
    "The tough pants are made out of a material that doesn't easily rip "
    "or tear. They are very good for use in work that requires a lot of "
    "kneeling."
  );
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_PANTS);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(60);
  SetValue(60);
  SetDamagePoints(60);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetWarmth(10);
  SetRepairSkills( ([ "textile working" : 3,
  ]) );
  SetRepairDifficulty(10);
}
