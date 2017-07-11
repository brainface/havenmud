#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("primitive spear");
  SetClass(13);
  SetDamagePoints(1200);
  SetValue(60);
  SetWeaponType("pierce");
  SetShort("a primitive wooden spear");
  SetHands(1);
  SetId( ({ "spear" }) );
  SetAdjectives( ({ "primitive", "wooden" }) );
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(10);
  SetDamageType(PIERCE);
  SetVendorType(VT_WEAPON);
  SetLong("This short wooden spear seems someone effective as a weapon. "
          "It is mainly used by the primitive tribes of lizardmen from "
          "the swamps of Gwonish."
          );
  SetMass(60);
}
