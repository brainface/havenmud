//swordslinger as ronin


#include <lib.h>

inherit LIB_TRAINER;


static void create() {
  trainer::create();
  SetKeyName("Kofumi");
  SetShort("Kofumi, the Errant");
  SetId( ({"kofumi","errant"}) );
  SetAdjectives( ({"kofumi","the"}) );
  SetLong(
    ""
  );
  SetTown("all");
  SetRace("human");
  SetGender("female");
  SetClass("cavalier");
  SetSkill("sword slinging",1,1);
  SetLevel(150);
  SetBaseLanguage("Tairi");
  SetCurrency( ([
    "koken" : random(1500) + 1000,
  ]) );
  SetMorality(-100);
  SetAction(7, ({
    "Are you another of Yori's dogs?",
    "Ka will never defeat me.",
    "The armour and sword were just gathering dust where they where. Much better they find use.",
    "I have a lot to teach anyone unhindered by the bounds of honor.",
    "I've been looking for a student, to pass on my skills.",
    "Do you want to win a fight? Slide a blade through his gullet before he knows to draw his.",
    "There's no glory in battle. There's just blood and the screams of the dying.",
    "If you see Taketori, stick a sword in him for me.",
  }) );

  SetCombatAction(50, ({
    "grit",
    "cut down",
    "run through",
    "run through",
    "whirlwind",
  }) );
  SetInventory( ([
        
  ]) );
  AddTrainingSkills("slash combat");
  AddTrainingSkills("sword slinging");
  SetLimit(1);
}

