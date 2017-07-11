/*
 * obsidian axe
 * for lesser fire elementals
 */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

int SetupProc();

static void create() {
  item::create();
  SetKeyName("obsidian axe");
  SetId( ({ "axe" }) );
  SetAdjectives( ({ "obsidian" }) );
  SetShort("an obsidian axe");
  SetLong(
    "This axe appears to have been carved from"
    " a solid chunk of obsidian. Nicks and scratches"
    " mar its glass edge."
  );
  SetHands(1);
  SetClass(15);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1000);
  SetValue(1600);
  SetMass(200);
  SetMaterials( ({ "natural" }) );
  SetRepairDifficulty(60);
  SetProperty("history",
    "This axe was crafted by some fell smith of the"
    " plane of fire for the elementals that guard that"
    " realm."
  );
}


