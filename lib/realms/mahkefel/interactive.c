/*    /lib/interactive.c
 *    from the Dead Soulsr1 Object Library
 *    an interactive object
 *    created by Descartes of Borg 941001 for the Idea Exchange
 *    Version: @(#) interactive.c 1.17@(#)
 *    Last modified: 97/01/03
 */

#include <lib.h>
#include <clock.h>
#include <privs.h>
#include <daemons.h>
#include <objects.h>
#include <rooms.h>
#include <marriage.h>
#include <medium.h>
#include <position.h>
#include <message_class.h>
#include <vision.h>
#include <voting.h>
#include <newsnotify.h>
#include "include/interactive.h"

inherit LIB_CONTAINER;
inherit LIB_OBJECT;
inherit LIB_AUTOSAVE;
inherit LIB_FILES;
inherit LIB_MOVE;
inherit LIB_PAGER;
inherit LIB_MESSAGES;
inherit LIB_INTERFACE;

private int Wrapping = 1, SocialRank = 1, ConfirmedEmail;
private int Age, WhereBlock, Brief, LoginTime, BirthTime;
private string Password, Email, RealName, Rank, LoginSite, HostSite, WebPage, *AdditionalId;
string *Ranks;
private class marriage *Marriages;
private static int LastAge, Setup;
private static object NetDiedHere;
private static mapping LastError;
private static string *UserId;
private mapping NewsgroupNotifySettings;
private int NewServerLogin;

int GetInCombat();
int eventWimpy();
int AddCarriedMass(int x) { return 1; }
int GetCarriedMass() { return 0; }
int GetConfirmedEmail();
string GetOOCName();

static void create() {
    object::create();
    messages::create();
    interface::create();
    SetOpacity(0);
    Marriages = ({});
    AdditionalId = ({});
    HostSite = "";
    Brief = 0;
    Password = 0;
    Email = 0;
    ConfirmedEmail = 0;
    RealName = 0;
    Rank = 0;
    Ranks = ({ "Citizen" });
    LoginSite = ROOM_START;
    BirthTime = time();
    LastAge = time();
    NewsgroupNotifySettings = ([ 
      "news.announcements" : NEWS_NOTIFY_LOGON,
	    "ooc" : NEWS_NOTIFY_LOGON,
	    ]);
    SetShort("$N the unaccomplished");
    SetLong("$N is nondescript.");
}

/* ***************  /lib/interactive.c modal functions  *************** */

int NewServer() { return !NewServerLogin; }
int SetNewServer(int x) { return NewServerLogin = x; }

mixed CanDivorce(object who) {
    class marriage m;
    
    if( !Marriages || !sizeof(Marriages) )
      return GetName() + " is not married!";
    m = Marriages[0];
    if( m->DivorceDate ) return GetName() + " is not married!";
    return 1;
}
    
mixed CanGet(object ob) {
    return GetName() + " is a living being!";
}

mixed CanMarry(object who, object to_whom) {
    if( !Marriages ) Marriages = ({});
    if( GetSpouse() ) return GetName() + " is currently married!";
    return 1;
}

