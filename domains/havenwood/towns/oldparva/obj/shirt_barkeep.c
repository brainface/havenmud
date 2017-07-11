#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shirt");
   SetShort("a silk shirt");
   SetId( ({ "shirt","silk" }) );
   SetAdjectives( ({ "silk" }) );
   SetLong("The silk shirt is a dark, purple-black color.  It "
           "is obviously made of quality silk.  Matching purple "
           "buttons go up the front.");
   SetMass(5);
   SetValue(125);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_SHIRT);
   SetArmourClass(ARMOUR_CLOTH);
   SetDamagePoints(450);
   // SetProtection(BLUNT,3);
   // SetProtection(SLASH,3);
   // SetProtection(PIERCE,3);
   SetProperty("magic","The shirt has a slight magical protection "
               "on it.");
   SetProperty("history","This shirt used to belong to Minkin, the "
               "owner of the inn in Parva.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(10);
   SetSize(SIZE_SMALL);
}
