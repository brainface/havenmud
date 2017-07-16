/* Mission Lib */
#include <lib.h>

string Town;
string Title;
string MissionName;
string MissionDescription;
int *MissionLevel;
int MissionPriority;
string Reward;

static void create() {
  Town = Title = MissionName = MissionDescription = 0;
  MissionLevel = ({ 1, 300 });
  MissionPriority = 50;
  Reward = "";
}

string SetReward(string x) { return Reward = x; }
string GetReward() { return Reward; }

int SetMissionPriority(int x)      { return MissionPriority = x; }
int GetMissionPriority()           { return MissionPriority;     }

int *SetMissionLevel(int x, int y) { return MissionLevel = ({ x, y }); }
int *GetMissionLevel()             { return MissionLevel; }

int GetMinimumLevel() { 
  if (!sizeof(MissionLevel)) return 0;
  return MissionLevel[0];
} 

int GetMaximumLevel() {
  if (sizeof(MissionLevel) < 2) return 500;
  return MissionLevel[1];
}

string SetTown(string x) { return Town = x; }
string GetTown()         { return Town;     }

string SetMissionName(string x) { return MissionName = x; }
string GetMissionName()         { return MissionName;     }

string SetMissionDescription(string x) { return MissionDescription = x; }
string GetMissionDescription()         { return MissionDescription;     }

string SetTitle(string x) { return Title = x; }
string GetTitle()         { return Title;     }

int GetCompletedMission(object who) {
  if (who->GetQuestCompleted(MissionName)) return 1;
  return 0;
}

void eventCompleteMission(object who) {
  who->AddQuest(Title, MissionName);
  who->RemovePermanentProperty("mission");
  return;
}

int CheckCompletedMission(object who) {
  /* This function should be written into every mission.  It will be
   * checked by the heart_beat of the player. It should return 0 if 
   * the player has NOT completed the mission, and should return 1
   * if the player HAS completed the mission. 
   */
   return 0;
}

void AssignMission(object who) {
  /* This function will be called by the mission control NPC at the 
   * time the mission is assigned. This function is where you would
   * want to do stuff like giving out a map, or a ticket, etc.
   */
}

/* int CanGetMission(object who)
 * Use this function to be able to check for "special" mission requirements,
 * such as having completed a previous mission in a series.
 */

int CanGetMission(object who) {
  return 1;
}
