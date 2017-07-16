/*  A daemon to purge non logging players.
 * Initial attempt : 18 Sept 1997
 * Duuktsaryth
 */
#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#define PURGE_TIME  7 /* 3 days per level */
#define PURGE_INTERVAL 48 /* Hours between purges */
inherit LIB_DAEMON;

string *eventGet(string);
void eventPostal();
void eventShipClean();
int eventClean();
void eventInform();
private int LoginTime, Level, Retired;
private int TestChar;
private string Class, CapName;

int NextPurge = 0;
int LastPurge = 0;
int NextInform;

static void create() {
  daemon::create();
  SetNoClean(1);
  set_heart_beat(1);
  LastPurge = time();
  eventInform();
}

int GetLastPurge() { return LastPurge; }
int SetLastPurge(int x) { return LastPurge = x; }
int SetNextPurge(int x) { return NextPurge = x; }
int GetNextPurge() { return NextPurge; }
int GetNextInform() { return NextInform - time(); }

void heart_beat() {
  if ( (time() - LastPurge) >= PURGE_INTERVAL * 3600) eventClean();
}

int eventClean() {
  string sapname;
  int sapnamelength;
  int num_purged = 0, total_players = 0;
  int p_time;
  int x;
  string *dirs, *losers;
  string file;
  string reason;
  
  dirs = ({ });
  losers = ({ });
  dirs = eventGet(DIR_PLAYERS + "/");
  log_file("players/purge", ctime(time()) + "\n");
  
  foreach(string path in dirs) {
    losers = eventGet(DIR_PLAYERS + "/" + path + "/");
    foreach(string sap in losers) {
      total_players++;
      sapnamelength = sizeof(sap);
      sapname = sap[0..(sapnamelength-3)];
      if (find_player(sapname)) continue;
      unguarded( (: restore_object, DIR_PLAYERS + "/" + path + "/" + sapname :) );
      reason = 0;
/*
      if (TestChar) continue;
*/
      if (!intp(Level)) Level = 1;
      if (Level > 25) continue;
      if (Retired) continue;
      p_time = PURGE_TIME * Level;
      
//      if (p_time < 3)     p_time = 3;           
      x = ((time() - LoginTime) / 86400);
      if (x > p_time) reason = "Last on " + ctime(LoginTime); 
      if ((x = (p_time - x)) <= 10 && !reason) {
        CHAT_D->eventSendChannel("PURGE_D", "reports", sapname + " (" + Level + ") is " + consolidate(x, "one day") + " from purge.");
        log_file("players/purge", sapname + " is " + consolidate(x, "one day") + " from purge.\n");
      }
      if (LoginTime == 0) reason = "Never logged in";    
      if (reason) {
        file = (DIR_PLAYERS + "/" + path + "/" + sap);
        unguarded( (: rm, file :) );
        log_file("players/purge", "Purged " + sapname + " reason: " + reason + ".\n");
        CHAT_D->eventSendChannel("PURGE_D", "reports", capitalize(sapname) + " (" + Level + ") purged for " + reason);
        num_purged++;
        }     
    }
  }
  eventPostal();
  eventShipClean();
  CHARACTER_D->CleanLinks();
  CHAT_D->eventSendChannel("PURGE_D", "reports", "The purge daemon purged " + num_purged + " of " + total_players + " players.");
  LastPurge = time();
  return num_purged;
}

string *eventGet(string args) {
  string *dir_files = ({ });
  dir_files = unguarded( (: get_dir, args :) );
  return dir_files;
 }

void eventInform() {
  int np = LastPurge + (PURGE_INTERVAL * 3600);
  int hour, minute;
  int t = np - time();
  hour = (t /3600);
  minute = (t / 60) - hour * 60;
//  CHAT_D->eventSendChannel("Purge", "reports", "The purge daemon will run in " + consolidate(hour, "an hour") + " " + consolidate(minute, "a minute") + ".");
  if (hour) call_out( (: eventInform :), 1800);
    else call_out( (: eventInform :), 900);
}

void eventPostal() {
  string *dir_letters, *players;
  string *target_files;
  dir_letters = unguarded( (: get_dir, "/secure/save/postal/" :) );
  foreach(string letter in dir_letters) {
    players = unguarded( (: get_dir, "/secure/save/postal/" + letter + "/" :) );
    foreach(string person in players) {
     if (!user_exists(person)) {
        target_files = unguarded( (: get_dir, 
                 "secure/save/postal/" + letter + "/" + person + "/" :) );
        foreach(string thing in target_files) { 
          unguarded( (: rm, "/secure/save/postal/" + letter + "/" + person + "/" + thing :));
          }
        unguarded( (: rmdir, "/secure/save/postal/" + letter + "/" + person :));
        }
     }
   }
}

void eventShipClean() {
  string *dirs = get_dir("/save/vehicles/");
  foreach(string person in dirs) {
    if (!user_exists(person)) {
      foreach(string letter in get_dir("/save/vehicles/" + person + "/")) {
        foreach(string ship in get_dir("/save/vehicles/" + person + "/" + letter + "/"))
          unguarded( (: rm, "/save/vehicles/" + person + "/" + letter + "/" + ship :));
        unguarded( (: rmdir, "/save/vehicles/" + person + "/" + letter + "/" :));
      }
      unguarded( (: rmdir, "/save/vehicles/" + person + "/" :));
    }
  }
}

