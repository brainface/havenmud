#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("shimmer");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetHelp("Using this spell causes the target to slightly shimmer, making it more difficult "
          "to hit the target with physical attacks for a short time."
          );
  SetProtectionTypes(ALL_PHYSICAL);
  SetShieldType(SHIELD_TIMED);
  SetSkills( ([
    "illusion" : 4,
    ]) );
  SetMessages( ({ 
    ({ "start", "$agent_name $agent_verb to %^BOLD%^CYAN%^shimmer%^RESET%^ slightly in the light." }),
    ({ "", "$target_possessive_noun attack is slightly misaimed due to the %^BOLD%^CYAN%^shimmer%^RESET%^ around $agent_name." }),
    ({ "stop", "$agent_name%^RED%^ $agent_verb shimmering%^RESET%^." }),
  }) );
}