#include <size.h>
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetSize(SIZE_SMALL);
   SetKeyName("plain visor");
   SetShort("a plain visor");
   SetId( ({ "visor","hat","cap" }) );
   SetAdjectives( ({ "plain" }) );
   SetLong("Stretchy cloth goes around from the bill of the visor to a "
           "clasp which holds it on one's head.  The bill is stiff but "
           "still slightly flexible.");
   SetMass(10);
   SetValue(15);
   SetProtection(SLASH,2);
   SetProtection(BLUNT,1);
   SetProtection(PIERCE,2);
   SetProtection(COLD,1);
   SetProtection(HEAT,1);
   SetProtection(ACID,1);
   SetDamagePoints(150);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_HELMET);
   SetMaterial( ({ "textile" }) );
   SetWarmth(3);
   SetRepairDifficulty(2);
   SetRepairSkills( ([
                       "textile working" : 1,
                       "armour smithing" : 1,
                  ]) );
}
