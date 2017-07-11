#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("pants");
   SetShort("a pair of brown pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "brown" }) );
   SetLong("This pair of brown pants was made out of a "
           "fairly tought material, but probably "
           "offers little protection from much "
           "save cold and exposure.");
   SetMass(15);
   SetVendorType(VT_CLOTHING);
   SetValue(10);
   SetArmourClass(ARMOUR_CLOTH);
   SetDamagePoints(120);
   SetArmourType(A_PANTS);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   // SetProtection(SLASH,1);
   // SetProtection(COLD,4);
   SetMaterial( ({ "textile" }) );
   SetWarmth(10);
   SetRepairDifficulty(4);
   SetRepairSkills( ([
                       "textile working" : 0,
                  ]) );
}
