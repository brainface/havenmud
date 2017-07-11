#include <lib.h>
#include <magic.h>
#include <dirs.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("practical food");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetRequiredMagic(60);
  SetSkills( ([
    "practical magic" : 120,
  ]) );
  SetMagicCost(20, 20);
  SetDifficulty(10);
  SetMorality(0);
  SetConjure(DIR_SPELLS "/obj/create_food_ob.c");
  SetMessages( ({ 
       ({ "create", "$agent_name $agent_verb a loaf of bread." }),
         }) );
  SetHelp(
    "Creating food is an essential skill for a caster. "
    "This spell allows the caster to create a loaf "
    "of bread to satisfy hunger."
  );
}
