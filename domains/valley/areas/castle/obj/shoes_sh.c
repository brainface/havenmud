#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shiny shoes");
   SetShort("a pair of shiny shoes");
   SetId( ({ "pair","shoes","shoe" }) );
   SetAdjectives( ({ "pair of","shiny","well-polished","polished",
                     "black" }) );
   SetLong("A bit of light shines of these well-polished black shoes, "
           "looking as if they belonged to a young boy.");
   SetMass(20);
   SetValue(10);
  SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_BOOT);
   SetProperty("multiples",1);
   SetDamagePoints(250);
   // SetProtection(PIERCE,6);
   // SetProtection(SLASH,6);
   // SetProtection(BLUNT,9);
   // SetProtection(COLD,5);
   // SetProtection(ACID,2);
   // SetProtection(HEAT,2);
   SetMaterial( ({ "leather" }) );
   SetRepairDifficulty(4);
   SetRepairSkills( ([
                       "leather working" : 1,
                       "armour smithing" : 1,
                  ]) );
   SetSize(SIZE_SMALL);
}
