#include <lib.h>
#include "../goblins.h"
inherit LIB_PLAYER_BARKEEP;

static void create() {
  ::create();
  SetKeyName("Ogadai");
  SetShort("Ogadai the Cook");
  SetId( ({ "ogadai", "cook" }) );
  SetRace("goblin");
  SetClass("rogue");
  SetGender("male");
  SetLevel(20);
  SetInventory( ([
    GOBLIN_OBJ "knifer" : 2,
    ]) );
  SetFirstCommands( ({ "wield knives" }) );
  SetBeverageDir(GOBLIN_OBJ "inn/");
  SetLocalCurrency("rounds");
  SetTown("Kresh");
  SetMorality(-75);
  SetCurrency("rounds",10 + random(10));
}