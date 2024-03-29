/*    /daemon/race.c
 *    from the Dead Souls  Object Library
 *    handles race configuration and administration
 *    created by Descartes of Borg 960108
 *    Version: @(#) races.c 1.4@(#)
 *    Last modified: 96/11/10
 */

#include <lib.h>
#include <save.h>
#include <size.h>
#include <privs.h>
#include <daemons.h>
#include "include/races.h"

inherit LIB_DAEMON;

private mapping Races = ([]);
static private mapping Resistances = ([]);
static private mapping Armours = ([]);

int GetSize(string size);
string GetSizeString(int);

static void create() {
    string array lines;
    
    daemon::create();
    if( unguarded((: file_size(SAVE_RACES __SAVE_EXTENSION__) :)) > 0 )
unguarded((: restore_object(SAVE_RACES) :));
    if( !Races ) Races = ([]);
    // Hocus pocus to load armour and resistance info
    lines = explode(read_file("/include/armour_types.h"), "\n");
    foreach(string line in lines) {
string type;

if( sscanf(line, "#define %s %*s", type) == 2 ) {
    string file = DIR_DAEMONS "/tmp/" + type + ".c";

    if( type == "A_MAX_ARMOUR_BIT" ) {
continue;
    }
    if( !file_exists(file) ) {
unguarded((: write_file($(file), "#include <armour_types.h>\n"
         "int armour() { return " +
$(type) + "; }\n") :));
    }
    Armours[type] = call_other(file, "armour");
}
    }
    lines = explode(read_file("/include/damage_types.h"), "\n");
    foreach(string line in lines) {
string type;

if( sscanf(line, "#define %s %*s", type) == 2 ) {
    string file = DIR_DAEMONS "/tmp/" + type + ".c";

    if( type == "MAX_DAMAGE_BIT" ) {
continue;
    }
    if( !file_exists(file) ) {
unguarded((: write_file($(file), "#include <damage_types.h>\n"
         "int damage() { return " +
$(type) + "; }\n") :));
    }
    Resistances[type] = call_other(file, "damage");
}
    }
  SetNoClean(1);
}

static private void validate() {
    if( !((int)master()->valid_apply(({ PRIV_ASSIST }))) )
error("Illegal attempt to modify race data");
}

void AddRace(string file, int player) {
    class Race res;
    string array lines, tmp;
    string race;
    
    validate();
    if( !file_exists(file) ) error("No such file: " + file);
    lines = explode(read_file(file), "\n");
    lines = filter(lines, function(string str) {
                      if( strlen(str) == 0 ) {
  return 0;
      }
      if( str[0] == '#' ) {
  return 0;
      }
      if( str[0] == ' ' || str[0] == '\t' ) {
  return 0;
      }
      return 1;
                          });
    race = lines[0];
    if( Races[race] ) error("Race already exists");
    res = new(class Race);
    res->Sensitivity = map(explode(lines[1], ":"), (: to_int :));
    res->Language = lines[2];
    if (strsrch(lines[3], "SIZE") != -1) {
    res->Size = GetSize(lines[3]);
    lines = lines[1..]; // Garbage to get the Resistances to work right.
    }
      else res->Size = SIZE_MEDIUM;
    lines = lines[3..];
    res->Resistance = ([]);
    while(sizeof(tmp = explode(lines[0], ":")) == 2) {
int x = to_int(tmp[0]);

if( x == 0 && tmp[0] != "0" ) x = GetResistance(tmp[0]);
res->Resistance[x] = tmp[1];
lines = lines[1..];
    }
    res->Stats = ([]);
    while(sizeof(tmp = explode(lines[0], ":")) == 3) {
class Stat s = new (class Stat);

s->Average = to_int(tmp[1]);
s->Class = to_int(tmp[2]);
res->Stats[tmp[0]] = s;
lines = lines[1..];
    }
    res->Limbs = ({});
    while(sizeof(tmp = explode(lines[0], ":")) == 4) {
mixed array limb = allocate(4);

limb[0] = tmp[0];
limb[1] = (tmp[1] == "0" ? 0 : tmp[1]);
limb[2] = to_int(tmp[2]);
limb[3] = map(explode(tmp[3], ","), function(string str) {
                                        int x = to_int(str);

if( x == 0 && str != "0" )
  return GetArmour(str);
return x;
         });
res->Limbs = ({ res->Limbs..., limb });
if( sizeof(lines) > 1 ) lines = lines[1..];
else {
    lines = ({});
    break;
}
    }
    res->Fingers = ([]);
    if( sizeof(lines) ) {
foreach(string hand in lines) {
    string array parts = explode(hand, ":");

    res->Fingers[parts[0]] = to_int(parts[1]);
}
    }
    res->Complete = 1;
    if( player ) {
res->PlayerFlag = 1;
    }
    else {
res->PlayerFlag = 0;
    }
    Races[race] = res;
    save_object(SAVE_RACES);
}

