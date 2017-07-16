#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include "../skaven.h"

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("greaves");
    SetId( "greaves"  );
    SetAdjectives( ({ "spiked", "arm" }) );
    SetShort("spiked arm greaves");
    SetLong(
      "A set of fairly elaborate metal arm greaves covered, "
      "in small spikes.  They are painted red and "
      "fastened with thick leather straps."
      );
    SetMaterial( ({ "metal" }) );
    SetWarmth(0);
    SetRepairSkills( ([
      "metal working" : 5,
      "armour smithing" : 5,
      ]) );
    SetRepairDifficulty(8);                  
    SetArmourClass(ARMOUR_REINFORCED);
    SetSize(SIZE_MEDIUM);
    SetVendorType(VT_ARMOUR);
    SetValue(250);
    SetMass(100);
    SetDamagePoints(1000);
    // SetProtection(BLUNT, 5);
    // SetProtection(SLASH, 8);
    // SetProtection(PIERCE, 5);
    // SetProtection(WATER, 1);
    // SetProtection(COLD, 1);
    // SetProtection(HEAT, 1);
    // SetProtection(SHOCK, 0);
    // SetProtection(ACID, 1);
    SetArmourType(A_ARMOUR);
    SetRestrictLimbs( ({ "left arm", "right arm" }) );
    SetWear("The greaves fit well, but make a great deal of noise.");
}
