#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shimmering pants");
   SetShort("a pair of shimmering pants");
   SetId( ({ "pants","pair of pants","pair of shimmering pants" }) );
   SetAdjectives( ({ "shimmering" }) );
   SetLong("The pants are loose and wavy, shining some in the light, "
           "even though they appear to be made of simple cloth.");
   SetMass(30);
   SetValue(400);
   SetVendorType(VT_ARMOUR|VT_MAGIC|VT_TREASURE);
   SetArmourType(A_PANTS);
   SetDamagePoints(800);
   // SetProtection(BLUNT,7);
   // SetProtection(SLASH,7);
   // SetProtection(PIERCE,7);
   // SetProtection(HEAT,7);
   // SetProtection(COLD,7);
   // SetProtection(SHOCK,7);
   // SetProtection(ACID,7);
   // SetProtection(GAS,7);
   // SetProtection(DISEASE,7);
   // SetProtection(POISON,7);
   // SetProtection(WATER,7);
   // SetProtection(MAGIC,7);
   SetMaterial( ({ "textile" }) );
   SetArmourClass(ARMOUR_CLOTH);
  SetWarmth(20);
  SetSize(SIZE_SMALL);
   SetWear("The pants shine as you put them on.");
   SetProperty("magic","Amelia, the Goddess of Good, has blessed these "
               "pants to protect her faithful.");
   SetProperty("history","The monks of the Eclat faith received these "
               "pants from their Goddess, Amelia, so that they might "
               "be better protected.");
}
