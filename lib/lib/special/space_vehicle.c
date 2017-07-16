/*  Starship Version 0.2a
 *  Attempting to clean the code
 *  And make it 100% functional
 *
 *  Duuk
 * 19 November 2001
 * Conversion to sailing ship.
 *  4 July 2004
 */
#include <lib.h>
#include <vehicle.h>
#include <std.h>
#include <daemons.h>
#include <save.h>
#include <message_class.h>
#include <damage_types.h>
#include <size.h>
#include <rooms.h>
#include "include/vehicle.h"
#include <talk_type.h>
#define SPACE "/domains/space/virtual/"
inherit LIB_STORAGE;
inherit LIB_MESSAGES;
inherit LIB_EXITS;

string VehicleName = "";
string CurrentLocation = "";
string BridgeDescription = "";
string Owner = "", Captain = "";
string ShipStyle = "human";
int SensorSuite = 0;
int DriveSystem = 0;
int VehicleSize = 0;
int WeaponSystem = 0;
int ShieldSystem = 0;
int Crystals = 0;
int hasMoved = 0, hasAttacked = 0;
string *DamagedSystems = ({});
string *VId, VLong, VShort;
object *ShipEnemies;
string *Crew;

static void create() {
	storage::create();
	messages::create();
	exits::create();
	AddSave( ({ "SensorSuite", "DriveSystem", "VehicleSize", "Owner", 
	            "Captain", "BridgeDescription", "WeaponSystem", 
	            "DamagedSystems", "CurrentLocation", "VehicleName", 
	            "ShipStyle", "Crystals", "ShieldSystem", 
	            "VId", "VLong", "VShort", "Crew", }) );
	hasMoved = hasAttacked = 0;
	Owner = Captain = 0;
	VehicleName = "";
	CurrentLocation = "";
	BridgeDescription = "The bridge of the ship is clean and "
	                    "sparkles with newness.";
	WeaponSystem = 0;
	SensorSuite = 0;
	ShieldSystem = 0;
	DriveSystem = 0;
	Crystals = 0;
	DamagedSystems = ({});
	VehicleSize = VS_YACHT;
	ShipEnemies = ({ });
  set_heart_beat(1);
  SetProperty("PROP_VEHICLE", 1);
  SetProperty("login", ROOM_DEATH);
  SetMessages( ([
    "come"   : "$N enters.",
    "leave"  : "$N leaves $D.",
    "telout" : "$N goes into nowhere.",
    "telin"  : "$N comes out of nowhere.",
    ]) );
  new(STD_OBJ "screen")->eventMove(this_object());
  SetPreventGet("");
  call_out( (: LoadVehicle :), 1);
}

/* Save and Load Functions */


void SaveVehicle() {
	string name = VehicleName;
	if (!clonep()) return;
	if (Owner == "" || VehicleName == "" || Owner == 0 || VehicleName == 0) return;
	if (file_size(SAVE_VEHICLES + "/" + Owner + "/" ) != -2) {
		mkdir(SAVE_VEHICLES + "/" + Owner + "/" );
	}
	name = lower_case(name);
	name = replace_string(name, " ", "_");
	if (file_size(SAVE_VEHICLES + "/" + Owner + "/" + name[0..0] + "/") != -2) {
		mkdir(SAVE_VEHICLES + "/" + Owner + "/" + name[0..0] );
	}
	save_object(SAVE_VEHICLES + "/" + Owner + "/" + name[0..0] + "/" + name);
}

void LoadVehicle() {
   string name = VehicleName;
   if (Owner == "" || VehicleName == "") { return; }
 	name = lower_case(name);
	name = replace_string(name, " ", "_");
   if (!file_exists(SAVE_VEHICLES + "/" + Owner + 
          "/" + name[0..0] + "/" + name + ".o") ) {
          	return; }
   restore_object(SAVE_VEHICLES + "/" + Owner + "/" + name[0..0] + "/" + name + ".o");
   if (VLong)  SetLong(VLong);
   if (VShort) SetShort(VShort);
   SetKeyName(VehicleName);
   if (VId)    SetId(VId);
   parse_refresh();
}

void DeleteVehicle() {
   string name = VehicleName;
   if (Owner == "" || VehicleName == "") { return; }
	name = lower_case(name);
	name = replace_string(name, " ", "_");
   if (!file_exists(SAVE_VEHICLES + "/" + Owner + 
          "/" + name[0..0] + "/" + name + ".o") ) {
          	return; }
   rm(SAVE_VEHICLES + "/" + Owner + "/" + name[0..0] + "/" + name + ".o");
   SetVehicleName("");
}

void RestoreVehicle(string file) {
	restore_object(file);
	
	parse_refresh();
}

/* End Save and Load Functions */

/* Driver Functions */

void heart_beat() {
	if (hasMoved || hasAttacked) 
         all_inventory()->eventPrint("The ship's computer chirps happily.");
	hasMoved = hasAttacked = 0;
	SaveVehicle();
}

