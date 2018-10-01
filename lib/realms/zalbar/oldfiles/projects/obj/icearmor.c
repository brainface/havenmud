// Written by Vanyel
#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
//#include "ice.h"

inherit LIB_ARMOUR;

mixed CanRepair(object who)
    	{return "You cannot repair ice!";}
    

static void create() {
    armour::create();
    SetKeyName("ice armour");
    SetId( ({ "armour" }) );
    SetAdjectives( ({ "ice","enchanted", "magic" }) );
    SetShort("ice armour");
    SetLong("Blue and cold, this enchanted suit of armour is entirely "
         "made of ice.  It can absorb the coldest attacks without damage. "
         "It glows with magic, keeping the ice cool by letting heat through.");
    SetVendorType(VT_ARMOUR);
    SetMass(300);
    SetMaterial( ({ "natural" }) );
    SetArmourClass(ARMOUR_NATURAL);
    SetProperty("laoise_flag", 1);
    SetWarmth(-20);
    SetValue(700);
    SetDamagePoints(700);
    // SetProtection(BLUNT, 7);
    // SetProtection(SLASH, 7);
    // SetProtection(PIERCE, 5);
    // SetProtection(HEAT, -2);
    // SetProtection(COLD, 10);
    // SetProtection(SHOCK, 1);
    // SetProtection(WATER, 10);
    // SetProtection(ACID, 2);
    // SetProtection(MAGIC, 5);
    SetRestrictLimbs( ({ "torso", "right arm", "left arm" }) );
    SetProperty("magic", 
    	"The enchantment on this suit of armor "
    	"blocks most magic, but lets fire pass through.");
    SetArmourType(A_ARMOUR);
    SetSize(SIZE_LARGE);
}


/* Approved by Balishae on Sat Oct  4 23:48:28 1997. */
