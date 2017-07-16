/*  The Setup Daemon */
#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;
#include <setup.h>

int GetStartingAge(string race) {
  return (StartingAges[race]);
 }

string *GetStartingLanguages() {
  return (values(StartingLanguages));
 }

string *GetTowns(string race) {
  return (Towns[race]);
 }

string *GetAdvancedTowns(string race) {
  if (AdvancedStart[race]) return AdvancedStart[race];
    return ({ });
}

string GetLanguage(string town) {
  return StartingLanguages[town];
}

string *GetMoveMessages(string race) {
  return MoveMessages[race];
}

string GetStartRoom(string town) {
  return StartRooms[town];
}

string GetCemetery(string town) {
  return Cemeteries[town];
}

string GetReligion(string town) {
  return Religions[town];
}

string *GetAllTowns() {
  return keys(StartRooms);
}

string *GetPlayerRaces(string email) {
  string *tmp = ({ });
  if (CHARACTER_D->CanAdvancedStart(email)) {
    tmp = RACES_D->GetRaces(1);
  }
  else {
    tmp = keys(Towns);
  }
  return tmp;
}

string *GetPlayerTowns(string email, string race) {
  string *tmp = ({ });
  tmp = GetTowns(race);
  if (CHARACTER_D->CanAdvancedStart(email)) {
    if (sizeof(GetAdvancedTowns(race))) tmp = GetAdvancedTowns(race);
    }
  return tmp;
}

string *GetHelpTowns(string race) {
  if (sizeof(AdvancedStart[race])) return AdvancedStart[race];
    return Towns[race];
}