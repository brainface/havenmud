/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: flame_sword.c
// Author: Matt Moran
// Immortal: Aagar@Haven
// Creation Date: Unknown
// Abstract: A sword of Flame for Aagron
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
    item::create();
  SetKeyName("flaming sword");
  SetId( ({ "sword", "broadsword"}) );
  SetAdjectives( ({  "broad", "flame", "flaming"} ) );
  SetShort("a flaming broadsword");
  SetLong(
    "At a length of about fourteen feet, this divine weapon burns with "
    "an eternal, elemental flame.  It's power is bestowed by the Lord "
    "of Elemental Energies, and has tremendous destructive power.  The air "
    "around the sword wavers from the tremendous heat produced by the "
    "broadsword.");

  SetVendorType(VT_WEAPON);
  SetDamagePoints(10000);
  SetValue(2000);
  SetClass(20);
  SetMass(1200);
  SetWeaponType("slash");
  SetDamageType(SLASH|HEAT);
  SetMaterial ( ({ "mithril" }) );
}
