//
// Remove Daze spell
// Thoin@haven
//

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("soothing mind");
   SetSpellType(SPELL_HEALING);
   SetSkills( ([
      "healing" : 400,
      "natural magic" : 400,
   ]) );
   SetRules("", "LIV");
   SetDifficulty(300);
   SetHelp(
     "This spell allows a natural user to attempt to clear the daze effect from themself or "
     "a target. The spell is very difficult, be warned."
   );
}

int eventCast(object who, int level, mixed limb, object *targets) {
   object target = targets[0];
   int amt = level + who->GetSkillLevel("healing");

   send_messages(({"use"}), "$agent_name $agent_verb the powers of "
                 "nature to clear " + (target == who ?
                 "$target_possessive " : "$target_possessive_noun ")+
                 "mind!", who, target,
                  environment(who));
   if(amt > target->GetRecoveryTime()) { amt = target->GetRecoveryTime(); }
   target->AddRecoveryTime(-amt);
   if(target->GetRecoveryTime() > 0) {
      send_messages(({"look"}), "$target_name still $target_verb dazed."
                    , who, target, environment(who));
   }
   return 1;
}
