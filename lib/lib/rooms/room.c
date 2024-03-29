/*    /lib/obj/room.c
 *    From the Dead Souls LPC Library
 *    The room object used to represent any room in the game
 *    Created by Descartes of Borg 940711
 *    Version: @(#) room.c 1.20@(#)
 *    Last Modified: 97/01/01
 */

#include <lib.h>
#include <rooms.h>
#include <config.h>
#include <daemons.h>
#include <objects.h>
#include <function.h>
#include <medium.h>
#include <message_class.h>
#include <talk_type.h>

inherit LIB_AMBIANCE;
inherit LIB_CLEAN;
inherit LIB_CONTAINER;
inherit LIB_EXITS;
inherit LIB_DESCRIPTION;
inherit LIB_INVENTORY;
inherit LIB_LOOK;
inherit LIB_PROPERTIES;
inherit LIB_REMOTEDESCRIPTION;

private string          Domain        = 0;
private function        Bury          = 0;
private string          Climate       = "temperate";
private int             DayLight      = 0;
private static string   DayLong       = 0;
private object array    DummyItems    = ({});
private int             FarmingBonus  = 0;
private int             MiningBonus  = 0;
private static int      GasCheck      = time();
private float           Gravity       = 1.0;
private int             LastReset     = 0;
private static mixed    Listen        = 0;
private int             NightLight    = 0;
private static string   NightLong     = 0;
private static int      NoReplace     = 0;
private static int      PlayerKill    = 0;
private static int      PoisonGas     = 0;
private static int      ResetNumber   = 0;
private static mixed    Search        = 0;
private static int      Shade         = 0;
private static mixed    Smell         = 0;
private static string   SpecialCrop   = 0;
private static string   SpecialMineral = 0;
private static mixed    Touch         = 0;
private string          Town          = 0;
private int             Warmth        = 0;
private static string  *Newsgroups    = ({ });

string GetClimate();
int GetNightLight();
int GetDayLight();
int GetShade();
varargs int eventPrint(string msg, mixed arg2, mixed arg3);

/***********      /lib/room.c data manipulation functions      **********/

string *SetNewsgroups(string *groups) { return (Newsgroups = groups); }

string *SetNewsGroups(string *g) { return SetNewsgroups(g); }

string *GetNewsgroups() { return Newsgroups; }

int SetFarmingBonus(int x) { return FarmingBonus = x; }

int GetFarmingBonus() { return FarmingBonus; }

string SetSpecialCrop(string x) { return SpecialCrop = x; }

int SetMiningBonus(int x) { return MiningBonus = x; }

int GetMiningBonus() { return MiningBonus; }

string GetSpecialMineral() { return SpecialMineral; }

string SetSpecialMineral(string x) { return SpecialMineral = x; }
string GetSpecialCrop() { return SpecialCrop; }

string SetDomain(string x) { return Domain = x; }

string GetDomain() {
	string unusedString;
	string *tmp;
 
 if (Domain) return Domain; 
 if(sscanf(file_name(this_object()), "/std/%s/%s", Domain,unusedString)) {
			Domain = "Southern Coast";
		  return Domain;
		}
 if(sscanf(file_name(this_object()), "/realms/%s/%s", Domain,unusedString)) {
			Domain = "Southern Coast";
		  return Domain;
		}

 if(!sscanf(file_name(this_object()), "/domains/%s/%s", Domain,unusedString)) {
			Domain = "Unregistered";
		  return Domain;
		}
 tmp = explode(Domain, "_");
 foreach(string word in tmp) { 
 	tmp -= ({ word }); 
 	tmp += ({ capitalize(word) });
 	}
 Domain = implode(tmp, " ");
 	return (Domain);
}

int GetAmbientLight() {
    int a;

    if( GetClimate() == "indoors" || GetClimate() == "underground" ) {
	return ambiance::GetAmbientLight();
    }
    if( query_night() ) {
	a = GetNightLight();
    }
    else {
	a = GetDayLight();
    }
    a += SEASONS_D->GetRadiantLight() - GetShade();
    return a;
}

function GetBury() {
    return Bury;
}

