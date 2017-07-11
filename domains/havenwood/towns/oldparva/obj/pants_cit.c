// Amelia@Haven
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("pants");
   SetShort("a pair of tough pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "pair of","tough","tan","colored" }) );
   SetLong("These pants were made from a tough, tan-colored "
           "material.  They are very plain.");
   SetMass(20);
   SetValue(15);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourClass(ARMOUR_CLOTH);
   SetArmourType(A_PANTS);
   SetDamagePoints(125);
   // SetProtection(BLUNT,2);
   // SetProtection(PIERCE,2);
   // SetProtection(SLASH,2);
   SetMaterial( ({ "textile" }) );
   SetWarmth(15);
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetProperty("history","These pants used to belong to one of the "
               "citizens of Parva.");
}
