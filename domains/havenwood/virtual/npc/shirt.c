#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shirt");
   SetShort("a brown shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "brown" }) );
   SetLong("This brown shirt was made out of a "
           "fairly tought material, but probably "
           "offers little protection from much "
           "save cold and exposure.");
   SetMass(5);
   SetVendorType(VT_CLOTHING);
   SetValue(7);
  SetSize(SIZE_MEDIUM);
   SetArmourClass(ARMOUR_CLOTH);
   SetDamagePoints(70);
   SetArmourType(A_SHIRT);
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
