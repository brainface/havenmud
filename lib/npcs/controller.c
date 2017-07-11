#include <lib.h>
#include <dirs.h>
#include <daemons.h>
inherit LIB_NPC;

string *QuestWords = ({ "quest", "quests", "mission", "missions" });

mixed eventRequest(object who, string what) {
  string *missions = ({ });
  object missobj = 0;

  if (member_array(what, QuestWords) == -1 ) {
    eventForce("speak People normally <ask " + GetKeyName() + " for quests> "
               "or <request quest from " + GetKeyName() + ">!");
    return 1;
  }
  if (who->GetProperty("mission")) {
    eventForce("speak You already have a quest!");
    who->eventPrint("Use the <score> command to view your current quest.");
    return 1;
  }
  missions = MISSION_D->FilterMissions(GetTown());
  foreach(string mission in missions) {
    object tmp = load_object(mission);
    if (who->GetTestChar()) 
      debug("mission : " + mission);
    if (tmp->GetMinimumLevel() > who->GetLevel()) { 
      if (who->GetTestChar()) debug("Below Min Level"); 
      continue; 
    }
    if (tmp->GetMaximumLevel() < who->GetLevel()) { 
      if (who->GetTestChar()) debug("Above Max Level"); 
      continue; 
    }
    if (tmp->GetCompletedMission(who)) { 
      if (who->GetTestChar()) 
        debug("Completed"); 
        continue;
    }
    if (tmp->CanGetMission(who) != 1) { 
      if (who->GetTestChar()) 
        debug("Can't Get"); 
        continue; 
    }
    if (!missobj) { 
      if (who->GetTestChar()) 
        debug("!missobj missobj = " + mission); 
        missobj = tmp;
    }
    if (missobj->GetMissionPriority() < tmp->GetMissionPriority()) {
      if (who->GetTestChar()) 
        debug("Mission Priority : missobj = " + missobj->GetMissionPriority() + " tmp = " + tmp->GetMissionPriority());
        missobj = tmp;
    }
  }
  if (!missobj) {
    eventForce("speak Sorry, I have no new quests for you right now.");
    return 1;
  }
  eventForce("speak I have a quest for you.");
  eventForce("speak " + missobj->GetMissionDescription());
  who->SetPermanentProperty("mission", base_name(missobj));
  missobj->AssignMission(who);
  CHAT_D->eventSendChannel("Mission", "reports", capitalize(who->GetKeyName()) + " has been assigned " +
                           missobj->GetMissionName() );
  return 1;
}
    
void eventGreet(object who) {
  eventForce("speak You could <ask " + GetKeyName() + " for quests> to get something to do.");
}