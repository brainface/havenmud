#include <lib.h>
#include <std.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("acolyte");
  SetShort("a pious acolyte of Kylin");
  SetLong(
    "This Acolyte of Kylin seems devoted to the idea of cutting off trade between Baria "
    "and Keryth."
    );
  SetId( ({ "acolyte", }) );
  SetAdjectives( ({ "pious", "kylin" }) );
  SetProperty("no bump", 1);
  SetRace("elf");
  SetGender("male");
  SetClass("cavalier");
  SetClass("priest");
  SetLevel(random(2)+20);
  SetFriends( ({ "acolyte", "cleric" }) );
  SetMorality(200);
  SetSpellBook( ([
    "fidei defensor" : 100,
    "wrath"          : 100,
   ]) );
  SetCurrency("imperials",random(70));
  SetInventory( ([
    STD_WEAPON "hack/battle_axe" : "wield axe",
  ]) );
  SetFirstCommands( ({ "cast fidei defensor" }) );
  SetCombatAction(30, ({ 
    "!cast fidei defensor",
    "!cast wrath",
    "!cast fidei defensor",
  }) );  
}


void eventEnemyDied(object died) {
  if (base_name(died) == BARIA_TOWNS "baria/npc/quest/merchant") {
    eventForce("yell All right then, the runner is dead!");
    eventForce("get all");
    environment()->eventPrint("The acolyte retires back from whence he came!");
    call_out( (: eventDestruct :), 0);
  }
  return ::eventEnemyDied(died);
}

string GetTown() { return "Wilderness"; }