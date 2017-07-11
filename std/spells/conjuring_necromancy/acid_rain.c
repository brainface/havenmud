//
// The 'acid rain' spell
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("acid rain");
   SetSpellType(SPELL_COMBAT);
   SetAreaSpell(1);
   SetRules("");
   SetSkills( ([ 
     "conjuring"  : 50,
     "necromancy" : 50,
   ]) );
   SetMorality(0);
   SetDifficulty(40);
   SetDamageType(ACID);
   SetHelp("This spell creates a cloud of corroding acid that will rain upon "
           "everyone in the same environment as the caster, not including "
           "the caster."
          );
}

int eventCast(object who, int level, string limb, object array targets) {
   int damage = GetDamage(level);
   int num = who->GetSkillLevel("necromancy")/10;
    if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
          }
   send_messages(({ "create" }), "$agent_name $agent_verb a huge cloud "
                 "of %^RED%^acid%^RESET%^ which promptly rains on "+
                  conjunction(targets->GetName())+".",who,targets,
                  environment(who));
   if (num > 5) num = 5;
   foreach(object target in targets) {
   	if (!target) continue;
   	if (who->GetFriends() == target->GetKeyName()) return 0;
     target->eventReceiveDamage(who, GetDamageType(), damage, 0, target->GetRandomLimb(target->GetTorso()) );
     for(int i=0;i<num;i++) {
      object array eq = all_inventory(target);
      if(sizeof(eq)) {
        object thing = (eq[random(sizeof(eq))]);
        send_messages("", 
          "The acid falling from the sky promptly %^RED%^corrodes%^RESET%^ $target_possessive_noun " +
remove_article(thing->GetShort())+"!",
          who, target, environment(who));
          thing->eventDeteriorate(GetDamageType());
      }
    }
   }
   return 1;
}
