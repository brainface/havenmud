#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("soft cloak");
   SetShort("a soft brown cloak");
   SetId( ({ "cloak" }) );
   SetAdjectives( ({ "soft","brown" }) );
   SetLong("The brown cloak looks soft and warm.");
   SetMass(45);
   SetValue(15);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_CLOAK);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
   SetDamagePoints(350);
   // SetProtection(BLUNT,4);
   // SetProtection(PIERCE,3);
   // SetProtection(SLASH,3);
   // SetProtection(HEAT,2);
   // SetProtection(COLD,11);
   // SetProtection(ACID,2);
   SetMaterial( ({ "textile" }) );
   SetRepairDifficulty(3);
   SetRepairSkills( ([
                       "armour smithing" : 1,
                       "textile working" : 1,
                  ]) );
}
