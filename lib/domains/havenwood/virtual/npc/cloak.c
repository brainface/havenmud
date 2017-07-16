#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("cloak");
   SetShort("a brown cloak");
   SetId( ({ "cloak" }) );
   SetAdjectives( ({ "brown" }) );
   SetLong("This brown cloak was made out of a "
           "fairly tought material, but probably "
           "offers little protection from much "
           "save cold and exposure.");
   SetMass(5);
   SetVendorType(VT_CLOTHING);
   SetArmourClass(ARMOUR_CLOTH);
   SetValue(15);
  SetSize(SIZE_SMALL);
   SetDamagePoints(150);
   SetArmourType(A_CLOAK);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   // SetProtection(SLASH,1);
   // SetProtection(COLD,4);
   SetMaterial( ({ "textile" }) );
   SetWarmth(15);
   SetRepairDifficulty(4);
   SetRepairSkills( ([
                       "textile working" : 0,
                  ]) );
}
