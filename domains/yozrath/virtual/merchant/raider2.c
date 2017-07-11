#include <lib.h>
#include <std.h>
#include <domains.h>
inherit LIB_NPC;
int Fighty();

static void create() {
  npc::create();
  SetKeyName("nomad");
  SetShort("a wiry looking desert nomad");
  SetLong(
    "This desert nomad is a wiry specimen that is obviously "
    "out only to take what he can from the travellers in the "
    "desert."
  );
  SetId( ({ "nomad" }) );
  SetAdjectives( ({ "wiry", "looking", "desert" }) );
  SetClass("fighter");
  SetMorality(-200);
  SetLevel(random(2)+1);
  SetFriends( ({ "bandit" }) );
  SetGender("male");
  SetRace("human");
  SetBaseLanguage("Padashi");
  SetCurrency("dinar",random(70)+1);
  SetInventory( ([
    STD_WEAPON + "slash/shortsword" : "wield shortsword",
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
