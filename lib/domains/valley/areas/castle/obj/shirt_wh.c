#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("white shirt");
   SetShort("a white shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "white" }) );
   SetLong("The shirt is fairly thin, but well made.");
   SetMass(30);
   SetValue(10);
   SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetArmourType(A_SHIRT);
   SetDamagePoints(150);
   // SetProtection(BLUNT,1);
   // SetProtection(PIERCE,1);
   // SetProtection(SLASH,1);
   // SetProtection(ACID,1);
   // SetProtection(HEAT,1);
   // SetProtection(COLD,1);
   SetMaterial( ({ "textile" }) );
   SetRepairDifficulty(2);
   SetRepairSkills( ([
                       "armour smithing" : 1,
                       "textile working" : 1,
                  ]) );
}
