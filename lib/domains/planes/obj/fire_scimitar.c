/*
 * obsidian scimitar
 * for lesser fire elementals
 */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("obsidian scimitar");
  SetId( ({ "scimitar" }) );
  SetAdjectives( ({ "obsidian" }) );
  SetShort("an obsidian scimitar");
  SetLong(
    "This large scimitar appears to have been carved from"
    " a solid chunk of obsidian. Nicks and scratches"
    " mar the curve of its glass edge."
  );
  SetHands(1);
  SetClass(20);
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1000);
  SetValue(1600);
  SetMass(200);
  SetMaterials( ({ "natural" }) );
  SetRepairDifficulty(60);
  SetWeaponType("slash");
  SetProperty("history",
    "This scimitar was crafted by some fell smith of the"
    " plane of fire for the elementals that guard that"
    " realm."
  );
}


