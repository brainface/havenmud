/* AI Ship Captains.  This is useful stuff for Pirates
 * and Vikings!  Woo!
 * Duuk
 */
// mahkefel 2011: I want some npcs to not pirate ships.
// and i don't want to write shipcaptains2.c

#include <lib.h>
#include <daemons.h>
#include <vehicle.h>
inherit LIB_NPC;

string *ShipWanderPath; /* A route between rooms.  Define ROOM FILENAMES as targets IN ORDER. */
int Direction, ShipWander, CaptainAggressiveness, ShipWimpy, Wait;
mapping TriedExits;
string LastCommand;

static void create() {
  ::create();
  SetProperty("swimmer", 1); /* I can enter ocean rooms while walking.  Pirates, Arr! */
  ShipWanderPath = ({ });  /* Do I have any place to head to? */
  Direction = 0;      /* Where am I going?  I will head toward ShipWanderPath[Direction] */
  ShipWander = 0;     /* By default, the AI will not wander. If it doesn't have a ShipWanderPath
                         it won't do a damn thing.  Nice, yes? */
  CaptainAggressiveness = 0; /* By default, I live in peace. */
  ShipWimpy  = 0; /* Additional modified to when I flee combat. */
  SetNoClean(1);
  TriedExits = ([ ]);
  LastCommand = 0;
  Wait = 0;
  set_heart_beat(3);
  SetProperty("will_pirate",1); // mahkefel
}

static int ContinueHeart() {
  return 1;
}

int AddWait(int x) { if (Wait + x < 0){ Wait = 0; return Wait; } return Wait += x; }
int GetWait()      { return Wait; }

int SetShipWimpy(int x) { return ShipWimpy = x; }
int GetShipWimpy() { return ShipWimpy; }

int SetCaptainAggressiveness(int x) { return CaptainAggressiveness = x; }
int GetCaptainAggressiveness()      { return CaptainAggressiveness;     }

int SetShipWander(int x) { return ShipWander = x; }
int GetShipWander() { return ShipWander; }

string SetLastCommand(string s) { return LastCommand = s; }
string GetLastCommand()         { return LastCommand; }
string GetLastDirection()       {
  if (!GetLastCommand()) return 0;
  return implode(explode(GetLastCommand(), " ") - ({ "sail" }), " " );
}

string *SetShipWanderPath(string *path...) {
  ShipWanderPath = path;
  return ShipWanderPath;


}

string GetShipPathStart() { return ShipWanderPath[0]; }
string GetShipPathEnd()   { return ShipWanderPath[1]; }

string *GetShipWanderPath() { return ShipWanderPath; }

int AddDirection(int x) {
  int max = sizeof(ShipWanderPath) -1;
  int newdirection = (Direction + x) % sizeof(ShipWanderPath);
  return Direction = newdirection;
}

int SetDirection(int x) {
  if (x > (sizeof(ShipWanderPath) -1)) {
    debug("*Bad Direction Set!  Are you TRYING to mess with the AI?");
    return -1;
  }
  return Direction = x;
}

int GetDirection() { return Direction; }

string GetDestination() { return ShipWanderPath[Direction]; }

string *SetTriedExit(string exit) {
  object ship = environment();
  object env  = environment(ship);
  string room = base_name(env);

  if (!sizeof(TriedExits[room])) TriedExits[room] = ({ });
  
  TriedExits[room] = distinct_array(TriedExits[room] + ({ exit }));
  return TriedExits[room];
}

int GetTriedExit(string exit) {
  object ship = environment();
  object env  = environment(ship);
  string room = base_name(env);

  if (!TriedExits[room]) return 0;
  if (member_array(exit, TriedExits[room]) != -1) return 1;
  return 0;
}

mapping GetTriedExits() { return TriedExits; }

varargs string *GetRoomTried(string room) {
  object ship = environment();
  object env  = environment(ship);

  if (!room) room = base_name(env);
  if (!TriedExits[room]) return ({ });
  return TriedExits[room];
}

int eventEncounterShip(object ship) {
  float x;
        int modifier, netaggro;
        object myship = environment();
        x = (100.0 * myship->GetDamagePoints()) / myship->GetMaxDamagePoints();
  modifier = 100 - to_int(x);
  //debug("Encounter Ship : " + identify(ship));
  netaggro = GetCaptainAggressiveness() - modifier;
  //debug("x " + x + " mod " + modifier + " netaggro " + netaggro);
  if (myship->CanLaunchWeapons(this_object(), ship, "attack"))
    if (random(100) < netaggro) { /* I am going to attack! */
    //  debug("I am going to attack!");
      eventForce("launch attack on " + ship->GetKeyName() + " 1");
    }
  return 1;
}

