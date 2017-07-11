// Amelia@Haven

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
 
static void create() {
   item::create();
   SetKeyName("rock");
   SetId( ({ "rock", }) );
   SetAdjectives( ({ "sharp" }) );
   SetShort("a sharp rock");
   SetLong("This rock is rather sharp, and dark in color.  "
           "It is sharp on one edge, the other edge being "
           "soft and rounded, easy to grip.  It would be "
           "easy to use in a slash type motion.  Little "
           "points on the sharp edge would pierce one's "
           "opponent during attack, as well.");
   SetMass(155);
   SetValue(5);
   SetVendorType(VT_WEAPON);
   SetClass(5);
   SetWeaponType("slash");
   SetDamageType(SLASH|PIERCE);
   SetDamagePoints(200);
   SetDestroyOnSell(1);
   SetWield("The sharp rock fits comfortably in your hand.");
   SetMaterial( ({ "natural" }) );
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "stone working" : 0,
                  ]) );
   SetProperty("history","This rock is from the Estergrym "
               "Mountains.");
}
