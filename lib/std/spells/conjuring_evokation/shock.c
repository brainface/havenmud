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
    SetSpell("shock");
    SetRules("", "LIV");
    SetSpellType(SPELL_COMBAT);
    SetSkills( ([
           "conjuring" : 25,
           "evokation" : 25,
    ]) );
    SetMorality(0);
    SetDifficulty(10);
    SetAutoDamage(0);
    SetDamageType(SHOCK);
    SetEnhanceSkills( ({ "shock magic" }) );
    SetMessages( ({
    ({"are",
      "$target_name $target_verb %^YELLOW%^jolted%^RESET%^ by " +
      "$agent_possessive_noun shocking grasp." }),
    ({ "electrocute",
      "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ $target_name with " +
      "a quick touch of $agent_possessive palm." }),
    ({ "roast",
      "$agent_name%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ " +
      "$target_name with a terrible hand of doom." }),
    }) );
   SetHelp(
      "This spell will attempt to electrocute the "
      "specified target. If none is specified, "
      "you will shock your current opponent.");
}


/* Approved by Duuktsaryth on Wed Sep  3 18:33:34 1997. */
