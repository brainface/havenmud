#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("shroud");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetShieldType(SHIELD_DAMAGE);
  SetSkills( ([
    "conjuring"  : 5,
    "necromancy" : 5,
    ]) );
  SetDifficulty(20);
  SetProtectionTypes(ALL_EXTERNAL);
  SetMessages( ({
   ({ ({ "wrap" }) ,"$agent_name%^BOLD%^BLACK%^ $agent_verb%^RESET%^ $target_name in a deathly shroud." }),
   ({ "hit",  "The %^BOLD%^%^BLACK%^shroud%^RESET%^ around $agent_name tears slightly as $target_name $target_verb it." }),
   ({ "", "The %^RED%^shroud%^RESET%^ around $target_name is rended into tatters." }),
   }) );
  SetHelp(
    "Using the powers of necromancy the mage is able to "
    "create a protective death shroud that "
    "surrounds and protect the target from all magical and  "
    "physical damage until it is completely ruined."
    );    
 }
