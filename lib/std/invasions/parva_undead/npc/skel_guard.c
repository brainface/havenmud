// Undead invasion of Parva
// Duuk
// Edited: Laoise, 2005

#include <lib.h>
#include "../uih.h"
inherit LIB_INVADER;

static void create() {
  invader::create();
  SetKeyName("skeleton guardian");
  SetShort("a skeletal guardian");
  SetId( ({ "skeleton", "warrior", "guardian", "undead_inv" }) );
  SetAdjectives( ({ "skeletal" }) );
  SetLong(
    "This guardian obviously has no intention of letting anyone "
    "pass by him while he stands here."
  );
  SetRace("human");
  SetGender("male");
  SetClass("fighter");
  SetLevel(20);
  SetUndead(1); 
  SetNoCorpse(1);
  SetUndeadType("skeleton");
  SetMorality(-200);
  SetInventory( ([
    UIH_OBJ + "skel_sword" : "wield sword",
    UIH_OBJ + "skel_armor" : "wear armour",
  ]) );
  SetFriends( ({ "undead_inv" }) );
  SetWanderSpeed(0);
  SetWanderPath( ({
    "guard west",
  }) );
  SetFirstCommands( ({ "guard west" }) );
}
