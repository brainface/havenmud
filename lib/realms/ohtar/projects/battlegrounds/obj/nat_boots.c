#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("boots");
  SetId(( {"clay", "hardened", "boots", "hardened clay" } ));
  SetShort("a pair of hardened clay boots");
  SetAdjectives( ({"clay", "hardened", "boots", "hardened clay"}) );
  SetLong(
    "These hardened clay boots appear to be very rugged. These "
    "particular boots were set around a mold of a foot and covered "
    "with a certain type of clay from the wilderness. This clay was "
    "then drnched in a liquid that cause it to harden like stone and "
    "then torched at a very high temperature. It has only ever been "
    "seen once before on an ancient goddess of the woods. They provide "
    "very little in the temperature area as they are only lined with a "
    "fine animal skin however there actual physical protection is like "
    "that of most metal made boots."
  );   
  SetProperty("multiples", 1);
  SetMass(180);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_MEDIUM);
  SetMaterial("natural");
  SetWarmth(1);
  SetRepairDifficulty(40);
  SetValue(1500);
  SetDamagePoints(2500);
  SetArmourType(A_BOOT);  
}
