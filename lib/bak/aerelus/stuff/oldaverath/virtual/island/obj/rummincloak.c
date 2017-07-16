#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("cloak");
   SetShort("Rummin's Cloak");
   SetId(({ "cloak" }) );
   SetAdjectives( ({ "rummins" }) );
   SetLong("Designs done in black ink cover this yellow cloak made "
           "from tough cloth. Rummin is spelled out prominently in "
           "the center.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_CLOAK);
   SetArmourClass(ARMOUR_CLOTH);
   SetMass(20);
   SetValue(400);
   SetDamagePoints(250);
   SetSize(SIZE_MEDIUM);
 //  SetMaterial( ({ "textile" }) );
 //  SetRepairDifficulty(15);
 //  SetRepairSkills( ([
 //                      "textile working" : 1,
 //                 ]) );
   SetProperty("history","This cloak belongs to Rummin, the Registrar of "
               "Averath.");
}
