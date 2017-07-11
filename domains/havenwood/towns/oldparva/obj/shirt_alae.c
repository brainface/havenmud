#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shirt");
   SetShort("a nice green shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "nice","dark","green" }) );
   SetLong("The dark green shirt is made of a soft leather, "
           "and appears very comfortable.  The leather looks "
           "tough.");
   SetMass(15);
   SetValue(85);
   SetVendorType(VT_CLOTHING);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetArmourType(A_SHIRT);
   SetDamagePoints(175);
   // SetProtection(BLUNT,4);
   // SetProtection(SLASH,4);
   // SetProtection(PIERCE,4);
   // SetProtection(COLD,6);
   // SetProtection(HEAT,1);
   SetWear("The shirt is soft on the inside.");
   SetMaterial( ({ "leather" }) );
   SetWarmth(15);
   SetRepairDifficulty(19);
   SetRepairSkills( ([
                       "leather working" : 1,
                  ]) );
   SetProperty("history","It used to be the property of Alae, the Parva "
               "Ranger.");
}
