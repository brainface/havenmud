// makes a potion that heals the drinker
// mahkefel '10
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <dirs.h>

inherit LIB_SPELL;

static void create() {
    spell::create();
  SetSpell("create healing potion");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetRequiredMagic(30);
  SetSkills( ([
    "faith" : 50,
    "enchantment" : 50,
  ]) );
  SetMagicCost(50, 10);
  SetDifficulty(15);
  SetConjure(DIR_SPELLS "/test_spells/obj/health_potion");
  SetMessages( ({
    ({ "summon", "$agent_name $agent_verb a dark red potion out of thin air." })
  }) );
  SetHelp(
    "This prayer allows the caster to create a potion of healing. "
    "The healer may use the potion to mend his wounds, or it "
    "may be passed on to aid another.  "
  );
}

