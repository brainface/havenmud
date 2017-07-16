#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_SMELL;
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("belt");
   SetShort("a pretty green belt");
   SetId( ({ "belt" }) );
   SetAdjectives( ({ "pretty","green" }) );
   SetLong("The belt is made of a strip of green cloth.  "
           "It is a nice sea-green color.  It wouldn't "
           "do much to protect one, but it would keep "
           "one's clothes together.");
   SetMass(2);
   SetValue(5);
   SetVendorType(VT_CLOTHING);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetArmourType(A_BELT);
   SetDamagePoints(5);
   // SetProtection(BLUNT,1);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   // SetProtection(COLD,1);
   SetSmell("The belt stinks of fish and the ocean.");
   SetWear("It's a little damp and wet.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(0);
   SetRepairDifficulty(3);
   SetRepairSkills( ([
                       "textile working" : 0,
                  ]) );
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
