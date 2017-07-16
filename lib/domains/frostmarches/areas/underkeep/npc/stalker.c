//
// An invisible stalker
// created by Ranquest@Haven
//
#include <damage_types.h>
#include <lib.h>
#include "main.h"
 inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetShort("an invisible stalker");
  SetLong(
    "The half-man, half-beast's face is like something from a nightmare"
    "; his human eyes and forehead look like they have been grafted on "
    "to a canine face, with the edges melted together. His jaws are locked"
    " in a constant grin of madness, yet the human eyes show the full "
    "horror of the knowledge of what he has become. His powerful body is "
    "a hybrid of wolf in man, with wicked scythe-like claws protruding "
    "from his fingertips. He looks absolutely ferocious.");
  SetKeyName("invisible stalker");
  SetId( "stalker");
  SetAdjectives("invisible");
  RemoveLanguage("wraithish");
  SetLanguage("Enlan",100,1); // Language can change w/ placement of area
  SetRace("human");
  SetMorality(-100);
  SetUndead(1);
  SetUndeadType("wraith");
  SetNoCorpse(1);
  SetInvis(1);
  SetResistance(BLUNT, "high");
  SetResistance(PIERCE, "high");
  SetResistance(SLASH, "high");
  SetResistance(POISON, "weakness");
  SetClass("rogue");
  SetLevel(30 + random(10));
  SetCurrency("crystals",240 + random(70));
  SetGender("male");
  SetWander(10);
  SetEncounter(60);
  SetMeleeAttackString("claws");
  SetMeleeDamageType(SLASH);

  SetAction(5, 
    ({"!say Please, Morgoth! Let me die!",
    "!weep"}) );
  SetCombatAction(5,
    ({"!emote snarls.",
    "!emote growls.",
    "!emote howls.",
    "!emote springs forward!"}) );
}
