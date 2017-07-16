#include <lib.h>
#include <daemons.h>
#include "../lisht.h"
inherit LIB_DAEMON;

string *MaleNames = ({ "rameses", "seti", "menemhet", "amasis", "thutmose", "akhenaten", "piankhi", "tutankhamen" });
string *FemaleNames = ({ "hatshepsut", "isis", "cleopatra", "astarte", "chione", "nefertiti" });
string CurrentPharaoh;
string PharaohGender;
mapping NameCount;

void RestorePharaoh() {
  unguarded( (: restore_object, LISHT_SAVE "pharaoh.o" :) );
}

void SavePharaoh() {
  unguarded( (: save_object, LISHT_SAVE "pharaoh.o" :) );
}

static void create() {
  ::create();
  NameCount = ([ ]);
  CurrentPharaoh = "seti";
  PharaohGender = "male";
  RestorePharaoh();
  SavePharaoh();
}

string GetNewPharaohName(string gender) {
  if (gender == "male") {
    return MaleNames[random(sizeof(MaleNames))];
  }
  return FemaleNames[random(sizeof(FemaleNames))];
}

string GetCurrentPharaoh() { 
  return CurrentPharaoh;
}

string SetCurrentPharaoh(string name) {
  CurrentPharaoh = name;
  SavePharaoh();
  return CurrentPharaoh;
}

string SetPharaohGender(string gender) { 
  PharaohGender = gender;
  SavePharaoh();
  return PharaohGender; 
}
string GetPharaohGender()              { return PharaohGender;          }

int GetPharaohNumber(string name) {
  if (!NameCount[name]) {
    NameCount[name] = 1;
  }
  return NameCount[name];
}

int SetPharaohNumber(string name, int number) {
  NameCount[name] = number;
  SavePharaoh();
  return NameCount[name];
}

int PharaohDied() {
  string newguy;
  int newnum, oldnum;
  
  
  if (!random(6)) SetPharaohGender("female"); else SetPharaohGender("male");
  newguy = GetNewPharaohName(GetPharaohGender());
  oldnum = GetPharaohNumber(GetCurrentPharaoh());
  newnum = GetPharaohNumber(newguy);
  newnum = SetPharaohNumber(newguy, newnum + 1);
  CHAT_D->eventSendChannel("Xandria", "ooc",
     "Pharaoh " + capitalize(GetCurrentPharaoh()) + " the " + oldnum + "" + 
     ordinal(oldnum) + " has been slain! "
     "The gods declare " + capitalize(newguy) + " the " + newnum + "" + ordinal(newnum) + " to be Pharaoh!"
     );
  SetCurrentPharaoh(newguy);
  SavePharaoh();
  return newnum;
}
