/*  A spell to nuke germs */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("cleanse flesh");
  SetSpellType(SPELL_HEALING);
  SetRules("LIV");
  SetSkills( ([
      "healing" : 20,
      "natural magic" : 20,
    ]) );
  SetDifficulty(40);
  SetHelp(
         "This spell when casted on a living target, makes an attempt "
         "to cure a LIVing target of a germ.");
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
         "$agent_name $agent_verb to cure diseases in $target_name, "
         "but $agent_verb.",
         who, sicko, environment(who) );
     return 1;
    }
  send_messages("cure",
    "$agent_name $agent_verb $target_name of " +
    germ[0]->GetKeyName() + ".",
     who, sicko, environment(who) );
    germ[0]->eventDestruct();
   return 1;
 }
