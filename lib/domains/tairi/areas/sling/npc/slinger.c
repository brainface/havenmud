//swordslinger as ronin


#include <lib.h>
#include <std.h>
#include "../sling.h"

inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("Kofumi");
  SetShort("Kofumi, the Errant");
  SetId( ({"kofumi","errant"}) );
  SetAdjectives( ({"kofumi","the"}) );
  SetLong(
    "This young woman seems to have seen her fair share of battle, judging "
    "by her wiry muscles and the network of scars covering her weathered "
    "skin. Perhaps once beautiful, her face is marred by a single deep gash "
    "crossing from her left temple to the perpetual scowl of her mouth."
  );
  SetTown("all");
  SetRace("human");
  SetGender("female");
  SetClass("cavalier");
  SetSkill("sword slinging",1,1);
  SetLevel(150);
  SetBaseLanguage("Tai");
  SetCurrency( ([
    "koken" : random(1500) + 1000,
  ]) );
  SetMorality(-100);
  SetAction(7, ({
    "!say Are you another of Yori's dogs?",
    "!say Ka will never defeat me.",
    "!say The sword was just gathering dust where it was. Much better it find use.",
    "!say I have a lot to teach anyone unhindered by the bounds of honor.",
    "!say If you want to die honorably, talk to Ka. If you want your opponent to die honorably, I'm the one to talk to.",
    "!say Do you want to win a fight? Slide a blade through his gullet before he knows to draw his.",
    "!say There's no glory in battle. There's just blood and the screams of the dying.",
    "!say If you see Taketori, stick a sword in him for me.",
  }) );

  SetCombatAction(50, ({
    "!grit",
    "!cut down",
    "!run through",
    "!run through",
    "!whirlwind",
  }) );
  SetInventory( ([
    STD_SLASH "bluesword" : "wield sword",
    SLING_OBJ "oyoroi" : "wear oyoroi",
  ]) );
  AddTrainingSkills("slash combat");
  AddTrainingSkills("sword slinging");
  SetLimit(1);
}

