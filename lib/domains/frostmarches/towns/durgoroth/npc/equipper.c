#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../durgoroth.h"

inherit LIB_EQUIPPER;
 
static void create() {
  ::create();
  SetKeyName("volac");
  SetRace("daemon");
  SetClass("fighter");
  SetLevel(180);
  SetGender("male");
  SetShort("Volac the Giver");
  SetId( ({ "daemon","giver", "aider"}) );
  SetAdjectives( ({ "volac", "daemon" }) );
  SetLong("Volac is a weak and pathetic looking daemon.  "
          "He has survived by hiding and supplying "
          "stronger and younger daemons with equipment "
          "they would need to survive in the harsh "
          "dog-eat-dog society of Durgoroth.");
  SetAction(5, ({
    "!emote looks around for useful items.",
    "!emote scurries about looking for a safe place to hide.",
    "!emote cowers at some imperceptible noise.",
    "!emote looks around for possible threats.",
    }) );
  SetCombatAction(10, ({
    "!scream pathetic",
    }) );
  SetCurrency("crystals", 2000);
  SetReligion("Saahagoth","Saahagoth");
  SetTown("Durgoroth");
  SetMorality(-700);
  SetInventory( ([
     ]) );
  SetLevelLimit(10);
  SetFreeEquipment( ([
    "shirt"          : STD_CLOTHING "lg_shirt",
    "pants"          : STD_CLOTHING "lg_pants",
    "coat"           : STD_CLOTHING "lg_coat",
    "sword"          : STD_SLASH "shortsword",
    "mace"           : STD_WEAPON "mace",
    "knife"          : STD_KNIFE "freeknife",
    "staff"          : STD_WEAPON "staff",
    "knuckles"       : STD_MELEE "brass_knuckles",
    "leather pants"  : STD_ARMOUR "free_armour/large/oldpants",
    "leather helmet" : STD_ARMOUR "free_armour/large/oldhelmet",
    "leather vest"   : STD_ARMOUR "free_armour/large/oldvest",
    "leather glove"  : STD_ARMOUR "free_armour/large/oldglove",
    "horseshoe"      : DURG_OBJ "newbie_horseshoe",
    ]) );
    SetLimit(1);
  }
