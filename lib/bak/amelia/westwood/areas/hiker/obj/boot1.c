#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("patched boot");
   SetShort("a patched boot");
   SetId( ({ "boot","patch","patches" }) );
   SetSize(SIZE_MEDIUM);
   SetAdjectives( ({ "patched","leather","colored" }) );
   SetLong("The boot is covered with various mismatched patches that "
           "show years of use and repair.  It seems to be good, tough "
           "leather all over, however, despite the strange colors to "
           "it.");
   SetMass(50);
   SetValue(90);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_BOOT);
   SetProperty("multiples",0);
   SetDamagePoints(250);
   SetProtection(BLUNT,5);
   SetProtection(SLASH,4);
   SetProtection(PIERCE,5);
   SetProtection(HEAT,1);
   SetProtection(ACID,1);
   SetProtection(WATER,3);
   SetProtection(COLD,5);
   SetMaterial( ({ "leather" }) );
  SetWarmth(5);
   SetRepairDifficulty(17);
   SetRepairSkills( ([
                       "leather working" : 1,
                       "armour smithing" : 0,
                  ]) );
}
