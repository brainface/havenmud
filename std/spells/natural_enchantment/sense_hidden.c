// Artanis@Haven (July 25, 2004)

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("sense hidden");
   SetSpellType(SPELL_OTHER);
   SetRules("");
   SetSkills( ([
     "natural magic" : 40,
     "enchantment" : 40,
   ]) );
   SetMagicCost(30, 30);
   SetMagicCost(5, 2);
   SetDifficulty(25);
  SetHelp(
     "By channeling the powers of Nature, the caster of this spell can "
     "sense any hidden beings in their immediate surroundings. "
  );
}

varargs int eventCast(object who, int level, mixed limb, object *targets) {
   int i, maxi, fail = 0;
   object *people = filter(all_inventory(environment(who)), (: playerp :));

   people -= ({ who });
   maxi = sizeof(people);
   for(i=0;i<maxi;i++) {
      if(people[i]->GetInvis()) {
         message("", "You sense " + capitalize(people[i]->GetKeyName()) +
                 " using the powers of Nature. ", who);
         if(!who->GetInvis()) {
            message("system","Your invisibility has been detected by "+
                    possessive_noun(who->GetName())+" magic.",people[i]);
         }
      } else fail++;
   }
   if(fail == maxi) {
      message("", "You sense no hidden beings amongst your surroundings.",who);
   }
   return 1;
}
