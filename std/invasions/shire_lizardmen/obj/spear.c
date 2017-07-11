// Lizardman invasion of Lloryk
// Duuk

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("primitive spear");
  SetShort("a primitive wooden spear");
  SetId( ({ "spear" }) );
  SetAdjectives( ({ "primitive", "wooden" }) );
  SetLong(
    "This short wooden spear seems someone effective as a weapon. "
    "It is mainly used by the primitive tribes of lizardmen from "
    "the swamps of Gwonish."
  );
  SetVendorType(VT_WEAPON);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetClass(13);
  SetDamagePoints(1200);
  SetValue(60);
  SetMass(60);
  SetHands(1);
  SetMaterials( ({ "wood" }) );
}
