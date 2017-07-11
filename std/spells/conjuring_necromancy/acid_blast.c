//
// The 'acid blast' spell
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("acid blast");
   SetSpellType(SPELL_COMBAT);
   SetRules("", "LIV");
   SetSkills( ([
     "conjuring"  : 20,
     "necromancy" : 20,
    ]) );
   SetMorality(-1);
   SetDifficulty(30);
   SetAutoDamage(0);
   SetDamageType(ACID);
   SetHelp( 
     "This spell conjures deteriorating acid out of thin air "
     "and hurls it towards your target. "
     );
   
}

int eventCast(object who, int level, string limb, object array targets) {
   object target = targets[0];
   int damage = GetDamage(level);
   int num = who->GetSkillLevel("necromancy")/20;
    if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
	    who->eventPrint("Your powers fail you.");
	    return 0;
	  }
   send_messages(({ "create", "hurl" }), 
     "$agent_name $agent_verb a ball of %^RED%^acid%^RESET%^ out of thin air and $agent_verb it at $target_name!",
     who,target,environment(who));
   target->eventReceiveDamage(who, GetDamageType(), damage, GetAutoDamage(), target->GetRandomLimb(target->GetTorso()));
   for(int i=0;i<num;i++) {
    if(sizeof(all_inventory(target))) {
      object thing = (all_inventory(target)[random(sizeof(all_inventory(target)))]);
         if(thing->GetMealType()) {
            send_messages("destroy", 
              "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_possessive_noun " + remove_article(thing->GetShort())+" with $agent_possessive acid blast!",
              who, target, environment(who));
            thing->eventDestruct();
         } else {
           send_messages("corrode", 
              "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_possessive_noun " + remove_article(thing->GetShort())+" with $agent_possessive acid blast!",
               who, target, environment(who));
           thing->eventDeteriorate(GetDamageType());
          }
      }
   }
   return 1;
}