mixed direct_board_obj() {
	return 1;
}

mixed direct_scan_str() {
  return 1;
}

mixed direct_repair_obj() {
	if (GetDamagePoints() == GetMaxDamagePoints()) 
	  return "But the ship is not damaged!";
	return 1;
}

void init() {
	storage::init();
	if (environment(this_player()) == environment(this_object())) {
		if (GetSensorSuite() && !GetDamagedSystem("navigation") && !(this_player()->GetInvis())) {
			eventPrint("Bing! Something has moved in range of the ship!.");
		}
	}
}

mixed direct_launch_attack_on_str() { return 1; }

int is_living() { return 1; }

/* End Driver Functions */

/* event Functions */


int eventMove(mixed dest) {
	int tmp;
	tmp = storage::eventMove(dest);
	ResetExit();
	return tmp;
}

// args d and l not used  -- From /lib/items/deterioration.c
varargs int eventReceiveDamage(object agent, int type, int amt, int d, mixed array l) {
    object *crew = all_inventory();
    object ePilot, *eCrew;
    int reward;
    int critical = random(100000);
    crew = filter(crew, (: living :) );
    if (agent && sizeof(crew)) {
      crew->eventPrint("%^YELLOW%^The ship is under attack!%^RESET%^");
      foreach(object person in crew) {
        if (person->GetSleeping()) {
          person->SetSleeping(0);
          person->eventPrint("You wake up!");
        }
      }
    }
    if (GetShieldSystem() && !GetDamagedSystem("shield")) {
    	crew->eventPrint("The shields deflect some damage.");
      amt -= (GetShieldSystem() * 7500);
      if (!random(20)) {
      	crew->eventPrint("%^BOLD%^RED%^The shields collapse!%^RESET%^");
      	if (agent) {
      	  agent->eventPrint("%^RED%^" + capitalize(GetShort()) + "'s shields have collapsed!%^RESET%^");
      	}
      	AddDamagedSystem("shield");
      	}
      }
    if (amt <= 0) return 1;
    AddDamagePoints(-amt);
    crew->eventPrint("%^YELLOW%^The ship has suffered damage!%^RESET%^");
    if (critical < (amt)) {
    	switch(random(4)) {
    		case 0:
    		  if (!DriveSystem || GetDamagedSystem("engines")) break;
    		  crew->eventPrint("%^RED%^The engines have been damaged!%^RESET%^");
    		  if (agent) {
    		    agent->eventPrint("%^RED%^An explosion on " + GetShort() + " shows that her engines have been hit!%^RESET%^");
    		  }
    		  AddDamagedSystem("engines");
    		  break;
    		case 1:
    		  if (!SensorSuite || GetDamagedSystem("navigation")) break;
    		  crew->eventPrint("%^RED%^The sensor suite has been damaged!%^RESET%^");
    		  if (agent) {
    		    agent->eventPrint("%^RED%^Silence on communications channels announces that " + GetShort() + "'s "
    		                      "navigation and sensors are damaged!%^RESET%^");
    		    }
    		  AddDamagedSystem("navigation");
    		  break;
    		case 2:
    		  if (!WeaponSystem || GetDamagedSystem("weapon")) break;
    		  crew->eventPrint("%^RED%^The weapons have been damaged!%^RESET%^");
    		  if (agent) {
    		    agent->eventPrint("%^RED%^With a roar, the weapon system on " + GetShort() + " is disabled!%^RESET%^");
    		  }
    		  AddDamagedSystem("weapon");
    		  break;
    		case 3:
    		  if (!ShieldSystem  || GetDamagedSystem("shield")) break;
    		  crew->eventPrint("%^RED%^The shield generator is damaged!%^RESET%^");
    		  if (agent) {
      	    agent->eventPrint("%^RED%^" + capitalize(GetShort()) + "'s shields have collapsed!%^RESET%^");
      	  }
    		  AddDamagedSystem("shield");
    		  break;
    		}
    		
    	}
    if( GetDamagePoints() < 1 ) {
      crew->eventPrint("%^BOLD%^RED%^The ship has been DESTROYED!%^RESET%^");
      ShipEnemies->eventEnemyDied(this_object());
      CHAT_D->eventSendChannel("Ship Died", "shipreports",
        capitalize(GetName()) + " has been destroyed.");
      if (environment()) {
       crew->eventMove(environment());
      } else {
      	crew->eventDie(agent);
      }
      set_heart_beat(0);
      DeleteVehicle();
      environment()->eventPrint(capitalize(GetShort()) + " explodes violently.");
      if (agent)
      if (userp(ePilot = agent->GetPilot())) {
      	reward = GetVehicleSize();
      	eCrew  = agent->GetCrewMembers();
        eCrew->eventPrint(
          "Sacking " + GetShort() + " yields " + (reward = random(GetVehicleSize() * 1000) * 2) + " imperials worth of loot!");
        eCrew->eventPrint("Your share is divided by a total of " + sizeof(eCrew) + " crew members.");
        foreach(object c in eCrew) {
         c->AddCurrency("imperials", reward/sizeof(eCrew));
        }
        if (random(1000) < GetVehicleSize()) {
        	eCrew->eventPrint("You have been rewarded with 1 development point!");
        	eCrew->AddDevelopmentPoints(1);
        	foreach(object woot in eCrew) {
        	  CHAT_D->eventSendChannel("Reward", "reports", capitalize(woot->GetKeyName()) + " got 1 dp for sinking " + GetShort());
          }
        }
      } 
    eventDestruct();
      return 1;
    }
    return GetDamagePoints();
}

