#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("warm brown pants");
   SetShort("a pair of warm brown pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "pair of","warm","brown" }) );
   SetLong("The pants are made of a soft brown cloth.  They appear "
           "to be very warm, and will probably fight off the effects "
           "of cold nicely.");
   SetMass(50);
   SetValue(13);
   SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_PANTS);
   SetDamagePoints(250);
   // SetProtection(PIERCE,2);
   // SetProtection(SLASH,2);
   // SetProtection(BLUNT,2);
   // SetProtection(ACID,2);
   // SetProtection(COLD,10);
   SetMaterial( ({ "textile" }) );
   SetRepairDifficulty(3);
   SetRepairSkills( ([
                       "armour smithing" : 1,
                       "textile working" : 1,
                  ]) );                      
   SetWear("The insides of the pants feel warm and comfortable.");
}
