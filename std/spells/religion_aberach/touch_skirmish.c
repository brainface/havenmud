/* Approved by Zaxan on Wed Feb 11 01:55:04 1998. */

// updated by Torak 2012
// originally a skill level 10 spell

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("skirmish touch");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetReligions( ({ "Aberach" }) );
  SetSkills(  ([
    "faith" : 20,
    "necromancy" : 20,
  ])  );
  SetDifficulty(10);
  SetAutoDamage(0);
  SetDamageType(COLD);
  SetEnhanceSkills( ({ "ice magic" }) );
  SetMessages(  ({
    ({ "touch",
      "$agent_name hardly $agent_verb $target_name " +
      "with the destruction from a skirmish of the past. "}),
    ({ "batter",
      "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name " +
      "with the force of a past skirmish." }),
    ({ "focus",
      "$agent_name%^BOLD%^RED%^ $agent_verb%^RESET%^ all of " +
      "the energy from a single skirmish against $target_name."}),
    })  );
  SetHelp(
    "This spell causes the enemy to feel the destructive "
    "force of a past skirmish.  If cast without a specified "
    "target while in combat, your current enemy will be "
    "targetted." 
  );
}