/* ***************  /lib/interactive.c lfuns  *************** */
int Setup() {
    mapping mp;
    string tmp;
    object room;

    if(Setup) return 0;
    else Setup = 1;
    set_living_name(GetKeyName());
    interface::Setup();
    add_action((: cmdQuit :), "quit");
    add_action((: cmdQuit :), "logout");
    HostSite = query_ip_name(this_object());
    LoginTime = time();
    SetId(({}));
    autosave::Setup();
    call_out("save_player", 2, GetKeyName());
    log_file("players/enter", GetCapName()+" (enter): "+ctime(time())+
      " : "+query_ip_name(this_object())+"\n");	
	catch(room = load_object(LoginSite));
	if( !eventMove(LoginSite) ) {
	    eventMove(LoginSite = ROOM_START);
	}

    environment()->eventPrint(tmp, MSG_ENV, this_object());
    if( !(tmp = GetMessage("login")) )
      tmp = GetName() + " enters "+mud_name()+".";
    if (creatorp())  CHAT_D->eventSendChannel(GetKeyName(), "allnotify",capitalize(GetKeyName()) + " (" + GetOOCName() + ") logs in.", 1);
    if (!creatorp()) CHAT_D->eventSendChannel(GetKeyName(), "notify", capitalize(GetKeyName()) + " (" + GetOOCName() + ") logs in.", 1);
    if(!catch(mp = (mapping)FOLDERS_D->mail_status(GetKeyName()))) {
        if(mp["unread"]) {
            eventPrint("\n>>> " + mp["unread"] + " of your " +
                       (mp["total"] == 1 ? mp["total"] + " letter is" :
                        mp["total"] + " letters remain") + " unread. <<<",
                       MSG_SYSTEM);
        }
    }
    if (!sizeof(NewsgroupNotifySettings))
    {
	NewsgroupNotifySettings = ([ "news.announcements" : NEWS_NOTIFY_LOGON,
				     "ooc" : NEWS_NOTIFY_LOGON ]);
    }
    if (creatorp() && member_array("news.imm", keys(NewsgroupNotifySettings)) == -1)
    {
	    NewsgroupNotifySettings["news.imm"] = NEWS_NOTIFY_LOGON;
    }
    NEWSGROUP_D->CheckLogonUnreadGroups(this_object());
    NEWS_D->NewbieNews();
    if (!GetConfirmedEmail()) {
      this_object()->eventPrint(
                       "%^B_RED%^BLACK%^"
                       "*****************************************************\n"
                       "Your email status is NOT CONFIRMED. You will need to "
                       "use the 'chfn' command and set a valid email address. "
                       "If this situation is not corrected, your ability to login "
                       "to Haven may be restricted or removed!\n"
                       "******************************************************"
                       "%^RESET%^"
                       );
      }
    return 1;
}

static void net_dead() {
    interface::net_dead();
    Age += time() - LastAge;
    LastAge = time();
    save_player(GetKeyName());
    log_file("players/enter", GetCapName() + " (net-dead): " + ctime(time()) + "\n");
    if (!creatorp()) CHAT_D->eventSendChannel(GetKeyName(), "notify", capitalize(GetKeyName()) + " linkdies.", 1);
    if (creatorp())  CHAT_D->eventSendChannel(GetKeyName(), "allnotify", capitalize(GetKeyName()) + " linkdies.", 1);
    if(query_snoop(this_object()))
      query_snoop(this_object())->eventPrint(GetCapName() + " has gone " "net-dead.", MSG_SYSTEM);
  cmdQuit("nd");
}

void eventReconnect() {
    string dead_ed;

    interface::eventReconnect();
    LastAge = time();
    HostSite = query_ip_name(this_object());
    eventPrint("Reconnected.", MSG_SYSTEM);
    if (!creatorp()) CHAT_D->eventSendChannel(GetKeyName(), "notify", capitalize(GetKeyName()) + " logs in.", 1);
    if (creatorp())  CHAT_D->eventSendChannel(GetKeyName(), "allnotify", capitalize(GetKeyName()) + " unlinkdies.", 1);
/*
    if( NetDiedHere ) eventMove(NetDiedHere);
    else eventMove(ROOM_START);
*/
    environment()->eventPrint(GetCapName() + " has rejoined this reality.",  MSG_ENV, this_object());
    NetDiedHere = 0;
}

int eventDestruct() {
    object ob;
    int i;

    interface::eventDestruct();
    foreach(ob in deep_inventory(this_object())) {
	if( ob ) catch(ob->eventDestruct());
    }
    return object::eventDestruct();
}

mixed eventDivorce(object who) {
    class marriage m;

    m = Marriages[0];
    m->DivorceDate = time();
    return 1;
}
    
mixed eventMarry(object who, object to_whom) {
    class marriage m;
    object env;

    if(!env = environment() ) return 0;
    m = new(class marriage);
    m->Spouse = (string)to_whom->GetCapName();
    m->WeddingDate = time();
    m->DivorceDate = 0;
    m->Location = file_name(env);
    Marriages = ({ m }) + Marriages;
    return 1;
}

