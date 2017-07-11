#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("flannel shirt");
   SetShort("a flannel shirt");
   SetId( ({ "shirt","flannel" }) );
   SetAdjectives( ({ "flannel","warm" }) );
   SetLong("A plaid pattern in primarily reds covers the warm flannel "
           "made of a thick textile.");
   SetMass(40);
   SetValue(50);
   SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_SHIRT);
   SetDamagePoints(200);
   // SetProtection(SLASH,2);
   // SetProtection(PIERCE,3);
   // SetProtection(BLUNT,2);
   // SetProtection(COLD,6);
   // SetProtection(HEAT,2);
   // SetProtection(ACID,2);
   SetMaterial( ({ "textile" }) );
   SetWarmth(20);
   SetRepairDifficulty(4);
   SetRepairSkills( ([
                       "textile working" : 1,
                       "armour smithing" : 1,
                  ]) );
   SetSize(SIZE_VERY_SMALL);
}
