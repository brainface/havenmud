#include <lib.h>
#include <dirs.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("create magic reserve");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetRequiredMagic(270);
  SetSkills( ([
     "conjuring" : 65,
     "enchantment" : 65,
  ]) );
  SetMagicCost(230, 40);
  SetDifficulty(40);
  SetMorality(0);
  SetConjure(DIR_SPELLS "/obj/reserve_potion");
  SetMessages( ({ 
    ({ "create", "$agent_name $agent_verb a magic potion from "
       "$agent_possessive own magical force." })
                }) );
  SetHelp(
    "This spell allows those with sufficiently well developed skills to "
    "create a potion and siphon some of their own magical energies into it "
    "for future use.  Obviously though, when energy is transfered from one "
    "place to another, much is lost."
  );
}



/* Approved by Zaxan on Sat Feb 14 20:52:47 1998. */
