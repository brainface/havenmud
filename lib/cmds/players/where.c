#include <lib.h>
#include <domains.h>
inherit LIB_DAEMON;

string find_where(object);
string find_domain(string what);

mixed cmd(string args) {
  object target;
  
  target = this_player();
  
  if (!args) {
    if (target->GetCanLocate()) 
      return "You can be located by other players.";
    return "You cannot be located by other players.";
  }
  if (args == "on") {
    target->SetCanLocate(1);
    return "You can now be located by other players.";
  }
  if (args == "off") {
    target->SetCanLocate(0);
    return "You can no longer be located by other players.";
  }
  if (args == "all") {
    foreach(object u in filter(users(), (: playerp($1) && environment($1) && !$1->GetTestChar() :) )) {
      this_player()->eventPrint(find_where(u));
    }
  return 1;
  }
  if (args == "me") args = target->GetKeyName();
  target = find_player(args);
  if (!target || target->GetInvis() || target->GetTestChar()) {
    this_player()->eventPrint("No target!");
    return 1;
  }
  if (creatorp(target) && !duukp(this_player())) {
    this_player()->eventPrint("Cannot where an Immortal.");
    return 1;
    }
  this_player()->eventPrint(find_where(target));
  return 1;
}

string find_where(object target) {
  string *path;
  object env;
  int v = 0;
  string base, where;
  where = "";
  env = environment(target);
  if (vehiclep(env)) {
    if (wagonp(env)) v = 2;
  if (shipp(env)) v = 1;
    env = environment(env);
  }
  if (!env) return target->GetCapName() + " is not available.";
  if (living(env) || vehiclep(env)) env = environment(env);
  if (!env) return target->GetCapName() + " is not available.";
  base = base_name(env);
  path = explode(base, "/");
  if (path[0] != "domains")
    where += "in " + env->GetDomain();
  if (path[2] == "virtual") 
    where += "roaming " + parse_area(path[3], path[1]) + " in " + parse_domain(path[1]) ;
  if (path[2] == "areas") 
    where += parse_area(path[3], path[1]) + " in " + parse_domain(path[1]);
  if (path[2] == "towns")
    where += "in the town of " + capitalize(path[3]) + " in " + parse_domain(path[1]);;
  if (path[1] == "planes")
    where = "on " + parse_domain(path[1]);
  if (path[1] == "islands")
    where = parse_area(path[3], path[1]);
  if (path[1] == "staff")
    where = parse_area(path[2], path[1]);
  if (path[1] == "estates")
    where = "in the private estate of " + env->GetOwner() + " in " + env->GetTown();
if (v) { where = "aboard a ship sailing " + env->GetShort(); }
if (v==2) { where = "riding a caravan near " + env->GetShort(); }
  if (target->GetCanLocate() == 0 && !duukp(this_player())) {
       if (path[1] == "estates") {
	      where = "in " + capitalize(find_domain(env->GetTown()) + "*");
       } else {
              where = "in " + parse_domain(path[1]) + "*";
       }
  }
  return target->GetCapName() + " is " + where + ".";
}


string find_domain(string what) {
        string *contents;
        contents = get_dir("/domains/");
        if (sizeof(what) == 0) return "Nope";
        foreach (string dom in contents) {
          string *towns;
          towns = get_dir("/domains/" + dom + "/towns/");
          if (!sizeof(towns)) continue;
          if (member_array(lower_case(what), towns) != -1) {
                return dom;
                break;
          }
        }
        return "Unavailable.";
}
string GetHelp(string s) {
  string h =
"Syntax:    where on/off \n"
"           where        \n"
"           where <player>    where me    where all\n"
"\n\n"
"This command allows you to easily locate other players for "
"roleplay opportunities. Using \"where on\" or \"where off\""
"sets your setting as to allowing other players know your general "
"location. \"where\" will display your current location. "
"\"where <player>\" and \"where all\" displays the location of "
"other players on the mud. \n"
"Be aware that \"where off\" doesn't completely hide you, only "
"makes your location more vague.";
  return h;
}
