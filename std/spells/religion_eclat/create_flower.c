/* 
 * Created by Amelia@Haven.
 */
#include <lib.h>
#include <magic.h>
#include <std.h>
 
inherit LIB_SPELL;
 
static void create() {
   spell::create();
   SetMorality(1);
   SetSpell("create flower");
   SetReligions( ({ "Eclat" }) );
   SetRules("");
   SetSpellType(SPELL_OTHER);
   SetSkills( ([
     "natural magic" : 1,
     "enchantment"   : 1,
     ]) );
   SetMagicCost(9, 10);
   SetDifficulty(5);
   SetMessages( ({
      ({ "create", "$agent_name $agent_verb "
                   "a beautiful flower." })
      }) );
  SetHelp(
           "Casting this spell creates a beautiful flower, and there "
           "are many different colors the flower can be.  It is for "
           "Eclatish clerics.");
   SetConjure(STD_SPELLS "/obj/flower");
}
