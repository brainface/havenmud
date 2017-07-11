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
  "agnostic" : ([ ]),
  
  "Aberach" : ([
    "necromancy" : 1, "slash combat" : 1, "chain armour" : 1, 
    "combat rage" : 2, "natural armour" : 2,
    "evokation" : 4, "metal working" : 4, "natural working" : 4, "weapon smithing" : 4
  ]),
   
  "Aetarin" : ([
    "enchantment" : 1, "pole combat" : 1, "cloth armour" : 1, 
    "healing" : 2, "parry" : 2, "illusion" : 2,
    "dodge" : 4, "swimming" : 4, "weapon smithing" : 4, "wood working" : 4, 
  ]),
   
  "Anteky" : ([
    "evokation" : 1, "pole combat" : 1, "cloth armour" : 1, 
    "healing" : 2, "parry" : 2,
    "enchantment" : 4, "swimming" : 4,
  ]),
   
  "Damhair" : ([
    "healing" : 1, "cloth armour" : 1, "blunt combat" : 1, 
    "enchantment" : 2, "navigation" : 2, "sailing" : 2, "swimming" : 2, 
    "evokation" : 4, "wood working" : 4, 
  ]),
   
  "Eclat" : ([ 
    "healing" : 1, "projectile combat" : 1, "cloth armour" : 1, 
    "enchantment" : 2, "natural armour" : 2, "dodge" : 2,
    "natural magic" : 4, "natural working" : 4, 
  ]),
   
  "Enniae" : ([
    "necromancy" : 1, "blunt combat" : 1, "cloth armour" : 1, 
    "evokation" : 2, "natural armour" : 2, "chain armour" : 2,
    "healing" : 4, "metal working" : 4, "natural working" : 4, 
  ]),
   
  "Kuthar" : ([
   
  ]),
   
  "Kylin" : ([
    "chain armour" : 1, "blunt combat" : 1, "evokation" : 1, 
    "healing" : 2, "mithril working" : 2,
    "enchantment" : 4, "metal working" : 4, "weapon smithing" : 4,
  ]),           
   
  "Desert Kylin" : ([
   
  ]), 
   
  "Magildan" : ([
   
  ]),
   
  "Rath Cult" : ([
    "necromancy" : 1, "cloth armour" : 1, "pole combat" : 1, 
    "evokation" : 2, "chain armour" : 2,
    "conjuring" : 4, "mithril working" : 4, "wood working" : 4, 
  ]),
   
  "Saahagoth" : ([
    "evokation" : 1, "pierce combat" : 1, "cloth armour" : 1, 
    "necromancy" : 2, "chain armour" : 2,
    "disorient" : 4, "illusion" : 4, 
  ]),
   
  "Soirin" : ([
    "cloth armour" : 1, "knife combat" : 1, "evokation" : 1,
    "healing" : 2, "stealth" : 2, "dodge" : 2,
    "illusion" : 4, 
  ]),
   
  "Taisoka" : ([
   
  ]),
   
  "Thorian" : ([
    "necromancy" : 1, "knife combat" : 1, "cloth armour" : 1, 
    "healing" : 2, "natural armour" : 2,
    "enchantment" : 4, "natural working" : 4, 
  ]),
   
  "Urgesh" : ([
   
  ]),
   
  "Tulu Cult" : ([
    "evokation" : 1, "pole combat" : 1, "cloth armour" : 1,
    "illusion" : 2, "knife combat" : 2, "natural armour" : 2, "parry" : 2,
    "disorient" : 4, "necromancy" : 4, "natural working" : 4, ]),
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
