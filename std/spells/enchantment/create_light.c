/*
 * Create Light Globe
 * A spell that creates a small ball of light
 * Created by Zaxan@Haven
 * 20th of February, 1997
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <dirs.h>
inherit LIB_SPELL;

static void create() {
spell::create();
  SetSpell("create light");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetRequiredMagic(15);
  SetSkills( ([
    "enchantment" : 10,
  ]) );
  SetMagicCost(10, 5);
  SetDifficulty(10);
  SetMorality(0);
  SetConjure( DIR_SPELLS "/obj/create_light_ob");
  SetMessages( ({ 
     ({ "create", "$agent_name $agent_verb a magical globe of light." }),
  }) );
  SetHelp(
          "This spell will bring into being a small globe of "
          "energy that provides some light for the caster or others. "
          "The light produced is equivelent to that of a torch." );
}