function SetBury(function what) {
    Bury = what;
}

static string GetExtraLong() {
    string *l;
    string ret;

    ret = "  ";
    l = filter(map(all_inventory(), 
		   (: (string)$1->GetAffectLong(this_object()) :)), (: $1 :));
    if( !sizeof(l) ) return 0;
    ret += implode(l, "  ");
    return ret;
}

string GetInternalDesc() {
    string ret, tmp;

    if( DayLong && !query_night() ) {
	ret = DayLong;
    }
    else if( NightLong && query_night() ) {
	ret = NightLong;
    }
    else {
	ret = container::GetInternalDesc();
    }
    if( !ret ) {
	ret = "";
    }
    if( tmp = GetExtraLong() ) {
	ret += GetExtraLong();
    }
    return ret;
}

int GetResetNumber() {
    return ResetNumber;
}
 
string array GetId() { return ({}); }

string SetDayLong(string str) { return (DayLong = str); }
string GetShort() { 
  if (!::GetShort()) return short_file(file_name(this_object()));
  return ("%^BOLD%^BLUE%^" +  ::GetShort() + "%^RESET%^");
}

string GetDayLong() { return DayLong; }

string SetNightLong(string str) { return (NightLong = str); }

string GetNightLong() { return NightLong; }

string SetClimate(string str) { return (Climate = str); }

string GetClimate() { 
  return Climate;
}

float SetGravity(float h) { return (Gravity = h); }

float GetGravity() { return Gravity; }

int SetWarmth(int x) { return Warmth = x; }

int AddWarmth(int x) { return Warmth += x; }

int GetWarmth() {
  if (Warmth) return Warmth;
  if (Climate == "indoors") return 40;
  if (Climate == "underground") return 40;
  return 0;
}

int GetRoomWarmth() {
	int modifier = 0;
	
	foreach(object ob in all_inventory()) {
	  modifier += ob->GetHeat();
	}
	if (GetClimate() == "indoors" || GetClimate() == "underground") {
    return (GetWarmth() + modifier);
  }
  return (WEATHER_D->GetTemperature(GetDomain(), GetClimate()) + GetWarmth() + modifier);
}

int GetDayLight() {
    return DayLight;
}

int SetDayLight(int x) {
    return (DayLight = x);
}

static object array GetDummyItems() {
    DummyItems = filter(DummyItems, (: $1 :));
    return DummyItems;
}

varargs void AddItem(mixed item, mixed val, mixed adjectives) {
  object ob;
    
  if( objectp(item) ) {
    ob = item;
  } else {
//	  if (present(item, this_object())) return;  /* Do not allow double spawning */
	  if( stringp(item))       { item = ({ item }); }
	  if( stringp(adjectives)) { adjectives = ({ adjectives }); }
	  ob = new(LIB_DUMMY, item, val, adjectives);
  }
  ob->eventMove(this_object());
  DummyItems = ({ DummyItems..., ob });
}

void RemoveItem(mixed item) {
    if( objectp(item) ) {
	DummyItems -= ({ item });
	item->eventDestruct();
	return;
    }
    else if( !arrayp(item) ) {
	item = ({ item });
    }
    foreach(object ob in GetDummyItems()) {
	if( sizeof(ob->GetId() & item) ) {
	    ob->eventDestruct();
	    DummyItems -= ({ ob });
	    return;
	}
    }
}

void SetItems(mixed items) {
    DummyItems->eventDestruct();
    DummyItems = ({});
    if( arrayp(items) ) {
	items->eventMove(this_object());
	DummyItems = items;
    }
    else if( mapp(items) ) {
	foreach(mixed key, mixed val in items) {
	    string array adjs = ({});
	    object ob;
	    
	    if( stringp(key) ) {
		key = ({ key });
	    }
	    else {
		if( sizeof(key) == 2 && arrayp(key[0]) ) {
		    adjs = key[1];
		    key = key[0];
		}
	    }
	    ob = new(LIB_DUMMY, key, val, adjs);
	    ob->eventMove(this_object());
	    DummyItems = filter( ({ DummyItems..., ob }), (: $1 :) );
	}
    }
    else {
	error("Bad argument 1 to SetItems(), expected object array or "
	      "mapping.\n");
    }
}

