/*  Ruthlessly copied from Duuktsaryth's
 *  regenerate limb spell by Morgoth
 *  out of sheer lazyness on November 14 1998
 */
#include <magic.h>
#include <lib.h>
inherit LIB_SPELL;
object target, caster;
string *limbs;
int CheckValidLimb(string limb);
int eventRestoreLimb(string limb);

static void create() {
  spell::create();
  SetSpell("regrowth");
  SetRules("LIV","");
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
     "natural magic" : 75,
     "healing" : 75,
     ]) );
  SetDifficulty(30);
  SetHelp(
          "If cast without a target, this spell defaults to self. "
          "This spell will use the restoring power of nature to regrow "
          "a missing limb. Where multiple limbs are missing it will "
          "ask which limb should be regrown first. Be "
          "aware that restoring an arm does not restore the hand as well, "
          "and multiple limb losses must be replaced individually.");
  }

varargs int eventCast(object who, int level, mixed b, object *targets) {
   caster = who;
   target = targets[0];
  limbs = target->GetMissingLimbs();

  if (!sizeof(limbs)) {
     message("my_action",
        "But that person has all of " + possessive(target) + " limbs!",
        who);
     message("other_action",
         who->GetCapName() + " looks confused.",
         environment(who), who);
      return 1;
     }
  if (sizeof(limbs) == 1) {
       eventRestoreLimb(limbs[0]);
       return 1;
       }
  if (sizeof(limbs) > 1) {
       message("my_action",
         "The target is missing the following limbs: " +
         implode(limbs, ", ") + ".\n" +
         "Which would you like to regrow first?",
         who);
       input_to( (: CheckValidLimb :) );
       return 1;
       }
  return 1;
  }

int CheckValidLimb(string limb) {
  if(!(target->GetMissingLimb(limb))) {
    message("my_action",
      "That limb is not missing! The target is missing the following "
      "limbs: " + implode(target->GetMissingLimbs(), ", ") + ". Which "
      "do you wish to restore?",
        caster);
    input_to( (: CheckValidLimb :) );
     return 1;
     }
  if(!(target->GetLimb((target->GetMissingLimb(limb))["parent"]))) {
   message("my_action", 
      "That limb cannot be restored until the parent "
      "limb is restored. \nPlease enter a valid limb:", caster);
       input_to( (: CheckValidLimb :) );
      return 1;
     }
  return eventRestoreLimb(limb);
   }

int eventRestoreLimb(string limb) {
  send_messages( ({ "call", "restore" }),
     "$agent_name $agent_verb upon the power of nature to regrow " 
     "$target_possessive_noun " + limb + ".",
     caster, target, environment(caster));
   target->RestoreLimb(limb);
  return 1;
  }
