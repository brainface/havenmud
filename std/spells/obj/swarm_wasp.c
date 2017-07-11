/* A wasp for the natural_evok
 * swarm spell.
 * Melchezidek - Sept 09
 */
#include <lib.h>
#include <damage_types.h>

inherit LIB_NPC;
void CombatStuffs();
void StingSting();
void Flake();
void Buzz();
void doAttack();

static void create() {
        ::create();
        SetShort("an angry wasp");
        SetLong("This is a large yellow and black wasp that has a very long"
                " stinger at the base of its abdomen. It looks very angry.");
        SetRace("wasp");
        SetKeyName("wasp");
        SetAdjectives( ({ "angry", "yellow", "black" }) );
        SetId("wasp");
        SetClass("animal");
        SetLevel(10);
        SetGender("female");
        SetMeleeDamageType(PIERCE);
        SetSkill("dodge", 150, 1);
        SetMeleeAttackString("stinger");
        SetCombatAction(100, (: CombatStuffs :) );
        SetDie("The wasp falls to the ground with one last buzz before dying.");
}

void StingSting(object target) {
        object owner = this_object()->GetOwner();
        int dmg = 25 + random(10);
        int xpamt = (dmg*2) * target->GetLevel();
        send_messages( ({ "fly", "sting" }), "$agent_name $agent_verb around"
                       " buzzing furiously before it $agent_verb $target_name!",
                       this_object(), target, environment());
        target->eventReceiveDamage(this_object(), POISON, dmg, 0);
        if (target->GetPoison() < 30) {
          target->AddPoison(random(2));
  }
        owner->AddExperience(xpamt);
}

void Flake(object target) {
        object owner = this_object()->GetOwner();
        int dmg = 100 + random(100);
        int xpamt = (dmg * target->GetLevel())/2;
        send_messages( ({ "stab" }), "$agent_name $agent_verb $target_name"
                      " horribly causing her stinger to break off in"
                      " $target_possessive_noun body!", 
                      this_object(), target, environment());
        target->eventReceiveDamage(this_object(), POISON, dmg, 0);
        if (target->GetPoison() < 30) {
          target->AddPoison((1 + random(10)));
         }
        owner->AddExperience(xpamt);
        this_object()->eventDie();
}

void Buzz(object target) {
        send_messages( ({"fly"}), "$agent_name $agent_verb around"
                     " $target_possessive_noun ear, buzzing furiously!",
                     this_object(), target, environment());
        target->AddRecoveryTime(random(10));
}
        

void CombatStuffs() {
        object target = GetCurrentEnemy();
        
        switch(random(100)) {
                case 0..65:
                        StingSting(target);
                        break;
                case 66..80:
                        Flake(target);
                        break;
                case 81..100:
                        Buzz(target);
                        break;
                }
        }
               
void eventEnemyDied(object ob) {
  message("system",
  "%^YELLOW%^An angry wasp flies away as her enemy dies.%^RESET%^",
  environment() );
  this_object()->eventDestruct();
  ::eventEnemyDied(ob);
  }
