/* Ship.c
 * Taken from duuk vehicle.c from forever ago that used to be starships
 * copied everything ship specific here and took out spaceship specific (!)
 * code.
 * -Mahkefel
 */

#include <lib.h>
#include <vehicle.h>
#include <daemons.h>
#include <size.h>
#include <std.h>
#include <damage_types.h>
inherit LIB_VEHICLE;

#define SPACE "/domains/innersea/virtual/"
string Captain = "";
string ShipStyle = "human";
int SensorSuite = 0;
int DriveSystem = 0;
int VehicleSize = 0;
int WeaponSystem = 0;
int ShieldSystem = 0;
int PrizeBonus = 0;
int Crystals = 0;
object *hasAttacked = ({});  
string *DamagedSystems = ({});
object *ShipEnemies;
string *Crew;

// mahkefel
// targeting block
// kind of kludge
// used for AI targeting to not dumbass.
// makes all ships have like, "ship930" or something in their Id list
private string UniqueVehicleId;
varargs string array SetId(string* val) {
  SetUniqueVehicleId();
  return ::SetId(val + ({ GetUniqueVehicleId() }) );
}
string SetUniqueVehicleId() {
  UniqueVehicleId = "ship"+random(10000);
  return UniqueVehicleId;
}
string GetUniqueVehicleId() {
  return UniqueVehicleId;
}
// end targetting kludge block

static void create() {
  vehicle::create();
  AddSave( ({ "SensorSuite",
              "DriveSystem",
              "VehicleSize",  
              "Captain", 
              "WeaponSystem", 
              "DamagedSystems",             
              "ShipStyle",
              "Crystals",
              "ShieldSystem", 
              "Crew" }) );
  hasAttacked = ({});
  Captain = 0;
  WeaponSystem = 0;
  SensorSuite = 0;
  ShieldSystem = 0;
  DriveSystem = 0;
  Crystals = 0;  
  DamagedSystems = ({});
  VehicleSize = VS_YACHT;
  ShipEnemies = ({ });
  new(STD_OBJ "screen")->eventMove(this_object());
  // for shipp(object) function
  SetProperty("PROP_VEHICLE","ship");
}

/* Driver Functions */

void heart_beat() {
  object sea = environment();
  ResetExit();
  if (hasMoved || sizeof(hasAttacked)) {
     all_inventory()->eventPrint("Waves gently crash against the ship.");
     SaveVehicle();
  }
  hasMoved = 0;
  hasAttacked = ({});
  if (time() - LastSave > 600) SaveVehicle();
  // MAHKEFEL dec 2013: shove ships out the endless.
  if (!random(60)) {
    if(playerp(GetPilot())) {
      if(!sea) return;
      if(strip_colours(sea->GetShort())=="the Endless Sea" && !sea->GetProperty("coastal")) {
        if (sea->GetXY() && (sea->GetXY()[0]<= -180)) {
          eventPrint("A %^BOLD%^BLUE%^rogue wave%^RESET%^ %^BOLD%^tosses%^RESET%^ the ship east!");
          eventMove("/domains/innersea/virtual/ocean/"+(sea->GetXY()[0]+1)+","+sea->GetXY()[1]);
        }
        if (sea->GetXY() && (sea->GetXY()[0]>= 100)) {
          eventPrint("A %^BOLD%^BLUE%^rogue wave%^RESET%^ %^BOLD%^tosses%^RESET%^ the ship west!");
          eventMove("/domains/innersea/virtual/ocean/"+(sea->GetXY()[0]-1)+","+sea->GetXY()[1]);
        }
      }
    }
  }
}

void init() {
  vehicle::init();
  if (environment(this_player()) == environment(this_object())) {
    if (GetSensorSuite() && !GetDamagedSystem("navigation") && !(this_player()->GetInvis())) {
      eventPrint("Ahoy! Something has moved in range of the ship!.");
    }
  }
}

mixed direct_launch_attack_on_str() { return 1; }

/* End Driver Functions */

// changes by mahkefel 2014 dec  13
// changed xp to be based on target skill
// increased xp by 10% (xp will likely net decrease)

