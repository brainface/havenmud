#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("boots");
   SetShort("a pair of waterproof boots");
   SetId( ({ "boots" }) );
   SetAdjectives( ({ "pair of","waterproof" }) );
   SetLong("These boots were made of some durable animal skin "
           "sewed together so tightly and cleverly as to "
           "allow little water to seep in, even when walking "
           "in a stream.");
   SetMass(50);
   SetValue(105);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_BOOT);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetProperty("multiples", 1);
   SetDamagePoints(340);
   // SetProtection(BLUNT,5);
   // SetProtection(SLASH,4);
   // SetProtection(PIERCE,5);
   // SetProtection(COLD,5);
   // SetProtection(HEAT,2);
   // SetProtection(WATER,9);
   SetWear("The boots aren't easy to pull on.");
   SetMaterial( ({ "leather" }) );
   SetWarmth(7);
   SetRepairDifficulty(39);
   SetRepairSkills( ([
      "leather working" : 3,
      ]) );
   SetProperty("history","These boots were the property of a fisherman.");
}
