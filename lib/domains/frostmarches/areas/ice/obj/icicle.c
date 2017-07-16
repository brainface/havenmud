// Written by Vanyel
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("icicle");
  SetId( ({ "icicle" }) );
  SetAdjectives( ({ "sharp", "magic", "enchanted" }) );
  SetShort("a sharp icicle");
  SetLong("Wickedly sharp, this nine inch long icicle is "
    "wonderful for stabbing someone with.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(750);
  SetClass(18);
  SetValue(750);
  SetMass(30);
    SetMaterial( ({ "natural" }) );
  SetWeaponType("knife");
  SetProperty("magic", "This enchanted icicle does cold damage as "
    "well as pierce.");
  SetDamageType(PIERCE | COLD);
}


/* Approved by Balishae on Sat Oct  4 23:46:38 1997. */
