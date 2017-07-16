/* illusion summon
 * mahkefel 2011
 */
#include <lib.h>
#include <damage_types.h>
 inherit LIB_NPC;

static void create(){
  npc::create();
  SetShort("a fluffy white rabbit");
  SetLong("This rabbit looks completely harmless in every way. Nevertheless, "
    "her blunt carrot eating teeth are bared in a furious growl, and she hops "
    "rapidly towards you in a poor imitation of a charge."
  );
  SetKeyName("rabbit");
  SetAdjectives( ({"fluffy","white"}) );
  SetId(({"rabbit"}));
  SetRace("rodent");
  SetClass("animal");
  SetLevel(2);
  SetGender("female");
  SetMeleeDamageType(BLUNT);
  SetMeleeAttackString("buck teeth");
  SetProperty("hat_trick",1);
}

void eventEnemyDied(object ob) {
  message("system",
    "%^BLUE%^A fluffy white rabbit hops away to find a garden.%^RESET%^",
    environment() );
  call_out( (: eventDestruct :), 0);
  ::eventEnemyDied(ob);
}

