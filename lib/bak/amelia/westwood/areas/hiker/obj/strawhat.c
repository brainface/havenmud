#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetSize(SIZE_SMALL);
   SetKeyName("straw hat");
   SetShort("a straw hat");
   SetId( ({ "hat","straw" }) );
   SetAdjectives( ({ "straw" }) );
   SetLong("The straw hat is simple, but has a plain red ribbon tied "
           "around it for decoration.");
   SetMass(15);
   SetValue(5);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_HELMET);
   SetDamagePoints(85);
   SetProtection(SLASH,1);
   SetProtection(BLUNT,2);
   SetProtection(PIERCE,1);
   SetProtection(COLD,2);
   SetMaterial( ({ "natural","textile" }) );
   SetWarmth(5);
   SetRepairDifficulty(4);
   SetRepairSkills( ([
                       "natural working" : 1,
                       "textile working" : 1,
                       "armour smithing" : 0,
                  ]) );
}
