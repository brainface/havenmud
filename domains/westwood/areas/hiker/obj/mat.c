#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetSize(SIZE_SMALL);
   SetKeyName("grass mat");
   SetShort("a grass mat");
   SetId( ({ "mat","grass" }) );
   SetAdjectives( ({ "grass" }) );
   SetLong("The mat is woven out of fresh, green grass.  It looks like "
           "it was once worn on someone's head; some short hair is "
           "caught in it.");
   SetMass(5);
   SetValue(2);
   SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_HELMET); 
   SetDamagePoints(50);
   // SetProtection(BLUNT,1);
   // SetProtection(PIERCE,1);
   // SetProtection(SLASH,1);
   // SetProtection(COLD,1);
   SetMaterial( ({ "natural" }) );
   SetWarmth(3);
   SetRepairDifficulty(3);
   SetRepairSkills( ([
                       "natural working" : 1,
                  ]) );
}