// args d and l not used  -- From /lib/items/deterioration.c
varargs int eventReceiveDamage(object enemy_gunner, int type, int amt, int d, mixed array l) {
    object *crew = all_inventory();
    object pilot;
    int xpMod = 1100; // what are we multiplying xp by?
    int critical = random(1000000 + 25000);
    int reward = 5;
    object enemy_ship, *enemy_crew;
    object audience;
    
    if (enemy_gunner && !environment(enemy_gunner)) return 0;
    
    // define the attack ship, if possible
    if (enemy_gunner && vehiclep(environment(enemy_gunner))) enemy_ship = environment(enemy_gunner);
    
    //if (enemy_ship) enemy_gunner = enemy_ship->GetPilot();
    crew = filter(crew, (: living :) );                      
    if (sizeof(crew)) pilot = GetPilot(); 

    //  if (enemy_gunner) debug("Pilot: " + enemy_gunner->GetShort());
    //  if (enemy_gunner && enemy_gunner->GetTestChar()) debug("amt: " + amt + " crit: " + critical + " diff: " + (amt-critical));

    if (sizeof(crew)) {
      crew->eventPrint("%^YELLOW%^The ship is under attack!%^RESET%^");
      foreach(object person in crew) {
        if (person->GetSleeping()) {
          person->SetSleeping(0);
          person->eventPrint("You wake up!");
        }
      }
    }

    if (enemy_ship) {
      audience = enemy_ship;
    } else if (enemy_gunner) {
      audience = enemy_gunner; 
    }
    
    if (GetShieldSystem() && !GetDamagedSystem("shield")) {
      crew->eventPrint("The shields deflect some damage.");
      amt -= (GetShieldSystem() * 7500);   
      if (!random(20)) {
        crew->eventPrint("%^BOLD%^RED%^The shields collapse!%^RESET%^");
        AddDamagedSystem("shield");
        if (audience) audience->eventPrint("%^RED%^BOLD%^*You have damaged the shields on your target!*%^RESET%^");
        if (GetPilot()) enemy_gunner->AddExperience(GetPilot()->GetSkillLevel("sailing") * xpMod);
      }
    }
    
    if (amt <= 0) return 1;
    AddDamagePoints(-amt);
    crew->eventPrint("%^YELLOW%^The ship has suffered damage!%^RESET%^");
    if (critical < (amt)) {
      switch(random(4)) {
        case 0:
          if (!DriveSystem || GetDamagedSystem("sails")) break;
          crew->eventPrint("The sails have been damaged!");
          AddDamagedSystem("sails");
          if (audience) audience->eventPrint("%^RED%^BOLD%^*You have damaged the sails on your target!*%^RESET%^");
          if (GetPilot()) enemy_gunner->AddExperience(GetPilot()->GetSkillLevel("sailing") * xpMod);
          break;
        case 1:
          if (!SensorSuite || GetDamagedSystem("navigation")) break;
          crew->eventPrint("The navigation has been damaged!");
          AddDamagedSystem("navigation");
          if (audience) audience->eventPrint("%^RED%^BOLD%^*You have damaged the navigation equipment on your target!*%^RESET%^");
          if (GetPilot()) enemy_gunner->AddExperience(GetPilot()->GetSkillLevel("sailing") * xpMod);
          break;
        case 2:
          if (!WeaponSystem || GetDamagedSystem("weapon")) break;
          crew->eventPrint("The weapons have been damaged!");
          AddDamagedSystem("weapon");
          if (audience) audience->eventPrint("%^RED%^BOLD%^*You have damaged the weapons on your target!*%^RESET%^");
          if (GetPilot()) enemy_gunner->AddExperience(GetPilot()->GetSkillLevel("sailing") * xpMod);
          break;
        case 3:
          if (!ShieldSystem  || GetDamagedSystem("shield")) break;
          crew->eventPrint("The shield generator is damaged!");
          AddDamagedSystem("shield");
          if (GetPilot()) enemy_gunner->AddExperience(GetPilot()->GetSkillLevel("sailing") * xpMod);
          if (audience) audience->eventPrint("%^RED%^BOLD%^*You have damaged the shields on your target!*%^RESET%^");
          break;
      }
    }
    if( GetDamagePoints() < 1 ) {
      crew->eventPrint("%^BOLD%^RED%^The ship has been DESTROYED!%^RESET%^");
      ShipEnemies->eventEnemyDied(this_object());
      CHAT_D->eventSendChannel("Ship Died", "shipreports", capitalize(GetName()) + " has been destroyed.");
      if (enemy_ship) {
        foreach(object sunk in crew) {
          enemy_gunner->AddReputation(sunk->GetTown(), -2);
          // mahkefel: don't give sink xp if they're chums
          //if(!sunk->GetLevel() < enemy_gunner->GetLevel() - 25) {
            if (GetPilot()) enemy_gunner->AddExperience(GetPilot()->GetSkillLevel("sailing") * xpMod);
          //} else {
          //  enemy_gunner->eventPrint("You learn little from sending this landlubber to Damhair's locker!");
          //}
        }
      }
      if (environment()) {
       crew->eventMove(environment());
       crew->AddParalyzed(3);
       crew->eventPrint("You are stunned as the ship sinks below the waves!");
      } else {
        crew->eventDie(enemy_ship);
      }
      set_heart_beat(0);
      
      environment()->eventPrint(capitalize(GetShort()) + " sinks beneath the waves.");
      
      // okay, for now, if you somehow magic a ship to death from not a ship, 
      // you don't get no monies or dev points, that ship just explodes.
      // mostly for cleaner code than balance or nothin
      if (userp(enemy_gunner) && enemy_ship) {
        
        //reward = GetVehicleSize() + GetPrizeBonus();
        enemy_crew  = enemy_ship->GetCrewMembers();
        enemy_crew->eventPrint(
          "Sacking " + GetShort() + " yields " + (reward = random((GetVehicleSize() + GetPrizeBonus()) * 1000) * 2) + " imperials worth of loot!");
        enemy_crew->eventPrint("Your share is divided by a total of " + sizeof(enemy_crew) + " crew members.");
        foreach(object c in enemy_crew) {
         c->AddCurrency("imperials", reward/sizeof(enemy_crew));
        }
        if (random(1000) < (GetVehicleSize() + GetPrizeBonus())) {
          enemy_crew = distinct_array(enemy_crew);
          enemy_crew->eventPrint("You have been rewarded with 1 development point!");
          enemy_crew->AddDevelopmentPoints(1);
          foreach(object woot in enemy_crew) {
            CHAT_D->eventSendChannel("Reward", "ooc", capitalize(woot->GetKeyName()) + " got 1 dp for sinking " + GetShort());
          }
        }
      } else if (userp(enemy_gunner)) {
        enemy_gunner->eventPrint("All remnants of the ship are annihilated and lost beyond salvage or repair!"); 
      }
      DeleteVehicle();
      eventDestruct();
      return 1;
    }
    SaveVehicle();
    return GetDamagePoints();
}

