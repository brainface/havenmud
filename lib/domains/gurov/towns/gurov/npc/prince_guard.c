#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_TOWNGUARD;
int eventSpecialAttack();
int eventEndScuffle(object ob);
int CheckCombat();

static void create() {
  ::create();
  SetRace("human");
  SetTown("Gurov");
  RemoveLanguage("Enlan");
  SetLanguage("Gurovian", 100, 1);
  SetGender("male");
  SetKeyName("gurovian guard");
  SetShort("a member of the Prince's Own guard");
  SetId( ({ "guard", "member" }) );
  SetAdjectives( ({ "prince", "prince's", "princes", "gurov", "gurovian", "guard", }) );
  SetFriends( ({ "prince", "guard" }) );
  SetClass("cavalier");
  SetLevel(50);
  SetMorality(85);
  SetCombatAction(5, ({
  	"disarm",
  	}) );
  SetInventory( ([
    STD_PIERCE "rapier" : "wield rapier",
    STD_CLOTHING "cloak/surcoat" : "wear surcoat",
    ]) );
  SetLong("This guard is wearing the tabard of one of the Prince's Own, "
          "the hardiest bunch of soldiers in the Principality of Gurov. "
          "He is charged with enforcing the peace and will often get "
          "involved in a scuffle to settle the brawl peacefully."
          );
  SetFirstCommands( ({ "guard prince" }) );
}
