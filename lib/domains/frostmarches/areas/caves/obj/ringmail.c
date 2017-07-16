#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("ring vest");
    SetId( ({ "mail", "vest", "ringmail" }) );
    SetAdjectives( ({ "ring", "mail", }) );
    SetShort("a ring mail vest");
    SetLong("This is a leather vest with metal rings sewn into it.");
    SetMass(400);
    SetArmourClass(ARMOUR_REINFORCED);
    SetSize(SIZE_SMALL);
    SetValue(70);
    SetDamagePoints(550);
    // SetProtection(SLASH, 6);
    // SetProtection(BLUNT, 2);
    // SetProtection(PIERCE, 3);
    SetArmourType(A_VEST);
    SetMaterial( ({
    	"leather",
    	"metal"
      }) );
    SetWarmth(10);
    SetRepairSkills( ([
      "leatherworking" : 1,
      "armour smithing" : 1,
      ]) );
    SetRepairDifficulty(15);
    SetVendorType(VT_ARMOUR);
}
