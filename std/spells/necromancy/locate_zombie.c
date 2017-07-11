#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("locate zombie");
  SetSpellType(SPELL_OTHER);
  SetRules("");
  SetHelp(
    "Using this spell, the caster attempts to locate their most recently "
    "animated minion. Use of this spell will alleviate the chances of "
    "being killed as punishment for animating extra corpses."
    );
  SetMagicCost(100, 100);
  SetStaminaCost(50, 50);
  SetDifficulty(50);
  SetSkills( ([
    "necromancy" : 1,
    ]) );
}


string find_where(object target) {
  string *path;
  object env;
  string base, where;
  where = "";
  env = environment(target);
  if (vehiclep(env)) { env = environment(env); where += "aboard a ship "; }
  if (!env) return target->GetCapName() + " is not available.";
  if (living(env) || vehiclep(env)) env = environment(env);
  if (!env) return target->GetCapName() + " is not available.";
  base = base_name(env);
  path = explode(base, "/");
  if (path[0] != "domains")
    where += "in " + env->GetDomain();
  if (path[2] == "virtual") 
    where += "roaming in " + parse_domain(path[1]);
  if (path[2] == "areas") 
    where += parse_area(path[3], path[1]) + " in " + parse_domain(path[1]);
  if (path[2] == "towns")
    where += "in the town of " + capitalize(path[3]) + " in " + parse_domain(path[1]);;
  if (path[1] == "planes")
    where = "on " + parse_domain(path[1]);
  if (path[1] == "islands")
    where = parse_area(path[3], path[1]);
  return  where + ".";
}


varargs int eventCast(object who, int level, mixed u, object *t) {
  object zombie;
  object zombie_env;
  string file = who->GetProperty("animate_zombie");
  
  if (!file) {
    who->eventPrint("You find no zombies beholden to you.");
    return 1;
  }
  if (!zombie = find_object(file)) {
    who->eventPrint("Your zombie has returned to the realm of the dead.");
    who->RemovePermanentProperty("animate_zombie");
    return 1;
  }
  if (!zombie_env = environment(zombie)) {
    zombie->eventDestruct();
    who->eventPrint("Your zombie has returned to the realm of the dead.");
    who->RemovePermanentProperty("animate_zombie");
    return 1;
  }
  who->eventPrint("Closing your eyes to locate your " + zombie->GetCapName() +", you visualize... : \n" + zombie_env->GetShort() + " " + find_where(zombie));
  return 1;
}   