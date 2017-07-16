// Torak Nov 2012

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("war touch");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetReligions( ({ "Aberach" }) );
  SetSkills(  ([
    "faith" : 300,
    "necromancy" : 300,
  ])  );
  SetDifficulty(40);
  SetAutoDamage(0);
  SetDamageType(COLD);
  SetEnhanceSkills( ({ "ice magic" }) );
  SetMessages(  ({
    ({ "touch",
      "$agent_name hardly $agent_verb $target_name " +
      "with the destruction from a war of the past. "}),
    ({ "batter",
      "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name " +
      "with the force of a past war." }),
    ({ "focus",
      "$agent_name%^BOLD%^RED%^ $agent_verb%^RESET%^ all of " +
      "the energy from a single war against $target_name."}),
  })  );
  SetHelp(
    "This spell causes the enemy to feel the destructive "
    "force of a past war.  If cast without a specified "
    "target while in combat, your current enemy will be "
    "targetted."
  );
}
