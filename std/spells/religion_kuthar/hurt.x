/* Urgesh combat spell
 * by Arathorn@Haven
 * Messages altered slightly because seeing 'in the chest' severing
 * an arm was confusing players. - Laoise
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;
static void create() {
    spell::create();
    SetSpell("hurt");
    SetRules("", "LIV");
    SetSpellType(SPELL_COMBAT);
    SetRequiredMagic(20);
    SetSkills( ([
     "faith" : 1,
     "natural magic" : 1,
    ]) );
    SetDifficulty(20);
    SetAutoDamage(0);
    SetDamageType(MAGIC|BLUNT);
    SetMessages(({
    ({({ "point", "chant" }), "$agent_name $agent_verb $agent_possessive "
                            "finger at $target_name and $agent_verb "
                            "a strange series of words, but nothing "
                            "happens."}),
    ({ "point", "$agent_name $agent_verb $agent_possessive finger at "
                "$target_name, sending out an invisible energy wave "
                "which hits $target_objective with significant force." }),
    ({ "are", "$target_name $target_verb smashed full-force with the "
              "strength of $agent_possessive spell." }),
    }));
  SetHelp(
             "This is the most basic attack spell for Kutharian shamans. "
             "It creates an invisible energy blast aimed at the target's "
             "torso, hurting them.");
  }


/* Approved by Morgoth on Wed Sep 23 19:15:20 1998. */
