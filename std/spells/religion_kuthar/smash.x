/* Urgesh Combat Spell.
 * Arathorn@Haven
*/
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;
static void create() {
    spell::create();
    SetSpell("smash");
    SetRules("", "LIV");
    SetSpellType(SPELL_COMBAT);
    SetSkills( ([
     "faith" : 8,
     "evokation" : 8,
    ]) );
    SetDifficulty(20);
    SetAutoDamage(0);
    SetDamageType(MAGIC|BLUNT);
    SetMessages(({
    ({ "scream", "$agent_name $agent_verb at the top of "
                      "$agent_possessive lungs in $target_possessive_noun "
                      "direction but nothing happens." }),
    ({ "scream", "$agent_name $agent_verb at the top of "
                       "$agent_possessive lungs in $target_possessive_noun "
                       "direction, sending a small, club shaped bolt of "
                       "%^YELLOW%^energy%^RESET%^ hurtling through the air, "
                       "striking $target_name in the stomach." }),
    ({ "cry", "$agent_name $agent_verb out in a primal scream, sending "
                 "a huge, club shaped blast of %^YELLOW%^energy%^RESET%^ "
                 "smashing into $target_possessive_noun head."}),
    }));
  SetHelp(
             "This spell creates a club-shaped blast of energy which "
             "strikes the target.");
  }



/* Approved by Morgoth on Sun Oct 11 01:47:17 1998. */
