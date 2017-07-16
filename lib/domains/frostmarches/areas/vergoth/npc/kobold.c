#include <lib.h>
#include "../vergoth.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("butler");
  SetRace("kobold");
  SetId( ({ "butler", "kobold" }) );
  SetAdjectives( ({ "small", "pinkish", "butler", "kobold" }) );
  SetClass("rogue");
  SetGender("male");
  SetShort("a kobold butler");
  SetLevel(1);
  SetLong("The butler is nothing more than a small kobold.  He stands here "
        "and shakes in fear.  He is about four feet tall and has a pinkish "
        "colored skin.");
  SetMorality(0);
  SetCombatAction(30, ({ 
     "!emote cries loudly.",
     "!emote mutters about not serving dinner on time.",
     "!emote whines pathetically.",
    }) );
  SetAction(10, ({
    "!emote mutters something about everyone being dead.",
    "!emote walks about making the table.",
    "!say go away, I am busy",
    "!whine",
   }) );
  SetDie( "Butler gasps in horror as he dies." );
 }
