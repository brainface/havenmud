// dumb copy of create light

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <dirs.h>
inherit LIB_SPELL;

static void create() {
spell::create();
  SetSpell("will o' wisp");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetRequiredMagic(15);
  SetSkills( ([
    "necromancy" : 10,
  ]) );
  SetMagicCost(10, 5);
  SetDifficulty(10);
  SetMorality(0);
  SetConjure( DIR_SPELLS "/obj/willowisp_ob");
  SetMessages( ({
     ({ "conjure", "$agent_name $agent_verb a ghostly, willowy light." }),
  }) );
  SetHelp(
    "This cantrip summons a minor and only slightly malicious spirit "
    "chained to the necromancers will--that will being to sit still and "
    "glow."
  );
}

