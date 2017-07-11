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
     ]) );
  SetAction(3, ({
    "!emote hums tunelessly.",
     "!hum",
     "!whistle",
  "!emote looks around at the world.",
   "!say A fine day for travelling, don't you think?",
    "!say On my way to Dalnairn, I am.",
    }) );
  }
