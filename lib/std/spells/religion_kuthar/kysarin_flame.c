/* kysarin flame, for kysarin shamans,
    kyla 1-98
*/
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("kysarin flame");
  SetRules("LIV", "");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "natural magic" : 250,
     "faith" : 250,
  ]) );
  SetDifficulty(65);
  SetAutoDamage(0);
  SetDamageType(HEAT);
  SetEnhanceSkills( ({ "fire magic" }) );
  SetMessages( ({
         ({ "singe", "$agent_name%^RED%^ $agent_verb%^RESET%^ "
                     "$target_name with $agent_possessive "
                     "Kysarin Flame." }),
         ({ "burn", "$agent_name%^RED%^ $agent_verb%^RESET%^ "
                    "$target_name with $agent_possessive "
                    "Kysarin Flame."}),
         ({ "ignite", "$agent_name%^BOLD%^RED%^ $agent_verb%^RESET%^ "
                     "$target_name with $agent_possessive "
                     "Kysarin Flame."}),
             }) );
  SetHelp(
     "This spell summons forth a spew of flames towards the intended target. "
     "This is one of the kuthars most powerful spells, it emulates the flames "
     "of a powerful dragon and burns the target."
  );
  }
