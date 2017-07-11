#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("leather vest");
    SetId( ({"vest", "armour"}) );
    SetAdjectives("leather");
    SetShort("a leather vest");
    SetLong("An armoured vest made of boiled leather and wood slats.");
    SetMass(500);
    SetSize(SIZE_SMALL);
    SetValue(80);
    SetDamagePoints(600);
    SetArmourClass(ARMOUR_REINFORCED);
    // SetProtection(SLASH, 4);
    // SetProtection(BLUNT, 2);
    // SetProtection(PIERCE, 1);
    SetArmourType(A_VEST);
    SetMaterials( ({
    	"leather",
    	"wood",
      }) );
    SetWarmth(10);
    SetRepairSkills( ([
      "leather working" : 1,
      "armour smithing" : 1,
      ]) );
    SetRepairDifficulty(20);
    SetVendorType(VT_ARMOUR);
}
