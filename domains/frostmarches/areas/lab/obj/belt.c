#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("straw belt");
   SetShort("a straw belt");
   SetId( "belt" );
   SetAdjectives( ({ "straw" }) );
   SetLong("This belt is made simply of tightly braided straw and "
           "other herbs.");
   SetMass(6);
   SetSize(SIZE_SMALL);
   SetValue(11);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_BELT);
   SetDamagePoints(230);
  SetArmourClass(ARMOUR_CLOTH);
   SetMaterial( ({ "natural" }) );
   SetWarmth(2);
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "natural working" : 1,
                       "armour smithing" : 1,
                  ]) );
}
