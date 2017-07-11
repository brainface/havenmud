#include <lib.h>
#include <std.h>
#include "../parva.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Hernando Morgan");
  SetShort("Hernando Morgan the Muscular Brute");
  SetId( ({ "hernando", "morgan", "brute" }) );
  SetAdjectives( ({ "hernando", "muscular" }) );
  SetFriends( ({ "rodrigo" }) );
  SetRace("human");
  SetTown("Parva");
  SetClass("fighter");
  SetPlayerTitles( ([
    "newbie" : "the Young Brawler",
    "mortal" : "the Parvan Brawler",
    "hm"     : "the Winner of Bar Brawls",
    "legend" : "the Destroyer of Tavern Furnishings",
    "avatar" : "the Extreme Punisher of Tavernkeeps",
    ]) );
  SetFreeEquipment( ([
    STD_HACK  "hand-axe"   : 1,
    STD_SLASH "shortsword" : 1,
    ]) );
  SetLong(
    "Hernando is the biggest, meanest lout in town. He is "
    "responsible for countless damage to the taverns and is a fine "
    "person to teach new <fighters>. One could <ask> him <to "
    "join fighters>."
    );
  SetGender("male");
  SetLevel(80);
  SetCurrency("oros",5);
  SetInventory( ([
    STD_HACK "battle_axe" : "wield axe",
    STD_CLOTHING "cloak/surcoat" : "wear surcoat",
    ]) );
  SetLimit(1);
  SetCombatAction(15, ({
  	"!disarm",
  	"!disorient",
  	}) );
}
