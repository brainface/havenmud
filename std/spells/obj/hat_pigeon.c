/* illusion summon
 * mahkefel 2011
 */
#include <lib.h>
#include <damage_types.h>
 inherit LIB_NPC;

static void create(){
  npc::create();
  SetShort("a white dove");
  SetLong("A beautiful white dove is flying around here, looking mostly "
    "terrified as she attempts to pointy arrows and spellfire."
  );
  SetKeyName("dove");
  SetAdjectives( ({"white"}) );
  SetId(({"dove"}));
  SetRace("bird");
  SetClass("animal");
  SetLevel(2);
  SetGender("female");
  SetMeleeDamageType(PIERCE);
  SetMeleeAttackString("beak");
  SetProperty("hat_trick",1);
}

void eventEnemyDied(object ob) {
  message("system",
    "%^BLUE%^A white dove flys away, looking for her master.%^RESET%^",
    environment() );
  call_out( (: eventDestruct :), 0);
  ::eventEnemyDied(ob);
}

