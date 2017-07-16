/* New Weather Daemon
 * Takes into account room warmth
 * 25 May 2003
 * Duuk@Haven, Augustus@PI
 */
#include <lib.h>
#include <daemons.h>
#include <save.h>
#include <dirs.h>
inherit LIB_DAEMON;

string *AddDomain(string);
string GetWeather(object room);

string *Domains = ({ });
mapping Temperature = ([]);
mapping Raining = ([]);

static void create() {
	string *newdomains;
	string *tmp, newd;
  ::create();
  SetNoClean(1);
  set_heart_beat(2500);
  newdomains = get_dir(DOMAINS_DIRS + "/");
  newdomains -= ({ "staff" });
  foreach(string domain in Domains) {
    Temperature[domain] = 50;
    Raining[domain] = 0;
   }
  unguarded( (: restore_object, SAVE_WEATHER + __SAVE_EXTENSION__ :) );
  foreach(string d in newdomains) {
  	tmp = explode(d, "_");
    foreach(string word in tmp) { 
 	    tmp -= ({ word }); 
 	    tmp += ({ capitalize(word) });
 	    }
 	  newd = implode(tmp, " ");
    newdomains -= ({ d });
    newdomains += ({ newd });
  }
  newdomains -= Domains;
  while(sizeof(newdomains)) {
  	AddDomain(newdomains[0]);
  	newdomains -= ({ newdomains[0] });
  	}
  CHAT_D->eventSendChannel("WEATHER_D", "reports", "Weather Daemon started in these domains: " + 
          conjunction(Domains, "and") );  
}

void heart_beat() {
  foreach(string domain in keys(Temperature)) {
    if (random(2)) {
      Temperature[domain]++;
      if (Temperature[domain] > 100) Temperature[domain] = 100;
    } else {
      Temperature[domain]--;
      if (Temperature[domain] < 0) Temperature[domain] = 0;
    }
    if (random(2)) { 
    	Raining[domain]++;
    	if (Raining[domain] > 10) Raining[domain] = 10;
    } else {
    	Raining[domain]--;
    	if (Raining[domain] < 0) Raining[domain] = 0;
    }
  }
  unguarded( (: save_object, SAVE_WEATHER + __SAVE_EXTENSION__ :) );
}

string *AddDomain(string domain) {
  Domains += ({ domain });
  Temperature[domain] = 50;
  unguarded( (: save_object, SAVE_WEATHER + __SAVE_EXTENSION__ :) );
  return Domains;
}

int GetTemperature(string domain, string climate) {
	int modifier;
	int base;

  if (domain == "FrostMarches") domain = "Frostmarches";
  if (domain == "WestWood") domain = "Westwood";
  if (domain == "HavenWood") domain = "Havenwood";
  if (member_array(domain, keys(Temperature)) == -1) {
     CHAT_D->eventSendChannel("WEATHER_D", "error", 
        "Had a call for Domain: \"" + domain + "\" from " +
        identify(previous_object()) );
  }
	
	base = Temperature[domain];
//	debug("base = " + base);
	switch(climate) {
    case "arctic"       : modifier = -20; break;
    case "sub-arctic"   : modifier = -10; break;
    case "temperate"    : modifier =  10; break;
    case "arid"         : modifier =  20; break;
    case "sub-tropical" : modifier =  35; break;
    case "tropical"     : modifier =  50; break;
    case "underground"  : modifier =  00; break;
    default             : modifier =  00; break;
  }
//  debug("modifier after climate = " + modifier);
  switch(query_season(time())) {
    case "summer"       : modifier += 15; break;
    case "winter"       : modifier -= 15; break;
    default             : break;
  if (query_night()) modifier -= 5;
  }
//  debug("modifier after season = " + modifier);
  if (base + modifier < 0) return 0;
  return base + modifier;
}

