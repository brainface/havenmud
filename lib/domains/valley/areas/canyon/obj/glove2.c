#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("green glove");
   SetShort("a green glove");
   SetId( ({ "glove" }) );
   SetAdjectives( ({ "green" }) );
   SetLong("The green glove appears to be basic leather with green "
           "dyes added.");
   SetMass(9);
   SetValue(12);
   SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_GLOVE);
   SetDamagePoints(120);
   // SetProtection(BLUNT,4);
   // SetProtection(SLASH,4);
   // SetProtection(PIERCE,4);
   // SetProtection(COLD,3);
   // SetProtection(HEAT,3);
   // SetProtection(ACID,3);
   SetMaterial( ({ "leather" }) );
   SetWarmth(5);
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "leather working" : 2,
                       "armour smithing" : 2,
                  ]) );
}


/* Approved by Zaxan on Sat Jan 17 02:42:02 1998. */