varargs void AddListen(mixed item, mixed val) {
    if( !val ) {
	Listen = item;
	return;
    }
    if( !item || item == "default" ) {
	Listen = val;
	return;
    }
    if( stringp(item) ) {
	item = ({ item });
    }
    foreach(string tmp in item) {
	foreach(object ob in GetDummyItems()) {
	    if( ob->id(tmp) ) {
		ob->SetListen(val);
		break;
	    }
	}
    }
}

mixed GetListen() {
    return Listen;
}

varargs void RemoveListen(mixed item) {
    if( !item || item == "default" ) {
	Listen = 0;
	return;
    }
    foreach(object ob in GetDummyItems()) {
	if( stringp(item) ) {
	    if( ob->id(item) ) {
		ob->SetListen(0);
	    }
	}
	else if( arrayp(item) ) {
	    if( sizeof(ob->GetId() & item) ) {
		ob->SetListen(0);
	    }
	}
    }
}

varargs void SetListen(mixed items, mixed arg) {
    if( !mapp(items) ) {
	if( !arg ) {
	    AddListen("default", items);
	}
	else {
	    AddListen(items, arg);
	}
	return;
    }
    foreach(mixed key, mixed val in items) {
	AddListen(key, val);
    }
}

int GetMedium() {
    return MEDIUM_LAND;
}

int GetNightLight() {
    return NightLight;
}

int SetNightLight(int x) {
    return (NightLight = x);
}

int SetNoReplace(int x) { return (NoReplace = x); }

int GetNoReplace() { return NoReplace; }

int GetPlayerKill() {
    return PlayerKill;
}

int SetPlayerKill(int x) {
    return (PlayerKill = x);
}

int AddPoisonGas(int x) {
    PoisonGas += x;
    return PoisonGas;
}

int GetPoisonGas() {
    int x;

    if( PoisonGas < 1 ) {
	return 0;
    }
    x = time() - GasCheck;
    GasCheck = time();
    if( x > 0 && x < 4 ) {
	x = 1;
    }
    else {
	x = x/4;
    }
    PoisonGas -= x;
    if( PoisonGas < 0 ) {
	PoisonGas = 0;
    }
    return PoisonGas;
}

int SetPoisonGas(int x) {
    return (PoisonGas = x);
}

void AddRead(mixed item, mixed val) {
    if( stringp(item) ) {
	item = ({ item });
    }
    foreach(string tmp in item) {
	foreach(object ob in GetDummyItems()) {
	    if( ob->id(tmp) ) {
		ob->SetRead(val);
		break;
	    }
	}
    }
}

void RemoveRead(mixed item) {
    foreach(object ob in GetDummyItems()) {
	if( stringp(item) ) {
	    if( ob->id(item) ) {
		ob->SetRead(0);
	    }
	}
	else if( arrayp(item) ) {
	    if( sizeof(ob->GetId() & item) ) {
		ob->SetRead(0);
	    }
	}
    }
}

varargs void SetRead(mixed items, mixed arg) {
    if( !mapp(items) ) {
	AddRead(items, arg);
	return;
    }
    foreach(mixed key, mixed val in items) {
	AddRead(key, val);
    }
}

int GetShade() {
    return Shade;
}

static int SetShade(int x) {
    return (Shade = x);
}

varargs void AddSearch(mixed item, mixed val) {
    if( !val ) {
	Search = item;
	return;
    }
    if( !item || item == "default" ) {
	Search = val;
	return;
    }
    if( stringp(item) ) {
	item = ({ item });
    }
    foreach(string tmp in item) {
	foreach(object ob in GetDummyItems()) {
	    if( ob->id(tmp) ) {
		ob->SetSearch(val);
		break;
	    }
	}
    }
}

varargs mixed GetSearch(string str) {
    return Search;
}

varargs void RemoveSearch(mixed item) {
    if( !item || item == "default" ) {
	Search = 0;
	return;
    }
    foreach(object ob in GetDummyItems()) {
	if( stringp(item) ) {
	    if( ob->id(item) ) {
		ob->SetSearch(0);
	    }
	}
	else if( arrayp(item) ) {
	    if( sizeof(ob->GetId() & item) ) {
		ob->SetSearch(0);
	    }
	}
    }
}

