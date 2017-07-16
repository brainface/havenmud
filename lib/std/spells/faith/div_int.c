#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("divine intervention");
  SetRules("",);
  SetSpellType(SPELL_DEFENSE);
  SetShieldType(SHIELD_TIMED);
  SetSkills( ([
    "faith" : 500,
    ]) );
  SetDifficulty(200);
  SetProtectionTypes(ALL_EXTERNAL);
  SetMessages( ({
   ({ ({"kneel", "chant", "are"}) , "$agent_name $agent_verb upon the ground and $agent_verb a prayer and"
                                               " $agent_verb enclosed in a majestic %^BOLD%^%^YELLOW%^aura%^RESET%^"
                                               " of spiritual power."
   }),
   ({ "attack", "$agent_possessive_noun $agent_verb is nullified by the %^BOLD%^%^YELLOW%^divine intervention%^RESET%^"" of $agent_possessive deity." }),
    ({ "dissolve", "The aura of %^BOLD%^%^YELLOW%^divine intervention%^RESET%^ around $agent_name has lifted." }),
    }) );
 
  SetHelp(
    "This shield is based purely upon the faith of the caster. It is the direct result of a commune with one's deity resulting in"
    " the God or Goddess's own personal blessing upon such a powerful champion of their cause. It protects against all forms of damage"
    " and is a reward only granted to the most pious and powerful followers."
    );    
}
