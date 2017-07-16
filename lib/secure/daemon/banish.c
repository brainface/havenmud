#include <daemons.h>
#include <lib.h>
#include <save.h>
#include <config.h>
inherit LIB_DAEMON;

void RestoreBanish();
void SaveBanish();

string *AddBanishedName(string name);
string *GetBanishedNames();
string *RemoveBanishedName(string);

string *AddBannedSite(string ip);
string *GetBannedSites();
string *RemoveBannedSite(string ip);

string *AddGuest(string who);
string *GetGuests();
string *RemoveGuest(string);

int CompareIP(string);

string *BanishedNames, *BannedSites, *Guests;

static void create() {
  ::create();
  BanishedNames = ({ });
  BannedSites   = ({ });
  Guests = ({ });
  RestoreBanish();
}

void RestoreBanish() {
  unguarded( (: restore_object, SAVE_BANISH :) );
  SaveBanish();
}

void SaveBanish() {
  unguarded( (: save_object, SAVE_BANISH :) );
}

int ValidName(string str) {
  int i, x; 
 
  if(base_name(previous_object()) != LIB_CONNECT ) return 0;
  if(member_array(str, GetBanishedNames()) != -1) return 0; 
  x = strlen(str);
  if(x > MAX_USER_NAME_LENGTH) return 0; 
  if(x < MIN_USER_NAME_LENGTH) return 0; 
  for(i = 0; i < x; i++)  
    if(str[i] < 'a' || str[i] > 'z') return 0; 
  return 1; 
}

string *AddBanishedName(string name) {
  string *tmp = BanishedNames;
  if (!arrayp(tmp)) tmp = ({ });
  
  tmp = distinct_array(tmp + ({ name }));
  
  BanishedNames = tmp;
  SaveBanish();
}

string *GetBanishedNames() { 
  if (!arrayp(BanishedNames)) { BanishedNames = ({ }); SaveBanish(); }
  return BanishedNames; 
}

string *RemoveBanishedName(string name) {
  BanishedNames = distinct_array(BanishedNames) - ({ name });
  SaveBanish();
  return BanishedNames;
}

int eventConnect(string name, string ip) {
  if (CompareIP(ip)) {
    if (member_array(name, GetGuests()) == -1) return 0;
    CHAT_D->eventSendChannel("SiteBan/Guest", "reports", capitalize(name) + " allowed from " + ip);
    return 1;
  }
  return 1;
}


int GetGuest(string who) {
  return (member_array(who, GetGuests()) != -1);
}

string *GetGuests() { 
  if (!arrayp(Guests)) { Guests = ({ }); SaveBanish(); }
  return Guests;
}

string *AddGuest(string name) {
  string *tmp = Guests;
  if (!arrayp(tmp)) tmp = ({ });
  
  tmp = distinct_array(tmp + ({ name }));
  
  Guests = tmp;
  SaveBanish();
}

string *RemoveGuest(string name) {
  Guests = distinct_array(Guests) - ({ name });
  SaveBanish();
  return Guests;
}

string *GetBannedSites() { 
    if (!arrayp(BannedSites)) { BannedSites = ({ }); SaveBanish(); }
  return BannedSites;
}

string *AddBannedSite(string name) {
  string *tmp = BannedSites;
  if (!arrayp(tmp)) tmp = ({ });
  
  tmp = distinct_array(tmp + ({ name }));
  
  BannedSites = tmp;
  SaveBanish();
}

string *RemoveBannedSite(string name) {
  BannedSites = distinct_array(BannedSites) - ({ name });
  SaveBanish();
  return BannedSites;
} 

int CompareIP(string ip) { 
  foreach(string site in BannedSites) {
   int i;
	 if( site == ip ) return 1;
	 i = strsrch(site, "*");
	 if( i > 0 ) {
	  if( ip[0..(i-1)] == site[0..(i-1)] ) return 1;
	  }
  }
  return 0;
}
