// Averath Sewers
// Aerelus
// Update by Ohtar, 2009
// Update by Mahkefel, 2017 (combat actions)
#include <lib.h>
#include <damage_types.h>
#include "../sewers.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("Dominic the Undead");
  SetShort("Dominic the Undead");
  SetId( ({ "dominic", "undead" }) );
  SetAdjectives( ({ "undead" }) );
  SetUndead(1);
  SetLong(
    "This undead man was once the ruler of most of Averath, many centuries "
    "ago. His transparent body the product of some magical act, he sits here "
    "alone, waiting for the end of time. He appears old, though still seems "
    "to maintain an air of dignity about him."
    );
  SetRace("human");
  SetClass("fighter");
  SetGender("male");
  SetBaseLanguage("Avera");
  SetSkill("sword slinging", 1);
  SetLevel(100);
  AddCurrency("ducats", random(1000)+200);
//  SetCombatStyle("sword slinging");
//  SetCombatStyleLevel("sword slinging", 100);
  SetCombatAction(15, ({
    "!say You think you are worthy to end my miserable existence? We shall "
        "see.",
    "!say Today will be your last!",
    "!disorient",
    "!disarm",
    "!run through",
    "!cut down",
    }) );
  SetAction(3, ({
    "!emote sits perfectly still on his chair.",
    "!say How I wish my body was still with me. Still, eternity is mine.",
          }) );
  SetInventory( ([
     SEWERS_OBJ "ethsword" : "wield broadsword",
     SEWERS_OBJ "etharmour" : "wear armour",
         ]) );
  SetEncounter(0);
  SetMorality(-50);
}

