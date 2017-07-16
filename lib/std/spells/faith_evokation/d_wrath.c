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
    SetSpell("divine wrath");
    SetRules("", "LIV");
    SetSpellType(SPELL_COMBAT);
    SetSkills( ([
           "faith" : 400,
           "evokation" : 400,
    ]) );
    SetMorality(0);
    SetDifficulty(50);
    SetAutoDamage(0);
    SetDamageType(HEAT);
    SetEnhanceSkills( ({ "fire magic" }) );
    SetMessages( ({
    ({"are",
      "$target_name $target_verb %^RED%^toasted%^RESET%^ by " + "$agent_possessive_noun divine wrath." }),
    ({ "burn",
      "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name with " + "a furious touch of $agent_possessive palm." }),
    ({ "unleash",
      "$agent_name $agent_verb " + "%^RED%^BOLD%^divine wrath%^RESET%^ upon $target_name!" }),
    }) );
   SetHelp(
      "This spell will attempt to unleash a flaming divine wrath at the "
      "specified target. If none is specified, you will cast upon your current opponent."
      );
}

