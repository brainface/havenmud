#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
	::create();
	SetSpell("burning hand");
	SetSpellType(SPELL_COMBAT);
	SetRules("", "LIV");
	SetSkills( ([
	  "faith" : 20,
    "evokation" : 20,
	  ]) );
  SetDifficulty(30);
  SetAutoDamage(0);
  SetDamageType(HEAT);
  SetEnhanceSkills( ({ "fire magic" }) );
	SetHelp("This spell causes the hand of the caster to flame, thus doing "
	        "damage to a target.");
	SetMessages( ({
		({ "touch", "$agent_possessive_noun hand starts to %^RED%^burn%^RESET%^.\n" +
		                   "Reaching out, $agent_name $agent_verb $target_name." }),
		({ "grasp", "$agent_possessive_noun hand starts to %^RED%^burn%^RESET%^.\n" +
		                   "Reaching out, $agent_name $agent_verb $target_name firmly." }),
		({ "burn", "$agent_possessive_noun hand starts to %^RED%^burn%^RESET%^.\n" +
		                    "With a sneer, $agent_name $agent_verb $target_name badly." }),
		                  }) );
}
          
