/*  A 1/1 combat spell */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("condense air");
  SetRules("","LIV");
  SetSpellType(SPELL_COMBAT);
  SetDifficulty(10);
  SetSkills( ([
      "evokation"     : 6,
      "natural magic" : 6,
    ]) );
  SetHelp(
          "This spell condenses the air around a LIVing target "
          "to the point of suffocation and damaging the target. "
  );
  SetDamageType(MAGIC);
  SetAutoDamage(0);
  SetMessages( ({
    ({ "condense", "$agent_name $agent_verb the air around "
                   "$target_name, choking $target_objective "
                   "slightly." }),
    ({ "stifle", "$agent_name $agent_verb the air surrounding "
                 "$target_name, making $target_objective "
                 "sputter and cough." }),
    ({ "thicken", "$agent_name $agent_verb the air surrounding "
                 "$target_name, making $target_objective "
                 "sputter and cough badly." }),
    }) );
 }
