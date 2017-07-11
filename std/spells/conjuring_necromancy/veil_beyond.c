#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("veil from beyond");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetShieldType(SHIELD_TIMED);
  SetSkills( ([
    "conjuring"  : 100,
    "necromancy" : 100,
    ]) );
  SetDifficulty(120);
  SetProtectionTypes(ALL_EXTERNAL);
  SetMessages( ({
   ({ ({"summon","wrap"}) , "$agent_name $agent_verb forth "
          "necromantic energies and "
          "$agent_verb them around $target_name into a "
          "opaque %^BOLD%^%^BLACK%^veil%^RESET%^ of energy." }),
   ({ "hit", "The %^BOLD%^%^BLACK%^veil%^RESET%^ "
          "around $agent_name shimmers slightly "
           "as $target_name $target_verb it." }),
    ({ "veil", "The %^RED%^veil%^RESET%^ around"
           " $agent_name fades into the beyond." }),
    }) );
 
  SetHelp(
    "Using the powers of necromancy the mage is able to "
    "create a protective veil of necromantic energies that "
    "surround and protect the target from all magical and  "
    "physical damage for the duration of the spell."
    );    
 }
