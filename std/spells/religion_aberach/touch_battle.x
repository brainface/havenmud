#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create()
{
	spell::create();
	SetSpell("battle touch");
	SetRules("", "LIV");
	SetSpellType(SPELL_COMBAT);
  SetReligions( ({ "Aberach" }) );
  SetMaximumMorality(-200);
	SetSkills(  ([
         "faith" : 25,
       "necromancy" : 25,
		])  );
	SetDifficulty(15);
	SetAutoDamage(0);
	SetDamageType(COLD);
  SetEnhanceSkills( ({ "ice magic" }) );
	SetMessages(  ({
		({ "touch",
		"$agent_name $agent_verb $target_name with a wisp " +
		"of the power of a battle." }),
		({ "assault",
		"$agent_name%^BOLD%^BLUE%^ $agent_verb%^RESET%^ " +
		"$target_name with the power of a battle."  }),
		({ "unleash",
		"$agent_name%^BOLD%^RED%^ $agent_verb " +
		"%^RESET%^the full force of a battle on $target_name. " }),
		})  );
  SetHelp(
		"This spell taps into the raw force of the battles "
                "overseen by the Dark Goddess.  If cast without a "
		"specified target while in combat, your current enemy "
		"will be targetted.  ");
}
