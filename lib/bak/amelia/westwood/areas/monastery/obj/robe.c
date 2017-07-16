#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() { 
   armour::create();
   SetKeyName("glimmering robe");
   SetShort("a glimmering robe");
   SetId( ({ "robe" }) );
   SetAdjectives( ({ "glimmering","eclat","eclatish" }) );
   SetLong("The robe seems to shine with joy and faith with its "
           "light demeaner.  It is made of a thin, light-weight "
           "cloth and stained pure white.");
   SetMass(80);
   SetVendorType(VT_ARMOUR|VT_TREASURE|VT_MAGIC);
   SetValue(850);
   SetArmourType(A_CLOAK);
   SetDamagePoints(850);
   SetProtection(BLUNT,13);
   SetProtection(SLASH,13);
   SetProtection(PIERCE,13);
   SetProtection(WATER,13);
   SetProtection(SHOCK,13);
   SetProtection(COLD,13);
   SetProtection(HEAT,13);
   SetProtection(ACID,13);
   SetProtection(GAS,13);
   SetProtection(MAGIC,13);
   SetProtection(DISEASE,13);
   SetProtection(POISON,13);
   SetProperty("magic","This robe was blessed by Amelia, the Goddess of "
               "Good, to protection her followers.");
   SetProperty("history","Amelia, the Goddess of Good, blessed this robe "
               "long ago and gave it to her monks and healers for "
               "protection.");
   SetWear("The robe twinkles as you put it on.");
   SetMaterial( ({ "textile" }) );
  SetWarmth(25);
   SetSize(SIZE_SMALL);
}
