#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shirt");
   SetShort("a small black shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "short","black" }) );
   SetLong("The black shirt was small and tight, but made from "
           "a warm, stretchy material.");
   SetMass(5);
   SetValue(19);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourClass(ARMOUR_CLOTH);
   SetArmourType(A_SHIRT);
   SetDamagePoints(45);
   // SetProtection(BLUNT,1);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   // SetProtection(COLD,5);
   // SetProtection(HEAT,1);
   SetWear("The shirt is warm.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(10);
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetProperty("history","It used to be the property of Pecunia, "
               "a barmaid in Parva and the leader of their rogues.");
}
