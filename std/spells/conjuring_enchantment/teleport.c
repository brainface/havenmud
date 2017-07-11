/*  Teleport Spell
 *  Duuk
 */
#include <lib.h>
#include <magic.h>
#include <daemons.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("teleport");
  SetDifficulty(50);
  SetRules("STR");
  SetRequiredMagic(80);
  SetMagicCost(100, 100);
  SetSkills( ([
     "conjuring" : 190,
     "enchantment" : 190,
  ]) );
  SetHelp(
    "Allows a person to move themselves to a memorized target. "
    "The STR syntax must be used and STR should be either area or "
    "person. The difficulty of the spell increases with the distance the caster "
    "is teleporting. For example: cast teleport on area\n"
    "See also: lock person, lock area."
  );
  }

varargs object *GetTargets(object who, mixed args...) {
  object target;

  if(sizeof(args) > 1) {
     message("system", "Move to a person or an area?", who);
     return 0;
     }
  if ((args[0] != "person") && (args[0] != "area")) {
     message("system", "Move to a person or an area?", who);
     return 0;
    }
  if (args[0] == "area") {
    if(!(who->GetProperty("locked_area"))) {
       message("system", "You have no locked area.", who);
       return 0;
      }
  if(!(target = find_object(who->GetProperty("locked_area")))) {
       target = load_object(who->GetProperty("locked_area"));
      if(!target) { 
          message("system", "Problem with the target area.", who);
          return 0;
        }
     }
    return ({ target });
    }
  if(args[0] == "person") {
     if( !who->GetProperty("locked_target") )
     {
       who->eventPrint("You have not locked a target.");
       return 0;
     }
     target = find_object(who->GetProperty("locked_target"));
  if(!target) { 
     message("system", "Unable to find your target.", who);
    return 0;
     }
  if(!environment(target)) {
     message("system", "Unable to locate your target.", who);
     return 0;
      }
  return ({ target });
  }
 return 0;
}

varargs int eventCast(object who, int level, mixed n, object *T) {
  object env;
  string blarg;
  if (!sizeof(T)) {
    message("system", "No target destination!", who);
    return 0;
    }
  if(environment(who)->GetProperty("no teleport")) { return 0; }
  if(environment(who)->GetProperty("lower plane")) { return 0; }
  send_messages( ({ "open", "step" }),
     "$agent_name $agent_verb a swirling vortex of energy and $agent_verb inside.", who, 0, environment(who));
  if(living(T[0])) {
     env = (environment(T[0]));
     if(environment(T[0])->GetProperty("lower plane")) { return 0; }
     if(environment(T[0])->GetProperty("no teleport")) { return 0; }
     if(sscanf(base_name(env), "/domains/heaven/%s", blarg)) { return 0; }
      who->eventMove(environment(T[0]));
      who->eventDescribeEnvironment(0);
      send_messages("step",
          "A swirling vortex appears and $agent_name $agent_verb out.",
           who, 0, environment(who) );
        return 1;
       }
     env = T[0];
     if (!env) {
      who->eventPrint("You've managed to lose your locked area!");
      who->RemoveProperty("locked_area");
      return 1;
     }
     if(sscanf(base_name(env), "/domains/heaven/%s", blarg)) { return 0; }
     if(env->GetProperty("no teleport")) { return 0; }
     if(env->GetProperty("lower plane")) { return 0; }
     who->eventMove(env);
      who->eventDescribeEnvironment(0);
      send_messages("step",
          "A swirling vortex appears and $agent_name $agent_verb out.",
           who, 0, environment(who) );
    return 1;
  }

varargs int CanCast(object who, int level, mixed limb, object *targets) {
  object env  = environment(who);
  object envT; 
  int distance;
  
  if (!sizeof(targets)) {
    error("No targets!");
    return 0;
  }
  if (living(targets[0])) envT = environment(targets[0]);
    else envT = (targets[0]);
  if (!envT) {
    who->eventPrint("Something went wrong in your casting and you've lost your target.");
    who->RemoveProperty("locked_area");
    return 0;
  }
  distance = DISTANCE_D->GetDistance(env->GetDomain(), envT->GetDomain());
  SetDifficulty(50 * (1 + distance));
  if(who->GetTestChar()) debug("Diff: " + GetDifficulty() + " dist: " + distance);
  return ::CanCast(who, level, limb, targets);
}
 
