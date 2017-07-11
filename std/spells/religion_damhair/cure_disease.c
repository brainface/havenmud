/*  A spell to nuke germs */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("drain disease");
  SetSpellType(SPELL_HEALING);
  SetRules("", "LIV");
  SetMagicCost(30, 30);
  SetStaminaCost(10, 10);
  SetSkills( ([
     "enchantment" : 30,
     "faith"       : 30,
    ]) );
  SetDifficulty(40);
  SetReligions("Damhair");
  SetHelp(
         "This spell makes an attempt to drain a LIVing target of a germ.");
  }

int CanCast(object who, int level, mixed u, object *targets) {
  if (!sizeof(filter(all_inventory(targets[0]), (: $1->GetProperty("germ") :) ))) {
    message("system", "But that person is not diseased!", who);
   return 0;
  }
  return ::CanCast(who, level, u, targets);
  }

int eventCast(object who, int level, mixed u, object *targets) {
  object *germ;
  object sicko = targets[0];

  germ = filter(all_inventory(sicko), (: $1->GetProperty("germ") :) );
  if (level + (random(who->GetStatLevel("luck"))) < germ[0]->GetCureChance()) {
      send_messages( ({ "attempt", "fail" }),
         "$agent_name $agent_verb to drain the diseases in $target_name, but $agent_verb.",
         who, sicko, environment(who) );
     return 1;
    }
  send_messages("convert",
    "$agent_name $agent_verb the" + germ[0]->GetKeyName() + " in $target_name into a cloudy water, which drains "
    "from $target_possessive_noun.", who, sicko, environment(who) );
  germ[0]->eventDestruct();
  return 1;
}
