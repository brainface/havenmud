

/*    
 * Nature's recovery
 * Thoin@haven
 * 01-25-06
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("nature's recovery");
  SetRules("", "LIV");
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
     "healing" : 250,
     "natural magic" : 250,
  ]) );
  SetStaminaCost(75, 200);
  SetRecoveryTime(5);
  SetDifficulty(175);
  SetHelp(
     "This spell greatly heals the target, or yourself if "
     "you specify no target. Also if cast on undead it will "
     "cause great damage to them.");
}

int CanCast(object who, int level, mixed limb, object *targets) {
   object target = targets[0];
    if(target->GetUndead()){
     return spell::CanCast(who, level, limb, targets);
   }
    if((target->GetHealthPoints()) == (target->GetMaxHealthPoints())){

    message("system", "That person does not need the aid of nature."
                 ,who);
      return 0;
   }
   return spell::CanCast(who, level, limb, targets);
}


int eventCast(object who, int level, mixed limb, object *targets) {
   object target = targets[0];
   int amt;
   amt = GetDamage(level);

  if(!target->GetUndead() || target == who) {
   send_messages(({"use"}), "$agent_name $agent_verb the powers of "
                 "nature to completely restore " + (target == who ?
                 "$target_possessive " : "$target_possessive_noun ")+
                 "body!", who, target,
                  environment(who));
   target->SetPoison(0);
   target->AddHealthPoints(target->GetMaxHealthPoints());
   target->SetBleeding(0);
 }
 else {
   send_messages(({"use"}), "$agent_name $agent_verb the powers of "
                 "nature in an attempt to destroy " + (target == who ?
                 "$target_possessive " : "$target_possessive_noun ")+
                 "body!", who, target,
                  environment(who));
   who->SetAttack(target);
 if (target->GetLevel() * 2 > who->GetSkillLevel("healing")){
   target->SetParalyzed(5);
 }
 else{
   target->eventReceiveDamage(who, MAGIC, amt, 1);
   target->SetParalyzed(2);
  }
}
   return 1;
}
