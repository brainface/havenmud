/* Religion morality limits */
#include <lib.h>
#include <daemons.h>
#define CLASS_FAITH  "priest"
inherit LIB_DAEMON;

mapping ReligionAlignment = ([
  "agnostic"     : "neutral" ,
  "Aberach"      : "evil" ,
  "Aetarin"      : "neutral" ,
  "Anteky"       : "good" ,
  "Damhair"      : "neutral" ,
  "Eclat"        : "good" ,
  "Enniae"       : "evil" ,
  "Kuthar"       : "neutral" ,
  "Kylin"        : "good" ,
  "Desert Kylin" : "good",
  "Magildan"     : "neutral" , 
  "Rath Cult"    : "evil" ,
  "Saahagoth"    : "evil" ,
  "Soirin"       : "evil" ,
  "Taisoka"      : "neutral" ,
  "Thorian"      : "neutral", 
  "Urgesh"       : "evil",
  "Tulu Cult"    : "evil",
  ]);
  
mapping ReligionSkills = ([
  "agnostic"     : ([ ]),
  "Aberach"      : ([ ]),
  "Aetarin"      : ([ ]),
  "Anteky"       : ([ ]),
  "Damhair"      : ([ ]),
  "Eclat"        : ([ ]),
  "Enniae"       : ([ ]),
  "Kuthar"       : ([ ]),
  "Kylin"        : ([ "evokation": 1, "blunt combat": 1, "chain armour": 1, "healing" : 2, "leather armour" : 2, "reinforced armour" : 2 ]),
  "Desert Kylin" : ([ ]),
  "Magildan"     : ([ ]),
  "Rath Cult"    : ([ ]),
  "Saahagoth"    : ([ ]),
  "Soirin"       : ([ ]),
  "Taisoka"      : ([ ]),
  "Thorian"      : ([ ]),
  "Urgesh"       : ([ ]),
  "Tulu Cult"    : ([ ]),
  ]);
  
  
mapping GetReligionSkills(string religion) {
	string *religions = keys(ReligionSkills);
	if (member_array(religion, religions) == -1) return ([]);
	return ReligionSkills[religion];
}  

int GetReligionSkillRank(string religion, string skill) {
	string *skills;
	string *religions = keys(ReligionSkills);
	mapping skillranks;
	
	if (member_array(religion, religions) == -1) {
		error("Called for religion " + religion + " in " + identify(previous_object()) + ".");
		return -1;
	}
	skillranks = GetReligionSkills(religion);
	skills = keys(skillranks);
	if (member_array(skill, skills) == -1) return 0;
	return skillranks[skill];
}

string GetReligionSkillsHelp(string religion) {
	string *skills;
	string *p, *s, *o, *r;
  mapping sk_m = GetReligionSkills(religion);
  string h = "";
  
  p = s = o = r = ({});
  skills = keys(sk_m);
  foreach(string skill in skills) {
  	if (sk_m[skill] == 0) r += ({ skill });
    if (sk_m[skill] == 1) p += ({ skill });
    if (sk_m[skill] == 2) s += ({ skill });
    if (sk_m[skill] == 4) o += ({ skill });
  }
  h += "  Priest specific skills \n";
  h += "  Primary skills:   " + implode(p, " - ") + "\n";
  h += "  Secondary skills: " + implode(s, " - ") + "\n";
  h += "  Other skills:     " + implode(o, " - ") + "\n";
  h += "  Removed skills:   " + implode(r, " - ") + "\n";
  return h;
}
  
	
  
int CheckMorality(object who) {
  int upper, lower;
  int mine;
  switch(ReligionAlignment[who->GetReligion()]) {
    case "good" :
      upper = 9999;
      lower = 1000;
      break;
    case "neutral":
      upper = 1500;
      lower = -1500;
      break;
    case "evil":
      upper = -1000;
      lower = -9999;
      break;
    default:  /* This exists only for non-set religions */
      debug("Called for religion: " + who->GetReligion() + " for " + base_name(who));
      upper = 0;
      lower = 0;
      break;
  }
  mine = who->GetMorality();
  if (who->GetTestChar()) debug("m : " + mine + " u: " + upper + " l: " + lower);
  if (mine > upper) { if (who->GetTestChar()) debug(1); return 1; }
  if (mine < lower) { if (who->GetTestChar()) debug(2); return 2; }
  if (who->GetTestChar()) debug(1); return 0;
}

void SetBaseMorality(object who) {
  switch(ReligionAlignment[who->GetReligion()]) {
    case "good" :
      who->SetMorality(1500);
      break;
    case "evil" :
      who->SetMorality(-1500);
      break;
    }
  return;
}

void SetNPCMorality(object npc) {
  string religion = SETUP_D->GetReligion(npc->GetTown());
  switch(ReligionAlignment[religion]) {
    case "good" :
      npc->SetMorality(150);
      break;
    case "evil" :
      npc->SetMorality(-150);
      break;
    }
  return;
}

string GetReligionAlignment(string religion) {
  return ReligionAlignment[religion];
}

string GetStringRange(string religion) {
  int upper, lower;
  switch(ReligionAlignment[religion]) {
    case "good" :
      upper = 3000;
      lower = 1000;
      break;
    case "neutral":
      upper = 1500;
      lower = -1500;
      break;
    case "evil":
      upper = -1000;
      lower = -3000;
      break;
  }
  return lower + " to " + upper;
}
