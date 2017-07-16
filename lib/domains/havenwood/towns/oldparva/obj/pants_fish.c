#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("pants");
   SetShort("a pair of waterproof pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "pair of","waterproof" }) );
   SetLong("These pants are very durable and tough; they were "
           "made nearly waterproof, too, by the close stiches "
           "in the animal skins.");
   SetMass(40);
   SetValue(125);
   SetVendorType(VT_CLOTHING | VT_CLOTHING);
   SetSize(SIZE_MEDIUM);
   SetArmourClass(ARMOUR_CLOTH);
   SetArmourType(A_PANTS);
   SetDamagePoints(240);
   // SetProtection(BLUNT,5);
   // SetProtection(SLASH,4);
   // SetProtection(PIERCE,4);
   // SetProtection(COLD,3);
   // SetProtection(HEAT,1);
   // SetProtection(WATER,7);
   SetWear("The pants are rough and tough.");
   SetMaterial( ({ "leather" }) );
   SetWarmth(20);
   SetRepairDifficulty(39);
   SetRepairSkills( ([
                       "leather working" : 3,
                  ]) );
   SetProperty("history","These pants were the property of a fisherman.");
}
