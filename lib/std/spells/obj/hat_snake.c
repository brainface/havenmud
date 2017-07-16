/* illusion summon
 * mahkefel 2011
 */
#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

static void create(){
  npc::create();
  SetShort("a poisonous viper");
  SetLong("This tiny, writhing snake is covered in alternating bands of "
    "white, red, and black. Clear venom drips from his open fangs."
  );
  SetKeyName("viper");
  SetAdjectives( ({"poisonous"}) );
  SetId(({"viper","snake"}));
  SetRace("snake");
  SetClass("animal");
  SetLevel(2);
  SetGender("male");
  SetMeleeDamageType(PIERCE);
  SetMeleeAttackString("fangs");
  SetProperty("hat_trick",1);
}

void eventEnemyDied(object ob) {
  message("system",
    "%^BLUE%^A poisonous viper slithers away, searching for the hat from "
    "wence it came.%^RESET%^",
    environment() );
  call_out( (: eventDestruct :), 0);
  ::eventEnemyDied(ob);
}

// bite someone
void eventMeleeAttack(object target, string limb) {
  npc::eventMeleeAttack(target, limb);
  if(!(random(10))) {
    target->AddPoison(2);
    message("system",
        "You feel the %^RED%^poison%^RESET%^ moving through your body.",
        target);
    message("system",
        capitalize(target->GetKeyName()) + " suddenly looks ill.",
        environment(target), target);
    }
  return;
}

