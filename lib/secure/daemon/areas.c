#include <domains.h>
#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#define HELP_DOC "/doc/help/players/areas"
inherit LIB_DAEMON;

string *Domains = ({ });
int NextDomain;
int numNPCs, numAnimals, numSentients;


static void create() {
  ::create();
  set_heart_beat(1);
  NextDomain = 0;
  numAnimals = numSentients = numNPCs = 0;
  Domains = get_dir(DOMAINS_DIRS + "/");
  rm(HELP_DOC);
  write_file(HELP_DOC, 
    "Not all listed areas and/or towns may be in the game. Areas listed \n"
    "as having a level range of 99999 - 0 were unparsed by the area controller \n"
    "and should be explored at risk.\n\n");
}

string englishDomain(string domain) { 
  string *tmp = explode(domain, "_");
  string tmp2 = "";
  foreach(string word in tmp) {
    tmp2 += capitalize(word) + " ";
  }
  return tmp2;
}

void ProcessArea(string domain, string area) {
  object tmpnpc;
  string *npcs = ({ });
  int low, high;
  high = 0;
  low  = 99999;
  CHAT_D->eventSendChannel("AREAS_D", "reports", "Processing area \"" + area + "\" in " + domain);
  if (file_size(DOMAINS_DIRS + "/" + domain + "/areas/" + area + "/npc/") == -2) {
    npcs = get_dir(DOMAINS_DIRS + "/" + domain + "/areas/" + area + "/npc/");
  }
  if (!sizeof(npcs)) {
    if (file_size(DOMAINS_DIRS + "/" + domain + "/areas/" + area + "/npcs/") == -2) {
      npcs = get_dir(DOMAINS_DIRS + "/" + domain + "/areas/" + area + "/npcs/");
    }
  }  
  foreach(string npc in npcs) {
    tmpnpc = load_object(DOMAINS_DIRS + "/" + domain + "/areas/" + area + "/npc/" + npc);
    if (!tmpnpc) tmpnpc = load_object(DOMAINS_DIRS + "/" + domain + "/areas/" + area + "/npcs/" + npc);
    if (!tmpnpc) continue;
    if (tmpnpc->GetLevel() < low) low = tmpnpc->GetLevel();
    if (tmpnpc->GetLevel() > high) high = tmpnpc->GetLevel();
    numNPCs++;
    if (tmpnpc->GetClass() == "animal") numAnimals++;
      else numSentients++;
    tmpnpc->eventDestruct();
    }
  write_file(HELP_DOC, "  " + parse_area(area, domain) + " (" + low + " - " + high + ")\n");
}

void ProcessTown(string domain, string town) {
  object tmpnpc;
  string *npcs = ({ });
  int low, high;
  high = 0;
  low  = 99999;
  CHAT_D->eventSendChannel("AREAS_D", "reports", "Processing town \"" + town + "\" in " + domain);
  if (file_size(DOMAINS_DIRS + "/" + domain + "/towns/" + town + "/npc/") == -2) {
    npcs = get_dir(DOMAINS_DIRS + "/" + domain + "/towns/" + town + "/npc/");
  }
  if (!sizeof(npcs)) {
    if (file_size(DOMAINS_DIRS + "/" + domain + "/towns/" + town + "/npcs/") == -2) {
      npcs = get_dir(DOMAINS_DIRS + "/" + domain + "/towns/" + town + "/npcs/");
    }
  }  
  foreach(string npc in npcs) {
    tmpnpc = load_object(DOMAINS_DIRS + "/" + domain + "/towns/" + town + "/npc/" + npc);
    if (!tmpnpc) tmpnpc = load_object(DOMAINS_DIRS + "/" + domain + "/towns/" + town + "/npcs/" + npc);
    if (!tmpnpc) continue;
    if (tmpnpc->GetLevel() < low) low = tmpnpc->GetLevel();
    if (tmpnpc->GetLevel() > high) high = tmpnpc->GetLevel();
    numNPCs++;
    if (tmpnpc->GetClass() == "animal") numAnimals++;
      else numSentients++;      
    }
  write_file(HELP_DOC, "  " + parse_area(town, domain) + " (" + low + " - " + high + ")\n");
}

void ProcessDomain(string domain) {
  string *areas = ({});
  string *towns = ({});
  if (file_size(DOMAINS_DIRS + "/" + domain + "/areas/") == -2) areas = get_dir(DOMAINS_DIRS + "/" + domain + "/areas/");     
  if (file_size(DOMAINS_DIRS + "/" + domain + "/towns/") == -2) towns = get_dir(DOMAINS_DIRS + "/" + domain + "/towns/");     

  CHAT_D->eventSendChannel("AREAS_D", "reports", "Processing domain: " + domain);
  write_file(HELP_DOC, "Domain: " + englishDomain(domain) + "Updated: " + ctime(time()) + "\n");
  foreach(string area in areas) {
    ProcessArea(domain, area);
  }
  foreach(string town in towns) {
    ProcessTown(domain, town);
  }
} 

void heart_beat() {
  if (NextDomain >= sizeof(Domains)) return;
  ProcessDomain(Domains[NextDomain]);
  NextDomain++;
}

void eventSpamOOC() {
  CHAT_D->eventSendChannel("Mud Report", "ooc", "Processed " + numNPCs + " NPCs with an approximate breakdown of " + numAnimals + " animals and " + numSentients + " sentients.");
  return;
}