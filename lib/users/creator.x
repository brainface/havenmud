/*    /lib/creator.c
 *    from the Nightmare IV LPC Library
 *    a very simple creator object
 *    created by Descartes of Borg 950321
 *    Version: @(#) creator.c 1.11@(#)
 *  last Modified 15 Sept 1997  Duuktsaryth@Haven
 */

#include <lib.h>
#include <daemons.h>
#include <vision.h>
#include <position.h>
#include <message_class.h>
#include "include/creator.h"

inherit LIB_INTERACTIVE;
inherit LIB_PERSIST;
inherit LIB_TALK;

#ifdef __PACKAGE_DATABASE_DB__
inherit LIB_ISQL;
#endif /* __PACKAGE_DATABASE_DB__ */

private int CreatorAge, CreatorBirth, Position = POSITION_STANDING;
private int WhoInvis;
private int Angel = 1, Retired = 0;
private string Sponsor = "None";
private string *Religion, ReligionTitle, Department;
private string Domain = "None";
private string DomainTitle;
private string *Sponsorees = ({ });
private string Gender;
mixed Status;
private static int LastCreatorAge;

/* *****************  /lib/creator.c driver applies  ***************** */

static void create() {
    interactive::create();
    talk::create();
    CreatorAge = 0;
    WhoInvis = 0;
    LastCreatorAge = time();
    CreatorBirth = time();
    Status = 0;
  AddSave( ({ "Angel", "Sponsor", "Sponsorees" }) );
  AddSave( ({ "Retired" }) );
  set_heart_beat(30);
}

int is_living() { return 1; }

int inventory_accessible() { return 1; }

int inventory_visible() { return 1; }

void heart_beat() {
  interactive::heart_beat();
  if (!interactive(this_object())) {
    set_heart_beat(0); 
    return;
   }
}

mixed direct_give_liv_obj() {
    if( this_player() == this_object() ) return "Are you confused?";
    return 1;
}

mixed direct_verb_rule(string verb) {
  return SOUL_D->CanTarget(this_player(), verb, this_object());
}

mixed direct_give_liv_obs() {
    return direct_give_liv_obj();
}

mixed indirect_give_obj_to_liv(object item) {
    if( !item ) return 0;
    if( this_player() == this_object() ) return "Are you confused?";
    if( environment(item) != this_player() ) return "You don't have that!";
    return CanCarry((int)item->GetMass());
}

mixed indirect_give_obs_to_liv(object *item) {
    return 1;
}

mixed direct_look_obj() {
  if (GetInvis()) return "There is no " + GetKeyName() + " here.";
  return "You have a hard time focusing on that.";
  }

mixed direct_look_at_obj() {
  if (GetInvis()) return "There is no " + GetKeyName() + " here.";
  return "You have a hard time focusing on that.";
  }

mixed direct_marry_liv_to_liv() {
    return 1;
}

mixed indirect_marry_liv_to_liv() {
    return 1;
}

static void net_dead() {
    interactive::net_dead();
    CreatorAge += time() - LastCreatorAge;
    LastCreatorAge = time();
    set_heart_beat(0);
}

mixed eventChangePosition(int position) {
    switch(position) {
    case POSITION_STANDING:
	environment()->eventPrint(GetName() + " gets up.", this_object());
	eventPrint("You stand up.");
	Position = position;
	return 1;

    case POSITION_SITTING:
	environment()->eventPrint(GetName() + " sits down.", this_object());
	eventPrint("You sit down.");
	Position = position;
	return 1;

    case POSITION_LYING:
	environment()->eventPrint(GetName() + " lies down.", this_object());
	eventPrint("You lie down.");
	Position = position;
	return 1;

    default:
	return 0;
    }
}

void eventReconnect() {
    string tmp;

    interactive::eventReconnect();
    LastCreatorAge = time();
    if( file_exists(tmp = user_path(GetKeyName()) + "dead.edit") )
      message("system", "\nYour edit file was saved as: "+tmp, this_object());
    set_heart_beat(30);
}

varargs mixed eventShow(object who, string str, string on_id) {
    who->eventPrint(GetLong(str));
   if(!this_player()->GetInvis() && !this_player()->GetProperty("assumed"))
    environment(who)->eventPrint((string)this_player()->GetName() +
				 " looks at " + GetShort() + ".",
				 ({ who, this_object() }));
    if( this_player() != this_object() )
    if (!(this_player()->GetInvis()))
      eventPrint((string)this_player()->GetName() + " looks you over.");
    return 1;
}

