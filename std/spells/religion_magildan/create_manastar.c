/* ----------------------------------------------------------------------- */
// Area Title: None
// Filename: create_manastar.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Jan 23rd, 1999
// Abstract: MagildanSpell[tm]
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <magic.h>
#include <dirs.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("create manastar");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetMagicCost(250, 250);
  SetStaminaCost(100, 100);
  SetRecoveryTime(20);
  SetSkills( ([
     "conjuring" : 100,
     "natural magic" : 100,
     "evokation" : 100,
  ]) );
  SetDifficulty(100);
  SetConjure(DIR_SPELLS "/obj/create_manastar_ob.c");
  SetMessages( ({ 
       ({ "create", "$agent_name $agent_verb a manastar." }),
         }) );
  SetHelp(
          "One of the ultimate powers of the Magildan Mystic is "
          "this spell which allows them to summon a manastar into "
          "being. The manastar is a magical object which can be used "
          "to recover from some of the detrimental effect of spell "
          "casting. Be warned the creation of a manastar is physically "
          "draining as well as mentally." );
  SetDetailedHelp("This spell allows the Mystic to create a manastar "
          "from natural, supernatural and elemental energies.\n"
          "The manastar is not only a symbol of the Magildan faith "
          "but also a powerful magical object.  Using the manastar, "
          "a Magildan follower can heal themselves magically.  It "
          "will reduce recovery time and heal the magic in oneself.\n"
          "The creation of a manastar is highly taxing both magically "
          "and physically.  It is also somewhat random.  Sometimes "
          "the power of the manastar will not be as valuable as "
          "the energy to create it.");
}
