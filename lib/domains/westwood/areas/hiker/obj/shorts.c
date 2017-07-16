#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("tough shorts");
   SetShort("a pair of tough shorts");
   SetId( ({ "shorts","short" }) );
   SetAdjectives( ({ "pair of","tough","thin","floppy","green" }) );
   SetLong("The shorts are made of a very tough ice-blue textile.");
   SetMass(20);
   SetValue(30);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_SMALL);
   SetDamagePoints(400);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_PANTS);
   // SetProtection(SLASH,4);
   // SetProtection(BLUNT,4);
   // SetProtection(PIERCE,4);
   // SetProtection(COLD,3);
   // SetProtection(HEAT,2);
   // SetProtection(ACID,1);
   SetMaterial( ({ "textile" }) );
   SetWarmth(10);
   SetRepairDifficulty(7);
   SetRepairSkills( ([
                       "textile working" : 2,
                       "armour smithing" : 1,
                  ]) );
}
