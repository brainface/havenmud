#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shimmering shirt");
   SetShort("a shimmering shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "eclat","eclatish","shimmering" }) );
   SetLong("Though made of simple, home-spun cloth, the shirt "
           "shine with a special radiance.");
   SetMass(40);
   SetValue(550);
   SetSize(SIZE_SMALL);
   SetVendorType(VT_TREASURE|VT_MAGIC|VT_ARMOUR);
   SetArmourType(A_SHIRT);
   SetDamagePoints(700);
   SetProtection(BLUNT,9);
   SetProtection(SLASH,9);
   SetProtection(PIERCE,9);
   SetProtection(WATER,9);
   SetProtection(SHOCK,9);
   SetProtection(COLD,9);
   SetProtection(HEAT,9);
   SetProtection(GAS,9);
   SetProtection(ACID,9);
   SetProtection(MAGIC,9);
   SetProtection(DISEASE,9);
   SetProtection(POISON,9);
   SetMaterial( ({ "textile" }) );
  SetWarmth(15);
   SetWear("The shirt glitters as you put it on.");
   SetProperty("magic","Amelia, the Goddess of Good, has blessed this "
               "shirt with her magical powers that it might protect "
               "her servants.");
   SetProperty("history","This robe was once worn by Eclatish monks in "
               "the WestWood, and was given to them especially for the "
               "purpose of protecting them.");
}
