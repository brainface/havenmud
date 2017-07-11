#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include "../skaven.h"

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("helmet");
    SetId( ({ "helmet", "spiked helmet" }) );
    SetShort("a spiked metal helmet");
    SetLong("This is a small metal helmet shaped like a bowl "
            "with a solitary bronze spike on the top of it.  "
          	"It is painted red and comes complete with chin strap.");
    SetMaterial( ({ "metal" }) );
    SetWarmth(0);
    SetRepairSkills( ([
    	"metal working" : 4,
      "armour smithing" : 4,
      ]) );
    SetRepairDifficulty(6);                  
    SetVendorType(VT_ARMOUR);
    SetSize(SIZE_MEDIUM);
    SetArmourClass(ARMOUR_PLATE);
    SetValue(150);
    SetMass(80);
    SetDamagePoints(900);
    // SetProtection(BLUNT, 4);
    // SetProtection(SLASH, 8);
    // SetProtection(PIERCE, 4);
    // SetProtection(WATER, 1);
    // SetProtection(COLD, 1);
    // SetProtection(HEAT, 1);
    // SetProtection(SHOCK, 0);
    // SetProtection(ACID, 1);
    SetArmourType(A_HELMET);
    SetRestrictLimbs( ({ "head" }) );
    SetWear("This helmet does not quite fit right, but should do.");
}
