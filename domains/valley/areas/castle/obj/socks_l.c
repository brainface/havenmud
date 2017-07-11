#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("long wool socks");
   SetShort("a pair of long wool socks");
   SetId( ({ "socks","sock" }) );
   SetAdjectives( ({ "pair of","long","wool","warm" }) );
   SetLong("Little fuzzies hang off the long wool socks.");
   SetMass(23);
   SetValue(10);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_SOCK);
   SetDamagePoints(370);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
   // SetProtection(BLUNT,5);
   // SetProtection(PIERCE,5);
   // SetProtection(SLASH,3);
   // SetProtection(COLD,9);
   // SetProtection(HEAT,2);
   // SetProtection(ACID,2);
   SetMaterial( ({ "textile" }) );
   SetRepairDifficulty(3);
   SetRepairSkills( ([
                       "armour smithing" : 1,
                       "textile working" : 1,
                  ]) );
}