/* *****************  /lib/creator.c events  ***************** */

void eventDescribeEnvironment(int verbose) {
    object env;

    if( !(env = environment()) ) {
        message("room_description", "No environment.", this_object());
        return;
    }
    message("system", file_name(env), this_object());
    interactive::eventDescribeEnvironment(verbose);
}

varargs int eventMoveLiving(mixed dest, string omsg, string imsg) {
    object *inv;
    object prev;

    if( prev = environment() ) {
        if( stringp(dest) ) {
            if(dest[0] != '/') {
                string *arr;

                arr = explode(file_name(prev), "/");
                dest = "/"+implode(arr[0..sizeof(arr)-2], "/")+"/"+dest;
            }
        }
        if( !eventMove(dest) ) {
	    eventPrint("You remain where you are.", MSG_SYSTEM);
            return 0;
        }
        inv = filter(all_inventory(prev), (: (!GetInvis($1) && living($1) &&
                                              ($1 != this_object())) :));
        if( !omsg || omsg == "" ) omsg = GetMessage("telout");
        else omsg = GetMessage("leave", omsg);
	inv->eventPrint(omsg, MSG_ENV);
    }
    else if( !eventMove(dest) ) {
	eventPrint("You remain where you are.", MSG_SYSTEM);
        return 0;
    }
    inv = filter(all_inventory(environment()),
                 (: (!GetInvis($1) && living($1) && ($1 != this_object())) :));
    if( (!imsg || imsg == "") && (!omsg || omsg == "") )
      imsg = GetMessage("telin");
    else if( !imsg || imsg == "" ) imsg = GetMessage("come", imsg);
    else imsg = replace_string(imsg, "$N", GetName());
    inv->eventPrint(imsg, MSG_ENV);
    eventDescribeEnvironment(GetBriefMode());
    return 1;
}

static int Destruct() {
    int x;

    if( !(x = interactive::Destruct()) ) return 0;
#ifdef __PACKAGE_DATABASE_DB__
    isql::Destruct();
#endif /* __PACKAGE_DATABASE_DB__ */
    return x;
}
	  
/* *****************  /lib/creator.c  local functions ***************** */

int Setup() {
    string tmp;
    int bugs, laston;

    laston = GetLoginTime();
    if( !interactive::Setup() ) return 0;
  AddChannel( ({ "imm", "time", "non", "reboot" }) );
  AddChannel("hl");
  AddChannel( ({ "fs", "isport" }) );
  AddChannel( ({ "ooc", "quest" }) );
  AddChannel( ({ "intergossip" }) );
  AddChannel("notify");
  AddChannel( ({ "debug", "ooc", "spam", }) );
  AddChannel( ({ "reports" }) );
  AddChannel( ({ "players" }) );
  AddChannel( ({ "prayer", "error" }) );
  AddChannel("ds");
  AddChannel("dc");
  AddChannel( ({ "ibsg", "intercre" }) );
  AddChannel( ({ "shipreports" }) );
  if (musep() )    AddChannel( ({  "souls", "muse",  }) );
  if (archp())     AddChannel( ({ "arch", "allnotify" }) );
  if (securep())   AddChannel( ({ "meta", }) );
  if (adminp())    AddChannel( ({ "admin", "nws", }) );
  if (duukp())     AddChannel( ({ "resets", "ignore" }) );
  
  if (!GetRetired()) {
    AddSearchPath( ({ DIR_CREATOR_CMDS, DIR_SECURE_CREATOR_CMDS }) );
  if( file_size(tmp = user_path(GetKeyName()) + "cmds") == -2 )
      AddSearchPath( ({ tmp }) );
  if( archp() ) AddSearchPath( ({ DIR_ADMIN_CMDS, DIR_SECURE_ADMIN_CMDS }) );
  if (musep() ) AddSearchPath( ({ DIR_MUSE_CMDS, DIR_SECURE_MUSE_CMDS }) );
  }
  NOTIFY_D->eventPrintNotices(this_object(), laston);
    return 1;
}

int eventForce(string cmd) {
    if( !((int)master()->valid_apply( ({ GetKeyName() }) )) ) return 0;
    else return interactive::eventForce(cmd);
}

/*  ***************  /lib/creator.c modal functions  *************** */

int CanCarry(int amount) { return 1; }

/* ************  /lib/creator.c data manipulation functions  ************ */

