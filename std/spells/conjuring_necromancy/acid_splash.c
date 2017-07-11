/* Created by Tim Morris (Morgoth) on 8-17-97 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("acid splash");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([ 
    "conjuring"  : 1,
    "necromancy" : 1,
    ]) );
  SetDifficulty(10);
  SetMorality(-1);
  SetAutoDamage(0);
  SetDamageType(ACID);
  SetMessages( ({ 
    ({ "get", "$target_name $target_verb a little %^BLUE%^wet%^RESET%^ from $agent_possessive_noun %^BOLD%^GREEN%^acid splash%^RESET%^." }),
    ({ "are", "$target_name $target_verb slightly %^RED%^burned%^RESET%^ by $agent_possessive_noun %^BOLD%^GREEN%^acid splash%^RESET%^. "}),
    ({ "scream", "$target_name $target_verb in %^RED%^pain%^RESET%^ as $target_possessive body is burned and mutilated by $agent_possessive_noun %^BOLD%^GREEN%^ acid splash%^RESET%^."})
    }));
  SetHelp(
    "This spell hurls a splash of noxious acid conjured from "
    "the depths of the underworld at your enemy. "
    "If cast without specifying a target while in combat, the "
    "acid is targetted at your current enemy."
    );
}



/* Approved by Duuktsaryth on Tue Sep  9 02:04:12 1997. */
