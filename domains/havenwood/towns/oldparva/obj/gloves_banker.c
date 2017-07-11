#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("gloves");
   SetShort("a set of black gloves");
   SetId( ({ "gloves","glove" }) );
   SetAdjectives( ({ "black","leather","set of" }) );
   SetLong("The black leather gloves look plenty large enough "
           "to fit most people's hands.  They are plain and "
           "the leather looks a little old.");
   SetMass(5);
   SetValue(35);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourClass(ARMOUR_CLOTH);
   SetArmourType(A_GLOVE);
   SetDamagePoints(120);
   // SetProtection(BLUNT,3);
   // SetProtection(SLASH,2);
   // SetProtection(PIERCE,3);
   // SetProtection(COLD,4);
   // SetProtection(HEAT,2);
   SetWear("The gloves slip on, rubbing against skin.");
   SetMaterial( ({ "leather" }) );
   SetWarmth(5);
   SetRepairDifficulty(9);
   SetRepairSkills( ([
                       "leather working" : 1,
                  ]) );
   SetProperty("history","It used to be the property of Magnum, Parva Banker.");
   SetProperty("multiples",1);
   SetRestrictLimbs( ({ "right hand","left hand" }) );
}