varargs void SetSearch(mixed items, mixed arg) {
    if( !mapp(items) ) {
	if( !arg ) {
	    AddSearch("default", items);
	}
	else {
	    AddSearch(items, arg);
	}
	return;
    }
    foreach(mixed key, mixed val in items) {
	AddSearch(key, val);
    }
}

varargs void AddSmell(mixed item, mixed val) {
    if( !val ) {
	Smell = item;
	return;
    }
    if( !item || item == "default" ) {
	Smell = val;
	return;
    }
    if( stringp(item) ) {
	item = ({ item });
    }
    foreach(string tmp in item) {
	foreach(object ob in GetDummyItems()) {
	    if( ob->id(tmp) ) {
		ob->SetSmell(val);
		break;
	    }
	}
    }
}

varargs mixed GetSmell(string str) {
    return Smell;
}

varargs void RemoveSmell(mixed item) {
    if( !item || item == "default" ) {
	Smell = 0;
	return;
    }
    foreach(object ob in GetDummyItems()) {
	if( stringp(item) ) {
	    if( ob->id(item) ) {
		ob->SetSmell(0);
	    }
	}
	else if( arrayp(item) ) {
	    if( sizeof(ob->GetId() & item) ) {
		ob->SetSmell(0);
	    }
	}
    }
}

varargs void SetSmell(mixed items, mixed arg) {
    if( !mapp(items) ) {
	if( !arg ) {
	    AddSmell("default", items);
	}
	else {
	    AddSmell(items, arg);
	}
	return;
    }
    foreach(mixed key, mixed val in items) {
	AddSmell(key, val);
    }
}

varargs void AddTouch(mixed item, mixed val) {
    if( !val ) {
	Touch = item;
	return;
    }
    if( !item || item == "default" ) {
	Touch = val;
	return;
    }
    if( stringp(item) ) {
	item = ({ item });
    }
    foreach(string tmp in item) {
	foreach(object ob in GetDummyItems()) {
	    if( ob->id(tmp) ) {
		ob->SetTouch(val);
		break;
	    }
	}
    }
}

varargs void RemoveTouch(mixed item) {
    if( !item || item == "default" ) {
	Touch = 0;
	return;
    }
    foreach(object ob in GetDummyItems()) {
	if( stringp(item) ) {
	    if( ob->id(item) ) {
		ob->SetTouch(0);
	    }
	}
	else if( arrayp(item) ) {
	    if( sizeof(ob->GetId() & item) ) {
		ob->SetTouch(0);
	    }
	}
    }
}

varargs void SetTouch(mixed items, mixed arg) {
    if( !mapp(items) ) {
	if( !arg ) {
	    AddTouch("default", items);
	}
	else {
	    AddTouch(items, arg);
	}
	return;
    }
    foreach(mixed key, mixed val in items) {
	AddTouch(key, val);
    }
}

string GetTown() {
	string unusedString, bleh;
	string *tmp;
 
 if (Town) return Town; 
 if(sscanf(file_name(this_object()), "/std/%s/%s", Town,unusedString)) {
			Town = "Wilderness";
		  return Town;
		}
 if(sscanf(file_name(this_object()), "/realms/%s/%s", Town,unusedString)) {
			Town = "Wilderness";
		  return Town;
		}
 if(sscanf(file_name(this_object()), "/domains/%s/areas/%s/%s", unusedString,Town, bleh)) {
		  if (unusedString == "islands") Town = parse_area(Town, unusedString);
		    else Town = "Wilderness";
		  return Town;
		}
 
 if(!sscanf(file_name(this_object()), "/domains/%s/towns/%s/%s", unusedString,Town, bleh)) {
			Town = "Wilderness";
		  return Town;
		}
 tmp = explode(Town, "_");
 foreach(string word in tmp) { 
 	tmp -= ({ word }); 
 	tmp += ({ capitalize(word) });
 	}
 Town = implode(tmp, " ");
 	return (Town);
}

