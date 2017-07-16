#include <lib.h>
#include "../uih.h"
inherit LIB_INVADER;

static void create() {
  invader::create();
  SetKeyName("skeleton guard");
  SetShort("a skeletal guardian");
  SetId( ({ "skeleton", "undead", "guardian", "undead_inv" }) );
  SetAdjectives( ({ "skeletal" }) );
  SetLong(
    "This guardian obviously has no intention of letting anyone "
    "pass by him while he stands here."
  );
  SetRace("human");
  SetClass("fighter");
  SetGender("male");
  SetLevel(20);
  SetUndead(1); 
  SetNoCorpse(1);
  SetEnemyTown("Haven");  
  SetUndeadType("skeleton");
  SetMorality(-200);
  SetInventory( ([
    UIH_OBJ + "skel_sword" : "wield sword",
    UIH_OBJ + "skel_armor" : "wear armour",
  ]) );
  SetFriends( ({ "undead_inv" }) );
  SetWanderSpeed(5);
  SetWanderPath( ({
    "go east", "go east", "go east", "go north", "go north",
    "go north", "go west", "go west", "enter bathhouse",
    "kill wadlow",
  }) );
}
