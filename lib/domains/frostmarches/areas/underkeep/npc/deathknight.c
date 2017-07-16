//
// A deathknight
// Created by Ranquest@Haven
//
#include <lib.h>
#include <damage_types.h>
#include "main.h"
 inherit LIB_NPC;

static void create() {
  npc::create();
  SetShort("a hulking deathknight");
  SetLong(
    "The hulking form of a deathknight stands here, a powerful "
    "undead skeleton wearing a suit of armour covered in twisting, "
    "writhing runes. Unholy fire glows in his eyesockets, and he "
    "holds a very big and sharp broadsword in his hands.");
  SetKeyName("deathknight");
  SetId(({"knight","deathknight"}));
  SetAdjectives("hulking");
  SetRace("human");
  SetUndead(1);
  SetUndeadType("wraith");
  SetMorality(-800);
  SetNoCorpse(1);
  SetDie(
    "The skeletal figure crumbles into dust, leaving the armour "
    "and broadsword behind.");
  SetClass("cavalier");
  SetClass("necromancer");
  SetLevel(40);
  SetMeleeDamageType(COLD);
  SetCurrency("crystals",300);
  SetGender("male");
  SetEncounter(60);
  SetInventory( ([
    RNQ_OBJ + "broadsword"   : "wield sword",
    RNQ_OBJ + "chaos_armour" : "wear armour",
    ]) );
}
