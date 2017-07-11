//
// The 'resurrect' spell
// Created by Zaxan@Haven
//
// Modified by Gabriel@Haven
//   to move stat loss to ress
//   for spell 10/17/99
//

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() 
{
  spell::create();
  SetSpell("advanced resurrection");
  SetRecoveryTime(100);
  SetRules("LIV");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([ 
    "healing" : 500,
    "faith"   : 500,
  ]) );
  SetMagicCost(350, 50);
  SetDifficulty(75);
  SetStaminaCost(300, 100);
  SetHelp(
    "This powerful spell will use some of the strongest "
    "healing power to bring someone back from "
    "undeath. This spell is rumored to be a great "
    "cost to the caster as that person must concentrate "
    "very hard to create its effect. \n"
    "**This spell cannot be self-targetted.**");
}

int CanCast(object who, int level, mixed limb, object array targets) {
   if (targets[0] == who) {
    who->eventPrint("You cannot use this spell on yourself.");
    return 0;
  }
   foreach(object target in targets) {
      if(!target->GetUndead()) {
         message("system","But "+target->GetName()+" is not "
                 "undead!.",who);
         return 0;
      }
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets) {
  foreach(object target in targets)   {
    send_messages( ({ "use", "bring" }),"$agent_name $agent_verb "
      "$agent_possessive great healing powers to "
      "$agent_verb $target_name back from undeath!",
      who,target,environment(who));
    target->SetUndead(0);
   }
   return 1;
}
