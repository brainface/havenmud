#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("enhance joy");
   SetSkills( ([
                 "faith" : 5,
                 "enchantment" : 5,
            ]) );
   SetRules("","LIV");
   SetMagicCost(10,5);
   SetStaminaCost(10,5);
   SetRequiredMagic(15);
   SetRequiredStamina(15);
   SetSpellType(SPELL_OTHER);
   SetDifficulty(10);
   SetHelp("Syntax:  <cast enhance joy>\n"
           "         <cast enhance joy on LIV>\n\n"
           "This spell makes your emotions stronger then they were before, "
           "but it tends to have peculiar side effects.");
}

varargs int eventCast(object who, int level, mixed b, object array targets) {
   object target = targets[0];
   if( (target->GetAlcohol()) > (target->GetStatLevel("coordination") * 3 +
        random(target->GetStatLevel("luck")) +
        random(target->GetStatLevel("wisdom")) / 2) ) {
      if(target == who) {
         who->eventPrint("You are too drunk right now.");
      }
      else {
         who->eventPrint(target->GetCapName() + " is too drunk right now.");
      }
      return 1;
   }
   else {
      if(target == who) {
         send_messages( ({ "swoon","enhance" }),"$agent_name $agent_verb "
                           "a little as $agent_nominative $agent_verb "
                           "$agent_possessive emotions.",who,0,
                           environment(who));
      }
      else {
         send_messages( ({ "swoon","enhance" }),"$target_name $target_verb "
                           "a little as $agent_name $agent_verb "
                           "$target_possessive emotions.",who,target,
                           environment(target));
      }
   }
   target->AddAlcohol((level)*(who->GetStatLevel("wisdom"))/8 +
                      random(who->GetStatLevel("luck")));
   return 1;
}