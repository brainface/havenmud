/*  The jolt spell for Kharnish Types */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("jolt");
  SetDifficulty(30);
  SetSpellType(SPELL_COMBAT);
  SetRules("", "LIV");
  SetSkills( ([
     "faith" : 50,
     "evokation" : 50,
    ]) );
  SetDamageType(MAGIC|SHOCK);
  SetEnhanceSkills( ({ "shock magic" }) );
  SetAutoDamage(0);
  SetMessages( ({
    ({ "send", "$agent_name $agent_verb small %^YELLOW%^jolts%^RESET%^ "
               "into $target_possessive_noun body." }),
    ({ "shock", "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ "
                "$target_name with "
                "moderate jolts of energy." }),
    ({ "scorch", "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ $target_name "
                 "badly with "
                 "magical energies." }),
     }) );
  SetHelp(
          "Allows the caster to send small amounts of magical energies "
          "into a target as an attack.");
 }
