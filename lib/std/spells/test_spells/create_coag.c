// makes a potion that slows bleeding
// mahkefel '10
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <dirs.h>

inherit LIB_SPELL;

static void create() {
    spell::create();
  SetSpell("create coagulation potion");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetRequiredMagic(30);
  SetSkills( ([
    "natural magic" : 10,
    "enchantment" : 10,
  ]) );
  SetMagicCost(50, 10);
  SetDifficulty(15);
  SetConjure(DIR_SPELLS "/test_spells/obj/coag_potion");
  SetMessages( ({
    ({ "summon", "$agent_name $agent_verb a crimson potion out of thin air." })
  }) );
  SetHelp(
    "This prayer allows the caster to create a potion of coagulation. "
    "The healer may use the potion to slow his bleeding, or it "
    "may be passed on to aid another.  "
  );
}

