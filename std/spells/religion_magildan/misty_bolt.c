#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("misty bolt");
  SetRules("LIV","");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "conjuring" :  75,
     "natural magic" : 75,
     "evokation" : 75,
    ]) );
  SetDifficulty(25);
  SetAutoDamage(0);
  SetDamageType(MAGIC|SHOCK);
  SetEnhanceSkills( ({ "shock magic" }) );
  SetMessages( ({
    ({ "fumble", "$agent_name $agent_verb in $agent_possessive "
                 "attempt to destroy $target_name." }),
    ({ "do", "$agent_name $agent_verb minimal damage to "
             "$target_name with $agent_possessive spell." }),
    ({ ({ "open", "assault" }), "$agent_name $agent_verb a "
                                "rift to the lower planes and "
                                "$agent_verb $target_name with "
                                "%^RED%^deadly energy%^RESET%^." }),
    }) );
  SetHelp(
     "This spell utilizes the power of the Magildan Mystic to "
     "create a mystical bolt of energy. "
  );
  }

