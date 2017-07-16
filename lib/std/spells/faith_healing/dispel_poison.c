//
// The 'dispel poison' spell
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("dispel poison");
   SetSpellType(SPELL_OTHER);
   SetSkills( ([
      "healing" : 50,
      "faith"   : 50,
   ]) );
   SetRules("", "LIV");
   SetMagicCost(30,20);
  SetMinimumMorality(100);
    SetDifficulty(22);
   SetStaminaCost(10,10);
  SetHelp(
           "Using this spell, a faithful person may dispel the poisons "
           "that may be in a player's body. The more skilled the healer, "
           "the more healing that will be done.");
}

int CanCast(object who, int level, mixed limb, object *targets) {
   object target = targets[0];

   if(!(target->GetPoison())) {
      if(target == who) {
         message("system", "But you don't seem to be poisoned!",
                 who);
         return 0;
      } else {
         message("system", "But that person doesn't seem to "
                 "be poisoned!",who);
         return 0;
      }
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
   object target = targets[0];
   int amt = level + who->GetSkillLevel("healing") / 10;

   send_messages(({"use"}), "$agent_name $agent_verb $agent_possessive "
                 "healing powers to dispel "+(target == who ? 
                 "$target_possessive " : "$target_possessive_noun ")+
                 "poison!",who, target,
                  environment(who));
   if(amt > target->GetPoison()) { amt = target->GetPoison(); }
   target->AddPoison(-amt);
   if(target->GetPoison() > 0) {
      send_messages(({"look"}), "$target_name still $target_verb affected "
                    "by poison.",who,target,environment(who));
   }
   return 1;
}
