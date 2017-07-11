#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("sheet");
   SetShort("a crisp sheet");
   SetId( ({ "sheet" }) );
   SetAdjectives( ({ "crisp" }) );
   SetLong("Stained in places, the crisp sheet has been used, cleaned, "
           "and re-used many times.");
   SetMass(3);
   SetValue(1);
   SetVendorType(VT_CLOTHING);
  SetArmourClass(ARMOUR_CLOTH);
   SetArmourType(A_CLOAK);
   SetDamagePoints(210);
   // SetProtection(SLASH,1);
   // SetProtection(BLUNT,1);
   // SetProtection(PIERCE,1);
   // SetProtection(HEAT,1);
   // SetProtection(COLD,2);
   SetMaterial( ({ "textile" }) );
   SetWarmth(10);
   SetRepairDifficulty(2);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetProperty("history","The patients' at the Eclatish Hospital near Parva "
               "used this sheet for years.");
}
