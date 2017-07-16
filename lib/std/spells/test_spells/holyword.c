#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("holy word");
  SetSpellType(SPELL_OTHER);
  SetRules("");
  SetSkills( ([
    "faith" : 350,
    "evokation" : 350,
    ]) );
  SetDifficulty(225);
  SetMinimumMorality(1000);
  SetMagicCost(150, 150);
  SetHelp("The ultimate offensive and defensive cleric spell. The spell afflects "
  "everyone in the room however the spell effect depends on the state and the "
  "alignment of the people. The spell does great damage and has a chance to completely "
  "destroy undeads. It will also do great damage to those of evil alignment while healing "
  "those of good alignment.");
 }

varargs int eventCast(object who, int level, mixed x, object array t) {
  int faith = who->GetSkillLevel("faith")*3 + level;
  int damage = GetDamage(level);
  object *targets = filter(all_inventory(environment(who)), (: living($1) && !newbiep($1) && noncreatorp($1) :));

  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
        } 
        
foreach(object target in targets){
 if (target->GetUndead()){
   int UndeadLevel = target->GetLevel();
  if (faith < UndeadLevel) {
    send_messages("speak", 
         "$agent_name $agent_verb a holy word stunning "
         "$agent_reflexive with its power.",
         who, target, environment(who) );
    who->AddEnemy(target);
    who->SetParalyzed(3);
    }
  if (faith > UndeadLevel && faith < UndeadLevel * 2) {
    send_messages("are",
      "$target_name $target_verb unaffected by $agent_possessive_noun "
      "holy word.",
      who, target, environment(who) );
      who->AddEnemy(target);
    }
  if (faith >= UndeadLevel * 2 && faith < UndeadLevel * 5) {
    send_messages("are",
      "$target_name $target_verb stunned by the power of $agent_possessive_noun "
      "holy word!",
      who, target, environment(who) );
      who->AddEnemy(target);
    target->SetParalyzed(2);
    }
  if (faith >= UndeadLevel * 5 && faith < UndeadLevel * 10) {
    send_messages("speak",
      "$agent_name $agent_verb a powerful holy word %^YELLOW%^stricking%^RESET%^ "
      "$target_name with its power!",
      who, target, environment(who) );
      who->AddEnemy(target);
  target->eventReceiveDamage(who, MAGIC|SHOCK, damage, 1);
      target->SetParalyzed(3);
    }
  if (faith > UndeadLevel * 10) {
    send_messages("are",
      "$target_name $target_verb %^RED%^obliterated%^RESET%^ by the "
      "power of $agent_possessive_noun holy word!",
      who, target, environment(who) );
    target->eventDestruct();
    }
  } else {
if(target->GetMorality() <= -200){
    send_messages("are",
      "$target_name $target_verb %^RED%^obliterated%^RESET%^ by the "
      "power of $agent_possessive_noun holy word!",
      who, target, environment(who) );
      who->AddEnemy(target);
  target->eventReceiveDamage(who, MAGIC|SHOCK, damage, 0); 
}
if(target->GetMorality() > -200 && target->GetMorality() < 200){
    send_messages("are",
      "$target_name $target_verb %^BLUE%^healed%^RESET%^ by the "
      "power of $agent_possessive_noun holy word!",
      who, target, environment(who) );
   damage = damage/3;
  target->eventHealDamage(damage, 1);  
}
if(target->GetMorality() > 200){
    send_messages("are",
      "$target_name $target_verb %^BOLD%^%^BLUE%^healed%^RESET%^ by the "
      "power of $agent_possessive_noun holy word!",
      who, target, environment(who) );
  target->eventHealDamage(damage, 1);  
}
}
}
return 1;
 }

