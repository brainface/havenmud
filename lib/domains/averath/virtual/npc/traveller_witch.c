/* mahk 2018
 * traveller on averath road
 * secretly a witch!
 */

#include <lib.h>
#include <std.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("traveller");
  SetShort("a wandering traveller");
  SetId( ({ "traveller" }) );
  SetAdjectives( ({ "wandering" }) );
  SetRace("human");
  SetClass("rogue");
  SetClass("evoker");
  SetLevel(10 + random(15) );
  SetGender("male");
  SetLong("This wandering man seems to be fascinated by his "
          "surroundings. His demeanor suggests that he is quite "
          "capable of taking care of himself.");
  SetCurrency( ([
     "ducats" : random(3000),
     ]) );
  SetInventory( ([
      STD_KNIFE + "pocket_knife" : "wield knife",
      STD_CLOTHING + "body/dgreen_robe" : "wear robe",
     ]) );
  SetCombatAction( 50, ({
    "!cast iceball",
    "!cast shock",
    "!cast missile",
    "!cast capsule",
    "!say You'll never take me alive!",
    "!say How did you find me?!",
    "!say Not like this!",
    "!say BURN!",
  }) );
  SetAction(3, ({
    "!emote hums tunelessly.",
    "!hum",
    "!whistle",
    "!emote looks around at the world.",
    "!say A fine day for travelling, don't you think?",
    "!say On my way to Dalnairn, I am.",
  }) );
}

