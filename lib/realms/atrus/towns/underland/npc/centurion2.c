//Underland centurion by Atrus
//2023@HavenMud

#include <lib.h>
#include "../underland.h"
inherit LIB_TOWNGUARD;

static void create() {
  ::create();
  SetKeyName("centurion");
  SetRace("gnome");
  SetGender("male");
  SetShort("a gnomish centurion");
  SetId( ({ "centurion", "gnome" }) );
  SetAdjectives( ({ "unassuming", "underland" }) );
  SetLong(
    "This unassuming gnome stands confidently. His demeaner suggests you "
    "should probably leave him alone. He is obviously a city centurion by "
    "his garb and weapon. However there is no sign of rank. The look on his "
    "face betrays his boredom. And his eyes dart around wishing someone would "
    "step out of line so that he may deal with it."
    );
  SetClass("fighter");
  SetClass("priest");
  SetLevel(255);
  SetSkill("pole combat", 510, 1);
  //For fairer combat rolls
  SetStat("strength",255);
  SetStat("durability",255);
  SetStat("agility",175);
  SetStat("coordination",175);
  SetStat("luck",75);
  SetStat("wisdom",99);
  SetStat("charisma",65);
  SetStat("intelligence",99);

  SetInventory( ([
    UNDER_OBJ "chainboots" : "wear boots",
    UNDER_OBJ "cenchain"  : "wear suit",
    UNDER_OBJ "chainhelm"  : "wear helm",
    UNDER_OBJ "halberd"    : "wield halberd",
    ]) );
  SetTown("Underland");
  SetWander(8);
  SetSpellBook( ([
    "avalanche"          : 100,
    "soul taint"         : 100,
    "maddening visions"  : 100,
    "cause bleeding"     : 100,
    "flamestrike"        : 100,
    "curse"              : 100,
    "unholy guardian"    : 100,
    "touch of death"     : 100,
    "temperature shield" : 100,
    ]) );
  SetCombatAction(10, ({
    "!cast maddening visions",
    "!cast soul taint",
    "!cast cause bleeding",
    "!cast curse",
    "!cast touch of death",
    "!cackle",
    "!cast soul tap",
    "!cast flamestrike",
    "!cast avalanche",
    "!say you really should not have done that.",
    "!say your folly will be your undoing.",
    }) );
  SetMorality(-500);
  SetCurrency("crystals", random(5000));
  SetAction(random(5), ({
    "!hum",
    "!whistle",
    "!grumble",
    "!look"
    "!say They figure out the name yet?",
    "!say I saw that figure again, snooping around the market.",
    "!emote kicks a pebble around.",
    "!emote scratches himself.",
    "!say I wonder if...",
    "!emote stalks off.",
    "!emote looks you up and down in apprehension.",
    "!say all these outsiders...",
    "!say I wish they would just go home.",
  }) );
  SetFirstCommands( ({ 
    "cast temperature shield",
    "cast temperature shield",
    "cast unholy guardian",
    "cast unholy guardian",
    "cast unholy guardian",
  }) );
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 2) {
    eventForce("unholy guardian");

  }
}
