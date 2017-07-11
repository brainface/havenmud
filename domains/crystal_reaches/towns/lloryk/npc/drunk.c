//Selket@Haven
//2006

#include <lib.h>
#include "../path.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("drunk");
  SetShort("a drunk farmer");
  SetId( ({ "farmer" }) );
  SetAdjectives( ({ "drunk" }) );
  SetLong("After a long day of field labor, this hard working "
          "soul has come to the Chestnut Mare to drink away "
          "his woes and worries of the next harvest. Although "
          "a bit grubby, he seems a simple, happy sort of "
          "chap.");
  SetRace("halfling");
  SetGender("male");
  SetClass("merchant");
  SetLevel(5);
  SetMorality(200);
  SetCurrency("rounds", 100);
  SetAction(3, ({
         "!stagger",
         "!say Darn cow got into my oats again. I'll have to "
         "sell her if she keeps that up.",
         "!say Andie's so pretty, and so nice. I wonder if I "
         "could ever have a chance with a girl like her.",
         "!burp",
         "!emote sloshes half of his beer on himself."}) );
  SetCombatAction(10, ({
    "!say Pick on someone your own size!",
    "!emote spills his beer on you.",
  }));
};
