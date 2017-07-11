/* Gangrene
 * Continuously rots limbs
 * Coded by Zeddicus@Haven on June 28, 1999
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("gangrene");
  SetReligions("Thorian");
  SetRules("LIV", "");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "necromancy" : 40,
     "faith"      : 40,
  ]) );
  SetMagicCost(50,50);
  SetStaminaCost(10,10);
  SetRecoveryTime(1);
  SetDifficulty(50);
  SetMorality(-5);
  SetHelp("Causes a target's limb to become gangrenous.");
}

int CanCast(object who, int level, mixed limb, object *targets) {
  if (present("gangrene_thingy", targets[0])) {
    who->eventPrint("That person is already afflicted with gangrenous "
                    "flesh.");
    return 0;
  }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
  object target = targets[0];
  object gangrene = new("/std/spells/obj/gangrene_obj");
  limb = target->GetRandomLimb();
  level /= 10;
  if (!level) level = 1;
  
  gangrene->eventMove(target);
  gangrene->SetArgs(limb, who, level, (who->GetSkillLevel("necromancy") +
                    who->GetLevel())/4);
  send_messages( ({ "grin", "touch" }) , "$agent_name $agent_verb "
    "maniacally as $agent_nominative $agent_verb $target_possessive_noun " +
    limb + ", turning it into gangrenous flesh.", who, target,
    environment(who));
  who->eventForce("cackle");
  return 1;
}


/* Approved by Zeddicus on Mon Jul  5 04:35:16 1999. */
