#include <lib.h>
#include <std.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("bandit");
  SetShort("a rough looking bandit");
  SetLong("This is a large rough looking bandit.  His demeanor suggests "
          "that combat is nothing new to him.");
  SetId( ({ "bandit", "rough looking bandit" }) );
  SetAdjectives( ({ "rough", "rough looking" }) );
  SetProperty("no bump", 1);
  SetRace("human");
  SetGender("male");
  SetClass("fighter");
  
  SetLevel(random(2)+1);
  SetFriends( ({ "bandit" }) );
  SetMorality(-200);
 
  SetCurrency("imperials",random(70));
  SetInventory( ([
    STD_WEAPON "hack/battle_axe" : "wield axe",
  ]) );
}


void eventEnemyDied(object died) {
  if (base_name(died) == SOUTHERN_COAST_TOWNS "haven/npc/dwarf") {
    eventForce("yell All right then, the merchant is dead!");
    eventForce("get all");
    environment()->eventPrint("The bandit flees back from whence he came!");
    call_out( (: eventDestruct :), 0);
  }
  return ::eventEnemyDied(died);
}

string GetTown() { return "Wilderness"; }