int eventMove(mixed dest) {
    string str;
    int x;

    x = move::eventMove(dest);
    if( x ) {
        if( !(str = (string)environment()->GetProperty("login")) )
          LoginSite = base_name(environment());
        else LoginSite = str;
    }
    return x;
}


int cmdQuit(string str) {
    string tmp;
    string who, file;

    if( previous_object() && !
       ((int)master()->valid_apply( ({ GetKeyName() }) )) ) return 0;
    if( (int)environment(this_object())->GetProperty("no quit") &&
      ! sizeof(previous_object(-1)) ) {
        message("system", "You are unable to escape this reality!",
          this_object());
        return 1;
    }
  if (GetInCombat() && str != "master") {
    message("system", "You cannot quit while fighting!", this_object());
    save_player(GetKeyName());
    return 1;
  }
  if (vehiclep(environment())) {
  	object ship = environment();
  	eventMove(environment(ship));
  	ship->eventDestruct();
  	save_player(GetKeyName());
  }
    message("system", "Please come back another time!", this_object());
    AddCarriedMass(-GetCarriedMass());
    save_player(GetKeyName());
    tmp = GetMessage("logout") || (GetName() + " is gone from this reality!");
    message("environment", tmp, environment(this_object()), ({this_object()}));
    log_file("players/enter", GetCapName()+" (quit): "+ctime(time())+"\n");
    if (str != "nd") {
      if (!creatorp()) CHAT_D->eventSendChannel(GetKeyName(), "notify", capitalize(GetKeyName()) + " logs out.", 1);
      if (creatorp())  CHAT_D->eventSendChannel(GetKeyName(), "allnotify", capitalize(GetKeyName()) + " logs out.", 1);
      }
    who = GetKeyName();
    file = DIR_KILLS "/" + who[0..0] + "/" + who;
    unguarded( (: rm, file :) );
    VEHICLES_D->PlayerLogout(this_object());
    eventDestruct();
    return 1;
}

int GetAge() {
    int x;

    if(!interactive(this_object())) return Age;
    x = time() - LastAge;
    Age += x;
    LastAge = time();
    return Age;
}

int GetBirth() { return BirthTime; }

string query_cwd() { return interface::query_cwd(); }

void SetEmail(string str) {
    if(!((int)master()->valid_apply(({ GetKeyName() })))) return;
    Email = str;
}

int SetConfirmedEmail(int x) { return ConfirmedEmail = x; }
int GetConfirmedEmail() { return ConfirmedEmail; }

string GetEmail() {
    return Email;
}


string *SetAdditionalId(string *s) {
  if (!arrayp(s)) s = ({ s });
  AdditionalId = s;
  SetId(({}));
  return GetId();
}

string *GetAdditionalId() { return AdditionalId; }

string *RemoveAdditionalId(string *s) {
  if (!arrayp(s)) s = ({ s });
  AdditionalId -= s;
  SetId(({}));
  return GetId();
}

void SetId(string *bogus) {
    int i;

//    if(UserId) return;
    if(!GetCapName()) {
        UserId = ({ GetKeyName() });
        return;
    }
    UserId = ({ GetKeyName(), lower_case(GetCapName()) });
    if (sizeof(AdditionalId)) UserId += AdditionalId;
    parse_refresh();
    if((i=sizeof(bogus = explode(lower_case(GetCapName()), " "))) == 1)
        return;
    while(i--)
        if(!user_exists(bogus[i])) UserId += ({ bogus[i] });
}

string *GetId() { return UserId; }

int id(string str) {
    if(!str || !UserId) return 0;
    else return member_array(lower_case(str), UserId) != -1;
}

int GetLoginTime() { return LoginTime; }

string SetKeyName(string str) {
    if( previous_object() != master() ) return GetKeyName();
    return object::SetKeyName(str);
}

string GetKeyName() { return object::GetKeyName(); }

void SetPassword(string str) {
    if(!((int)master()->valid_apply(({ GetKeyName() })))) return;
    Password = str;
    save_player(GetKeyName());
}

string GetPassword() {
    if(!((int)master()->valid_apply(({ GetKeyName() })))) return 0;
    else return Password;
}

