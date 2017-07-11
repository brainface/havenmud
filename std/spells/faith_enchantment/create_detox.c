#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <dirs.h>

inherit LIB_SPELL;

static void create() {
    spell::create();
  SetSpell("create detox potion");
    SetRules("");
    SetSpellType(SPELL_OTHER);
    SetRequiredMagic(30);
   SetSkills( ([
     "faith" : 10,
     "enchantment" : 10,
     ]) );
    SetMagicCost(50, 10);
    SetDifficulty(15);
    SetMorality(5);
  SetConjure(DIR_SPELLS "/obj/detox_potion");
  SetMessages( ({ 
       ({ "summon", "$agent_name $agent_verb a dark blue potion out of thin air." })
         }) );
  SetHelp(
          "This prayer allows the caster to create a potion of detoxification. "
          "The healer may use the potion to increase his own sobriety, or it "
          "may be passed on to aid another.  "
  );
}


