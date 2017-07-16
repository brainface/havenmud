#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shining circlet");
   SetShort("a shining circlet");
   SetId( ({ "circlet" }) );
   SetAdjectives( ({ "shining" }) );
   SetLong("The circlet looks like metal leaves melded together in "
           "a circle that is to go around one's head.  It shines with "
           "a joyous light.");
   SetMass(30);
   SetValue(1500);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_HELMET);
   SetDamagePoints(950);
   SetProtection(BLUNT,17);
   SetProtection(SLASH,17);
   SetProtection(PIERCE,17);
   SetProtection(HEAT,17);
   SetProtection(COLD,17);
   SetProtection(SHOCK,17);
   SetProtection(ACID,17);
   SetProtection(GAS,17);
   SetProtection(DISEASE,17);
   SetProtection(POISON,17);
   SetProtection(WATER,17);
   SetProtection(MAGIC,17);
   SetWear("The circlet shines as you wear it.");
   SetMaterial( ({ "metal" }) );
  SetWarmth(0);
   SetProperty("magic","This circlet has been blessed by Amelia, the "
               "Goddess of Good, to protect her followers.");
   SetProperty("history","Amelia, the Goddess of Good, blessed this "
               "circlet and then gave it to her druids so they might "
               "be protected.");
   SetSize(SIZE_SMALL);
}
