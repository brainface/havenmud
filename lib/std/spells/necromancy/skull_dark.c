/* 
 * Skull of darkness
 * Zeratul@Haven
 * Basically a copy of dark and light globe for necros
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <dirs.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("skull of darkness");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
     "necromancy" : 1,
  ]) );
  SetMagicCost(10, 5);
  SetDifficulty(20);
  SetMorality(0);
  SetConjure(DIR_SPELLS "/obj/skull_dark_ob");
  SetMessages( ({
     ({
    ({ "use", "summon" }), "$agent_name $agent_verb $agent_possessive necromantic "
     "powers to $agent_verb a skull of darkness. "
     }),
  }) );
  SetHelp(
     "This spell allows a necromancer to summon a skull that generates a negative "
     "effect against the light in the area, making it darker. "
  );
}
