// This is going to be a land of artesians. 
// However, they have stat caps in place.
// High level should deter HM/Legend characters believing they can roll it
// Most casters will be able to, and fighters can cruise through on level.


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
  SetAdjectives( ({ "beautiful", "kind", "artesian" }) );
  SetLong(
    "As gnomes go, Nazza is an exceptional example of strength and durability. "
    "She has a beautiful face and kind eyes. Her face is tanned from the forge. Her long "
    "flowing black hair tumbles over her shoulder in a mass that almost protects "
    "her neck as well as her apron does. Her movements have a calm and practiced gait "
    "which reveals her to be an artisan."
    );
  SetClass("merchant");
  SetLevel(100);
  //For fairer combat rolls
  SetStat("strength",175);
  SetStat("durability",175);
  SetStat("agility",75);
  SetStat("coordination",75);
  SetStat("luck",75);
  SetStat("wisdom",75);
  SetStat("charisma",190);
  SetStat("intelligence",85);
  SetLocalCurrency("rupies");
  SetInventory( ([
   UNDER_OBJ "apron" : "wear apron",
   UNDER_OBJ "smithhammer" : "wield hammer",
   UNDER_OBJ "artisanpant" : "wear pants",
   UNDER_OBJ "artisanshirt" : "wear shirt",
   UNDER_OBJ "pocketwatch" : 1,
   UNDER_OBJ "leatherboots" : "wear boots",
  ]) );
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
