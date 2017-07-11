/*  A huge dragon.
 *  modified so the breathe weapon wouldnt
 *  kill someone not in the cave with her
 *  Gabriel@Haven 10/17/99
 *  Changed Morality to 5000 Zalbar 8/08
 */
#define FRIENDS ({ "gnath", "tithian", "bram" })
#define ENEMIES ({ "neptune", "dux" })
#include <lib.h>
#include <damage_types.h>
#include <daemons.h>
inherit LIB_NPC;
inherit LIB_FEAR;
void PossibleAttack();
varargs void eventStryke(object who); 
void CheckEnemy();
static void create() {
  npc::create();
  SetKeyName("stryke");
  SetMorality(5000);
  SetRace("dragon");
  RemoveLanguage("Dragonish");
  SetLanguage("Eltherian", 100, 1);
  SetClass("cavalier");
  SetClass("priest");
  SetReligion("Kylin");
  SetLevel(5000);
  SetMeleeAttackString("claws");
  SetMeleeDamageType(BLUNT);
  // Balishae added this so Stryke didn't get killed all the time.
  SetGender("female");
  SetShort("Stryke, the mightiest dragon of Kailie");
  SetId( ({ "dragon", "stryke" }) );
  SetAdjectives( ({ "mightiest" }) );
  SetLong("This towering mass of golden body is Stryke, the greatest "
         "dragon that has ever walked the world of Kailie.  Her towering "
         "form stands over the area in a display of power.");
  SetFearType("%^RED%^DRAGONFEAR%^RESET%^");
  SetFearLength(40 + random(40));
  SetResistLevel(200);
  SetAction(30, (: PossibleAttack :) );
  SetCombatAction(20, (: eventStryke :) );
  SetSpellBook( ([
     "hand of judgement" : 100,
     "superior wall of force" : 100,
    ]) );
  SetEncounter((: CheckEnemy() :));
  SetResistance(ALL_DAMAGE, "high");
  SetFirstCommands( ({ "cast superior wall of force", "cast superior wall of force", "cast superior wall of force" }) );
}


void eventEnemyDied(object who) {
  message("system",
   "%^GREEN%^A dragonish cackle howls across the land as Stryke kills " +
   capitalize(who->GetKeyName()) + ".", users() );
   eventForce("eat corpse");
  npc::eventEnemyDied(who);
}

void init() {
  npc::init();
  fear::init();
  if (userp(this_player()))
    CHAT_D->eventSendChannel("Stryke", "reports", this_player()->GetKeyName() + " has made contact with Stryke.");
}

varargs int eventDie(object agent) {
   if (agent) {
      message("shout",
    "%^GREEN%^" + capitalize(agent->GetKeyName()) + 
      " has killed Stryke!  Long live the Dragon Slayer!%^RESET%^",
         users() );
      agent->AddTitle("the Dragon Slayer");
      }
  return npc::eventDie(agent);
}


void PossibleAttack() {
  object *people;

  people = filter(all_inventory(environment()), (: living :));
  people -= ({ this_object() });
  foreach(object thing in people) { 
     if (member_array(thing->GetKeyName(), FRIENDS) != -1) {
            people -= ({ thing });
            }
     }       
  foreach(object thing in people) {
     eventForce("attack " + thing->GetKeyName());
     }
  return;
}

varargs void eventStryke(object who) {
  if(!who) who = GetCurrentEnemy();
  if (random(2)) {
    if(present(who))  {
      send_messages("breath", "$agent_name%^RED%^ $agent_verb%^RESET%^ a huge gout of flames and death at $target_name!", this_object(), who, environment());
      who->eventReceiveDamage(this_object(), HEAT, GetHealthPoints(), 0);
      }
  } else {
    eventForce("cast hand of judgement");
  }
  return;
}

void CheckEnemy() {
  object *people;

  people = filter(all_inventory(environment()), (: living :));
  people -= ({ this_object() });
  foreach(object thing in people) { 
      //Added by Morgoth after Neptune killed Stryke at least 15 times in
      //the space of 3 days.
      if(member_array(thing->GetKeyName(), ENEMIES) != -1) {
        message("", "%^RED%^Strykes eyes glow with fury as she spots one of her most hated enemies.%^RESET%^", environment());
        AddEnemy(thing);
        call_out("eventStryke", 6, thing); 
      }
    }
  }

int GetLanguageLevel(string str) {
	return 100;
}

mixed CanEat(object ob) {
	return 1;
}

varargs int CheckResistFear(object who, int lvl, string Type){
  if (creatorp(who)) { return 0; }
  if ((who->GetLevel() * (who->GetProperty("blessed") ? 2:1)) > lvl) {
    return 0;
  }
  if (member_array(who->GetKeyName(), FRIENDS) != -1) return 0;
  return (GetFearLength());
}
  
