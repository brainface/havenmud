#include <lib.h>
#include "../goblins.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("little goblin");
  SetId( ({ "little goblin", "goblin" }) );
  SetShort("a little goblin");
  SetLong("This little creature is a goblin of small worth.");
  SetRace("goblin");
  SetClass("fighter");
  SetLevel(random(3)+1);
  SetMorality(-50);
  SetGender("male");
  SetInventory( ([
     GOBLIN_OBJ + "knifer" : "wield knife",
      ]) );
  }