int SetSocialRank(int x) { return SocialRank = x; }

int GetSocialRank() { return SocialRank; }

string *SetRanks(string *str) { Ranks = str; SetShort(""); return Ranks; }
string *AddRank(string str) { return distinct_array(Ranks += ({ str })); }
string *GetRanks() { Ranks = distinct_array(Ranks); return Ranks; }
string *RemoveRank(mixed str) {
  string *tmp;
  if (arrayp(str)) tmp = str;
    else tmp = ({ str });
  Ranks -= tmp;
  return Ranks;
}

void SetRank(string str) { AddRank(str); }

string GetRank() { if (sizeof(Ranks)) return Ranks[0]; else return 0; }

void SetRealName(string str) {
    if(!((int)master()->valid_apply(({ GetKeyName() })))) return;
    RealName = str;
}

string GetRealName() { return RealName; }

string GetShort() {
    string str;

    str = object::GetShort(str);
    if( !str ) str = "$N the unaccomplished";
    if( strsrch(str, "$N") == -1 ) str = "$N";
    str = replace_string(str, "$N", GetName());
    if( interactive(this_object()) ) return str;
    else return str + " (net-dead)";
}

varargs string GetLong() {
    string str;

    str = object::GetLong(str);
    if(!str || strsrch(str, "$N") == -1) str = "$N is nondescript.";
    str = replace_string(str, "$N", GetName());
    return str;
}

int SetBriefMode(int x) { return (Brief = x); }

int GetBriefMode() { return Brief; }

int SetWrappingMode(int x) { return (Wrapping = x); }

int GetWrappingMode() { return Wrapping; }

int SetWhereBlock() { return (WhereBlock = !WhereBlock); }

int GetWhereBlock() { return WhereBlock; }

string get_path() {
    log_file("get_path", identify(previous_object())+"\n");
    return query_cwd();
}

void SetLastError(mapping m) {
    if (previous_object() != master()) return;
    LastError = m;
}

mapping GetLastError() {
    string caller = file_name(previous_object());
    if( caller[0..24] == "/secure/cmds/creators/dbx" ||
      caller[0..23] == "/secure/cmds/players/bug" ) return LastError;
    error("Privilege Violation: " + caller);
}

void SetCapName(string str) {
    if( base_name(previous_object(0)) != LIB_CONNECT ) return;
    object::SetCapName(str);
}

void move_or_destruct() {
    (eventMove(ROOM_START) || eventMove(ROOM_VOID));
}

string SetShort(string str) {
    if( strsrch(str, "$N") == -1 ) return object::GetShort();
    else return object::SetShort(str);
}

string SetLong(string str) {
    if(strsrch(str, "$N") == -1) return object::GetLong();
    else return object::SetLong(str);
}

string GetName() { return object::GetName(); }

varargs int GetInvis(object ob) { return object::GetInvis(ob); }

mixed *GetCommands() {
    if( !((int)master()->valid_apply( ({ GetKeyName() }) )) ) return ({});
    else return commands();
}

string GetSpouse() {
    if( !Marriages || !sizeof(Marriages) ) return 0;
    if( ((class marriage)Marriages[0])->DivorceDate ) return 0;
    return ((class marriage)Marriages[0])->Spouse;
}

class marriage *GetMarriages() { return Marriages; }

class marriage *ResetMarriages() { return Marriages = ({ }); }

string GetHostSite() {
    if( WhereBlock ) {
	if( !((int)master()->valid_access(({ PRIV_ASSIST }))) )
	  return "Confidential";
	else return HostSite;
    }
    return HostSite;
}

void eventLoadObject(mixed *value, int recurse) { }

varargs int GetRadiantLight(int ambient) {
    return (object::GetRadiantLight(ambient) +
	    container::GetRadiantLight(ambient));
}

string GetWebPage() {
    return WebPage;
}

string SetWebPage(string page) {
    if( !master()->valid_apply(({ GetKeyName() })) ) {
	return WebPage;
    }
    return (WebPage = page);
}

int SetNewsgroupNotifySetting(string group, int setting)
{
    return (NewsgroupNotifySettings[group] = setting);
}