int GetRaining(string domain, string climate) {
  int modifier;
  int base = Raining[domain];
  
  switch(climate) {
    case "arid"         : modifier = -2; break;
    case "sub-tropical" : modifier =  1; break;
    case "tropical"     : modifier =  2; break;
    default             : modifier =  0; break;
    }
  if (domain == "Yozrath") modifier += -3; 
  if ((base + modifier) <= 0)  { base = 0;  modifier = 0; }
  if ((base + modifier) >= 10) { base = 10; modifier = 0; }
	return base + modifier;
}

string GetCloudCoverString(int raining, string climate) {
  string *CloudTypes = ({ "clear skies", "wispy cloud fingers",
                          "high white clouds", 
                          "thin clouds", "thick clouds",
                          "dense clouds", "thick, angry clouds", });
  int modifier;

  switch(climate) {
    case "arid"         : modifier = -2; break;
    case "sub-tropical" : modifier =  1; break;
    case "tropical"     : modifier =  2; break;
    default             : modifier =  0; break;
    }
  switch(raining) {
    case  0..1   : modifier += 0; break;
    case  2..3   : modifier += 1; break;
    case  4..5   : modifier += 2; break;
    case  6..7   : modifier += 3; break;
    case  8   : modifier += 4; break;
    case  9   : modifier += 5; break;
    case  10   : modifier += 6; break;
    default   : modifier = modifier; break;
    }
  if (modifier < 0) modifier = 0;
  if (modifier > 6) modifier = 6;

  return CloudTypes[modifier];
}

string GetTemperatureString(int temperature) {
  string *words = ({ "frigid", "very cold", "cold", "cool",
                     "pleasant",
                     "warm", "very warm", "hot", "very hot",
                     "burning hot" });
 
 if (temperature < -20) { return words[0]; }
 if (temperature <  10) { return words[1]; }
 if (temperature <  30) { return words[2]; }
 if (temperature <  50) { return words[3]; }
 if (temperature <  75) { return words[4]; }
 if (temperature <  100) { return words[5]; }
 if (temperature < 120) { return words[6]; }
 if (temperature < 140) { return words[7]; }
 if (temperature >= 140) { return words[8]; }
}

string GetPrecipitationType(int temperature) {
  string temp = GetTemperatureString(temperature);

  switch(temp) {
    case "frigid"       : return "icy hail"; break;
    case "very cold"    : return "thick snow"; break;
    case "cold"         : return "snow"; break;
    case "cool"         : return "cold rain"; break;
    case "warm"         : return "cool rain"; break;
    case "very warm"    : return "rain"; break;
    case "hot"          : return "warm rain"; break;
    case "very hot"     : return "misty rain"; break;
    case "burning hot"  : return "warm mist"; break;
    default             : return "rain"; break;
    }
}

string GetWeather(object room) {
	string climate = room->GetClimate();
	string domain = room->GetDomain();
	int temp;
	int rain = GetRaining(domain, climate);
	string ret;
	
	temp = room->GetRoomWarmth();
	ret = "It is " + GetTemperatureString(temp) + " with " + GetCloudCoverString(rain, climate) + " here.";
	if (rain == 10) { ret += "\n" + capitalize(GetPrecipitationType(temp)) + " falls from the sky."; }
	return ret;
}

void eventReportNumbers(object who) {
  string ret;
  who->eventPrint(sprintf("%-20s %-15s %-15s", "Domain Name", "Temperature", "Raining"));
  foreach(string domain in Domains) {
    ret = sprintf("%-20s %-15d %-15d", domain, 
          Temperature[domain],
          GetRaining(domain, "") );
    who->eventPrint(ret);
  }
}

int AddRaining(string domain, int rain) {
	Raining[domain] += rain;
	unguarded( (: save_object, SAVE_WEATHER + __SAVE_EXTENSION__ :) );
	return Raining[domain];
}

int AddTemperature(string domain, int temp) {
	Temperature[domain] += temp;
  unguarded( (: save_object, SAVE_WEATHER + __SAVE_EXTENSION__ :) );
  return Temperature[domain];
}

	
