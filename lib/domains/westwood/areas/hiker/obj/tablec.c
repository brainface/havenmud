#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("checkered tablecloth");
   SetShort("a checkered tablecloth");
   SetId( ({ "tablecloth","cloth","table cloth" }) );
   SetAdjectives( ({ "checkered","thin","flappy" }) );
   SetLong("Red and white squares cover the tablecloth, which is "
           "thin and flappy.");
   SetMass(10);
   SetValue(5);
   SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_TREASURE|VT_ARMOUR);
   SetDamagePoints(30);
   SetMaterial( ({ "textile" }) );
   SetWarmth(10);
   SetRepairDifficulty(2);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetArmourType(A_CLOAK);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   // SetProtection(BLUNT,1);
   // SetProtection(COLD,2);
}
