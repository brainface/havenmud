// mahkefel 2010   
// A lowbie timed shield for droods
#include <magic.h>                 
#include <lib.h>                   
#include <damage_types.h>          
inherit LIB_SPELL;                 

static void create() {
  ::create();         
  SetSpell("aura of righteousness");
  SetRules("");   
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
      "faith" : 40,
      "evokation" : 40,
  ]) );
  //SetMagicCost(10,20);
  SetDifficulty(25);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetReligions( "Anteky" );
  SetMessages( ({
    ({ "are",
      "$agent_possessive_noun plea is answered, and $agent_objective $agent_verb surrounded by an %^BOLD%^CYAN%^aura of righteousness%^RESET%^!"
    }),
    ({ "verb",
      "The %^BOLD%^CYAN%^aura of righteousness%^RESET%^ around $agent_name %^RED%^dulls%^RESET%^ the attack."
    }),
    ({ "verb",
      "$agent_possessive_noun %^BOLD%^CYAN%^aura of righteousness%^RESET%^%^CYAN%^ wanes%^RESET%^."
    }),
  }) );
  SetHelp(
    "The righteous of Anteky can protect themselves with a shield of "
    "sanctity, reducing the power of all violence against them due "
    "to the purity of their righteousness and faith."    );
}

