// Written by Vanyel
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "ice.h"

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("ice robes");
  SetId( ({  "robe", "robes" }) );
  SetAdjectives( ({ "ice",  "enchanted", "magic" }) ); 
  SetShort("ice robes");
  SetLong("Frigid with the white frost, this magical robe is "
    "very comfortable, but not very flexible. ");
  SetVendorType(VT_ARMOUR);
  SetMass(100);
    SetMaterial( ({ "natural" }) );
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_NATURAL);
  SetWarmth(0);
  SetValue(500);
  SetDamagePoints(400);
  // SetProtection(BLUNT, 3);

  // SetProtection(SLASH, 3);
  // SetProtection(PIERCE, 2);
  // SetProtection(COLD, 10);
  // SetProtection(SHOCK, 3);
  // SetProtection(WATER, 10);
  // SetProtection(ACID, 5);
  // SetProtection(MAGIC, 10);
  SetRestrictLimbs( ({ "torso", "right arm", "left arm", 
    "right leg", "left leg" }) );
  SetProperty("magic", "The enchantment on these robes protect "
    "against most kinds of magic.");
  SetArmourType(A_BODY_ARMOUR);
}


/* Approved by Balishae on Sat Oct  4 23:47:56 1997. */
