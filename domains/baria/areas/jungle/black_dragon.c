/*  A black dragon */
#include <lib.h>
#include <damage_types.h>
#include "dragon.h"
inherit LIB_FEAR;
inherit LIB_NPC;
int CheckPlayer();

void eventBreatheAcid();
static void create() {
  npc::create();
  SetKeyName("Kysanth");
  SetGender("female");
  SetShort("Kysanth, the huge black dragon");
  SetFearType("%^RED%^DRAGONFEAR%^RESET%^");
  SetResistLevel(99);
  SetFearLength(random(40));
  SetRace("dragon");
  SetClass("animal");
  SetLevel(400);
  SetEncounter( (: CheckPlayer :) );
  SetMorality(-500);
  SetId( ({ "kysanth", "dragon" }) );
  SetAdjectives( ({ "large", "black" }) );
  SetCombatAction(20, (: eventBreatheAcid :) );
  SetLong("Kysanth, a black dragon, is a large creature that dominates the "
          "landscape around her. She is the oldest resident of the Barian "
           "Jungle and the guardian of its treasure.");
  }

void init() {
  fear::init();
  npc::init();
  }

void eventBreatheAcid() 
{
  object target = GetCurrentEnemy();

  if(present(target))
  {
    send_messages( "breathe",
      "%^BOLD%^RED%^With a gasp, " + 
      "$agent_name $agent_verb a gush of acid at $target_name!%^RESET%^",
      this_object(), target, environment(target) );
    target->eventReceiveDamage(this_object(), ACID, GetHealthPoints(), 
      0);
  }
  return;
}

int eventEnemyDied(object who) {
   eventForce("eat first corpse");
  eventForce("howl joy");
  ::eventEnemyDied(who);
  }

varargs int eventDie(object agent) {
  if (agent) {
  agent->AddTitle("the Jungle Blight");
  }
  return npc::eventDie(agent);
}

int CheckPlayer() {
  string tp_rel = this_player()->GetReligion();
  string tp_race = this_player()->GetRace();
  string tp_town = this_player()->GetTown();

  if(creatorp(this_player())) return 0;
  
  if ( (tp_rel == "Kuthar") && (tp_race == "draconian") )
    return 0;
  else
    if ( (tp_rel == "Kuthar") && (tp_race == "human") && (tp_town == "Baria") )
      return 0;
  return 1;
  }