int GetLastReset() { return LastReset; }

string GetLastResetTime() { return ctime(LastReset); }

string SetTown(string town) { return (Town = town); }

/** this stuff is for backwards compat **/



string GetLong() {
    return GetInternalDesc();
}

string SetLong(string str) {
    return SetInternalDesc(str);
}
string AddLong(string str) {
  if (DayLong) DayLong += " " + str;
  if (NightLong) NightLong += " " + str;
  return SetLong(GetLong() + str);
}

string AddDayLong(string str) {
	return (SetDayLong(GetDayLong() + str));
}

string AddNightLong(string str) {
	return (SetNightLong(GetNightLong() + str));
}

int CanAttack( object attacker, object who ) {
    if( PlayerKill ) {
	return 1;
    }
    attacker->RemoveHostile( who );
    return 0; 
}

varargs int eventShow(object who, string args) {
    string str;

    if( !(str = (string)SEASONS_D->GetLong(args)) ) {
	who->eventPrint("You do not see that there.");
        return 1;
    } 
    who->eventPrint(str);
    eventPrint(who->GetName() + " looks at the " + args + ".", who);
}
    
/***********          /lib/room.c events          ***********/
mixed eventBuryItem(object who, object tool, object what) {
    if( !functionp(Bury) ) {
	return "You cannot bury things here!";
    }
    if( functionp(Bury) & FP_OWNER_DESTED ) {
	return "You cannot bury things here.";
    }
    return evaluate(Bury, who, tool, what);
}

varargs mixed eventHearTalk(object who, object target, int cls, string verb,
			    string msg, string lang) {
    object *obs;
    string exit, door;
    
    switch(cls) {
	case TALK_PRIVATE:
	return 1;

	case TALK_SEMI_PRIVATE:
	target->eventHearTalk(who, target, cls, verb, msg, lang);
	eventPrint("%^BOLD%^CYAN%^" + (string)who->GetName() +
		   " whispers something to " + (string)target->GetName() + ".",
		   MSG_CONV, ({ who, target }));
	return 1;

	case TALK_LOCAL:
	obs = filter(all_inventory(),
		     (: (int)$1->is_living() && $1 != $(who) :));
	obs->eventHearTalk(who, target, cls, verb, msg, lang);
	return 1;

	case TALK_AREA:
	foreach(exit in GetExits()) {
	    string tmp;

	    tmp = GetExit(exit);
	    if( !find_object(tmp) ) continue;
	    if( (door = GetDoor(exit)) && (int)door->GetClosed() ) continue;
	    tmp->eventHearTalk(who, target, TALK_LOCAL, verb, msg, lang);
	}
	foreach(exit in GetEnters()) {
	    string tmp;

	    tmp = GetEnter(exit);
	    if( !find_object(tmp) ) continue;
	    if( (door = GetDoor(exit)) && (int)door->GetClosed() ) continue;
	    tmp->eventHearTalk(who, target, TALK_LOCAL, verb, msg, lang);
	  }
	  obs = filter(all_inventory(), (: (int)$1->is_living() && $1 != $(who) :));
	  obs->eventHearTalk(who, target, cls, verb, msg, lang);
    return 1;
	
    }
}

int eventMove(mixed dest) { return 0; }

varargs int eventPrint(string msg, mixed arg2, mixed arg3) {
    object *targs;
    int msg_class;

    if( !arg2 && !arg3 ) {
	targs = filter(all_inventory(), (: (int)$1->is_living() :));
	msg_class = MSG_ENV;
    }
    else if( objectp(arg2) || arrayp(arg2) ) {
	if( objectp(arg2) ) arg2 = ({ arg2 });
	targs = (filter(all_inventory(), (: (int)$1->is_living() :)) - arg2);
	msg_class = MSG_ENV;
    }
    else if( !arg3 ) {
	targs = filter(all_inventory(), (: (int)$1->is_living() :));
	msg_class = arg2;
    }
    else if( objectp(arg3) || arrayp(arg3) ) {
	if( objectp(arg3) ) arg3 = ({ arg3 });
	targs = (filter(all_inventory(), (: (int)$1->is_living() :)) - arg3);
	msg_class = arg2;
    }
    targs->eventPrint(msg, msg_class);
    return 1;
}

