/*  A mace for the Templar Invasion */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("heavy mace");
  SetShort("a heavy iron mace");
  SetId( ({ "mace" }) );
  SetAdjectives( ({ "heavy", "iron" }) );
  SetLong(
    "This heavy iron mace appears to be of great value "
    "and worth. Its head is a massive weight of pure crushing "
    "power. This is a weapon of war, not defense."
  );
  SetVendorType(VT_WEAPON);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetClass(15);
  SetMass(85);
  SetValue(100);
  SetDamagePoints(900);
  SetMaterials( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smithing" : 1,
  ]) );
  SetRepairDifficulty(40);
  SetProperty("history", "This is a mace used by the Templars of Kylin.");
}
