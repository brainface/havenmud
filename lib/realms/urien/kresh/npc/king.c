/*  The goblin king */
#include "../goblins.h"
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("Urg Unt Alla");
  SetGender("male");
  SetTown("Kresh");
  SetFriends( ({ "goblin" }) );
  SetShort("Urg Unt Alla, the Goblin Khan");
  SetId( ({ "alla", "urg", "unt", "khan", "goblin" }) );
  SetAdjectives( ({ "urg", "unt", "alla", "khan", "goblin" }) );
  SetRace("goblin");
  SetClass("fighter");
  SetSkill("melee combat",1,1);
  SetCombatAction(25, ({
  	"!disarm",
  	"!disorient",
  	}) );
  SetLevel(75);
  SetMorality(-500);
  SetCurrency( ([
     "rounds" : random(500)+ 150,
    ]) );
  SetLong(
    "The goblin khan is an impressive looking stout with "
    "a nearly regal visage."
    );
  SetInventory( ([
      ]) );
}
