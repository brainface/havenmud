#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("boots");
   SetShort("a pair soft leather boots");
   SetId( ({ "boots" }) );
   SetAdjectives(  ({ "soft", "leather" })  );
   SetLong("The boots are made of soft leather and "
           "look quite comfortable.");
   SetMass(75);
   SetValue(50);
   SetArmourClass(ARMOUR_LEATHER);
   SetSize(SIZE_MEDIUM);
   SetMaterial("leather");
   SetRepairDifficulty(10);
   SetWarmth(5);
   SetDamagePoints(900);
        // SetProtection(COLD, 2);
        // SetProtection(HEAT, 2);
        // SetProtection(SHOCK, 2);
        // SetProtection(WATER, 2);
        // SetProtection(ACID, 2);
        // SetProtection(BLUNT, 5);
        // SetProtection(SLASH, 5);
        // SetProtection(PIERCE, 5);
   SetArmourType(A_BOOT);
   SetVendorType(VT_ARMOUR);
}
