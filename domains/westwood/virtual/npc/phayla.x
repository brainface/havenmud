#include <lib.h>
#include <std.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Phayla");
  SetShort("Phayla the Wandering Bard");
  SetId( ({"faerie","wandering","bard","phayla"}) );
  SetAdjectives( ({"wandering"}) );
  SetLong("This young women is a beautiful faerie. Her gossamer wings glitter "
       "slightly as she moves. Her eyes sparkle with flecks of gold and silver. "
       "Her longe hair is tangled with leaves and twigs. She is by far one of "
       "the most attractive beings you have ever seen.");
  SetNoJoin(1);
  SetLimit(1);
  SetWander(10);
  SetWanderRecurse(1);
  SetGender("female");
  SetRace("faerie");
  SetClass("bard");
  SetLevel(100);
  SetAction(4, ({
        "!say I am Phayla, I am a songweaver and a mistress to "
        "sound.",
        "!emote sings a beautiful song.",
        "!emote sighs happily.",
        }) );
  SetInventory( ([
         STD_WEAPON + "small_knife" : "wield knife",
        ]) );
  SetSongBook( ([
        "sonic barrier" : 100,
        "sonic movement" : 100,
        ]) );
}

