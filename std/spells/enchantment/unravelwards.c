//                    
// The 'disperse protections' spell
// Created by Zaxan@Haven          
//                                 
// copied by mahkefel again
#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();   
   SetSpell("unravel wards");
   SetSpellType(SPELL_OTHER);       
   SetRules("");                    
   SetSkills( ([                    
      "enchantment" : 5,              
   ]) );
   SetDifficulty(5);
   SetMagicCost(20,10);
   SetHelp(
     "This spell will unravel any unwanted defensive spells "
     "warding the caster, removing them."
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
   send_messages( ({ "unravel" }),
     "$agent_name $agent_verb $agent_possessive warding " + shields +".",
     who, 0, environment(who));
   return 1;
}

