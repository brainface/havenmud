#include <lib.h>
#include <dirs.h>
inherit LIB_DAEMON;

string *LoadMissions();
string *FilterMissions(string world);


static void create() {
  ::create();
  LoadMissions();
}

string *LoadMissions() {
  string *missions = ({ });
  string *dirs = ({ });
  dirs = unguarded( (: get_dir, DIR_STD "missions/" :) );
  foreach(string dir in dirs) {
    if (file_size(DIR_STD "missions/" + dir) == -2) 
      foreach(string mish in unguarded( (: get_dir, DIR_STD "missions/" + dir + "/" :) ) ) {
        missions += ({ DIR_STD + "missions/" + dir + "/" + mish });
      }
  }
  return missions;
}

string *FilterMissions(string world) {
  string *tmp = ({ });
  
  foreach(string mission in LoadMissions()) {
    if (!load_object(mission)) continue;
    if (load_object(mission)->GetTown() == world) tmp += ({ mission });
    if (load_object(mission)->GetTown() == "all") tmp += ({ mission });
  }
  return tmp;
}

string GetRandomMission(string world) {
  string tmp;
  object mission;
  string *missions = ({ });
  
  if (!world) missions = LoadMissions();
    else missions = FilterMissions(world);
  return missions[random(sizeof(missions))];
}

void CheckMission(object who, string m) {
  object mission;
  
  mission = load_object(m);
  
  if (!mission) return;
  if (mission->CheckCompletedMission(who)) {
    mission->eventCompleteMission(who);
  }
}


  