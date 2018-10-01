#include <lib.h>
#include "../underland.h"
inherit LIB_BARKEEP;

static void create() {
  ::create();
  SetKeyName("nazza");
  SetRace("gnome");
  SetGender("female");
  SetShort("Nazza the Armourer");
  SetId( ({ "armourer", "nazza", "gnome" }) );
  SetAdjectives( ({ }) );
  SetLong(
    "Nazza is the Armourer in the Underland. Her wares range from mundane to "
    "exotic, and her prices are enough to make most grown gnomes cry."
    );
  SetClass("merchant");
  SetLevel(10);
  SetLocalCurrency("rupies");
  SetMenuItems( ([
    "cloth belt"    : UNDER_OBJ "clothbelt",
    "cloth glove"   : UNDER_OBJ "clothglove",
    "cloth helmet"  : UNDER_OBJ "clothhelmet",
    "cloth pants"   : UNDER_OBJ "clothpants",
    "cloth shirt"   : UNDER_OBJ "clothshirt",
    "leather boots" : UNDER_OBJ "leatherboots",
    "leather glove" : UNDER_OBJ "leatherglove",
    "leather helmet": UNDER_OBJ "leatherhelmet",
    "leather pants" : UNDER_OBJ "leatherpants",
    "leather vest"  : UNDER_OBJ "leathervest",
    "chainmail gauntlet" : UNDER_OBJ "chaingauntlet",
    "chainmail helm"     : UNDER_OBJ "chainhelm",
    "chainmail vest"     : UNDER_OBJ "chainvest",
    "chainmail armour"   : UNDER_OBJ "chainmail",
    "chainmail boots"    : UNDER_OBJ "chainboots",
    "chainmail cuisse"   : UNDER_OBJ "chaincuisse",
    ]) );
}
