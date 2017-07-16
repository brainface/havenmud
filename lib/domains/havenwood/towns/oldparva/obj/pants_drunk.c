#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("pants");
   SetShort("a pair of old pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "pair of","old" }) );
   SetLong("The pants are old, but not worn really.  Beer "
           "and food and work stains freckle the tough "
           "deep blue material.");
   SetMass(15);
   SetValue(5);
   SetVendorType(VT_CLOTHING);
   SetArmourClass(ARMOUR_CLOTH);
   SetArmourType(A_PANTS);
   SetDamagePoints(95);
   // SetProtection(BLUNT,2);
   // SetProtection(PIERCE,2);
   // SetProtection(SLASH,2);
   SetMaterial( ({ "textile" }) );
   SetWarmth(15);
   SetRepairDifficulty(9);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetSize(SIZE_SMALL);
}

