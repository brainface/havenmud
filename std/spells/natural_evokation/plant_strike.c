//A ranger spell that evokes nature to aid in combat.
//coded by Malak@Haven 7/98
//edited by Syra@Haven 7/8 to include climate check
// edited messsage grammer slightly - Laoise, 9/04

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
    spell::create();
    SetSpell("plant strike");
    SetRules("", "LIV");
    SetSpellType(SPELL_COMBAT);
    SetSkills( ([
      "natural magic" : 300,
      "evokation"     : 300,
    ]) );
    SetDifficulty(15);
    SetAutoDamage(0);// Bad coder! External damage!
    SetDamageType(BLUNT);
    SetMessages(({
      ({ ({ "point", "chant" }), "$agent_name $agent_verb $agent_possessive finger "
               "at $target_name and $agent_verb a strange series of words, but nature "
              "does not respond." }),
      ({ "point", "$agent_name $agent_verb $agent_possessive finger at "
               "$target_name, calling the plants around $target_objective to lash "
               "out, lightly bruising $target_objective. "}),
      ({ "point", "$agent_name $agent_verb $agent_possessive finger at "
              "$target_name, causing the very plants to come alive and cut "
              "into $target_objective." }),
      }));
  SetHelp(   
    "This calls on the plants around the caster to reach out and "
    "strike the victim. Can only be used outdoor or while under "
    "the influence of a natural charge."
    );
}

int CanCast(object who, int level, mixed limb, object *targets) {
  if( (environment(who)->GetClimate() == "indoors") || (environment(who)->GetClimate() == "underground") ){
    if (!present("natural_charge", who)) {
      who->eventPrint("Your spell fizzles and refuses to work in these types of environmental settings.");
      return 0;
     }
  }
  return spell::CanCast(who, level, limb, targets);
}
