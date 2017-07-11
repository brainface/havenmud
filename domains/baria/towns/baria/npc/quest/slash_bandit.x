#include <lib.h>
#include <std.h>
#include <domains.h>
inherit LIB_NPC;
int Fighty();

static void create() {
  npc::create();
  SetKeyName("cleric");
  SetShort("a pious cleric of Kylin");
  SetLong(
    "This cleric of Kylin shows no interest in discussing world events, only in killing "
    "evil-doers and those that aid them."
    );
  SetId( ({ "cleric" }) );
  SetAdjectives( ({ "pious", "kylin" }) );
 
  SetRace("elf");
  SetGender("female");
  SetClass("priest");
  SetLevel(random(2)+1);
  SetFriends( ({ "acolyte", "cleric" }) );
  SetMorality(200);
  SetCurrency("imperials",random(70));
  SetInventory( ([
    STD_WEAPON + "slash/shortsword" : "wield shortsword",
  ]) );
  SetSpellBook( ([
    "fidei defensor" : 100,
    "wrath"          : 100,
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
    environment()->eventPrint("The cleric retreats back from whence he came!");
    call_out( (: eventDestruct :), 0);
  }
  return ::eventEnemyDied(died);
}

string GetTown() { return "Wilderness"; }