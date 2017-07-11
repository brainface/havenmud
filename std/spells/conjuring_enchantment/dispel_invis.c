//
// The 'dispel invisibility' spell
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("dispel invisibility");
   SetSpellType(SPELL_OTHER);
   SetMagicCost(25,25);
   SetRequiredMagic(50);
   SetRules("");
   SetSkills( ([ 
     "conjuring" : 30,
     "enchantment" : 30,
   ]) );
   SetDifficulty(20);
   SetMorality(0);
  SetHelp(
           "This spell causes a currently invisible player "
           "to step out of the shadows and be visible again, ending "
           "the effects of their 'invisibility' spell.");
}

int CanCast(object who, int level, string limb, object *targets) {
   if (!who->GetInvis()) {
      message("my_action","You aren't invisible!",who);
      return 0;
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
   who->SetInvis(0);
   send_messages("step", "$agent_name $agent_verb out of "
                 "the shadows.",who,0,environment(who));
   return 1;
}
