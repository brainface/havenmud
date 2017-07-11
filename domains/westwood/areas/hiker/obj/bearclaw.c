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
   SetShort("an adult bear claw");
   SetId( ({ "claw" }) );
   SetAdjectives( ({ "adult","bear","large" }) );
   SetLong("The bear claw can be worn on one's hands, almost like a "
           "glove, but the sharp points would make it a weapon as "
           "well.  It is large, and it is easy to tell that a bear "
           "claw this size would have to come from an adult.");
   SetMass(100);
   SetValue(50);
   SetDamagePoints(450);
   // SetProtection(PIERCE,7);
   SetArmourClass(ARMOUR_REINFORCED);
   // SetProtection(SLASH,5);
   // SetProtection(BLUNT,6);
   SetWeaponType("melee");
   SetDamageType(SLASH);
   SetClass(14);
   SetHands(1);
   SetArmourType(A_WEAPON);
   SetVendorType(VT_ARMOUR | VT_WEAPON);
   SetTouch("The tips of the claws are very sharp.");
   SetSize(SIZE_LARGE);
   SetRepairDifficulty(80);
   SetMaterial("natural");
}
