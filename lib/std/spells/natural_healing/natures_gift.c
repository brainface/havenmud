//
// The 'resurrect' spell for natural users
// Created by Thoin@Haven
//

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("nature's gift");
   SetRecoveryTime(20);
   SetRules("LIV");
   SetSpellType(SPELL_OTHER);
   SetSkills( ([ 
      "healing" : 100,
      "natural magic"   : 100,
   ]) );
   SetDifficulty(60);
   SetStaminaCost(250,51);
   SetHelp(
           "This powerful spell will use some of the strongest "
           "healing powers that nature has to offer to bring someone"
           " back from undeath. This spell is rumored to be a great "
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
   
   if( (environment(who)->GetClimate() == "indoors") ){
      message("system","Your spell fizzles and refuses to work "
              "in these types of environmental settings.",who);
      return 0;
   }

   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets) {
   foreach(object target in targets) {
      send_messages( ({ "call", "restore" }),"$agent_name $agent_verb "
                        "on nature to $agent_verb $target_name back from "
                        "undeath!",
                         who,target,environment(who));
      target->eventRevive();
   }
   return 1;
}