int GetNewsgroupNotifySetting(string group)
{
    if (!NewsgroupNotifySettings[group]) return 0;

    return NewsgroupNotifySettings[group];
}

mapping GetNewsgroupNotifySettings() { return NewsgroupNotifySettings; }

mapping RemoveNewsgroupNotifySetting(string group)
{
    map_delete(NewsgroupNotifySettings, group);

    return NewsgroupNotifySettings;
}

/* --------------- */

string CheckVisibility() {
  string tmp = 0;
  switch( GetEffectiveVision() ) {
    case VISION_BLIND:
	    tmp = "You are blind and can see nothing.";
	    break;
    case VISION_TOO_DARK:
      tmp = ("It is much too dark to see.");
	    break;
    case VISION_DARK:
	    tmp = ("It is too dark to see.");
      break;
    case VISION_TOO_BRIGHT:
      tmp = ("It is much too %^YELLOW%^bright%^RESET%^ to see.");
	    break;
    case VISION_BRIGHT:
      tmp = ("It is too %^YELLOW%^bright%^RESET%^ to see.");
      break;
    }
  return tmp;
}



void eventDescribeEnvironment(int brief) {
    object env;
    mixed tmp = 0;
    string *shorts;
    string desc, smell, sound, touch, weather;
    int i, maxi;
    mapping lying = ([]), sitting = ([]), standing = ([]), sleeping = ([]);
    object *obs;
    string key;
    int val;
    

    if(!(env = environment(this_object()))) {
        eventPrint("You are nowhere.", MSG_ROOMDESC);
        eventDestruct();
        return;
    }
   if (env->GetProperty("PROP_VEHICLE")) env = environment(env);
   if (tmp = CheckVisibility()) {
     eventPrint(tmp);
     return;
    }  
    
   if( !brief ) { /* brief is off */
      desc = (string)env->GetObviousExits() || "";
      if (!vehiclep(environment())) {
	      desc = capitalize((string)env->GetShort() || "") + " [" + desc + "]\n";
        } else { desc = "[" + desc + "]\n"; }
      if (environment()->GetProperty("PROP_VEHICLE")) 
        desc = "%^BOLD%^GREEN%^Aboard " + environment()->GetShort() + " [out]\n%^RESET%^" + desc;
	   desc += (string)env->GetLong();
     if(functionp(tmp = (mixed)env->GetSmell("default")))
	      tmp = (string)(*tmp)("default");
     smell = tmp;
     if(functionp(tmp = (mixed)env->GetListen("default")))
        tmp = (string)(*tmp)("default");
     sound = tmp;
     if( functionp(tmp = (mixed)env->GetTouch("default")) )
        tmp = evaluate(tmp, "default");
     touch = tmp;
     if (env->GetClimate() != "indoors" && env->GetClimate() != "underground" && !(env->GetProperty("no weather")) )
        weather = WEATHER_D->GetWeather(env);
    
    } else {  /* brief is on */
	    desc = capitalize((string)env->GetShort());
	    if( (tmp = (string)env->GetObviousExits()) && tmp != "" )
	      desc += " [Exits: " + tmp + "]";
      if (sizeof(env->GetUniqueEnters())) {
        desc += "[Enters: " + implode(values(env->GetUniqueEnters()), ", ") + "]";
      }
	  }	
    
    if( desc )   eventPrint(desc,                   MSG_ROOMDESC);
    if( smell )  eventPrint("%^GREEN%^"  + smell,   MSG_ROOMDESC);
    if( sound )  eventPrint("%^CYAN%^"   + sound,   MSG_ROOMDESC);
    if( touch )  eventPrint("%^YELLOW%^" + touch,   MSG_ROOMDESC);
    if (weather) eventPrint("%^BLUE%^"   + weather, MSG_ROOMDESC);
    if (env->GetPoisonGas()) eventPrint("%^RED%^There is a cloud of poison gas here.%^RESET%^");

    desc = "";
    
    /* non-living inventory */
    shorts = map(filter(all_inventory(env), function(object ob) {
	           if( living(ob) )                       return 0;
             if( (int)ob->GetInvis(this_object()) ) return 0;
				     if( (int)ob->isFreshCorpse() )         return 0;
             if (ob == environment())               return 0;
				     return 1;
	          } ), (: (string)$1->GetShort() :));
	  foreach(string s in shorts) {
	    if( s ) {
		    lying[s]++;
	      }
	    }
	  for(i=0, desc = 0, maxi = sizeof(shorts = keys(lying)); i<maxi; i++) {
	    key = shorts[i];
	    val = lying[shorts[i]];
	    if( val < 2 ) {
		    if( !desc ) desc = "%^MAGENTA%^" + capitalize(key) + "%^RESET%^MAGENTA%^";
		      else desc += key + "%^RESET%^MAGENTA%^";
	    } else {
		    if( !desc ) desc = "%^MAGENTA%^" + capitalize(consolidate(val, key)) + "%^RESET%^MAGENTA%^";
		      else desc += consolidate(val, key) + "%^RESET%^MAGENTA%^";
	      }
	    if( i == maxi - 1 ) {
		    if( maxi > 1 || val >1 )
		      desc += " are here.%^RESET%^\n";
		      else desc += " is here.%^RESET%^\n";
	      }
	      else if( i == maxi - 2 ) {
		      if( maxi == 2 ) {
		        desc += " and ";
		        }
		        else {
		        desc += ", and ";
	   	      }
	        }
	      else desc += ", ";
	     } 
     
     key = 0; val = 0; lying = ([]);
     obs = filter(all_inventory(env), function(object ob) {
             if( (int)ob->GetInvis(this_object()) >= rank() ) return 0;
					   if( living(ob) )                                 return 1;
					   if( (int)ob->isFreshCorpse() )                   return 1;
	           }) - ({ this_object() });
	
	  maxi = sizeof(shorts = map(obs, (: (string)$1->GetHealthShort() :)));
	  foreach(object liv in obs) {
	    string s = (string)liv->GetHealthShort();
	    int pos = (int)liv->GetPosition();
	    
	    if( !s ) continue;
	    if( creatorp(liv) || pos == POSITION_STANDING) standing[s]++;
	    else if( (pos == POSITION_LYING || (int)liv->isFreshCorpse()) && !liv->GetSleeping() )
	      lying[s]++;
	    else if( pos == POSITION_SITTING ) sitting[s]++;
	    else if (liv->GetSleeping()) sleeping[s]++;
	    else lying[s]++;
	  }
    if( !desc ) {  tmp = "";  } else { tmp = desc;  }
	  desc = ""; 
	  
	  foreach(key, val in lying) {
	    if( val < 2 ) desc += capitalize(key) + "%^RESET%^ is lying down.";
	      else desc += capitalize(consolidate(val, key)) + "%^RESET%^ are lying down.";
	    desc += "\n";
	    }
	  foreach(key, val in sleeping) {
      if (val < 2) desc += capitalize(key) + "%^RESET%^ is sleeping.";
        else desc += capitalize(consolidate(val, key)) + "%^RESET%^ are sleeping.";
      desc += "\n";
      }
	  foreach(key, val in sitting) {
	    if( val < 2 )
	      desc += capitalize(key) + "%^RESET%^ is sitting down.";
	        else desc += capitalize(consolidate(val, key)) + "%^RESET%^ are sitting down.";
	      desc += "\n";
	    }
	  foreach(key, val in standing) {
	    if( val < 2 )
	      desc += capitalize(key) + "%^RESET%^ is here.";
	        else desc += capitalize(consolidate(val, key)) + "%^RESET%^ are here.";
	      desc += "\n";
	    }
    
   if( tmp ) { desc = tmp + desc; }
   if( sizeof(desc) ) {
	   if (environment()->GetProperty("PROP_VEHICLE"))
	     eventPrint(desc, MSG_ROOMDESC); else
	     eventPrint(desc + "\n", MSG_ROOMDESC);
    }
   
   /* Room description complete... unless you're in a vehicle */
   if (environment()->GetProperty("PROP_VEHICLE")) {
       eventPrint("%^ORANGE%^" + environment()->GetLong() + "%^RESET%^");
       env = environment();

    desc = ""; lying = ([]); standing = ([]); sitting = ([]); sleeping = ([]);
    key = 0; val = 0;
    
    /* non-living inventory */
    shorts = map(filter(all_inventory(env), function(object ob) {
	           if( living(ob) )                       return 0;
             if( (int)ob->GetInvis(this_object()) ) return 0;
				     if( (int)ob->isFreshCorpse() )         return 0;
             if (ob == environment())               return 0;
				     return 1;
	          } ), (: (string)$1->GetShort() :));
	  foreach(string s in shorts) {
	    if( s ) {
		    lying[s]++;
	      }
	    }
	  for(i=0, desc = 0, maxi = sizeof(shorts = keys(lying)); i<maxi; i++) {
	    key = shorts[i];
	    val = lying[shorts[i]];
	    if( val < 2 ) {
		    if( !desc ) desc = "%^MAGENTA%^" + capitalize(key) + "%^RESET%^MAGENTA%^";
		      else desc += key + "%^RESET%^MAGENTA%^";
	    } else {
		    if( !desc ) desc = "%^MAGENTA%^" + capitalize(consolidate(val, key)) + "%^RESET%^MAGENTA%^";
		      else desc += consolidate(val, key) + "%^RESET%^MAGENTA%^";
	      }
	    if( i == maxi - 1 ) {
		    if( maxi > 1 || val >1 )
		      desc += " are here.%^RESET%^\n";
		      else desc += " is here.%^RESET%^\n";
	      }
	      else if( i == maxi - 2 ) {
		      if( maxi == 2 ) {
		        desc += " and ";
		        }
		        else {
		        desc += ", and ";
	   	      }
	        }
	      else desc += ", ";
	     } 
     
     key = 0; val = 0; lying = ([]);
     obs = filter(all_inventory(env), function(object ob) {
             if( (int)ob->GetInvis(this_object()) >= rank() ) return 0;
					   if( living(ob) )                                 return 1;
					   if( (int)ob->isFreshCorpse() )                   return 1;
	           }) - ({ this_object() });
	
	  maxi = sizeof(shorts = map(obs, (: (string)$1->GetHealthShort() :)));
	  foreach(object liv in obs) {
	    string s = (string)liv->GetHealthShort();
	    int pos = (int)liv->GetPosition();
	    
	    if( !s ) continue;
	    if( creatorp(liv) || pos == POSITION_STANDING) standing[s]++;
	    else if( (pos == POSITION_LYING || (int)liv->isFreshCorpse()) && !liv->GetSleeping() )
	      lying[s]++;
	    else if( pos == POSITION_SITTING ) sitting[s]++;
	    else if (liv->GetSleeping()) sleeping[s]++;
	    else lying[s]++;
	  }
    if( !desc ) {  tmp = "";  } else { tmp = desc;  }
	  desc = ""; 
	  
	  foreach(key, val in lying) {
	    if( val < 2 ) desc += capitalize(key) + "%^RESET%^ is lying down.";
	      else desc += capitalize(consolidate(val, key)) + "%^RESET%^ are lying down.";
	    desc += "\n";
	    }
	  foreach(key, val in sleeping) {
      if (val < 2) desc += capitalize(key) + "%^RESET%^ is sleeping.";
        else desc += capitalize(consolidate(val, key)) + "%^RESET%^ are sleeping.";
      desc += "\n";
      }
	  foreach(key, val in sitting) {
	    if( val < 2 )
	      desc += capitalize(key) + "%^RESET%^ is sitting down.";
	        else desc += capitalize(consolidate(val, key)) + "%^RESET%^ are sitting down.";
	      desc += "\n";
	    }
	  foreach(key, val in standing) {
	    if( val < 2 )
	      desc += capitalize(key) + "%^RESET%^ is here.";
	        else desc += capitalize(consolidate(val, key)) + "%^RESET%^ are here.";
	      desc += "\n";
	    }
    
   if( tmp ) { desc = tmp + desc; }
   eventPrint(desc, MSG_ROOMDESC);
   } /* end vehicle description */
}
