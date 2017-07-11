/* General faith spell.  Amelia@Haven Dec '98
 * Rebalanced by Dylanthalus April 11, 1999
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("pious obstructions");
   SetRules("","LIV");
   SetSpellType(SPELL_DEFENSE);
   SetProtectionTypes(ALL_EXTERNAL);
   SetShieldType(SHIELD_TIMED);
   SetDifficulty(60);
   SetSkills( ([
     "faith"       : 150,
     "evokation" : 150,
            ]) );
   SetMessages( ({
     ({ "","A dense %^ORANGE%^mist %^RESET%^coalesces around "
        "$target_name." }),
     ({ "","$target_possessive_noun attack "
        "is absorbed into "
        "the %^ORANGE%^mist%^RESET%^ surrounding $agent_name." }),
     ({ "","The %^RED%^mist %^RESET%^around $agent_name "
                      "fades into nothingness." }),
              }) );
  SetHelp(
      "Pious obstructions protect the target, or caster if "
      "no target is given, from all types of damage for the duration of the "
      "spell."
    ); 
}
