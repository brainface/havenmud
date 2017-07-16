#include <lib.h>
#include <damage_types.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {

  ::create();
  SetKeyName("female citizen");
  SetShort("a beautiful female citizen");
  SetId( ({ "citizen" }) );
  SetAdjectives( ({ "beautiful", "female" }) );
  SetLong("This tall, beautiful woman is a sight for sore eyes. Her beauty "
           "is captivating, and she knows it.");
  SetRace("human");
  SetGender("female");
  SetLevel(3);
  SetCombatAction(3, ({
    "!yell help!.",
    "!emote cowers in fear, awaiting the next blow.",
    "!scream",
    }) );
  SetAction(3, ({
    "!emote hums to herself contentedly.",
      "!say Beautiful day, isn't it?",
    "!say It is so safe here.",
    }) );
  SetMorality(20);
  SetCurrency( ([
     "ducats" : random(8),
    ]) );
}
