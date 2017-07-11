#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("skirt");
   SetShort("a short black skirt");
   SetId( ({ "skirt" }) );
   SetAdjectives( ({ "short","black" }) );
   SetLong("The black skirt is very short and revealing.  "
           "It was made from a soft, warm, black material.");
   SetMass(5);
   SetValue(15);
   SetSize(SIZE_MEDIUM);
   SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_PANTS);
   SetDamagePoints(45);
   // SetProtection(BLUNT,1);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   // SetProtection(COLD,1);
   // SetProtection(HEAT,1);
   SetWear("The skirt is awfully short.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(10);
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetProperty("history","It used to be the property of Pecunia, "
               "a barmaid in Parva and the leader of their rogues.");
}
