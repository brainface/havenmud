#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("pants");
   SetShort("a pair of red pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "pair of","red","bright" }) );
   SetLong("The pants are made of a simple, thin "
           "cloth that can't offer that much protection.  "
           "The bright red color makes the surrounding "
           "area look a little more dull by comparsion.");
   SetMass(10);
   SetValue(45);
   SetVendorType(VT_CLOTHING);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetArmourType(A_PANTS);
   SetDamagePoints(50);
   // SetProtection(BLUNT,1);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   // SetProtection(COLD,2);
   // SetProtection(HEAT,1);
   SetWear("The pants are soft and smooth.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(15);
   SetRepairDifficulty(18);
   SetRepairSkills( ([
                       "textile working" : 2,
                  ]) );
   SetProperty("history","These pants used to be the property of Samson, "
               "the Parva Mayor.");
}
