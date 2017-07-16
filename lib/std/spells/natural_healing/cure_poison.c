#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("cure poison");
   SetSpellType(SPELL_OTHER);
   SetSkills( ([
      "healing" : 35,
      "natural magic" : 35,
   ]) );
   SetRules("", "LIV");
   SetDifficulty(25);
   SetStaminaCost(10,10);
   SetHelp(
     "This spell enables the caster to cure any deadly toxins that reside in one's body. "
  );
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

   send_messages(({"use"}), "$agent_name $agent_verb the powers of "
                 "nature to cure " + (target == who ?
                 "$target_possessive " : "$target_possessive_noun ")+
                 "body of the deadly poison!", who, target,
                  environment(who));
   if(amt > target->GetPoison()) { amt = target->GetPoison(); }
   target->AddPoison(-amt);
   if(target->GetPoison() > 0) {
      send_messages(({"look"}), "$target_name still $target_verb affected "
                    "by deadly poisons. ", who, target, environment(who));
   }
   return 1;
}
