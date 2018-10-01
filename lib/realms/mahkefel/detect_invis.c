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


// mahkefel 2012: changed to detect anything of invis level 1.
// imms should be smert enough to setinvis 2
// coders should setinvis 2 things never to be seen.
//   I'm going to assume everyone's smart enough to have done this.
varargs int eventCast(object who, int level, mixed limb, object *targets) {
   int i, maxi, fail = 0;
   //object *people = filter(all_inventory(environment(who)), (: playerp :));
   object *people = all_inventory(environment(who));
   people -= ({ who });
   maxi = sizeof(people);
   for(i=0;i<maxi;i++) {
      //if(people[i]->GetInvis()) {
      if(people[i]->GetInvis() == 1) {
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

