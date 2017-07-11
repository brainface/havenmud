#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() { 
   armour::create();
   SetKeyName("robe");
   SetShort("a shimmering robe");
   SetId( ({ "robe" }) );
   SetAdjectives( ({ "shimmering","eclat","eclatish" }) );
   SetLong("The robe glistens with light and life, and an aura of joy seems "
           "to surround it.  Dyed a pure, soft white, it shimmers and "
           "sparkles.");
   SetMass(60);
   SetVendorType(VT_CLOTHING|VT_TREASURE|VT_MAGIC);
   SetValue(850);
   SetArmourType(A_CLOAK);
   SetArmourClass(ARMOUR_CLOTH);
   SetDamagePoints(800);
   // SetProtection(BLUNT,13);
   // SetProtection(SLASH,13);
   // SetProtection(PIERCE,13);
   // SetProtection(WATER,13);
   // SetProtection(SHOCK,13);
   // SetProtection(COLD,13);
   // SetProtection(HEAT,13);
   // SetProtection(ACID,13);
   // SetProtection(GAS,13);
   // SetProtection(MAGIC,13);
   // SetProtection(DISEASE,13);
   // SetProtection(POISON,13);
   SetSize(SIZE_SMALL);
   SetProperty("magic","This robe was blessed by Amelia, the Goddess of "
               "Goodness, to protect her followers.");
   SetProperty("history","Amelia, the Goddess of Good, blessed this robe "
               "among other, similar ones, and gave them to Kiee to "
               "distribute to her faithful.  Kiee gave them to the "
               "doctors, determined to work far from the protection of "
               "the WestWood, so that they may help the poor Parvans "
               "near the ocean.");
   SetWear("The robe feels warm and comforting.");
   SetMaterial( ({ "textile" }) );
   SetRepairDifficulty(20);
   SetWarmth(20);
}
