/* Kuthar combat spell
 * by Arathorn@Haven
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;
static void create() {
    spell::create();
    SetSpell("crush");
    SetRules("", "LIV");
    SetSpellType(SPELL_COMBAT);
    SetSkills( ([
     "faith" : 30,
     "evokation" : 30,
    ]) );
    SetDifficulty(40);
    SetAutoDamage(0);
    SetDamageType(MAGIC|BLUNT);
    SetMessages(({
    ({ "clench", "$agent_name $agent_verb $agent_possessive "
                      "hand into a fist, causing slight pressure to build up "
                      "around $target_possessive_noun body."}),
   ({ "clench", "$agent_name $agent_verb $agent_possessive "
                     "hand into a fist, causing a good deal of pressure to "
                     "build up, sending bolts of %^BOLD%^RED%^pain%^RESET%^ "
                     "throughout $target_possessive_noun body." }),
   ({ "writhe", "Bones snap and skin bruises terribly as $target_name "
                      "$target_verb in pain from $agent_possessive_noun "
                      "spell." }),
    ({ "scream", "$target_name $target_verb in bitter agony as "
                 "thousands of pounds of pressure are applied all around "
                 "$target_possessive body by $agent_possessive_noun spell."}),
    }));
  SetHelp(
             "This brutally painful Kuthar combat spell causes pressure "
             "to build up in the air around the target, crushing them.");
  }


/* Approved by Morgoth on Wed Sep 23 19:16:12 1998. */
