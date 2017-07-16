#include <lib.h>
#include <magic.h>
#include <position.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetAreaSpell(1);
   SetSpell("lullaby");
   SetRules("");
   SetSkills( ([
                 "faith" : 13,
                 "healing" : 10,
                 "enchantment" : 10,
            ]) );
   SetMagicCost(10,10);
   SetStaminaCost(10,5);
   SetRequiredMagic(20);
   SetRequiredStamina(15);
   SetDifficulty(25);
   SetSpellType(SPELL_OTHER);
   SetHelp("Syntax:  <cast lullaby>\n\n"
           "The caster calls special powers from their God, "
           "singing a lullaby that causes the target to relax at "
           "various levels.");
}

varargs int eventCast(object who, int level, mixed a, object array targets) {
   object target = targets[0];
   int my_lev = who->GetSkillLevel("faith") + who->GetStatLevel("wisdom");
   int tar_lev = target->GetLevel() + target->GetStatLevel("wisdom");
   int schtuff = my_lev - tar_lev;

   if( who == target) {
      send_messages(({ "begin","become","stop" }), "$agent_name $agent_verb "
                       "to drift off to sleep under $agent_possessive "
                       "own spell, but $agent_verb so weary that "
                       "$agent_nominative $agent_verb singing the "
                       "lullaby, waking $agent_objective.",
                       who, 0, environment(who));
      return 1;
   }

   if(schtuff <= 0) {
      send_messages("resist","$target_name $target_verb the "
                    "urge to sleep.",who,target,environment(target));
      return 1;
   }

   if(schtuff < 5) {
      target->eventChangePosition(POSITION_SITTING);
      send_messages( ({ "relax" }), "$target_name $target_verb "
                        "into a sitting position through "
                        "$agent_possessive_noun lullaby.",
                        who,target,environment(who));
      return 1;
   }
   if(schtuff < 10) {
      target->eventChangePosition(POSITION_LYING);
      send_messages( ({ "slip" }), "$target_name $target_verb to the "
                        "ground through $agent_possessive_noun "
                        "lullaby.",who,target,environment(who));
      return 1;
   }
   if(schtuff >= 10) {
      send_messages( ({ "fall" }),"$target_name $target_verb to the "
                        "ground, beginning to slumber, because of "
                        "$agent_possessive_noun lullaby.",who,
                        target,environment(who));
      target->eventCollapse();
      target->SetSleeping(schtuff);
      return 1;
   }
   return 0;
}