int GetCreatorAge() {
    int x;

    if( !interactive(this_object()) ) return CreatorAge;
    x = time() - LastCreatorAge;
    CreatorAge += x;
    LastCreatorAge = time();
    return CreatorAge;
}

int GetSkillLevel(string skill) { return 100; }
int GetStatLevel(string stat) { return 200; }
int AddSkillPoints(string x, int y) { return 1; }

int GetSleeping() { return 0; }

int GetInCombat() {
  return 0;
  }

mixed SetStatus(mixed n) { return Status = n; }

mixed GetStatus() {
  return Status;
}

string SetSponsor(string who) {
   return (Sponsor = who);
  }

string GetSponsor() {
  return Sponsor;
  }

string *SetSponsorees(string *args) {
  return (Sponsorees = args);
  }

string *AddSponsoree(string arg) {
   (Sponsorees += ({ arg }) );
   return (Sponsorees);
  }

string *RemoveSponsoree(string arg) {
   (Sponsorees -= ({ arg }) );
  return (Sponsorees);
  }

string *GetSponsorees() {
  return (Sponsorees);
  }

int SetAngel(int x) {
  return (Angel = x);
  }

int GetAngel() {
  return (Angel);
  }
string SetGender(string gender) {
    if( !((int)master()->valid_apply( ({ GetKeyName() }) )) ) return Gender;
    else return (Gender = gender);
}

string GetGender() { return Gender; }

int AddLanguagePoints(string x, int y) {
  return 1;
  }

varargs string GetLong(string str) {
    mapping counts;
    string item;

    str = GetShort() + "\n";
    str += interactive::GetLong() + "\n";
    foreach(item in map(all_inventory(),
                        (: (string)$1->GetAffectLong(this_object()) :)))
      if( item ) str += item + "\n";
    counts = ([]);
    foreach(item in map(
        filter(all_inventory(), (: !((int)$1->GetInvis(this_object())) :)),
        (: (string)$1->GetShort() :)))
      if( item ) counts[item]++;
    if( sizeof(counts) ) str += GetCapName() + " is carrying:\n";
    foreach(item in keys(counts))
      str += consolidate(counts[item], item) + "\n";
    return str;
}

int GetCreatorBirth() { return CreatorBirth; }

int GetEffectiveVision() { return VISION_CLEAR; }

string GetNativeLanguage() { return "Common"; }

int GetLanguageLevel(string whocares) { return 100; }

string GetLanguageName(string lang) {
    if( convert_name(lang) != "common" ) return 0;
    else return "common";
}

string GetHealthShort() { return GetShort(); }

string GetName() { 
    if( !GetInvis() ) return ::GetName();
  else return "An invisible immortal";
}

int GetPosition() {
    return Position;
}

int SetPosition(int x) {
    return (Position = x);
}

int GetRadiantLight() {
    return 0;
}

string *GetFriends() { return ({ }); }

int GetGravity() { 
  if (environment()) { return (environment()->GetGravity()); }
  else return 0;
  }

int AddCarriedMass(int x) { return 0; }
int GetCarriedMass() { return 0; }

string SetDomain(string x) { return (Domain = x); }

string GetDomain() { return (Domain); }

string SetDomainTitle(string x) { return (DomainTitle = x); }

string GetDomainTitle() { return (DomainTitle); }

int SetRetired(int x) { return (Retired = x); }

int GetRetired() { return (Retired); }

string GetRace() { return "Immortal"; }

void eventLoadObject(mixed *value, int recurse) { return interactive::eventLoadObject(value, recurse); }

string GetOOCName() { return GetName(); }

string *SetReligion(string *r) { 
  if (!arrayp(r)) Religion = ({ r });
  else Religion = r;
  return Religion;
}


string GetReligion() {
  if (arrayp(Religion)) return (string)Religion[0];
  else return (string)Religion;
 }

string SetReligionTitle(string x) { return (ReligionTitle = x); }

string GetReligionTitle() { return (ReligionTitle); }

string SetDepartment(string d) { return (Department = d); }

string GetDepartment() { return Department; }

int SetWhoInvis(int flag) {
  return WhoInvis = flag;
}

int GetWhoInvis() {
  return WhoInvis;
}

int GetUndead() { return 0; }

string GetUndeadType() { return "Smurf"; }

varargs int eventCheckSkill(string skill, int con, int bonus, int train) {
  return 1000;
}

int GetLevel() { return 501; }

int GetStaminaPoints() { return 10000; }
int GetHealthPoints() { return 10000; }
int GetMagicPoints() { return 10000; }
