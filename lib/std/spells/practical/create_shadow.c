#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <dirs.h>
inherit LIB_SPELL;

static void create() {
spell::create();
  SetSpell("practical darkness");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
    "practical magic" : 30,
    ]) );
  SetMagicCost(10, 5);
  SetDifficulty(10);
  SetMorality(0);
  SetConjure( DIR_SPELLS "/obj/create_shadow_ob");
  SetMessages( ({ 
        ({ "create", "$agent_name $agent_verb a globe of shadows." }),
        }) );
  SetHelp(
          "This spell will bring into being a small globe of "
          "energy that provides some darkness for the caster or others. "
          "the darkness produced is opposite that of a torch." );
}
