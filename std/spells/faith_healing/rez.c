//
// The 'resurrect' spell
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("resurrect");
   SetRecoveryTime(50);
   SetRules("LIV");
   SetSpellType(SPELL_HEALING);
   SetSkills( ([ 
      "healing" : 150,
      "faith"   : 150,
   ]) );
   SetDifficulty(60);
   SetStaminaCost(250,51);
   SetHelp(
           "This powerful spell will use some of the strongest "
           "healing power to bring someone back from "
           "undeath. This spell is rumored to be a great "
           "cost to the caster as that person must concentrate "
           "very hard to create its effect.");
}

int CanCast(object who, int level, mixed limb, object array targets) {
   foreach(object target in targets) {
      if(!target->GetUndead()) {
         message("system","But "+target->GetName()+" is not "
                 "undead!.",who);
         return 0;
      }
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets) {
   foreach(object target in targets) {
      send_messages( ({ "use", "bring" }),"$agent_name $agent_verb "
                        "$agent_possessive great healing powers to "
                        "$agent_verb $target_name back from undeath!",
                         who,target,environment(who));
      target->eventRevive();
   }
   return 1;
}
