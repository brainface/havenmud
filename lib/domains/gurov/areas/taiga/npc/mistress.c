//Illura@Haven
//Sept 2009
//mistress
#include <lib.h>
#include <std.h>
#include "../taiga.h"
inherit LIB_SENTIENT;
inherit LIB_FEAR;

static void create() {
  sentient::create();
  SetKeyName("mistress");
  SetId( ({ "mistress" }) );
  SetAdjectives( ({ "six-armed", "six armed", "ice" }) );
  SetShort("a six-armed mistress of ice");
  SetLong(
    "This six-armed creature looks a lot like the maraliths of the Abyss "
    "you hear so much talk about, although she doesn't seem very big. "
    "Her long torso and abdomen provide enough room for the slim, six "
    "arms extending off of it. Her ice-blue skin seems to radiate a glow. "
    "Even her face, extremely gorgeous, is twisted with a haunting power "
    "that is only enhanced by the fact that she does not tread upon the "
    "ground, but floats somehow just above it."
  );
  SetFirstCommands( ({"wield all"}) );
  SetGender("female");
  SetRace("maralith");
  SetClass("fighter");
  SetLevel(50);
  SetInventory( ([
    STD_SLASH "bluesword" : 3,
    TAIGA_OBJ "iceaxe" : 3,
      ]) );
    SetAction(5, ({
    "!say in archaic leave this hallowed place, and do not return.",
     "!say in archaic do you believe your gods to be the eldest ones, foolish mortal?",
    "!emote turns her cold aquamarine eyes upon you, their limitless depths holding ageless wisdom.",
                })  );
  SetCombatAction(10, ({
    "The face of the mistress hardens as she attacks.",
    "The mistress of ice slams into you with great force.",
    }) );
  SetBaseLanguage("archaic");
  SetCurrency( ([
     "rubles" : random(2000),
     ]) );
  SetFearType("demon fear");
  SetFearLength(10);
  SetNoCorpse(1);
  SetDie("The mistress of ice sighs at you and disappears into a beam of light.");
  }

void init() {
  sentient::init();
  fear::init();
  }
