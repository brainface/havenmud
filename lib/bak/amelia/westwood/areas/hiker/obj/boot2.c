#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("brown leather boot");
   SetShort("a brown leather boot");
   SetId( ({ "boot","leather" }) );
   SetAdjectives( ({ "brown","leather" }) );
   SetSize(SIZE_MEDIUM);
   SetLong("The boot is made of tough leather, softened so that it "
           "doesn't cause blisters on one's feet.");
   SetMass(50);
   SetValue(130);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_BOOT);
   SetProperty("multiples",0);
   SetDamagePoints(300);
   SetProtection(BLUNT,6);
   SetProtection(SLASH,5);
   SetProtection(PIERCE,6);
   SetProtection(HEAT,1);
   SetProtection(ACID,1);
   SetProtection(WATER,3);
   SetProtection(COLD,6);
   SetMaterial( ({ "leather" }) );
  SetWarmth(5);
   SetRepairDifficulty(20);
   SetRepairSkills( ([
                       "leather working" : 1,
                       "armour smithing" : 0,
                  ]) );
}
