#include <lib.h>
mixed *AddSave(mixed *x);

mapping Reputations = ([]);
int GetReputation(string faction);
int AddReputation(string faction, int value);
string GetStringReputation(string faction);
mapping GetAllReputations();
void DisplayReputations();

mapping OpposingFactions = ([
  "Haven"        :    "Malveillant",
  "Karak"        :    "Glimmerdin",
  "Glimmerdin"   :    "Karak",
  "Malveillant"  :    "Haven",
  "Gwonish"      :    "Lloryk",
  "Lloryk"       :    "Gwonish",
  "Durgoroth"    :    "Grymxoria",
  "Grymxoria"    :    "Durgoroth",
  "Ungkh"        :    "Jidoor",
  "Jidoor"       :    "Ungkh",
  ]);

static void create() {
  AddSave( ({ "Reputations" }) );
}

mixed GetOpposingFaction(string faction) {
  if (OpposingFactions[faction]) return OpposingFactions[faction];
  return 0;
}

int GetReputation(string faction) {
  int p;
  if (!sizeof(Reputations)) Reputations = ([]);
  if (p = Reputations[faction])
    return p;
  else return 0;
}

int AddReputation(string faction, int value) {
  if (faction == "all" || faction == "Wilderness") return 0;
  if (!sizeof(Reputations)) Reputations = ([]);
  if (!Reputations[faction]) {
    Reputations[faction] = value;
  } else {
    Reputations[faction] += value;
  }
  if (Reputations[faction] < -1000) Reputations[faction] = -1000;
  if (Reputations[faction] > 1000) Reputations[faction] = 1000;
  this_object()->eventPrint("You are now " + GetStringReputation(faction) + " with " + faction + ". (" + Reputations[faction] + ")");
  if (GetOpposingFaction(faction)) {
    faction = GetOpposingFaction(faction);
    value = (value * -1)/2;
    if (!Reputations[faction]) {
      Reputations[faction] = value;
    } else {
      Reputations[faction] += value;
    }
    if (Reputations[faction] < -1000) Reputations[faction] = -1000;
    if (Reputations[faction] > 1000) Reputations[faction] = 1000;
    this_object()->eventPrint("You are now " + GetStringReputation(faction) + " with " + faction + ". (" + Reputations[faction] + ")");
  }
  return Reputations[faction];
}

mapping GetAllReputations() { return Reputations; }

string GetStringReputation(string faction) {
  int pnts;
  pnts = Reputations[faction];

  if (pnts > 1000)
    return "Revered";
  if (pnts < -1000)
    return "Reviled";
  switch (pnts) {
    case -1000..-500:
      return "Hated";
      break;
    case -499..-250:
      return "Infamous";
      break;
    case -249..-100:
      return "Disliked";
      break;
    case -99..-1:
      return "Unfriendly";
      break;
    case 0:
      return "Neutral";
      break;
    case 1..99:
      return "Friendly";
      break;
    case 100..249:
      return "Liked";
      break;
    case 250..500:
      return "Honored";
      break;
    case 501..1000:
      return "Loved";
      break;
    default:
      return "Strangely Unknown";
      break;
  }
} 

void DisplayReputations(object viewer) {
  string *reps = keys(Reputations);
  viewer->eventPrint("Displaying Reputation information for " + this_object()->GetShort());
  if (!sizeof(reps)) {
    viewer->eventPrint("You are utterly without reputation.");
  }
  foreach(string faction in reps) {
    viewer->eventPrint("You are " + GetStringReputation(faction) + " with " + faction + ". (" + Reputations[faction] + ")");
  }
}

mixed *AddSave(mixed *x) { }

// mahkefel debug
string GetFactionList() {
  string shebang="";

  foreach (string faction in keys(OpposingFactions)) {
    shebang += faction+": "+OpposingFactions[faction];
  }
  return shebang;
}

