#include <lib.h>
#include <std.h>
#include "../underland.h"
inherit LIB_BARKEEP;

static void create() {
  ::create();
  SetKeyName("diamond");
  SetRace("gnome");
  SetGender("female");
  SetShort("Diamond, the Tavern Proprietor");
  SetId( ({ "gnome", "diamond", "barkeep", "proprietor" }) );
  SetAdjectives( ({ "tavern" }) );
  SetLong(
    "Diamond is the owner of the Underland Tavern, a raucous "
    "place of disorder and merriment."
    );
  SetClass("merchant");
  SetLevel(6);
  SetAction(5, ({ 
    "!laugh",
    "!smile warmly",
    "!grin innocently",
    "!smirk",
    "!emote looks around the Tavern with a twinkle in her eye.",
  }) );
  SetLocalCurrency("rupies");
  SetTown("Underland");
  SetMenuItems( ([
    "cheese" : STD_MEAL "food/cheese",
    "bread"  : STD_MEAL "food/bread",
    "beer"   : STD_MEAL "alcohol/beer",
    "ale"    : STD_MEAL "alcohol/ale",
    "water"  : STD_MEAL "drink/water",
    ]) );
}
