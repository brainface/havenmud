//
// Remove Infection for thorian
// Thoin@haven
//

#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("remove minor infection");
  SetSpellType(SPELL_HEALING);
  SetRules("", "LIV");
  SetMagicCost(30, 30);
  SetStaminaCost(10, 10);
  SetSkills( ([
       "necromancy" : 10,
       "faith" : 10,
    ]) );
  SetDifficulty(40);
  SetReligions("Thorian");
  SetHelp(
         "This spell allows a faithful thorian cleric to cure themself "
         "or others of minor diseases.");
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
      send_messages( ({ "fail" }),
         "$agent_name $agent_verb to cure the infection in $target_name.",
         who, sicko, environment(who) );
     return 1;
    }
  send_messages("remove",
    "$agent_name $agent_verb " +
    germ[0]->GetKeyName() + " from $target_name.",
     who, sicko, environment(who) );
    germ[0]->eventDestruct();
   return 1;
 }