void RemoveRace(string race) {
    validate();
    map_delete(Races, race);
    save_object(SAVE_RACES);
}

int GetArmour(string str) {
    string file = DIR_DAEMONS "/tmp/" + str + ".c";
    
    if( !unguarded((: file_exists($(file)) :)) ) {
unguarded((: write_file($(file), "#include <armour_types.h>\n" +
    "int armour() { return " + $(str) + "; }\n") :));
    }
    return call_other(file, "armour"); 
}

int GetResistance(string str) {
    string file = DIR_DAEMONS "/tmp/" + str + ".c";
    
    if( !unguarded((: file_exists($(file)) :)) ) {
unguarded((: write_file($(file), "#include <damage_types.h>\n" +
    "int damage() { return " + $(str) + "; }\n") :));
    }
    return call_other(file, "damage"); 
}

mapping GetRemoteRaces() {
    mapping mp = ([]);

    foreach(string race, class Race res in Races) {
mapping stats = ([]);

mp[race] = ([]);
mp[race]["limbs"] = res->Limbs;
mp[race]["resistance"] = res->Resistance;
foreach(string stat, class Stat st in res->Stats) {
    stats[stat] = ([]);
    stats[stat]["class"] = st->Class;
    stats[stat]["average"] = st->Average;
}
mp[race]["stats"] = stats;
mp[race]["fingers"] = res->Fingers;
mp[race]["sensitivity"] = res->Sensitivity;
mp[race]["player"] = res->PlayerFlag;
mp[race]["language"] = res->Language;
mp[race]["size"] = res->Size;
    }
    return mp;
}

void SetComplete(string race) {
    class Race res;
    
    validate();
    if( !Races[race] ) error("No such race");
    else res = Races[race];
    res->Complete = 1;
    save_object(SAVE_RACES);
}

void SetLightSensitivity(string race, int array sensitivity) {
    class Race res;
    
    validate();
    if( !Races[race] ) error("No such race");
    else res = Races[race];
    if( sensitivity[0] < 1 ) error("Invalid sensitivity value");
    if( sensitivity[1] > 99 ) error("Invalid sensitivity value");
    if( sensitivity[0] > sensitivity[1] ) error("Invalid sensitivity value");
    res->Sensitivity = sensitivity;
    save_object(SAVE_RACES);
}

void SetCharacterLimbs(string race, mixed array args) {
    class Race res = Races[race];
    mixed array tmp = ({});

    if( !res || !res->Complete || sizeof(args) != 2 ) return;
    args[0] = copy(res->Limbs);
    foreach(string finger, int count in res->Fingers)
      tmp = ({ tmp..., ({ finger, count }) });
    args[1] = tmp;
}

void SetCharacterRace(string race, mixed array args) {
    class Race res = Races[race];
    mixed array tmp;
    
    if( !res || !res->Complete || sizeof(args) != 5 ) return;
    tmp = ({});
    foreach(int key, string val in res->Resistance)
tmp = ({ tmp..., ({ key, val }) });
    args[0] = tmp;
    tmp = ({});
    foreach(string key, class Stat stat in res->Stats)
tmp = ({ tmp..., ({ key, stat->Average, stat->Class }) });
    args[1] = tmp;
    args[2] = res->Language;
    args[3] = ({ res->Sensitivity[0], res->Sensitivity[1] });
    args[4] = ({ res->Size });
}
    
varargs string array GetRaces(int player_only) {
    return filter(keys(Races), function(string race, int player_only) {
                           class Race res = Races[race];

   if( !res->Complete ) return 0;
   if( player_only && !res->PlayerFlag )
     return 0;
   return 1;
                               }, player_only);
}

string GetRandomRace() {
  string *races = GetRaces(1);
  return races[random(sizeof(races))];
}

string TranslateNumber(int x) {
  if (x == 1) return "primary";
  if (x == 2) return "secondary";
  if (x == 3) return "average";
  if (x == 4) return "below average";
  if (x == 5) return "abysmal";
  return "unknown";
}

