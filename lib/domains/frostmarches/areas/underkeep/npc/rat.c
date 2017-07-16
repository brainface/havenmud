//
// A cute rat
// created by Ranquest@Haven
//
#include <lib.h>
#include <damage_types.h>
#include "main.h"
 inherit LIB_NPC;

static void create(){
  npc::create();
  SetShort("a vicious rat");
  SetLong("This rodent is covered with dirt and mud. His feral eyes gleam "
    "in the dim light, and his yellowing teeth are bared in an expression "
    "of rage and terror.");
  SetKeyName("rat");
    SetAdjectives( ({"vicious","mean"}) );
  SetId(({"rat"}));
  SetRace("rodent");
  SetClass("animal");
  SetLevel(2);
  SetGender("male");
  SetMeleeDamageType(PIERCE);
  SetMeleeAttackString("teeth");

  SetAction(5,
    ({"!emote looks for food.",
    "!emote squeaks viciously.",
    "!emote washes his paws."}) );
}
