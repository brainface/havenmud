#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;


static void create() {
  armour::create();
  SetId( ({ "tough pants", "pants" }) );
  SetWarmth(15);
  SetKeyName("pants");
  SetAdjectives( ({ "tough" }) );
  SetShort("a pair of tough pants");
  SetLong("These tough pants are worn by the Pharez, the mayor of Keryth.  "
          "They are tough and completely black, except for a yellow diamond "
          "shaped patch of cloth on each thigh.");
  SetMass(75);
  SetValue(90);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_PANTS);
  SetDamagePoints(350);
  // SetProtection(SLASH,5);
  // SetProtection(COLD,5);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(1);
  SetRepairSkills( ([
    "armor smithing": 1,
    "textile working" : 1 
  ]) );

}

