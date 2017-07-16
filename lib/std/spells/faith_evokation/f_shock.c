/* Shock Spell
 * A slightly less powerful version of a lightning bolt.
 * Balanced and Re-Coded 3 Sept 1997
 * Duuktsaryth@Haven
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create(){
    spell::create();
    SetSpell("holy fury");
    SetRules("", "LIV");
    SetSpellType(SPELL_COMBAT);
    SetSkills( ([
           "faith" : 200,
           "evokation" : 200,
    ]) );
    SetMorality(0);
    SetDifficulty(50);
    SetAutoDamage(0);
    SetDamageType(SHOCK);
    SetEnhanceSkills( ({ "shock magic" }) );
    SetMessages( ({
    ({"are",
      "$target_name $target_verb %^YELLOW%^shocked%^RESET%^ by " + "$agent_possessive_noun holy fury." }),
    ({ "electrocute",
      "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ $target_name with " + "a furious touch of $agent_possessive palm." }),
    ({ "unleash",
      "$agent_name $agent_verb " + "%^YELLOW%^BOLD%^holy fury%^RESET%^ upon $target_name!" }),
    }) );
   SetHelp(
      "This spell will attempt to unleash a bolt of pure energy at the "
      "specified target. If none is specified, you will shock your current opponent."
      );
}


/* Approved by Duuktsaryth on Wed Sep  3 18:33:34 1997. */
