#include <lib.h>
#include <dirs.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("practical water");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetRequiredMagic(30);
  SetSkills( ([
    "practical magic" : 80,
    ]) );
  SetMagicCost(10, 10);
  SetDifficulty(5);
  SetMorality(0);
  SetConjure(DIR_SPELLS "/obj/create_water_ob");
  SetMessages( ({ 
       ({ "create", "$agent_name $agent_verb some water." }),
         }) );
  SetHelp(
          "Creating water is an essential skill for a caster. "
          "This spell allows the caster to create a small cup of water "
          "to quench their thirst. " );
}
