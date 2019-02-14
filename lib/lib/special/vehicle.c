/*  Starship Version 0.2a
 *  Attempting to clean the code
 *  And make it 100% functional
 *
 *  Duuk
 * 19 November 2001
 * Conversion to sailing ship.
 *  4 July 2004
 *
 * Mahkefel
 * 2016 December
 * Splitting off ship specific functions into a separate file
 * so I can make alessandra a wagon
 * that inherits this file but does not float.
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

inherit LIB_STORAGE;
inherit LIB_MESSAGES;
inherit LIB_EXITS;

string VehicleName = "";
string CurrentLocation = "";
string BridgeDescription = "";
string Owner = "";
int hasMoved = 0;
int LastSave = 0;
string *VId, VLong, VShort;

static void create() {
  storage::create();
  messages::create();
  exits::create();
  AddSave( ({ "Owner",
              "BridgeDescription",
              "CurrentLocation",
              "VehicleName", 
              "VId", 
              "VLong", 
              "VShort" }) );
  hasMoved = 0;
  VehicleName = "";
  CurrentLocation = "";
  Owner = 0;
  LastSave = 0;  
  set_heart_beat(1);
  SetProperty("PROP_VEHICLE", 1);
  SetProperty("login", ROOM_DEATH);
  SetMessages( ([
    "come"   : "$N enters.",
    "leave"  : "$N leaves $D.",
    "telout" : "$N goes into nowhere.",
    "telin"  : "$N comes out of nowhere.",
    ]) );  
  SetPreventGet("");
  call_out( (: LoadVehicle :), 1);
}  

/* Save and Load Functions */


void SaveVehicle() {
  string name = VehicleName;
  if (!clonep()) return;
  if (Owner == "" || VehicleName == "" || Owner == 0 || VehicleName == 0) return;
  if (!environment()) eventDestruct();
  if (file_size(SAVE_VEHICLES + "/" + Owner + "/" ) != -2) {
    mkdir(SAVE_VEHICLES + "/" + Owner + "/" );
  }
  name = lower_case(name);
  name = replace_string(name, " ", "_");
  if (file_size(SAVE_VEHICLES + "/" + Owner + "/" + name[0..0] + "/") != -2) {
    mkdir(SAVE_VEHICLES + "/" + Owner + "/" + name[0..0] );
  }
  LastSave = time();
  save_object(SAVE_VEHICLES + "/" + Owner + "/" + name[0..0] + "/" + name);

}

void LoadVehicle() {
   string name = VehicleName;
   if (Owner == "" || VehicleName == "") { return; }
   name = lower_case(name);
  name = replace_string(name, " ", "_");
   if (!file_exists(SAVE_VEHICLES + "/" + Owner +  "/" + name[0..0] + "/" + name + ".o") ) { return; }
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
   if (!file_exists(SAVE_VEHICLES + "/" + Owner +  "/" + name[0..0] + "/" + name + ".o") ) 
     return; 
   rm(SAVE_VEHICLES + "/" + Owner + "/" + name[0..0] + "/" + name + ".o");
   
   SetVehicleName("");
   
}

void RestoreVehicle(string file) {
  restore_object(file);
  
  parse_refresh();
}

/* End Save and Load Functions */

//TODO: Vehicle base heartbeat
void heart_beat() {
  SaveVehicle();
  hasMoved = 0;
  ResetExit();
}

mixed direct_board_obj() {
  return 1;
}

mixed direct_repair_obj() {
  if (GetDamagePoints() == GetMaxDamagePoints()) 
    // TODO: vehicle generic or object spe cific message
    return "But the ship is not damaged!";
  return 1;
}

// TODO: genericy vehicly stuff?
void init() {
  storage::init();
}

// apparently vehicles are alive!
int is_living() { return 1; }

/* End Driver Functions */

/* event Functions */

int eventMove(mixed dest) {
  int tmp;
  tmp = storage::eventMove(dest);
  ResetExit();
  return tmp;
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
  int x; int y; int *ar;
  if (environment()) {
    prev = file_name(environment());
    if (!outmessage) { environment()->eventPrint(GetMessage("telout"), MSG_ENV, this_object());
      } else { environment()->eventPrint(GetMessage("leave", outmessage), MSG_ENV, this_object());
      }
    }
  if(!objectp(dest)) load_object(dest);
  eventMove(dest);
  foreach(object liv in all_inventory()) { if (living(liv)) liv->eventDescribeEnvironment(liv->GetBriefMode()); }
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

  // oh god none of this should be in base vehicle
  // maybe it's usable for bandit encounters though? leaving.
  if (sizeof(ar = SAILING_D->GetCoordinates(base_name(environment()))) == 2) {
    x = ar[0]; y = ar[1];
    if (!random(25)) SAILING_D->createShipEncounter(x, y);
  }
  
  foreach(object ship in all_inventory(environment())) {
    if (ship == this_object()) continue;
    if (!vehiclep(ship)) continue;
    ship->eventEncounterShip(this_object());
    }
}

int GetAmbientLight() {
  if (!environment()) return 50;
  return environment()->GetAmbientLight();
}

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

int GetHasMoved() { return hasMoved; }

// long used for the interior of the vehicle
string SetBridgeDescription(string x) { return BridgeDescription = x; }
string GetBridgeDescription() { return BridgeDescription; }

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
  return "\nThe vessel could sink at any time."; 
}

string GetName() { return (GetVehicleName() != "" ? GetVehicleName() : GetShort()); }

/*
// TODO: generic vehicle repairskill
string GetRepairSkill(string system) {
  if (!system) return "wood working";
  switch (system) {
    case "sails"      : return "sailing";
    case "navigation" : return "navigation";
    case "weapon"     : return "sailing";
    case "shield"     : case "shields" : return "enchantment";
  }
  return "sailing";
}

string *GetRepairSkills() { return ({ "sailing", "navigation", "enchantment", "wood working" }); }
*/
string SetVLong(string x) { return VLong = x; }
string SetVShort(string x) { return VShort = x; }
string *SetVId(string *x) { return VId = x; }

string GetVLong() { return VLong; }
string GetVShort() { return VShort; }
string *GetVId() { return VId; }

string GetDomain() {
  if (!environment()) return "Southern Coast";
  return environment()->GetDomain();
}

/* Modal Functions */

void ResetExit() {
  AddExit("out", base_name(environment()));
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
  return env->GetRoomWarmth();
}

int GetCanClose() {
  return 0;
}

int GetCanLock() {
  return 0;
}

string *GetNewsgroups() { return ({ }); }

