// mahkefel 2010
// A lowbie timed shield for magildan druid/mystics with
//   an arcanith theme
// Requires a reagent from arcanith
// It protects from all physical, poison, acid and gas damage
//   (arcanith's newbie creatures deal poison type damage,
//    I expanded the theme to "common necromantic attacks")
#include <magic.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("shielding shard");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
      "natural magic" : 30,
      "evokation" : 30,
  ]) );
  SetMagicCost(10,20);
  SetDifficulty(25);
  SetProtectionTypes(ALL_PHYSICAL|POISON|ACID|GAS);
  SetShieldType(SHIELD_TIMED);
  SetUniqueSpell(1);
  SetReligions("Magildan");
  SetMessages( ({
    ({ "chant",
      "$agent_name $agent_verb a few words of magic to a runed shard of "
      "marble, which %^BOLD%^CYAN%^glows%^RESET%^ brightly and begins "
      "orbiting $target_possessive_noun head."
    }),
    ({ "",
      "The orbiting shard %^CYAN%^intercepts%^RESET%^ "
      "$target_possessive_noun attack."
    }),
    ({ "",
      "The shard orbiting $agent_name %^ORANGE%^crumbles%^RESET%^ into "
      "dust." }),
    }) );
  SetHelp(
    "This spell temporarily reactivates a shard of ruined Arcanith's "
      "old wall, which shields the target from all physical damage and common "
    "necromantic attacks for a short period of time. The shard is consumed "
    "in the process."
  );
}

//if have a runed shard, dest it and shield us, otherwise fail.
varargs int eventCast(object who, int level, string limb, object array targets) {
  object *shards;
  debug("iterating thru inventory");
  shards = filter(all_inventory(who),
    (: member_array("arcanith_wall_shard", $1->GetId() ) > -1 :) );
  debug("i have this many shards: ");
  debug(sizeof(shards));
  if (sizeof(shards) < 1 ) {
    //debug("no shards, failing spell");
    // todo: fail message
    send_messages( "mutter", "$agent_name $agent_verb a few words of magic that "
      "sound impressive but have little effect", who, 0, environment(who) );
    return 0;
    who->eventPrint(
      "You must have a runed shard of marble from Arcanith to cast this spell!"
    );
  } else {
    if (shards[0]) shards[0]->eventDestruct();
    return spell::eventCast(who, level, limb, targets);
  }
}

