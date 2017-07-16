#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("sharp vest");
   SetShort("a sharp vest");
   SetId( ({ "vest" }) );
   SetAdjectives( ({ "sharp","black" }) );
   SetLong("This black vest is rather neat and sharp looking.");
   SetMass(30);
   SetValue(17);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_VEST);
   SetDamagePoints(200);
   // SetProtection(BLUNT,2);
   // SetProtection(SLASH,2);
   // SetProtection(PIERCE,2);
   // SetProtection(COLD,3);
   // SetProtection(HEAT,1);
   // SetProtection(ACID,1);
   SetMaterial( ({ "textile" }) );
   SetRepairDifficulty(4);
   SetRepairSkills( ([
                       "armour smithing" : 1,
                       "textile working" : 1,
                  ]) );
}