/* This function won't do much except in concert with an AI ship captain. */

void eventEncounterShip(object ship) {
  object p = GetPilot();
  if (p) p->eventEncounterShip(ship);
}

int eventScuttle(object who) {
  if (userp(who)) CHAT_D->eventSendChannel("", "shipreports", capitalize(who->GetKeyName()) + " has scuttled " + GetName() + "!", 1);
  eventPrint(capitalize(who->GetKeyName()) + " has ordered the ship be scuttled!");
  environment()->eventPrint(capitalize(GetShort()) + " sinks beneath the waves as the captain scuttles her.");
  all_inventory()->eventMove(environment());
  DeleteVehicle();
  eventDestruct();
  return 1;
}

int eventPirate(object who) {
  string name = who->GetKeyName();
  if (userp(who)) CHAT_D->eventSendChannel("", "shipreports", capitalize(name) + " has successfully pirated " +
                                           GetName() + "!", 1);
  eventPrint(capitalize(name) + " has seized control of the ship!");
  SetCaptain(name);
  DeleteVehicle();
  if (userp(who)) SetOwner(name); else SetOwner(0);
  return GetCaptain() == who->GetKeyName();
}                                             

varargs int eventLaunchWeapons(object who, object target, string weapon) {
  int success, amount, con;
  object ePilot;
  ePilot = target->GetPilot();
  con = (ePilot ? ePilot->GetSkillLevel("sailing") : 0);
  success = who->eventCheckSkill("sailing", con, 0, 0);
  target->eventPrint("You are under fire from " + GetName() + "!");
  // debug(success);
  if (success > 0) {
    amount = GetWeaponSystem() * 10000;
    target->eventPrint("%^RED%^The ship has been hit!%^RESET%^");
    // mahkefel 2014: changing this a bit-- it now wants the person using the guns and not the ship where the guns are on.
    // (i.e. who and not this_object())
    target->eventReceiveDamage(who, BLUNT, amount);
    eventPrint("%^GREEN%^The enemy ship has been %^BOLD%^hit!%^RESET%^");
    message("system", capitalize(GetShort()) + "'s attack hits!", environment(), ({ this_object(), target }) );
    if (!target) eventPrint("%^GREEN%^The enemy ship has been %^RED%^BOLD%^destroyed!%^RESET%^");
   } else {
    eventPrint("%^GREEN%^The attack has missed!%^RESET%^");
    target->eventPrint("The enemy attack has missed.");
    message("system", capitalize(GetShort()) + "'s attack misses!",  environment(), ({ this_object(), target }) );   
  }
  if (target) {
    target->AddShipEnemy(this_object());
    AddShipEnemy(target);
    }
  hasAttacked += ({who});
  if (userp(who)) AddCrystals(-5); // consume some ammo
}