static void create() {
    exits::create();
    set_heart_beat(30);
    reset(query_reset_number());
    if( replaceable(this_object()) && !GetNoReplace() ) {
	    string array tmp= inherit_list(this_object());
    	if( sizeof(tmp) == 1 ) {
	      replace_program(tmp[0]);
	      }
    }
   ESTATE_D->LoadRoom(base_name(this_object()));
}

varargs void reset(int count) {
    inventory::reset(count);
    all_inventory()->reset(count);
    ResetNumber++;
    LastReset = time();
}

void eventPurgeRoom() {
  object *stuff;
  stuff = all_inventory();
  if (sizeof(stuff) > 30) {
    foreach(object o in stuff) {
      if (o->isDummy()) continue;
      if (living(o)) continue;
      if (vehiclep(o)) continue;
      o->eventDestruct();
    }
  }
}

static void heart_beat() {
  object *stuff = filter(all_inventory(), (: living :) );
  object local;
  string tmp;
  if (sizeof(stuff) & !(time() % 5)) {
      if (GetClimate() != "underground" && GetClimate() != "indoors" &&  !GetProperty("no weather")) if (WEATHER_D->GetRaining(GetDomain(), GetClimate()) == 10) {
           eventPrint(capitalize(WEATHER_D->GetPrecipitationType(GetRoomWarmth()) ) + " continues to fall from the sky.");
           stuff->eventCheckCold();
      }
      stuff = filter(stuff, (: $1->GetInCombat() :) );
       if (sizeof(stuff)) {
          foreach(string area in GetExits()) {
             if (local = find_object(GetExit(area))) {
                 tmp = local->GetDirection(base_name(this_object()));
                 if (!tmp) tmp = "fucked a distance";
                 sscanf(tmp, "%s %s", area, tmp);
                   /* area used as a useless string var */
                 if(tmp == "up") {
                 local->eventPrint("The sounds of battle come from above.");
                   }
                 if (tmp == "down") {
                 local->eventPrint("The sounds of battle come from below.");
                   } 
                 if (tmp == "out") {
                 local->eventPrint("The sounds of battle come from outside.");
                   }
                 if(tmp != "out" && tmp != "up" && tmp != "down") {
                   local->eventPrint("The sounds of battle come from the " + tmp + ".");
                   }
                 }
          }
          foreach(string area in GetEnters()) {
             if (local = find_object(GetEnter(area))) {
                 tmp = local->GetDirection(base_name(this_object()));
                  sscanf(tmp, "%s %s", area, tmp);
                   /* area used as a useless string var */
                 if (tmp == "out") {
                    local->eventPrint("The sounds of battle come from outside.");
                 } else 
                 local->eventPrint("The sounds of battle come from the " + tmp + ".");
                 }
              }
          }
        }
  stuff = all_inventory();
  if (sizeof(stuff) > 30) call_out( (: eventPurgeRoom :), 120);
  
  if (GetProperty("ocean") || GetProperty("shallows"))
  foreach(object thing in stuff) {
   if (!thing) continue;
    if (living(thing)) continue;
    if (vehiclep(thing)) continue;
    if (thing->GetInvis()) continue;
    eventPrint(capitalize(thing->GetShort()) + " sinks into the depths.");
    thing->eventDestruct();
    }
}

int id(string str) {
    return 0;
}

int inventory_accessible() {
    return 1;
}

int inventory_visible() {
    return 1;
}

static void init() {
    if (sizeof(Newsgroups) && !present("newsboard", this_object())) {
	    object board = new(OBJ_NEWSBOARD);
	    board->eventMove(this_object());
    }
}

mapping SetItemAdjectives(mapping mp) { 
	foreach(string thing in keys(mp)) {
      if (!present(thing)) continue;
		  present(thing)->SetAdjectives(mp[thing]);
		}
	return mp;
}

void AddItemAdjectives(string thing, string *adj) {
  if (!present(thing)) return;
  present(thing)->SetAdjectives(adj);
}