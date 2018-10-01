#include <lib.h>

int levelSkills(string player_name, int level) {
  object who = this_player();
  object target;

  if (!(target = find_living(player_name))) {
    debug("cain't find that player");
  }
  if (!target->GetTestChar()) {
    who->eventPrint("that ain't no test char");
    return 0;
  }
  if (level < 0 ) {
    who->eventPrint("We ain't gonna set their skills to negative brah");
    return 0;
  }
  if (level > 1000) {
    who->eventPrint("Yeah we're not gonner set their levels to over a thousand either.");
    return 0;
  }
  
  foreach(string skill in target->GetSkills()) {
    target->SetSkill(skill,level);
  }
  who->eventPrint(target->GetName() + " skill levels set to " + level);
  return 1;
}
