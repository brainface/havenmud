//
// The 'spirit call' spell
// Created by Arathorn@Haven
//

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("spirit call");
  SetRules("OBJ");
    SetSpellType(SPELL_OTHER);
  SetSkills( ([
    "necromancy" : 5,
    ]) );
  SetDifficulty(20);
  SetMorality(-10);
  SetHelp(
    "By summoning the energy that remains in a newly dead "
    "corpse, the caster has the ability to add it to his/her "
    "own stamina."
    );
}

int CanCast(object who, int level, string limb, object *targets) {
   object target = targets[0];

   if (!target) return 0;
   if(!target->GetDecayLife()) {
      who->eventPrint("spell_failure","You cannot draw energy from " + target->GetName() + "!");
      return 0;
   }
   if (target->GetUserCorpse()) { 
     who->eventPrint("That spirit refuses to be called.");
     return 0;
    }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
  object target = targets[0];
  object *inv = all_inventory(target);

  send_messages("draw", 
    "$agent_name $agent_verb some stamina from a corpse.",
     who, 0, environment(who));
  who->AddStaminaPoints(target->GetStrength());
  foreach(object thing in inv) {
     thing->eventMove(environment());
   }
  target->eventDestruct();
  return 1;
}
