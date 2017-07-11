//
//  Disease spell for Thorians
//  Thoin@haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <std.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("carrier of the blessed plague");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
    "necromancy" : 400,
    "faith"      : 400,
  ]) );
  SetMagicCost(200, 200);
  SetDifficulty(20);
  SetMorality(0);
  SetAutoDamage(0);
  SetReligions("Thorian");
  SetHelp(
          "This spell allows a faithful thorian cleric to infect themselves with "
          "the blessed plague. The plague is infectious only to those of "
          "the faith."
          );
}


int CanCast(object who, int level, mixed limb, object *targets) {
  object *germ;
  germ = filter(all_inventory(who), (: $1->GetProperty("germ") :) );

   foreach(object germ2 in germ) {
      if (germ2->GetKeyName("blessed blight")) {
      message("system", "But you have already been infected with the blessed blight.", who);
      return 0;
      }
   }
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
  object target = targets[0];

          send_messages( ({"wrap", "grasp"}),
                  "%^BOLD%^%^BLACK%^Black smoke%^RESET%^ $agent_verb around "
                  "$agent_name and then it begins to slowly seep into $agent_possessive "
                  "skin.",who, 0,environment(who) );
     STD_GERMS "tplague"->eventInfect(who);
    return 1;
  }

