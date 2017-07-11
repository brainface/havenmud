/* Urgesh combat spell
 * by Arathorn@Haven
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;
static void create() {
    spell::create();
    SetSpell("mangle");
    SetRules("", "LIV");
    SetSpellType(SPELL_COMBAT);
    SetSkills( ([
    "faith" : 15,
    "evokation" : 15,
    ]) );
    SetDifficulty(28);
    SetAutoDamage(0);
    SetDamageType(MAGIC);
    SetMessages(({
    ({ "jerk", "$agent_name $agent_verb $agent_possessive hands in a "
                  "swift motion, attempting to bring harm to $target_name, "
                  "but nothing happens." }),
    ({ "jerk", "$agent_name $agent_verb $agent_possessive hands in a "
                   "swift motion, causing $target_possessive_noun body to "
                   "be wrenched in uncomfortable directions." }),
    ({ "", "$target_possessive_noun limbs and joints are "
            "%^BOLD%^RED%^mangled%^RESET%^ "
            "by $agent_possessive_noun attack." }),
    }));
  SetHelp(
             "This spell pulls the target's limbs outwards from his/her "
             "body, attempting to rip them apart.");
  }


/* Approved by Morgoth on Wed Sep 23 19:16:54 1998. */
