#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shirt");
   SetShort("a white shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "white" }) );
   SetLong("The shirt is nothing special; it was made from a "
           "stiff, white fabric.  It would offer a little "
           "protection from the elements and cover one's "
           "torso and arms, if one chose to wear it.");
   SetMass(10);
   SetValue(25);
   SetSize(SIZE_MEDIUM);
   SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_SHIRT);
   SetDamagePoints(50);
   // SetProtection(BLUNT,1);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   // SetProtection(COLD,2);
   // SetProtection(HEAT,1);
   SetWear("The shirt is stiff.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(10);
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetProperty("history","It used to be the property of Magnum, Parva Banker.");
}
