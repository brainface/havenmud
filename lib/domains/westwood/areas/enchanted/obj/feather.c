// Amelia@Haven

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;
 
static void create() {
   armour::create();
   SetKeyName("feather");
   SetId( ({ "feather","white feather" }) );
   SetAdjectives( ({ "white" }) );
   SetShort("a white feather");
   SetLong("The soft white feather is long enough that it could be easily "
	"slipped into someone's hair, though it would provide little to no "
	"protection against anything.");
   SetMass(1);
   SetValue(20);
   SetArmourClass(ARMOUR_CLOTH);
   SetDamagePoints(100);
   // SetProtection(BLUNT,1);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   SetWarmth(2);
   SetArmourType(A_HELMET);
   SetMaterial( ({ "natural" }) );
   SetRepairSkills( ([ "natural working" : 1, ]) );
   SetRepairDifficulty(1);
    SetVendorType(VT_CLOTHING);
}
