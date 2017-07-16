#include <size.h>
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("jacket");
   SetShort("a light white jacket");
   SetId( ({ "jacket","windbreaker","wind breaker","breaker","coat" }) );
   SetSize(SIZE_SMALL);
   SetAdjectives( ({ "leather","light","white","thin" }) );
   SetLong("The light white jacket is a thin coat made out of "
           "leather meant only to block the fierce wind.");
   SetMass(20);
   SetValue(10);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_SHIRT); // ?
   SetProtection(COLD,4);
   SetProtection(BLUNT,1);
   SetProtection(SLASH,1);
   SetProtection(PIERCE,1);
   SetProtection(ACID,1);
   SetProtection(WATER,1);
   SetProtection(HEAT,2);
   SetMaterial( ({ "leather" }) );
  SetWarmth(7);
   SetRepairDifficulty(2);
   SetRepairSkills( ([
                       "armour smithing" : 1,
                       "leather working" : 1,
                  ]) );
}