varargs mixed eventHearTalk(object who, object target, int cls, string verb,
                            string msg, string lang) {
    object *obs;
    string exit, door;
    
    
    switch(cls) {
        case TALK_PRIVATE:
        return 1;

        case TALK_SEMI_PRIVATE:
        if (environment(who) != this_object() ) {
         return 1;
        }
        target->eventHearTalk(who, target, cls, verb, msg, lang);
        eventPrint("%^BOLD%^CYAN%^" + (string)who->GetName() +
                   " whispers something to " + (string)target->GetName() + ".",
                   MSG_CONV, ({ who, target }));
        return 1;

        case TALK_LOCAL:
        if (environment(who) != this_object() ) {
         return 1;
        }
        obs = filter(all_inventory(),
                     (: (int)$1->is_living() && $1 != $(who) :));
        obs->eventHearTalk(who, target, cls, verb, msg, lang);
        return 1;

        case TALK_AREA:
        if (environment(who) == this_object())
        foreach(exit in GetExits()) {
            string tmp;

            tmp = GetExit(exit);
            if( !find_object(tmp) ) continue;
            if( (door = GetDoor(exit)) && (int)door->GetClosed() ) continue;
            tmp->eventHearTalk(who, target, TALK_LOCAL, verb, msg, lang);
        }
        if (environment(who) == this_object())
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

varargs int eventMoveLiving(mixed dest, string outmessage, string inmessage) {
	string prev;
	string msg;
	if (environment()) {
		prev = file_name(environment());
	  if (!outmessage) { environment()->eventPrint(GetMessage("telout"), MSG_ENV, this_object());
	    } else { environment()->eventPrint(GetMessage("leave", outmessage), MSG_ENV, this_object());
	    }
	  }
	load_object(dest);
	eventMove(dest);
  foreach(object liv in all_inventory()) {
    if (living(liv)) liv->eventDescribeEnvironment(liv->GetBriefMode());
    }
	SetCurrentLocation(file_name(environment()));
	foreach(string ex in dest->GetExits()) {
		load_object(dest->GetExit(ex));
	}
	foreach(string ex in dest->GetEnters()) {
		load_object(dest->GetEnter(ex));
	}
	hasMoved = 1;
	if (!(environment()->GetDirection(prev)) && !inmessage) { 
		  msg = GetMessage("telin");
	  } else  
	  	if (inmessage) { msg = replace_string(inmessage, "$N", GetName());
	  } else { msg = GetMessage("come"); }
	  environment()->eventPrint(msg, MSG_ENV, this_object());
	foreach(object ship in all_inventory(environment())) {
	  if (ship == this_object()) continue;
	  if (!vehiclep(ship)) continue;
	  ship->eventEncounterShip(this_object());
	  }
}

/* This function won't do much except in concert with an AI ship captain. */

void eventEncounterShip(object ship) {
  object p = GetPilot();
  if (p) p->eventEncounterShip(ship);
}

int eventScuttle(object who) {
  if (userp(who)) CHAT_D->eventSendChannel("", "shipreports", capitalize(who->GetKeyName()) + " has scuttled " + GetName() + "!", 1);
  eventPrint(capitalize(who->GetKeyName()) + " has ordered the ship be scuttled!");
  environment()->eventPrint(capitalize(GetName()) + " explodes as the captain scuttles her.");
  eventDestruct();
  return 1;
}

int eventPirate(object who) {
  string name = who->GetKeyName();
  if (userp(who)) CHAT_D->eventSendChannel("", "shipreports", capitalize(name) + " has successfully pirated " +
                                           GetName() + "!", 1);
  eventPrint(capitalize(name) + " has seized control of the ship!");
  SetCaptain(name);
	if (GetOwner() != "") {
    rm(SAVE_VEHICLES + "/" + Owner + "/" + VehicleName[0..0] + "/" + VehicleName + ".o");
    SetOwner(who->GetKeyName());  
    }
	return GetCaptain() == who->GetKeyName();
}                                             

varargs int eventLaunchWeapons(object who, object target, string weapon) {
	int success, amount, con;
	object ePilot;
	ePilot = target->GetPilot();
	con = (ePilot ? ePilot->GetSkillLevel("piloting") : 0);
	success = who->eventCheckSkill("piloting", con, 0, 0);
	target->eventPrint("You are under fire from " + GetName() + "!");
	// debug(success);
	if (success > 0) {
	  amount = GetWeaponSystem() * 10000;
	  target->eventPrint("%^RED%^The ship has been hit!%^RESET%^");
	  target->eventReceiveDamage(this_object(), BLUNT, amount);
	  who->eventTrainSkill("piloting", success, con, 1, GetWeaponSystem());
	  eventPrint("%^GREEN%^The enemy ship has been hit!%^RESET%^");
	  message("system", capitalize(GetShort()) + "'s attack hits!", environment(), ({ this_object(), target }) );
    if (!target) eventPrint("%^GREEN%^The enemy ship has been %^RED%^BOLD%^destroyed!%^RESET%^");
	 } else {
	  eventPrint("%^GREEN%^The attack has missed!%^RESET%^");
	  target->eventPrint("The enemy attack has missed.");
	  message("system", capitalize(GetShort()) + "'s attack misses!",  environment(), ({ this_object(), target }) );
    
	  who->eventTrainSkill("piloting", 0, con, 0, GetWeaponSystem());
	}
	if (target) {
	  target->AddShipEnemy(this_object());
	  AddShipEnemy(target);
	  }
	hasAttacked = 1;
}

int eventHyperjump(object who, string sx) {
	int distance;
	string str;
	string cSys;
	int success = 0;
	if (!environment()) {
	  who->eventPrint("Whew.  Something bad happened!");
	  return 1;
	}
	if ((cSys = (string)environment()->GetDomain()) != "Space") {
		who->eventPrint("You can only jump from space!");
		return 1;
	}
	cSys = environment()->GetSystem();
	str = capitalize(sx);
	distance = SYSTEMS_D->GetDistance(cSys, sx);
	success = who->eventCheckSkill("piloting", distance * 20, 0, 30);
  if (who->GetTestChar()) debug("Success: " + success + " @dist " + distance);
	if (success > 100) success = 100;
	if (success < -300) {
    	switch(random(4)) {
    		case 0:
    		  eventPrint(who->GetCapName() + " hits some space debris.");
    		  eventReceiveDamage(0, BLUNT, absolute_value(success));
    		  break;
    		case 1:
    		  who->eventPrint("The ship fails to respond to your commands.");
    		  eventPrint("The ship doesn't move.");
    		  return 1;
    		  break;
    		case 2:
    		  who->eventPrint("You somehow manage to overload the engines!");
    		  eventPrint("%^RED%^BOLD%^The engines become overloaded.%^RESET%^");
    		  AddDamagedSystem("engines");
    		  break;
    		case 3:
    		  who->eventPrint("The ship comes out of hyperspace near an asteroid!");
    		  who->eventPrint("You attempt to maneuver clear!");
    		  eventReceiveDamage(0, BLUNT, absolute_value(success) * 100);
    		  break;
    		}
    	}
	eventPrint("%^BOLD%^YELLOW%^The ships makes a noticable *POP* sound as it jumps to hyperspace.%^RESET%^");
	eventMoveLiving(SYSTEMS_D->GetWarpZone(sx));
	AddCrystals(-15);
	hasMoved = 1;
	return 1;
}

int eventScan(object who, string what) {
  object env = environment();
  object target;
  string size;
  
  if (!what) {
    who->eventPrint("Scan what?");
    return 1;
  }
  target = present(what, env);
  if (!target) {
    who->eventPrint("Can't find " + what + " here.");
    return 1;
  }
  if (what == "space") {
    if (who->eventCheckSkill("navigation", 10, 10, 5) < 0) {
      send_messages( ({ "attempt", "fail" }), "$agent_name $agent_verb to scan surrounding space "
                                              "but fails miserably.", who, 0, this_object());
      return 1;
    }
    who->eventPrint("You determine that you are in the " + environment()->GetSystem() + " system.");
    who->eventPrint("Sensors find " + PLANETS_D->SystemScan(environment()->GetSystem()) + " in this system.");
    return 1;
  }                                              
  if (who->eventCheckSkill("navigation", 10, 10, 5) < 0) {
    send_messages(({ "attempt", "fail" }), "$agent_name $agent_verb to scan " +
                  target->GetShort() + ", but $agent_verb miserably.", who, 0, this_object());
    return 1;
  }
  if (!vehiclep(target)) {
    who->eventPrint("Sensors reveal that to be " + capitalize(target->GetKeyName()) + ".");
    return 1;
  }
  switch(target->GetVehicleSize()) {
    case VS_YACHT:
      size = "shuttle";
      break;
    case VS_GALLEY:
      size = "raider";
      break;
    case VS_CRUISER:
      size = "cruiser";
      break;
    case VS_DREADNAUGHT:
      size = "dreadnaught";
      break;
    default:
      size = "ship";
      break;
    }
  who->eventPrint("A quick scan of the target reveals...\n"
                  "The " + size + " " + target->GetVehicleName() + " has hull integrity of " + 
                  (target->GetDamagePoints()) * 100 / target->GetMaxDamagePoints() + "%.\n"  +
                  	  target->GetDriveStatus()  + "\n" +
	                    target->GetWeaponStatus() + "\n" +
	                    target->GetShieldStatus() + "\n" +
	                    target->GetSensorStatus() + "\n" 
	               );                  
  return 1;
}

int eventNavigate(object who, string what) {
	object env = environment();
	int x, y, z, *f;
	int success;
	int distance = 0;
	mixed *Sys;
	object *ob;
	string xPos = "", yPos = "", str = "", zPos = "", bleh;
	string *nav = ({ });
	
	if (!SensorSuite) {
		who->eventPrint("The ship has neither navigation or communications equipment.");
		return 1;
	}
	if (!env) {
		who->eventPrint("This would be the least of your worries.");
	  return 1;
	}
	if (sscanf(base_name(env), "/systems/%s/virtual/space/%d,%d,%d", str, x, y, z) != 4) {
		who->eventPrint("You are unable to see enough stars from here.");
		return 1;
	}
	if (SensorSuite < VSE_WIDE) {
  	who->eventPrint("We have no navigation equipment.");
  	return 1;
  }
  Sys = PLANETS_D->GetPlanetGrid(what);
  if (!sizeof(Sys)) debug("Bad what of " + what);
  bleh = Sys[0]; f = Sys[1];
  distance += absolute_value(x - f[0]);
  distance += absolute_value(y - f[1]);
  distance += absolute_value(z - f[2]);
  distance = distance/50;
  if (environment()->GetSystem() != capitalize(bleh)) {
    who->eventPrint("We're not even in the right system!");
    who->eventPrint("Use <scan space> to determine which system you're in!");
    return 1;
  }
  if (who->GetTestChar()) debug("distance/50 from " + what + " = " + distance);
  success = who->eventCheckSkill("navigation", distance, 0, distance * 10);
  if (success < 1) {
  	who->eventPrint("You fail to determine the ship's location.");
  	return 1;
  }
  if (success >= 1 && success <= 40) {
  	switch(random(3)) {
  		case 0:
  		  x += (random(distance) - success);
  		  break;
  		case 1:
  		  y += (random(distance) - success);
  		  break;
  		case 2:
  		  z += (random(distance) - success);
  		  break;
  		default:
  		  x += (random(distance) - success); 
  		  y += (random(distance) - success);
  		  z += (random(distance) - success);   
  		  break;
  		}
    }
  x -= f[0]; y -= f[1]; z -= f[2];
  if (x > 0) xPos = "east"; else xPos = "west";
  if (y > 0) yPos = "north"; else yPos = "south";
  if (z > 0) zPos = "above"; else zPos = "below";
  str = "Our best guess for spacial location is ";
  if (x == 0 && y == 0 && z == 0) str += "in orbit around";
  if (x != 0) nav += ({ cardinal(absolute_value(x)) + " " + xPos });
  if (y != 0) nav += ({ cardinal(absolute_value(y)) + " " + yPos });
  if (z != 0) nav += ({ cardinal(absolute_value(z)) + " " + zPos });
  who->eventPrint(str + conjunction(nav, "and") + " " + capitalize(what) + ".");
  return 1;
}

int eventHail(object who, string trg, string msg) {
	object target = present(trg, environment());
	int success;
	if (!target) {
		who->eventPrint("Your target has left the area.");
		return 1;
	}
	if (!(target->GetSensorSuite())) {
		who->eventPrint("That ship doesn't seem to have any communications equipment.");
		return 1;
	}
	success = who->eventCheckSkill("navigation", 25, 25);
	if (success >= 1) {
		who->eventPrint("You signal your message.");
		target->eventPrint(GetShort() + " hails , \"" + translate(msg, success, "viking") + "\"");
		return 1; 
		}
  who->eventPrint("You failed to hail " + target->GetName() + ".");
  return 1;
}
  
int eventEnemyDied(object enemy) {
  RemoveShipEnemy(enemy);
  return sizeof(GetShipEnemies());
}
	
/* End event Functions */

/* Data Manipulation Functions */

int SetCrystals(int x) { return Crystals = x; }
int AddCrystals(int x) { 
	if ((Crystals + x) < 0) return Crystals = 0;
	return Crystals += x; 
}
int GetCrystals() { return Crystals; }

int SetShipStores(int x) { return Crystals = x; }
int AddShipStores(int x) { return AddCrystals(x); }
int GetShipStores() { return Crystals; }

string SetShipStyle(string x) { return ShipStyle = x; }
string GetShipStyle() { return ShipStyle; }

int GetAmbientLight() { return environment()->GetAmbientLight(); }

string SetCurrentLocation(string x) { return CurrentLocation = x; }
string GetCurrentLocation() { return CurrentLocation; }

string SetVehicleName(string x) {
	VehicleName = x;
	SetId(GetId() + ({ x }) );
	return VehicleName;
}

string GetVehicleName() { return VehicleName; }

string SetOwner(string x) {
	if (Owner != "") {
    rm(SAVE_VEHICLES + "/" + Owner + "/" + VehicleName[0..0] + "/" + VehicleName + ".o");
    }
	Owner = x;
	return Owner;
}
string GetOwner() { return Owner; }

string SetCaptain(string x) {
	return Captain = x;
}
string GetCaptain() { return Captain; }

int SetVehicleSize(int x) { return VehicleSize = x; }
int GetVehicleSize() { return VehicleSize; }

int SetSensorSuite(int x) { return SensorSuite = x; }
int GetSensorSuite() { return SensorSuite; }

string *SetCrew(string *str) {
	Crew = str;
   foreach(string x in Crew) {
  	Crew -= ({ x });
  	Crew += ({ lower_case(x) });
  } 
  return Crew = distinct_array(Crew);
}

string *GetCrew() {
	if (!Crew) return ({ });
  Crew -= ({ GetCaptain() }); 
  Crew -= ({ GetOwner() });
  return Crew;
}

object *GetCrewMembers() {
	object *tmp = ({ });
	object ob;
	foreach(string crewmember in GetCrew()) {
		if (ob = present(crewmember, this_object())) tmp += ({ ob });
		}
  if (GetCaptain())
  if (ob = present(GetCaptain(), this_object())) tmp += ({ ob });
  if (GetOwner())
  if (ob = present(GetOwner(), this_object())) tmp += ({ ob });
  return tmp;
}

int SetDriveSystem(int x) { return DriveSystem = x; }
int GetDriveSystem() { return DriveSystem; }

int SetWeaponSystem(int x) { return WeaponSystem = x; }
int GetWeaponSystem() { return WeaponSystem; }

int SetShieldSystem(int x) { return ShieldSystem = x; }
int GetShieldSystem() { return ShieldSystem; }

int GetHasAttacked() { return hasAttacked; }
int GetHasMoved() { return hasMoved; }

string SetBridgeDescription(string x) { return BridgeDescription = x; }
string GetBridgeDescription() { return BridgeDescription; }

string *SetDamagedSystems(string *system) {
	if (!arrayp(system)) system = ({ system });
	DamagedSystems = distinct_array(system);
	return DamagedSystems;
}

string *AddDamagedSystem(string system) {
	if (member_array(system, DamagedSystems) == -1)
	CHAT_D->eventSendChannel("Ship Damage", "shipreports", GetName() + " has been " +
	                    "critically hit in the " + system + ".");
	return DamagedSystems = distinct_array(DamagedSystems + ({ system }));
}

string *RemoveDamagedSystem(string system) {
	return DamagedSystems -= ({ system });
}

string *GetDamagedSystems() { return DamagedSystems; }

int GetDamagedSystem(string system) {
	if (member_array(system, DamagedSystems) != -1) return 1;
	return 0;
}

string GetClimate() { return "indoors"; }

string GetLong() {
	string tmp;
	if (present(this_player(), this_object())) {
		tmp = BridgeDescription;
		foreach(object thing in all_inventory()) {
			if (thing->GetAffectLong()) tmp += (" " + thing->GetAffectLong());
			}
		return tmp;
	}
	return storage::GetLong();
}

string GetItemCondition() {
	float x;
	x = (100.0 * GetDamagePoints()) / GetMaxDamagePoints();

  if (x > 95.0) { return "\nThe vessel shines like new."; }
  if (x > 80.0) { return "\nThe vessel has some minor damage."; }
  if (x > 60.0) { return "\nThe vessel is showing some obvious damage."; }
  if (x > 40.0) { return "\nThe vessel is seriously damaged."; }
  if (x > 20.0) { return "\nThe vessel appears to be nearly destroyed."; }
  return "\nThe vessel could be destroyed at any time."; 
}

string GetSensorStatus() {
	string tmp;
	switch (SensorSuite) {
		case 0:
		  tmp = "The ship has no navigation or communication equipment.";
		  break;
		case VSE_LOCAL:
		  tmp = "The ship has hailing equipment.";
		  break;
		case VSE_WIDE:
		  tmp = "The ship has communications equipment and navigation devices.";
		  break;
		}
	if (GetDamagedSystem("navigation")) 
	  tmp += " %^BOLD%^RED%^The navigation and communication "
	         "equipment is damaged.%^RESET%^";
  return tmp;
}

string GetDriveStatus() {
	string tmp;
	switch (DriveSystem) {
		case 0:
                  tmp = "This ship has no means of movement.";
		  break;
		case VM_COASTAL:
                  tmp = "The ship is capable of standard movement only.";
		  break;
		case VM_DEEP:
                  tmp = "The ship is capable of hyperspace movement.";
		  break;  
		}
	if (GetDamagedSystem("engines")) 
	  tmp += " %^BOLD%^RED%^The engines are damaged.%^RESET%^";
  return tmp;
}

string GetWeaponStatus() {
	string tmp;
	switch (WeaponSystem) {
		case 0:
		  tmp = "The ship has no weapons.";
		  break;
		case VW_SMALL:
                  tmp = "The ship has some minor weapons.";
		  break;
		case VW_MEDIUM:
                  tmp = "The ship has a normal weapons compliment.";
		  break;
		case VW_HUGE:
		  tmp = "The ship has a formidable weapons system.";
		  break;
		case VW_DEVASTATING:
		  tmp = "The ship is outfitted as a complete Ship of War.";
		  break;
		}
        if (GetHasAttacked()) tmp += " The weapons are being reloaded.";
	if (GetDamagedSystem("weapon")) 
	  tmp += " %^BOLD%^RED%^ The weapons are damaged.%^RESET%^";
  return tmp;
}

string GetShieldStatus() {
	string tmp;
	switch (ShieldSystem) {
		case 0:
		  tmp = "The ship has no shields.";
		  break;
		case VSH_SMALL:
		  tmp = "The ship has small shields.";
		  break;
		case VSH_MEDIUM:
		  tmp = "The ship has medium shields.";
		  break;
		case VSH_LARGE:
		  tmp = "The ship has large shields.";
		  break;
		}
		if (GetDamagedSystem("shield")) 
	    tmp += " %^BOLD%^RED%^ The shields are disrupted.%^RESET%^";
  return tmp;
}

string GetName() { return (GetVehicleName() != "" ? GetVehicleName() : GetShort()); }

string GetRepairSkill(string system) {
	if (!system) return "engineering";
	switch (system) {
		case "engines"  : return "engineering";
		case "navigation" : return "navigation";
		case "weapon" : return "engineering";
		case "shield" : return "engineering";
	}
	return "piloting";
}

string SetVLong(string x) { return VLong = x; }
string SetVShort(string x) { return VShort = x; }
string *SetVId(string *x) { return VId = x; }

string GetVLong() { return VLong; }
string GetVShort() { return VShort; }
string *GetVId() { return VId; }

object *GetShipEnemies() {
  if (!ShipEnemies) return ({ });
  ShipEnemies = filter(ShipEnemies, (: $1 :) );
  return ShipEnemies;
}
object *AddShipEnemy(object e) { return ShipEnemies = distinct_array(GetShipEnemies() + ({ e })); }
object *RemoveShipEnemy(object e) { return ShipEnemies = distinct_array(GetShipEnemies() - ({ e })); }

object GetPilot() {
  object p, o;
//  debug(GetCaptain() + " " + GetOwner());
  if (GetCaptain())
    p = present(GetCaptain(), this_object());
  if (GetOwner())
    o = present(GetOwner(), this_object());
  if (p) if (!living(p)) p = 0; if (o) if (!living(o)) o = 0;
  if (p) return p;
  return o;
}

string GetDomain() {
  if (!environment()) return "Southern Coast";
  return environment()->GetDomain();
}

/* Modal Functions */

void ResetExit() {
	AddExit("out", base_name(environment()));
}

mixed CanScuttle(object who) {
  if (GetOwner() && who->GetKeyName() != GetOwner()) {
    return "Don't you think the owner might be mad about that?";
  }
  if (!GetOwner() && who->GetKeyName() != GetCaptain()) {
    return "Only the Captain can order the ship destroyed!";
  }
  return 1;
}

mixed CanPirate(object who) {
  string name = who->GetKeyName();
  object tmp;
  if (name == GetOwner() || name == GetCaptain()) {
    return "Isn't it silly to pirate a ship you're allowed to sail anyway?";
  }
  if (GetOwner() && GetVehicleName() && strsrch(base_name(environment()), SPACE) == -1) {
    if (user_exists(GetOwner())) return "You can't seem to sail away with this ship!";
    }
  if (GetOwner()) {
    if (tmp = present(GetOwner(), this_object())) {
      if (living(tmp))
        return "The owner isn't too keen on that idea.";
      }
    }
  if (GetCaptain()) {
    if (tmp = present(GetCaptain(), this_object())) {
      if (living(tmp))
        return "The captain isn't too keen on that idea.";
      }
    }
  return 1;
}

int CanSell(object who) {
  if (who->GetKeyName() == GetOwner()) return 1;
  if (who->GetKeyName() == GetCaptain()) return 1;
  return 0;
}

mixed CanPilot(object who, mixed dest) {
	if (member_array(who->GetKeyName(), ({ GetCaptain(), GetOwner() })) 
       == -1) return "You are neither Captain nor Owner of this vessel.";
  if (!GetVehicleName()) return "The ship cannot leave port until it has a name.";
  if (GetDriveSystem() == 0) return "But this vessel has no movement capability!";
  if (GetHasMoved()) return "The ship has expended its movement for right now.";
  if (GetDamagedSystem("engines")) return "The ship's engines are damaged.";
  if (GetCrystals() < 1) return "You have not enough stores.";
  return 1;
}

mixed CanScan(object who, string what) {
	if (member_array(who->GetKeyName(), ({ GetCaptain(), GetOwner() })) == -1) 
	  return "You are neither Captain nor Owner of this vessel.";
	if (!SensorSuite) {
		who->eventPrint("The ship has neither navigation or communications equipment.");
		return 1;
	}
  return 1;
}

varargs mixed CanLaunchWeapons(object who, object target, string weapon) {
	if (member_array(who->GetKeyName(), ({ GetCaptain(), GetOwner() })) 
       == -1) return "You are neither Captain nor Owner of this vessel.";
  if (weapon != "attack") return "You can't launch " + weapon + " at that.";
  if (!target) return "You need a valid target.";
  if (target == this_object()) return "Cannot target our own ship!";
	if (!present(target, environment())) return "That is no longer present.";
	if (GetDamagedSystem("weapon")) return "The weapons systems are damaged.";
	if (GetHasAttacked()) return "The weapons are reloading."; 
	if (!GetWeaponSystem()) return "But the ship is unarmed!";
	if (living(target) && target->GetSize() < SIZE_GIANT) return "You can't target something so small!";
  if (target->GetOwner() && strsrch(base_name(environment()), SPACE) == -1) {
    if (user_exists(GetOwner())) return "You can't attack a ship in port!";
    }
	return 1;
}

varargs mixed CanHyperjump(object who, string x) {
	if (member_array(who->GetKeyName(), ({ GetCaptain(), GetOwner() })) 
       == -1) return "You are neither Captain nor Owner of this vessel.";
  if (!GetVehicleName()) return "The ship cannot leave port until it has a name.";
  if (GetDriveSystem() == 0) return "But this vessel has no movement capability!";
  if (GetDriveSystem() != VM_DEEP) return "But this vessel is not capable of hyperjumping.";
  if (GetHasMoved()) return "The ship has expended its movement for right now.";
  if (GetDamagedSystem("engines")) return "The ship's engines are damaged.";
  if (GetCrystals() < 1) return "You have not enough stores.";
  return 1;
}


mixed CanHail(object who, string tar) {
	object target = present(tar, environment());
	if (member_array(who->GetKeyName(), ({ GetCaptain(), GetOwner() })) 
       == -1) return "You are neither Captain nor Owner of this vessel.";
	if (!target) return "There is nothing like that in the area.";
	if (!SensorSuite) return "This ship has no communications equipment.";
	if (GetDamagedSystem("sensor")) return "The communications devices are damaged.";
	return 1;
}

varargs mixed CanTakeoff(object who, string x, string y, string z) {
	if (member_array(who->GetKeyName(), ({ GetCaptain(), GetOwner() })) 
       == -1) return "You are neither Captain nor Owner of this vessel.";
  if (!GetVehicleName()) return "The ship cannot leave port until it has a name.";
  if (GetDriveSystem() == 0) return "But this vessel has no movement capability!";
  if (GetHasMoved()) return "The ship has expended its movement for right now.";
  if (GetDamagedSystem("engines")) return "The ship's engines are damaged.";
  if (GetCrystals() < 1) return "You have not enough stores.";
  return 1;
}

mixed CanRepair(object who, string what) {
	if (!GetDamagedSystem(what)) return "But the " + what + " system is not broken!";
	return 1;
}

int CanReceive(object ob) {
	return 1;
}


/* Usage overrides -- Overrides to tell this file which function to use. */

static mixed array AddSave(mixed array vars) {
    return storage::AddSave(vars);
}

int GetRoomWarmth() {
	object env = environment();
	if (!env) return 40;
	if (env->GetProperty("space")) return 40;
	return env->GetRoomWarmth();
}

/* Fishing Stuff.  Let's see if this works.  */

mixed CanCast(object who, string where) {
  if (!environment()) return "You are so screwed.";
  return environment()->CanCast(who, where);
}

mixed eventCast(object who, object pole, string str) {
  if (!environment()) return "Ruh Roh Shaggy!";
  return environment()->eventCast(who, pole, str);
}

mixed CanStop(object who, string str) {
  if (!environment()) return "Ruh Roh Shaggy!";
  return environment()->CanStop(who, str);
}

mixed eventStop(object who, string str) {
  if (!environment()) return "Ruh Roh Shaggy!";
  return environment()->eventStop(who, str);
}
  
