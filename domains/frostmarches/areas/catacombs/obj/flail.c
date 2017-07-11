#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("flail");
  SetId( ({ "flail" }) );
  SetAdjectives( ({ "heavy", "obsidian" }) );
  SetShort("a heavy obsidian flail");
  SetLong("A large obsidian chunk dangles from a metal"
          " chain that is attached to a wooden grip."
          " It looks very heavy. A slight glow shines"
          " in the center of the obsidian piece.");
  SetClass(21);
  SetDamagePoints(1000);
  SetValue(1000);
  SetWeaponType("blunt");
  SetDamageType(BLUNT | MAGIC);
  SetMass(25);
  SetMaterial( ({ "metal", "natural" }) );
  SetVendorType(VT_WEAPON);
}
