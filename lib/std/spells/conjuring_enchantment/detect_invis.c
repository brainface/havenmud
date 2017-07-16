//
// The 'detect invisibility' spell
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("detect invisibility");
   SetSpellType(SPELL_OTHER);
   SetRules("");
   SetSkills( ([
       "conjuring" : 35,
       "enchantment" : 35,
   ]) );
   SetMagicCost(75, 25);
   SetDifficulty(25);
  SetHelp(
           "Using the spell, the caster is able to detect any invisible "
           "beings in the immediate vicinity.");
}

varargs int eventCast(object who, int level, mixed limb, object *targets) {
   int i, maxi, fail = 0;
   object *people = filter(all_inventory(environment(who)), (: playerp :));

   people -= ({ who });
   maxi = sizeof(people);
   for(i=0;i<maxi;i++) {
      if(people[i]->GetInvis()) {
         message("system","You detect "+capitalize(people[i]->GetKeyName())+
                 " with your magic.", who);
         if(!who->GetInvis()) {
            message("system","Your invisibility has been detected by "+
                    possessive_noun(who->GetName())+" magic.",people[i]);
         }
      } else fail++;
   }
   if(fail == maxi) {
      message("system","Nobody was detected by your magic.",who);
   }
   return 1;
}
