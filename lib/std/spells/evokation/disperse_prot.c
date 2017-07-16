//
// The 'disperse protections' spell
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("disperse protections");
   SetSpellType(SPELL_OTHER);
   SetRules("");
   SetSkills( ([
      "evokation" : 1,
   ]) );
   SetDifficulty(5);
   SetMagicCost(10,10);
   SetHelp(
     "This spell will interrupt the defensive shields "
     "currently active on the caster, removing them."
     );
}

int CanCast(object who, int level, mixed limb, object *targets) {
   int i = spell::CanCast(who, level, limb, targets);
   if(!(sizeof(who->GetMagicProtection()))) {
      message("system", "But you don't have any magical protection!",who);
      return 0;
   }
   return i;
}

int eventCast(object who, int level, mixed limb, object *targets) {
   int i = sizeof(who->GetMagicProtection());
   string shields;
   (i > 1 ? shields = "shields" : shields = "shield");
   while(i--) {
      who->RemoveMagicProtection(i);
   }
   send_messages( ({ "disperse" }), 
     "$agent_name $agent_verb $agent_possessive magical " + shields +".",
     who, 0, environment(who));
   return 1;
}
