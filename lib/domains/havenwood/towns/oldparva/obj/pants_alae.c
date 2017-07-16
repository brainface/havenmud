#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("pants");
   SetShort("a pair of green pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "pair of","dark","green" }) );
   SetLong("The leather pants are a beautiful dark green "
           "color.  They are meant for females, it appears, "
           "and are tight fitting.");
   SetMass(15);
   SetValue(75);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_PANTS);
   SetDamagePoints(250);
   // SetProtection(BLUNT,5);
   // SetProtection(SLASH,5);
   // SetProtection(PIERCE,5);
   // SetProtection(COLD,6);
   // SetProtection(HEAT,3);
   SetWear("The pants are difficult to pull on.");
   SetMaterial( ({ "leather" }) );
   SetWarmth(20);
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "leather working" : 1,
                  ]) );
   SetProperty("history","It used to be the property of Alae, the Parva "
               "Ranger.");
}
