#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shirt");
   SetShort("an old shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "old" }) );
   SetLong("The shirt is old and stained from work and "
           "drinking.  Food stains also decorate the "
           "tough deep blue cloth.");
   SetMass(5);
   SetValue(4);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_SHIRT);
   SetArmourClass(ARMOUR_CLOTH);
   SetDamagePoints(45);
   // SetProtection(BLUNT,1);
   // SetProtection(PIERCE,1);
   // SetProtection(SLASH,1);
   SetMaterial( ({ "textile" }) );
   SetWarmth(10);
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetSize(SIZE_SMALL);
}
