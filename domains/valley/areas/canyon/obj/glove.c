#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
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
   // SetProtection(BLUNT,2);
   // SetProtection(SLASH,2);
   // SetProtection(PIERCE,2);
   // SetProtection(COLD,1);
   // SetProtection(HEAT,1);
   // SetProtection(ACID,1);
   SetMaterial( ({ "leather" }) );
   SetWarmth(5);
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "leather working" : 1,
                       "armour smithing" : 1,
                  ]) );
}


/* Approved by Zaxan on Sat Jan 17 02:42:00 1998. */
