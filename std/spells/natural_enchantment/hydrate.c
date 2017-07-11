//
// The 'hydrate' spell
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("hydrate");
   SetSpellType(SPELL_OTHER);
   SetRules("", "LIV");
   SetSkills( ([
      "natural magic" : 75,
      "enchantment" : 75,
   ]) );
   SetMagicCost(40, 20);
   SetDifficulty(15);
   SetHelp(
           "Using this spell, the caster is able to draw upon the "
           "nourishment of the surroundings to provide themself or "
           "their target with water. This spell is much more effective "
           "then the typical summon water spell.");
}

int CanCast(object who, int level, mixed limb, object *targets) {
   object target = targets[0];

   if(target->GetDrink() >= 1000) {
      if(target == who) {
         message("system","But you feel way too full to drink any more!",
                 who);
      } else {
         message("system","But "+target->GetName()+" looks way too full to "
                 "drink any more!", who);
      }
      return 0;
   } else return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
   object target = targets[0];
   int amt = level + random(who->GetSkillLevel("natural magic"));

   if(target == who) {
      send_messages("draw", "$agent_name $agent_verb upon the nourishment "
                    "of the surroundings in an attempt to hydrate "
                    "$agent_reflexive.", who, 0, environment(who));
   } else {
      amt -= target->GetLevel() * 2;
      send_messages("draw", "$agent_name $agent_verb upon the nourishment "
                    "of the surroundings in an attempt to hydrate "
                    "$target_name.", who, target, environment(who));
   }
   if(amt < 0) { amt = 0; }
   target->AddDrink(amt);
   return 1;
}
