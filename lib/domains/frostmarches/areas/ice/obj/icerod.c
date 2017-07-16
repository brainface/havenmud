// Written by Vanyel
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("ice rod");
    SetId( ({ "rod" }) );
    SetAdjectives( ({ "ice", "magic", "enchanted" }) );
    SetShort("an ice rod");
    SetLong("Enchanted, this foot-long rod is frozen solid, raining "
       "icy terror upon its target.");
    SetVendorType(VT_WEAPON);
    SetDamagePoints(400);
    SetClass(10);
    SetValue(500);
    SetMass(30);
    SetMaterial( ({ "natural" }) );
    SetWeaponType("pole");
  SetProperty("magic", "This enchanted rod does cold damage as "
    "well as blunt.");
    SetDamageType(BLUNT | COLD);
}


/* Approved by Balishae on Sat Oct  4 23:47:14 1997. */
