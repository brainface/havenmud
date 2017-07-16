// Written by Vanyel
#include <lib.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "ice.h"

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("skates");
    SetId( ({ "skates", "skate" }) );
    SetAdjectives( ({ "ice", "sharp" }) );
    SetShort("ice skates");
    SetLong("Equipped with sharp blades on the bottom of sturdy boots, "
         "these ice skates are perfect for skating on a frozen lake.");
    SetVendorType(VT_ARMOUR);
    SetMass(50);
  SetArmourClass(ARMOUR_LEATHER);
    SetMaterial( ({ "metal", "leather" }) );
  SetSize(SIZE_MEDIUM);
    SetWarmth(10);
    SetValue(100);
    SetDamagePoints(300);
    // SetProtection(BLUNT, 2);
    // SetProtection(SLASH, 2);
    // SetProtection(PIERCE, 2);
    // SetProtection(COLD, 10);
    // SetProtection(MAGIC, 1);
    SetArmourType(A_BOOT);
    SetProperty("multiples", 1);
}


/* Approved by Balishae on Sat Oct  4 23:46:00 1997. */
