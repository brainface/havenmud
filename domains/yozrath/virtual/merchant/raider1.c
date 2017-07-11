#include <lib.h>
#include <std.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("nomad");
  SetShort("a rough looking desert nomad");
  SetLong(
    "This desert nomad appears ready to seize any cargo or money "
    "that comes within his grasp."
  );
  SetId( ({ "bandit", "nomad" }) );
  SetAdjectives( ({ "rough", "looking", "desert" }) );
  SetProperty("no bump", 1);
  SetClass("fighter");
  SetMorality(-200);
  SetLevel(random(2)+1);
  SetFriends( ({ "nomad" }) );
  SetGender("male");
  SetRace("human");
  SetBaseLanguage("Padashi");
  SetCurrency("dinar",random(70)+1);
  SetInventory( ([
    STD_WEAPON "hack/battle_axe" : "wield axe",
    ]) );
}


void eventEnemyDied(object died) {
  if (base_name(died) == YOZRATH_VIRTUAL "merchant/merchant") {
    eventForce("yell All right then, the merchant is dead!");
    eventForce("get all");
    environment()->eventPrint("The bandit flees back from whence he came!");
    call_out( (: eventDestruct :), 0);
  }
  return ::eventEnemyDied(died);
}
