//Selket@Haven
//2006

#include <lib.h>
#include "../path.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("Andie");
  SetShort("Andie the Happy Barmistress");
  SetId( ({ "andie", "barmistress", "waitress", "barkeep" }) );
  SetLong("Andie is a jubilant young halfling whose glib tongue "
          "and pretty looks keep her patrons coming back. She "
          "runs the Chestnut Mare with few problems, likely "
          "glad to keep her soft hands from working in the "
          "dirt.");
  SetRace("halfling");
  SetGender("female");
  SetClass("merchant");
  SetLevel(10);
  SetMenuItems( ([ "beer" : "/std/meal/beer.c",
                   "cheese"  : "/std/meal/food/cheese.c",
                   "bread"  : "/std/meal/food/bhunk.c" ]) );
  SetLocalCurrency("rounds");
  SetMorality(50);
  SetCurrency("rounds", 4000);
  SetAction(3, ({
         "!say It used to be called the Dun Mare when my pa "
         "managed the place, but I think the new name has a "
         "nice ring to it, don't you?",
         "!say I sure hope we have a little rain tomorrow. "
         "The crops could use a good nice soak.",
         "!say You should try some of my beer! Finest in the "
         "Shire, no better way to wet your whistle!",
         "!smile cheerily",
         "!emote finds a smudge on the bar and wipes it away.",
         "!say Nothing goes better with my fresh grain bread "
         "than a little wedge of cheese sandwiched in! Mmm!",
         "!whistle"}) );
  SetCombatAction(10, ({
    "!say That's not very sporting of you!",
    "!emote snaps a wet bar rag at you. That stings!",
  }));
};
