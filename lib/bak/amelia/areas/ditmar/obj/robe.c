#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("robe");
   SetShort("a leather robe");
   SetId( ({ "robe","leather" }) );
   SetAdjectives( ({ "leather" }) );
   SetLong("The leather robe can easily wrap around one's body and be worn for basic "
           "protection and modesty.  The leather is soft and not too thick but will "
           "keep out the basic nastiness of being punched, kicked, impaled, or "
           "otherwise bothered by a weapon.  It won't offer much help against "
           "anything but the most simple of weapons wielded by the least of the "
           "mortals.");
   SetMass(30);
   SetValue(5);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_CLOAK);
   SetDamagePoints(500);
   SetMaterial( ({ "leather" }) );
   SetProtection(SLASH,2);
   SetProtection(BLUNT,2);
   SetProtection(PIERCE,2);
   SetRepairSkills( ([
                       "leather working" : 0,
                       "armour smithing" : 0,
                  ]) );
   SetRepairDifficulty(8);
}