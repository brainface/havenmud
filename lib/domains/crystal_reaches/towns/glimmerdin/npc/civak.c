#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Civak Axethrower");
  SetRace("dwarf");
  SetClass("fighter");
  SetLevel(75);
  SetMorality(400);
  SetGender("male");
  SetShort("Civak Axethrower, Glimmerdin Arms Thane");
  SetId( ({ "civak", "axethrower", "thane", "dwarf"}) );
  SetAdjectives( ({ "civak", "glimmerdin", "arms" }) );
  SetLong(
    "Though lightly armoured, Civak is obviously a fighter of "
    "legendary ability.  Streaks of grey run through the long red "
    "beard of his youth and wrinkles cluster around his kindly blue "
    "eyes.  Civak serves in a number of capacities, the guard "
    "answers to him as well as any non-military fighter recruits."
    );
  SetTown("Glimmerdin");
  AddStatBonus("strength",30);
  AddStatBonus("agility",20);
  
  SetPlayerTitles( ([
    "newbie" : "the Young Glimmerdin Fighter",
    "mortal" : "the Axe of Glimmerdin",
    "hm"     : "the Hammer of the Mountain",
    "legend" : "the Legendary Bearer of Arms", 
    "avatar" : "the Hammer and Shield of the Dwarves",
    ]) );
  SetFreeEquip( ([
    G_OBJ "axe"   : 1,
    STD_ARMOUR "shield/small_wooden" : 1,
    ]) );
  SetCombatAction(20,({
    "!disarm", 
  }) );
  SetInventory( ([
    G_OBJ "light_mithril_shirt" : "wear shirt",
    G_OBJ "br_kilt"     : "wear kilt", 
    G_OBJ "black_boots" : "wear boots",
    G_OBJ "mithril_axe" : "wield axe",
  ]) );
}
