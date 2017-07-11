/*
 * A pestilence Golem
 * full of badassness.
 * Melchezidek@Haven 2007
 */

#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <daemons.h>
#include <dirs.h>
#include "../cata.h"

inherit LIB_NPC;

int RestoreMe();
void eventBelch();
void eventConsume();
void eventBite();
void eventHealMe();
void eventDropStuff();
void doStuff();
static void create() {
  ::create();
  SetKeyName("pestilence golem");
  SetId( ({ "golem", "cata_npc" }) );
  SetShort("a pestilence golem");
  SetAdjectives( ({ "pestilence" }) );
  SetLong("A surging mass of worms and snakes and other vile"
          " creatures compose the body of this golem. It has"
          " been molded into a humanoid shape by some strong"
          " magical force, and without a doubt it would prove"
          " a very powerful foe.");
  SetRace("demon", "golem");
  SetGender("neuter");
  SetMorality(-2000);
  SetClass("fighter");
  SetLevel(110);
  SetBaseLanguage("Archaic");
  SetResistance(GAS, "immune");
  SetResistance(HUNGER, "immune");
  SetNoCorpse(1);
  SetCombatAction(85, (: doStuff :) );
}

void init() {
  npc::init();
}

varargs int eventDie(object who) {
  object germ;
  object key;
  
  if(random(10)) {
    key = new(CATA_OBJ "casket_key");
     key->eventMove(environment());
  }
  if(random(10) == 1) {
   germ = new(CATA_OBJ "pestilence");
   germ->eventMove(who);
   who->eventForce("cough");
  }
  new(CATA_OBJ "unicorn_heart")->eventMove(environment());
  return npc::eventDie(who);
 }

  
int RemoveLimb(string limb, object agent) {
    object asp;
    object tarantula;
    
    asp = new(CATA_NPC "asp1");
    tarantula = new(CATA_NPC "tarantula");
    new(CATA_NPC "worm")->eventMove(environment());
    new(CATA_NPC "rat")->eventMove(environment());
  
    if (limb == GetTorso()) return 0;
    if( environment() ) {
    asp->eventMove(environment());
    tarantula->eventMove(environment());
    message("environment", "As the " + limb + " falls to the ground, the creatures"
                          " that compose it regain their will.", environment());
    return npc::RemoveLimb(limb, agent);
        }
  }
  
int RestoreMe() {
  int count = 0;
  object *critters = ({ });
  int addhp = 0;
  
  critters = filter(all_inventory(environment(this_object())), (: $1->id("golem_piece") :) );
  count = sizeof(critters); 
  addhp = (this_object()->GetMaxHealthPoints() - this_object()->GetHealthPoints()) / 2;

  if (!sizeof(critters)) return 0;
  if(!sizeof(this_object()->GetMissingLimbs())) return 0;
  this_object()->NewBody("demon", "golem");
  this_object()->SetBleeding(0);
  this_object()->AddHealthPoints(addhp);
  critters->eventDestruct();
  message("environment", "The Pestilence Golem leans back and roars mightily as it"
                         " recalls the pestilence creatures to restore it's limbs.",
                         environment());
  return 1;
  }
  
void heart_beat() {
  ::heart_beat();
    RestoreMe();
} 

  /* combat specials */

  
void eventBelch() {
  send_messages( ({ "belch" }), "$agent_name opens it's mouth and%^GREEN%^ $agent_verb"
              "%^RESET%^, emitting a cloud of poisonous gas.", this_object(), 0,
              environment());
              environment()->AddPoisonGas(10);
            }
            
void eventConsume(object target) {
  send_messages( ({ "consume" }), "$agent_name slams into $target_name and $agent_verb"
              " $target_objective, restricting $target_possessive movements.",
               this_object(), target, environment());

  target->eventReceiveDamage(this_object(), BLUNT, 100, 0);
  target->eventCollapse();
  target->SetParalyzed(3);
 }
 
void eventBite(object target) {
  send_messages( ({"bite" }), "A snake erupts from the Pestilence golem's chest and"
                      "%^GREEN%^ $agent_verb%^RESET%^ $target_name.", this_object(),
                      target, environment());
  target->AddPoison(random(15));
  target->eventReceiveDamage(this_object(), POISON, 100, 0);
 }   
 
void eventHealMe() {                  
 int addhp = 0;
 addhp = (this_object()->GetMaxHealthPoints() - this_object()->GetHealthPoints()) / 2;
 
 this_object()->AddHealthPoints(addhp);
 send_messages("redistribute", "$agent_name $agent_verb the creatures that compose"
                        " it.", this_object(), 0, environment());
  }
 
void eventDropStuff() {
  send_messages("fall", "Some creatures fall out of the Pestilence Golem's body",
                    this_object(), 0, environment());
  new(CATA_NPC "tarantula")->eventMove(environment());
  new(CATA_NPC "worm")->eventMove(environment());
  new(CATA_NPC "worm")->eventMove(environment());
  new(CATA_NPC "rat")->eventMove(environment());
  new(CATA_NPC "asp1")->eventMove(environment());
}
 
void doStuff() {
object target = GetCurrentEnemy();

  switch(random(15)) {
  case 1:
   eventBelch();
   break;
  case 2:
   eventConsume(target);
   break;
  case 3:
   eventBite(target);
   break;
  case 4:
   eventHealMe();
   break;
  case 5:
   eventDropStuff();
   break;
  }
 }
