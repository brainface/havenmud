/* LIB_RACE 
 * A lib object to set up definitions for each race.
 * Much easier than an ugly file.
 */
#include <size.h>
#include <damage_types.h>
#include <armour_types.h>

mapping Resistances;
int *LightSensitivity;
string Language;
string RaceName;
int Size;
int Fingers;
mixed *Limbs;
mixed *Stats;
int PlayerRace = 0;
string NativeTown;
string NativeReligion;
int StartingAge;

static void create() {
  RaceName       = "";
  Size           = SIZE_MEDIUM;
  Resistances    = ([ ]);
  LightSensitivity = ({ 20, 60 });
  Language       = "Enlan";
  Fingers        = 5;
  Limbs          = ({ });
  Stats          = ({ });
  PlayerRace     = 0;
  NativeTown     = "Haven";
  NativeReligion = "agnostic";
  StartingAge    = 16;
}

string SetRaceName(string n) { return RaceName = n; }
string GetRaceName() { return RaceName; }

int *SetLightSensitivity(int *n) { return LightSensitivity = n; }
int *GetLightSensitivity() { return LightSensitivity; }

string SetLanguage(string l) { return Language = l; }
string GetLanguage() { return Language; }

mapping SetResistance(int damage, string amount) {
  Resistances[damage] = amount;
  return Resistances;
}

string GetResistance(int damage) {
  return Resistances[damage];
}

mapping GetResistances() {
  return Resistances;
}

mapping SetResistances(mapping m) {
  return Resistances = m;
}

int SetSize(int s) { return Size = s; }
int GetSize() { return Size; }

int SetFingers(int f) { return Fingers = f; }
int GetFingers() { return Fingers; }

string SetNativeTown(string nt) { return NativeTown = nt; }
string GetNativeTown() { return NativeTown; }

string SetNativeReligion(string nr) { return NativeReligion = nr; }
string GetNativeReligion() { return NativeReligion; }

int SetStartingAge(int sa) { return StartingAge = sa; }
int GetStartingAge() { return StartingAge; }

mixed *AddStat(string stat, int base, int statclass) {
  Stats += ({ ({ stat, base, statclass }) });
  return Stats;
}

mixed *SetStat(string stat, int base, int statclass) {
  return AddStat(stat, base, statclass);
}

mixed *GetStats() { return Stats; }

mixed *GetStat(string stat) {
  foreach (mixed *st in Stats) {
    if (st[0] == stat) { return st; }
  }
  return ({ });
}

mixed *AddLimb(string limb, string connect, int limbclass, int armours) {
  Limbs += ({ ({ limb, connect, limbclass, armours }) });
  return Limbs;
}

mixed *SetLimb(string limb, string connect, int limbclass, int armours) {
  return AddLimb(limb, connect, limbclass, armours);
}

mixed *GetLimbs() { return Limbs; }

mixed *GetLimb(string stat) {
  foreach (mixed *st in Limbs) {
    if (st[0] == stat) { return st; }
  }
  return ({ });
}

int SetPlayerRace(int p) { return PlayerRace = p; }
int GetPlayerRace() { return PlayerRace; }
