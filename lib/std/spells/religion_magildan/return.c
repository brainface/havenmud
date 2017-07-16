#include <lib.h>
#include <magic.h>
#include <daemons.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("return");
  SetDifficulty(15);
  SetRules("");
  SetMagicCost(50, 50);
  SetStaminaCost(5, 5);
  SetSkills( ([
     "conjuring" : 12,
     "natural magic" : 12,
     "evokation" : 12,
  ]) );
  SetHelp(
     "Allows a faithful of Magildan to return back to the town of Jidoor" 
  );
}

varargs int CanCast(object who, int level, string limb) {
        object env  = environment(who);
        int distance;

  if (env->GetProperty("no teleport")) {
     who->eventPrint("You cannot seem to flee this place.");
     return 0; 
    }

       distance = DISTANCE_D->GetDistance(env->GetDomain(), "Valley");
       SetDifficulty(50 * (1 + distance));
        return spell::CanCast(who, level, limb);
}


int eventCast(object who) {

  string origin;

  origin = "/domains/valley/towns/jidoor/room/temple/grove";

  send_messages( ({ "close", "disappear" }),
                 "$agent_name $agent_verb $agent_possessive eyes and $agent_verb. ",
                  who, 0, environment(who));

  who->eventMove(origin);
  who->eventDescribeEnvironment(0);

  send_messages("appear",
                 "$agent_name suddenly $agent_verb out of thin air. ",
                  who, 0, environment(who));

  return 1;
}

