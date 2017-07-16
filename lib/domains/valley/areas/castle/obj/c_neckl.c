#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("tarnished necklace");
   SetShort("a tarnished necklace");
   SetId( ({ "necklace" }) );
   SetAdjectives( ({ "tarnished","simple" }) );
   SetLong("The simple necklace looks as if it has adorned the bodies of "
           "the dead.");
   SetMass(4);
   SetValue(40);
   SetVendorType(VT_ARMOUR);
   SetArmourClass(ARMOUR_CLOTH);
   SetDamagePoints(89+random(40));
   //SetProtectionBonus(POISON,7);
   //SetProtectionBonus(DISEASE,7);
   //SetProtectionBonus(HUNGER,7);
   //SetProperty("magic","All the days among the dead has caused the "
   //                    "necklace to pick up protections to "
   //                    "poison, disease, and hunger.");
   SetDestroyOnSell(1);
   SetMaterial( ({ "metal" }) );
}
