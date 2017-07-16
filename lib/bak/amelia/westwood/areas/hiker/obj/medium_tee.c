#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("floppy tee-shirt");
   SetShort("a floppy tee-shirt");
   SetId( ({ "tee-shirt","tee","shirt","tee shirt" }) );
   SetAdjectives( ({ "floppy","thin","blue","green" }) );
   SetLong("The tee-shirt is made of thin material, and is mostly white "
           "with some swirling designs in blue and green.");
   SetMass(20);
   SetValue(15);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_VEST);
   SetDamagePoints(125);
   SetProtection(SLASH,1);
   SetProtection(PIERCE,1);
   SetProtection(BLUNT,1);
   SetProtection(COLD,2);
   SetProtection(HEAT,1);
   SetProtection(ACID,1);
   SetMaterial( ({ "textile" }) );
   SetWarmth(8);
   SetRepairDifficulty(1);
   SetRepairSkills( ([
                       "textile working" : 1,
                       "armour smithing" : 1,
                  ]) );
   SetSize(SIZE_MEDIUM);
}
