//
// Flaming Arrow Spell
// Coded by Dunedain@Haven
// 16 September 1997
// Adjusted to new Requirements by Arathorn@Haven
// 14 December 1998
// Spell Messages updated by Torak@Haven
// 1 June 2017
//


#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("flaming arrow");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
    "evokation" : 1,
    "faith"     : 1,
           ]) );
  SetDifficulty(10);
  SetAutoDamage(0);
  SetMorality(0);
  SetDamageType(HEAT|PIERCE);
  SetEnhanceSkills( ({ "fire magic" }) );
 //
 // SetMessages(({
 //   ({ "attempt", "$agent_name $agent_verb to summon a flaming arrow to "
 //      "discipline $target_name, but, alas, $agent_possessive faith is not "
 //      "quite strong enough." }),
 //   ({ "pray", "As $agent_name $agent_verb to $agent_possessive God, a "
 //      "flaming arrow appears to discipline the offenders of "
 //      "$agent_possessive_noun faith and stings $target_name." }),
 //   ({ "", "As $agent_possessive_noun prayers reach the ears of "
 //      "$agent_possessive God, a flaming arrow charged with wrath of God "
 //      "appears and slams into the treacherous $target_name." })
 // }));
 // SetHelp(
 //         "This spell allows those with enough faith to receive a flaming "
 //         "arrow from their Gods that flies towards the enemy specified.  "
 //         "If cast without specifying a target while in combat, the "
 //         "flaming arrow is targetted at your current enemy.");
 //
   SetMessages( ({
     ({ "fail", "%^BLACK%^BOLD%^$agent_name $agent_verb to maintain a chanting "
                "prayer.%^RESET%^" }),
	 ({ "maintain", "%^BLACK%^BOLD%^$agent_name barely $agent_verb the chant "
                    "before a %^RED%^flaming arrow%^RESET%^ appears and hurls "
                    "itself at $target_name.%^RESET%^" }),
	 ({ "summon", "%^BLACK%^BOLD%^Through the power of a soft chant $agent_name "
                 "$agent_verb %^RED%^BOLD%^a flaming arrow%^BLACK%^BOLD%^ which "
                 "hurls itself at and strikes $target_name!" }),
	 }) );
  SetHelp(
    "Through the power of prayer and faith a flaming arrow strikes the target. "
	"Cast flaming arrow at <target> "
	"If no target is stated during cast current target will be applied."
	);
}
