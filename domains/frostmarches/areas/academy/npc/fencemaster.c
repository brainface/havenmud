/*
 A fencemaster sent from jidoor to aid their magildan brethren
 Keeps kobolds alive a little bit longer, so that they don't
   kill each other before players can get to them.
 Should be moderately challenging foe at her level, but not a
   bastard like taketori.
 */
#include <lib.h>
#include "../fence.h"

inherit LIB_EQUIPPER;

static void create() {
  ::create();

  //descriptive text
  SetKeyName("lamrani fencemaster");
  SetId( ({ "master","fencemaster","lamrani" }) );
  SetShort("a lamrani fencemaster");
  SetAdjectives( ({"lamrani"}) );
  SetLong(
    "This elderly lamrani fencemaster was sent from jidoor to aid the "
    "youth of arcanith. Though ostensibly an act of charity, likely she "
    "was simply ostracized from her city due to her specialization in "
    "such a vulgar skill as swordfighting. She looks as if she was once a "
    "deadly opponent, but her face bears the scars of combat and wrinkles "
    "of age, suggesting her prime is long since past."
  );

  // base statistics 
  SetRace("lamrani");
  SetClass("ranger");
  SetLevel(FENCE_MASTER_LEVEL);

  // misc stuff
  SetAction(25, ({
    "!yell No, no, no! Even a gelfling could topple you with that stance!",
    "!say Please, try not to knock each other's eyes out.",
    "!say If I'd been any good at thaumaturgy, I wouldn't have to herd "
      "these furry rascals.",
    "!yell You're dropping your guard!",
    "!say It's too cold out here for an old woman.",
    "!emote mutters under her breath.",
    "!cast barkskin on brash student",
    "!cast barkskin on cowardly student",
    "!yell Again! You're dueling until you get it right, and then you're "
      "dueling some more!"
  }) );
  SetBaseLanguage("Koblich");
  SetCombatAction(25, ({
    "!say I may be old, but I've a few tricks left!",
    "!say Please! I don't want to die of boredom!",
    "!emote calmly floats away from the blow.",
    "!cast vermin horde",
    "!cast terra",
    "!disarm",
    "!cast thicken skin",
  }) );
  SetCurrency("senones",random(500));
  SetDie(
    "The fencemaster sighs with exhaustion, then falls to the ground."
  );
  SetFirstCommands( ({
    "cast thicken skin",
    "cast thicken skin",
    "cast barkskin on cowardly kobold",
    "cast barkskin on brash kobold",
  }) );
  SetFreeEquipment( ([
    "foil" : FENCE_OBJ "practice_foil",
    "jacket" : FENCE_OBJ "fencing_jacket",
  ]) );
  SetGender("female");
  SetInventory( ([ 
    FENCE_OBJ "sidesword.c" : "wield sidesword",
  ]) );
  SetLevelLimit(10);
  SetSkill("disarm",FENCE_MASTER_LEVEL*2,1);
  SetSkill("pierce combat",FENCE_MASTER_LEVEL*2,1);
  SetSpellBook( ([
    "barkskin":25,
    "vermin horde":100,
    "terra":100,
    "thicken skin":100,
    "tend wounds":100,
  ]) );
}