int CheckValidExit(string direction) {
  object ship = environment();
  object env  = environment(ship);
  object dest;
  if (!env) {
    eventDestruct();
    return 0;
  }
 if (GetProperty("debug")) debug("Last: " + GetLastCommand());
  if (member_array(direction, env->GetExits()) == -1) {
  if (GetProperty("debug"))    debug(direction + " not an exit");
    return 0;
    }
  dest = load_object(env->GetExit(direction));
  if (!dest) {
    return -1;
  }
  if (!(dest->GetProperty("coastal")) && !(dest->GetProperty("shallows")) &&!(dest->GetProperty("ocean"))) { 
    if (GetProperty("debug"))    debug(direction + " is non-water");
    return 0;
  }
  if (dest->GetProperty("ocean") && ship->GetDriveSystem() != VM_DEEP) { return 0; } /* I can't sail into the ocean. */
  if (GetLastCommand() == "sail west" && direction == "east")          { return 0; }
  if (GetLastCommand() == "sail east" && direction == "west")          { return 0; }
  if (GetLastCommand() == "sail north" && direction == "south")        { return 0; }
  if (GetLastCommand() == "sail south" && direction == "north")        { return 0; }
  if (GetLastCommand() == "sail northwest" && direction == "southeast"){ return 0; }
  if (GetLastCommand() == "sail northeast" && direction == "southwest"){ return 0; }
  if (GetLastCommand() == "sail southwest" && direction == "northeast"){ return 0; }
  if (GetLastCommand() == "sail southeast" && direction == "northwest"){ return 0; }
  //mahk: i think this line may be causing whirlygigs.
  if (GetTriedExit(direction)) {  return 0; }
  if (GetProperty("debug"))  debug(direction + " is where I'm heading");
  return 1;
}

void CheckReturnPath() {

  /* This function is in for certain AI Captains */
}

string eventDecidePath() {
  int xCurrent, yCurrent;
  int xDestination, yDestination;
  int *tmp;
  object ship = environment();
  string *ex = environment(ship)->GetExits();
  string rnd;
  if (!ship) return "";
  tmp = SAILING_D->GetCoordinates(base_name(environment(ship)));
  xCurrent = tmp[0];
  yCurrent = tmp[1];
  if (!Direction) { /* I am head TOWARDS the end */
    tmp = SAILING_D->GetCoordinates(GetShipPathEnd());
  } else {
    tmp = SAILING_D->GetCoordinates(GetShipPathStart());
  }
  xDestination = tmp[0];
  yDestination = tmp[1];
  if (xCurrent < xDestination) { /* I am west of where I need to be. */

    if (CheckValidExit("east"))  {
      SetTriedExit("east");
      return "sail east";
    }
    if (CheckValidExit("north")) {
      SetTriedExit("north");
      return "sail north";
    }
    if (CheckValidExit("south")) {
      SetTriedExit("south");
      return "sail south";
    }
  }
  if (xCurrent > xDestination) { /* I am east of where I need to be. */

    if (CheckValidExit("west"))  {
      SetTriedExit("west");
      return "sail west";
      }
  }
  if (yCurrent < yDestination) { /* I am south of where I need to be. */

    if (CheckValidExit("north")) {
      SetTriedExit("north");
      return "sail north";
    }
    if (CheckValidExit("west"))  {
      SetTriedExit("west");
      return "sail west";
    }
    if (CheckValidExit("east"))  {
      SetTriedExit("east");
      return "sail east";
    }
  }
  if (yCurrent > yDestination) { /* I am north of where I need to be. */

    if (CheckValidExit("south")) {
      SetTriedExit("south");
      return "sail south";
    }
    if (CheckValidExit("west"))  {
      SetTriedExit("west");
      return "sail west";
    }
    if (CheckValidExit("east"))  {
      SetTriedExit("east");
      return "sail east";
    }

  }
  if (yCurrent == yDestination && xCurrent == xDestination) { /* I am at my destination */
    AddDirection(1); /* Increment my direction */
    TriedExits = ([ ]);
    CheckReturnPath();
    AddWait(10);
    return "yell All aboard!";
    }
  if (GetLastDirection())
    if (!GetTriedExit(GetLastDirection())) {
      SetTriedExit(GetLastDirection());
      return "sail " + GetLastDirection();
      }
  /* None of the above worked. */
  ex -= GetRoomTried();
  if (!sizeof(ex)) {
if (GetProperty("debug")) debug("Oh man.  Nothing I haven't tried here.  Help.");
    TriedExits = ([]);
    return "ponder";
    }
  rnd = ex[random(sizeof(ex))];
  SetTriedExit(rnd);
  return "sail " + rnd;
}

