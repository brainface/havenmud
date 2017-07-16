#include <lib.h>
#include <damage_types.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {

  ::create();
  SetKeyName("male citizen");
  SetShort("a tall male citizen");
  SetId( ({ "citizen" }) );
  SetAdjectives( ({ "tall", "male" }) );
  SetLong("This tall, thin man is horribly dressed.  While his features "
           "are homely, his eyes glow with hospitality.");
  SetRace("human");
  SetGender("male");
  SetLevel(3);
  SetCombatAction(3, ({
    "!yell Somebody please help me!",
    "!say Please stop, I have done you no wrong!",
    "!say Ow! That hurt, you rat bastard!",
    }) );
  SetAction(3, ({
    "!emote whistles a little ditty.",
      "!say Every day in Averath is a splendid day!",
    "!say I’m worried about the Duke. He hasn’t been himself lately.",
    }) );
  SetMorality(50);
   SetCurrency("ducats",5);
}
