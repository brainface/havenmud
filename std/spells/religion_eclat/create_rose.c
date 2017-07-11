#include <lib.h>
#include <std.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("create rose");
  SetReligions("Eclat");   
   SetRules("");
   SetSpellType(SPELL_OTHER);
   SetSkills( ([
      "natural magic" : 10,
      "enchantment" : 10,
            ]) );
   SetDifficulty(10);
   SetMagicCost(13,7);
   SetMorality(1);
   SetMessages( ({
                   ({ "cause","$agent_name $agent_verb a "
                      "beautiful rose to appear." }),
              }) );
  SetHelp(
           "Casting this spell creates a rose that is either "
           "red, yellow, or white.  The spell is for Eclatish "
           "druids.");
  SetConjure(STD_SPELLS "obj/rose");
   SetDetailedHelp("Similar to create flower, this spell brings "
                   "a more powerful rose into existance.  "
                   "Amelia's joyful powers have given it "
                   "a scent so pleasing that is heals stamina, "
                   "magic, and health.");
}