string eventShipWander() {
  object ship  = environment();
  object env;
  string exits;
  if (!vehiclep(ship)) return "speak Fare well!";
  env   = environment(ship);
  exits = env->GetExits();

  TriedExits = ([ ]);   /* Wandering Ships can just go back and forth. */
  exits = filter(exits, (: CheckValidExit :) );
  if (ship->GetDamagedSystem("sails")) return "repair sails";
  if (!sizeof(exits)) {
    if (GetProperty("debug"))  debug("No valid exits!");
    return "ponder";
    }
  return "sail " + exits[random(sizeof(exits))];
}

string eventShipCombat(object *enemies) {
  float x;
        object myship = environment();
        object ship = enemies[random(sizeof(enemies))];
        x = (100.0 * myship->GetDamagePoints()) / myship->GetMaxDamagePoints();
        x = to_int(x); x -= ShipWimpy;
  if (x <= 0) return eventShipWander();
  if (!myship->GetWeaponSystem()) { return eventShipWander(); } /* I'm unarmed.  I should flee. */
  if (myship->GetDamagedSystem("weapon")) return "repair weapon";
  return "launch attack on " + ship->GetUniqueVehicleId();
  return eventShipWander(); /* I don't wanna be here anymore! */
}

string eventCheckRepairs() {
  object ship = environment();
  string *broken = ship->GetDamagedSystems();
  if (!GetSkillLevel("enchantment")) {
    broken -= ({ "shield" });
  }
  if (sizeof(broken)) {
    return "repair " + broken[random(sizeof(broken))];
  }
}


void heart_beat() {
  object ship = environment();
  object *enemies = ({ });
  string com = 0;
  ::heart_beat();
  if (Wait > 0) {
    Wait--;
    return;
  }
  if (!ship) { return; }
  if (vehiclep(ship) && !environment(ship)) {
    eventDestruct();
    return;
  }
  if (!environment(ship)) {
    com = "board ship";
  }
  /* This is to clean up useless ships that aren't affecting players and are out of stores. */
  if (ship->GetShipStores() == 0) {
    com = "scuttle ship";
    foreach(object o in all_inventory(ship)) {
      if (userp(o)) com = 0;
    }
  }
  if (!id(ship->GetOwner()) && !id(ship->GetCaptain())) {
    /* I am neither the Captain nor the Owner */
    if(GetProperty("will_pirate")) com = "pirate";
  }
  if (!vehiclep(ship)) { com = "board 1st ship"; }
  if (!com) { /* Ok.  We're not scuttling the ship.  Are we in combat? */
    enemies = ship->GetShipEnemies();
    if (!enemies) { enemies = ({ }); }
    enemies = filter(enemies, (: $1 :) );

    foreach(object e in enemies) {
      if (environment(e) != environment(ship)) enemies -= ({ e });
      }
    if (sizeof(enemies)) { com = eventShipCombat(enemies); }
  }
  if (!com) {
    com = eventCheckRepairs();
  }
  if (GetInCombat()) { com = ""; } /* We're in hand-to-hand. */
  if (!com) { /* Ok, no valid combat command.  Are we on a path to go somewhere? */
    if (sizeof(ShipWanderPath)) {  com = eventDecidePath(); }
    }
  if (!com) { /* Ok.  I have stores, I am not in combat, and I don't have a ShipWanderPath */
    if (ShipWander) { com = eventShipWander(); }
    }
  if (!sizeof(players())) { com = "scuttle ship"; }
  /* Ok, do we have a valid command? */
  if (com) {
    if (!stringp(com)) return;
    if (!com || com == "") return;
    eventForce(com);
    LastCommand = com;
    }
}

 

