#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("serenity");
   SetSpellType(SPELL_HEALING);
   SetSkills( ([
      "healing" : 100,
      "faith" : 100,
   ]) );
   SetRules("");
   SetDifficulty(45);
   SetHelp(
     "This spell allows a faithful individual to attempt to clear their mind."
   );
}

int eventCast(object who, int level, mixed limb, object *targets) {
   object target = targets[0];
   int amt = level + who->GetSkillLevel("healing")/2;

   send_messages(({"concentrate"}), "$agent_name $agent_verb on $agent_possessive deity clearing"
                 " $agent_possessive mind!", who, target, environment(who));
   if(amt > target->GetRecoveryTime()) { amt = target->GetRecoveryTime(); }
   target->AddRecoveryTime(-amt);
   if(target->GetRecoveryTime() > 0) {
      send_messages(({"appear"}), "$target_name still $target_verb to be dazed.",
                    who, target, environment(who));
   }
   return 1;
}
