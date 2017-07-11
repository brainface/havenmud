#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("shaman garb");
    SetId( ({"garb", "armour"}) );
    SetAdjectives( ({"shaman", "shamanic"}) );
    SetShort("a shaman's garb");
    SetLong("This is a shaman's garb composed of cloth and leather, with "
            "appropriate markings.");
    SetMass(90);
    SetSize(SIZE_SMALL);
    SetMaterial( ({
    	"textile",
    	"leather"
      }) );
    SetRepairDifficulty(5);
    SetArmourClass(ARMOUR_LEATHER);
    SetWarmth(20);
    SetValue(50);
    SetDamagePoints(400);
    // SetProtection(SLASH, 3);
    // SetProtection(BLUNT, 3);
    // SetProtection(PIERCE, 1);
    SetArmourType(A_CLOAK);
    SetVendorType(VT_ARMOUR);
}
