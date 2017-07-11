#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("workmans glove");
   SetShort("a working glove");
   SetId( ({ "glove" }) );
   SetAdjectives( ({ "working","workmans","workers","worker",
                     "workman","work","tough" }) );
   SetLong("This glove is fairly tough, made for purposes such as "
           "working in a field.");
   SetMass(11);
   SetValue(23);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_GLOVE);
   SetProperty("multiples",1);
   SetDamagePoints(370);
   // SetProtection(PIERCE,5);
   // SetProtection(SLASH,5);
   // SetProtection(BLUNT,5);
   // SetProtection(ACID,2);
   // SetProtection(HEAT,2);
   // SetProtection(COLD,7);
   SetMaterial( ({ "textile" }) );
   SetRepairDifficulty(4);
   SetRepairSkills( ([
                       "armour smithing" : 1,
                       "textile working" : 2,
                  ]) );
}