string GetHelp(string race) {
    class Race res = Races[race];
    string array limbs;
    string help = "Race: " + race + "\n\n";
    string tmp;
    int x;
    mapping stats = ([ ]);
    for(int i = 1; i <= 5; i++) stats[TranslateNumber(i)] = ({ });
    
    if( !res ) return 0;
    limbs = map(res->Limbs, (: $1[0] :));
    foreach(string key, class Stat stat in res->Stats) {
      stats[TranslateNumber(stat->Class)] = stats[TranslateNumber(stat->Class)]  + ({ key });
    }
    for(int i = 1; i <= 5; i++) {
      string key = TranslateNumber(i);
      help += capitalize(key) + " stats: " + (sizeof(stats[key]) ? conjunction(stats[key], "and") : "none") + "\n";
    }
    help += "Limbs:\n";
    help += capitalize(item_list(map(limbs, (: add_article :)))) + ".\n";
    help += "Fingered limbs: ";
    foreach(string finger, int count in res->Fingers) help += finger + " (" + count + ") ";
    help += "\n";
    x = res->Sensitivity[0];
    if (x <= 0)       tmp = "night vision";
    else if( x < 11 ) tmp = "excellent";
    else if( x < 16 ) tmp = "above average";
    else if( x < 21 ) tmp = "good";
    else if( x < 26 ) tmp = "average";
    else if( x < 31 ) tmp = "below average";
    else if( x < 36 ) tmp = "very poor";    
    else tmp = "extremely poor";
    help += "Night vision: " + tmp + "\n";
    x = res->Sensitivity[1];
    if( x < 61 ) tmp = "extremely poor";
    else if( x < 66 ) tmp = "very poor";
    else if( x < 71 ) tmp = "below average";
    else if( x < 76 ) tmp = "average";
    else if( x < 81 ) tmp = "good";
    else if( x < 86 ) tmp = "above average";
    else tmp = "excellent";
    help += "Day vision: " + tmp + "\n";
    help += "Size: " + GetSizeString(res->Size || SIZE_MEDIUM) + "\n";
    help += "Starting Town(s): " + conjunction(SETUP_D->GetHelpTowns(race), "or") + "\n";
    if (SETUP_D->GetHelpTowns(race) != SETUP_D->GetTowns(race)) help += "**This race features advanced start options,\nnot all towns are available to new players.**\n";
    return help;
}

public mapping GetResistances() {
    return copy(Resistances);
}

public mapping GetArmours() {
    return copy(Armours);
}

int GetValidRace(string race) {
  if (member_array(race, GetRaces()) == -1) 
    return 0;
  return 1;
}

int GetSize(string size) {
switch(size) {
    case "SIZE_TINY"       : return SIZE_TINY;       break;
    case "SIZE_VERY_SMALL" : return SIZE_VERY_SMALL; break;
    case "SIZE_SMALL"      : return SIZE_SMALL;      break;
    case "SIZE_MEDIUM"     : return SIZE_MEDIUM;     break;  
    case "SIZE_LARGE"      : return SIZE_LARGE;      break;
    case "SIZE_VERY_LARGE" : return SIZE_VERY_LARGE; break;
    case "SIZE_HUGE"       : return SIZE_HUGE;       break;
    case "SIZE_GIANT"      : return SIZE_GIANT;      break;
  }
  error("BAD SIZE passed to GetSize() in /daemon/races.c \n"
                    "Expected SIZE_ token, got: " + size);
}

string GetSizeString(int size) {
switch (size) {
    case SIZE_TINY       : return "tiny";       break;
    case SIZE_VERY_SMALL : return "very small"; break;
    case SIZE_SMALL      : return "small";      break;
    case SIZE_MEDIUM     : return "medium";     break;  
    case SIZE_LARGE      : return "large";      break;
    case SIZE_VERY_LARGE : return "very large"; break;
    case SIZE_HUGE       : return "huge";       break;
    case SIZE_GIANT      : return "giant";      break;
  }
  return "ERROR";
}

int GetSizeInt(string size) {
	switch (size) {
    case "tiny"       : return SIZE_TINY;      ; break;
    case "very small" : return SIZE_VERY_SMALL ; break;
    case "small"      : return SIZE_SMALL      ; break;
    case "medium"     : return SIZE_MEDIUM     ; break;  
    case "large"      : return SIZE_LARGE      ; break;
    case "very large" : return SIZE_VERY_LARGE ; break;
    case "huge"       : return SIZE_HUGE       ; break;
    case "giant"      : return SIZE_GIANT      ; break;
  }
  return 0;
}

void ReloadRaces() {
foreach(string race in keys(Races)) {
RemoveRace(race);
AddRace("/secure/cfg/races/" + race, 0);
}
}

int GetRaceSize(string race) {
  class Race res = Races[race];
  if (!res) return -1;
  return res->Size;
}

void RemakeRaces() {
    string *dirs = ({ });
    string *ores = ({ });

    foreach(string race in keys(Races)) {
      RemoveRace(race);
    }
    
    dirs = get_dir("/secure/cfg/races/");
    foreach(string dir in dirs) {
      AddRace("/secure/cfg/races/" + dir, 0);
    }
      dirs = get_dir("/secure/cfg/player_races/");
      foreach(string dir in dirs) {
        AddRace("/secure/cfg/player_races/" + dir,1);
    }
}
