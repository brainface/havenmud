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
  SetClass("acrobat");
  SetClass("evoker");
  SetLevel(10 + random(15) );
  SetGender("female");
  SetLong("This wandering woman keeps a sharp eye on her surroundings. Her skin "
    "is tanned and fingers calloused from long days of travel behind her.");  
  SetCurrency( ([
     "ducats" : random(3000),
     ]) );
  SetInventory( ([
      STD_POLE + "staff" : "wield staff",
      STD_CLOTHING + "body/blue_dress" : "wear dress",
     ]) );
  SetCombatAction( 50, ({
    "!cast iceball",
    "!cast shock",
    "!cast missile",
    "!cast capsule",
    "!say Damn Aurelius!",
    "!say Toad! Become a Toad! Work dammit!",
    "!say Spirits of Earth and Fire save me!",
    "!say FREEZE!",
  }) );
  SetAction(3, ({
    "!emote sings softly under her breath.",
    "!emote twirls her staff expertly.",
    "!say On my way back from Dalnairn, I am.",
    "!say On the road again, here I am, on the road again.",
    "!emote glances toward you warily.",
    "!emote hums tunelessly.",
  }) );
}

