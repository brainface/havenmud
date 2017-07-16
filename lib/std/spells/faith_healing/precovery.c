



/*    
 * Perfect recovery
 * Thoin@haven
 * 01-25-06
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() 
{
  spell::create();
  SetSpell("perfect recovery");
  SetRules("", "LIV");
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
     "healing" : 275,
     "faith"   : 275,
  ]) );
  SetStaminaCost(75, 200);
  SetMinimumMorality(2200);
  SetDifficulty(195);
  SetHelp(
     "This spell greatly heals the target, or yourself if "
     "you specify no target as well as cure's them of many ailments. "
     "Also if cast on undead it will cause great damage to them.");
}

int CanCast(object who, int level, mixed limb, object *targets) {
   object target = targets[0];

  if(target->GetUndead()){
     return spell::CanCast(who, level, limb, targets);
   }
if (sizeof(filter(all_inventory(targets[0]), (: $1->GetProperty("germ") :) ))) {
   return spell::CanCast(who, level, limb, targets);
  }
    if((target->GetHealthPoints()) == (target->GetMaxHealthPoints())){

    message("system", "That person does not need your help."
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
   send_messages(({"pray"}), "$agent_name $agent_verb to $agent_possessive "
                 "god, with a flash of brilliant %^BOLD%^%^WHITE%^light%^RESET%^ "
                 + (target == who ? "$target_possessive " : "$target_possessive_noun ")+
                 "body is completely restored.", who, target,
                  environment(who));
   target->SetPoison(0);
   target->NewBody(target->GetRace());
   if (target->GetBlind()) target->eventBlind(1, 0);
   foreach(object ob in all_inventory(target)) {
      if (ob->GetProperty("germ")) ob->eventDestruct();
   }
   target->AddHealthPoints(target->GetMaxHealthPoints());
   target->SetBleeding(0);
 }
 else {
   send_messages(({"pray"}), "$agent_name $agent_verb to $agent_possessive god, "
                 "god, with a flash of brilliant %^BOLD%^%^WHITE%^light%^RESET%^ "
                 + (target == who ? "$target_possessive " : "$target_possessive_noun ")+
                 "body is harmed greatly.", who, target,
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