int eventScan(object who, string what) {
  object env = environment();
  int x, y, *z;
  int success;
  object *ob;
  string xPos = "", yPos = "", str = "";
  
  if (!SensorSuite) {
    who->eventPrint("The ship has neither navigation or communications equipment.");
    return 1;
  }
  if (GetDamagedSystem("navigation")) {
    who->eventPrint("The navigation and communication system is damaged.");
    return 1;
  }  
  if (!env) {
    who->eventPrint("This would be the least of your worries.");
    return 1;
  }
  if (sscanf(base_name(env), SPACE "%s/%d,%d", str, x, y) != 3) {
    who->eventPrint("You are unable to see enough stars from here.");
    return 1;
  }
  if (SensorSuite < VSE_WIDE ) {  
    if (env->GetProperty("shallows")) {
      who->eventPrint("This close to land, you attempt to orient yourself by "
        "dead reckoning.");
    } else {
      who->eventPrint("We have no navigation equipment.");
    }
    return 1;
  }                                                    
  success = who->eventCheckSkill("navigation", 50, 0, 100);
  if (success < 1) {
    who->eventPrint("You fail to determine the ships location.");
    return 1;
  }
  if (success >= 1 && success <= 40) {
    switch(random(3)) {
      case 0:
        x += (random(40) - success);
        break;
      case 1:
        y += (random(40) - success);
        break;
        break;
      default:
        x += (random(40) - success); 
        y += (random(40) - success);   
        break;
      }
    }
  z = SAILING_D->GetCoordinates(SAILING_D->GetTownDock(what));
  if (!sizeof(z)) debug("Bad what of " + what);
  x -= z[0]; y -= z[1];
  if (x > 0) xPos = "east"; else xPos = "west";
  if (y > 0) yPos = "north"; else yPos = "south";
  str = "Our best guess for position is";
  if (x != 0) str += (" " + absolute_value(x) + " leagues " + xPos + " of " + capitalize(what));
  if (y != 0) str += (" " + absolute_value(y) + " leagues " + yPos + " of " + capitalize(what));
  who->eventPrint(str + ".");
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
  if (GetDamagedSystem("navigation")) {
    who->eventPrint("The navigation and communication system is damaged.");
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

int SetPrizeBonus(int x) { return PrizeBonus = x; }
int GetPrizeBonus()      { return PrizeBonus; }

string SetShipStyle(string x) { return ShipStyle = x; }
string GetShipStyle() { return ShipStyle; }
string SetCaptain(string x) {
  return Captain = x;
}
string GetCaptain() { return Captain; }

int SetVehicleSize(int x) { return VehicleSize = x; }
int GetVehicleSize() { return VehicleSize; }

string GetVehicleSizeString() {
 if (VehicleSize == VS_YACHT       ) return "yacht";
 if (VehicleSize == VS_GALLEY      ) return "galley";
 if (VehicleSize == VS_CRUISER     ) return "cruiser";
 if (VehicleSize == VS_DREADNAUGHT ) return "dreadnaught";
 return "unknown";
}

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

int GetHasAttacked(object who) {
  if( member_array(who, hasAttacked) != -1) {
    return 1;
  }
  return 0;
}

string *SetDamagedSystems(string *system) {
  if (!arrayp(system)) system = ({ system });
  DamagedSystems = distinct_array(system);
  return DamagedSystems;
}

string *AddDamagedSystem(string system) {
  if (member_array(system, DamagedSystems) == -1)
  CHAT_D->eventSendChannel("Ship Damage", "shipreports", GetName() + " has been " +
                      "critically hit in the " + system + ". " + short_file(base_name((environment()))));
  return DamagedSystems = distinct_array(DamagedSystems + ({ system }));
}

string *RemoveDamagedSystem(string system) {
  if (system == "shields") system = "shield";
  return DamagedSystems -= ({ system });
}

string *GetDamagedSystems() { 
    // mahkefel 2017: it's restoring weird and calling this undefined since
    // i split up this library--not sure what's happening, trying to just
    // workaround the issue by redeclaring it as an empty array if it's
    // undedfined.
  if (!DamagedSystems) DamagedSystems = ({ });
  return DamagedSystems; 
}

int GetDamagedSystem(string system) {
  if (system == "shields") system = "shield";
  if ( member_array(system, GetDamagedSystems()) != -1 ) return 1;
  return 0;
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
                  tmp = "The ship is capable of coastal sailing only.";
      break;
    case VM_DEEP:
                  tmp = "The ship is capable of deep ocean sailing.";
      break;  
    }
  if (GetDamagedSystem("sails")) 
    tmp += " %^BOLD%^RED%^The sails are damaged.%^RESET%^";
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
    //if (GetHasAttacked()) tmp += " The weapons are being reloaded.";
  if (GetDamagedSystem("weapon")) 
    tmp += " %^BOLD%^RED%^ The weapons are damaged.%^RESET%^";
  return tmp;
}

string GetShieldStatus() {
  string tmp;
  switch (ShieldSystem) {
    case 0:
      tmp = "The ship has no magical shields.";
      break;
    case VSH_SMALL:
      tmp = "The ship has small magical shields.";
      break;
    case VSH_MEDIUM:
      tmp = "The ship has medium magical shields.";
      break;
    case VSH_LARGE:
      tmp = "The ship has large magical shields.";
      break;
    }
    if (GetDamagedSystem("shield")) 
      tmp += " %^BOLD%^RED%^ The shields are disrupted.%^RESET%^";
  return tmp;
}

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

mixed CanScuttle(object who) {
  if (GetOwner() && who->GetKeyName() != GetOwner()) {
    return "Don't you think the owner might be mad about that?";
  }
  if (!GetOwner() && who->GetKeyName() != GetCaptain()) {
    return "Only the Captain can order the ship sunk!";
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
  if (GetDamagedSystem("sails")) return "The ship's sails are damaged.";
  if (GetCrystals() < 1) return "You have not enough stores.";
  return 1;
}

varargs mixed CanLaunchWeapons(object who, object target, string weapon) {
  if (member_array(who->GetKeyName(), ({ GetCaptain(), GetOwner(), GetCrew() })) 
       == -1) return "You are neither Captain nor Owner nor Crew of this vessel.";
   if(who->GetOwner()&&who->GetOwner()!="") {
    who->eventForce("emote confused and stupid.");
    return 0;
  }
  if (weapon != "attack") return "You can't launch " + weapon + " at that.";
  if (!target) return "You need a valid target.";
  if (target == this_object()) return "Cannot target our own ship!";
  if (!present(target, environment())) return "That is no longer present.";
  if (GetDamagedSystem("weapon")) return "The weapons systems are damaged.";
  if (GetHasAttacked(who)) return "You are still reloading."; 
  if (!GetWeaponSystem()) return "But the ship is unarmed!";
  if (living(target) && target->GetSize() < SIZE_GIANT) return "You can't target something so small!";
  if (target->GetOwner() && strsrch(base_name(environment()), SPACE) == -1) {
    if (user_exists(GetOwner())) return "You can't attack a ship in port!";
    }
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

mixed CanRepair(object who, string what) {
  if (!GetDamagedSystem(what)) return "But the " + what + " system is not broken!";
  return 1;
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

int AddReputation(string faction, int amount) {
  object p;
  if (p = GetPilot()) {
    if (faction != "Wilderness" && faction != "all") p->AddReputation(faction, amount);
  }
  return amount;
}

