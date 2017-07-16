#include <lib.h>
#include <size.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;
inherit LIB_WEAPON;
inherit LIB_TOUCH;
 
static void create() {
   armour::create();
   SetKeyName("bear claw");
   SetShort("a small bear claw");
   SetId( ({ "claw" }) );
   SetAdjectives( ({ "small","bear" }) );
   SetLong("The bear claw can be worn on one's hands, almost like a "
           "glove, but the sharp points would make it a weapon as "
           "well.  It is not very large; it probably came from a baby.");
   SetMass(50);
   SetValue(20);
   SetDamagePoints(250);
   // SetProtection(PIERCE,3);
   // SetProtection(SLASH,1);
   // SetProtection(BLUNT,2);
   SetWeaponType("melee");
   SetArmourClass(ARMOUR_LEATHER);
   SetDamageType(SLASH);
   SetClass(8);
   SetHands(1);
   SetArmourType(A_WEAPON);
   SetVendorType(VT_ARMOUR | VT_WEAPON);
   SetTouch("The tips of the claws are sharp.");
   SetSize(SIZE_SMALL);
   SetMaterial("natural");
   SetRepairDifficulty(80);
}
