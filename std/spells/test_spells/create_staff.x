// This spell has been removed from the game for the following reasons :
// 1) the object file's SetLong is crap and uses humans as measuring sticks
// 2) newbies get an infinite supply of craptastic staves from newbie equippers

// Removed by Torak
#include <lib.h>
#include <dirs.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("create staff");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetRequiredMagic(40);
  SetSkills( ([
     "conjuring" : 1,
     "enchantment" : 1,
  ]) );
  SetMagicCost(20, 40);
  SetDifficulty(10);
  SetConjure(DIR_SPELLS "/obj/wizard_staff");
  SetMorality(0);
  SetMessages( ({
    ({ ({"clap"}), "$agent_name $agent_verb $agent_possessive hands together "
      "and a staff appears in $agent_possessive grasp with a loud pop!" })
  }) );
  SetHelp(
    "One of the first spells apprentice enchanters learn is to summon an "
    "enchanted staff to provide them with some defense."
  );
}


