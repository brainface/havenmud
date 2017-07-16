// Amelia@Haven
 
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;
inherit LIB_WEAPON;
 
static void create() {
   armour::create();
   SetKeyName("brass knuckles");
   SetShort("a set of brass knuckles");
   SetId( ({ "knuckles","knuckle","set" }) );
   SetAdjectives( ({ "set of","brass" }) );
   SetLong("The brass knuckles are a hunk of metal that fits over "
           "one's knuckles.  There are holes in it to put fingers "
           "through.");
   SetMass(75);
   SetSize(SIZE_MEDIUM);
   SetValue(80);
   SetDamagePoints(360);
   SetProtection(PIERCE,4);
   SetProtection(SLASH,8);
   SetProtection(BLUNT,4);
   SetWeaponType("melee");
   SetDamageType(BLUNT);
   SetClass(12);
   SetHands(1);
   SetArmourType(A_WEAPON);
   SetVendorType(VT_ARMOUR | VT_WEAPON);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(30);
   SetRepairSkills( ([
                       "metal working" : 2,
                       "armour smithing" : 1,
                       "weapon smithing" : 1,
                  ]) );
}
