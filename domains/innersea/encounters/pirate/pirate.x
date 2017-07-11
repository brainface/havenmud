#include <lib.h>
#include <domains.h>

inherit LIB_SHIPCAPTAIN;

// keeps track of boarders, to prevent
// 47 small goden pirates from piling up
object *pirates;

// pirate will not level below this
private int minLevel = 1;
void SetMinLevel(int level);
int  GetMinLevel();

// pirate will level up to this
private int maxLevel = 50;
void SetMaxLevel(int level);
int  GetMaxLevel();

// boarder attacks enemy pilot
private string boarder = "";
int    SetBoarder(string filename);
string GetBoarder();

// first mate guards the ship captain when boarded
private string firstMate = "";
int    SetFirstMate(string filename);
string GetFirstMate();

// swabby assaults PASSENGERS on an enemy ship
private string passengerAttacker = "";
int    SetPassengerAttacker(string filename);
string GetPassengerAttacker();

// There's a dude on my ship. Do I fight him?
int eventCheckPlayer();

// THere's a ship out there. Do I hate it?
//  (Note that low CaptainAgressiveness can prevent pirates
//   from attacking ships they hate. Cuz they're scairt.)
int eventEncounterShip(object ship);

/*
// Let's be frank: what do I feel about this guy, whether
// pilot or dude next to me?
// int eventCheckPlayer();
*/

// A lot of pirates like to start combat with "backstab"
// or "disarm". This allows that to be set if you want
// a backstabby guy. defaults to "kill".
private string combatStartVerb = "kill";
int    SetCombatStartVerb(string verb);
string GetCombatStartVerb();

static void create() {
  ::create();         
  SetEncounter( (:eventCheckPlayer:) );                                         
  pirates = ({ });                                                              
}

// By default, auto attack any player that shows up
// overwrite this function and call it to prevent i.e.
// Kylin sailors from killing kylin players.
int eventCheckPlayer() {
  object who = this_player();
  object pirate;
  if (playerp(who)) {
    SetAttack(who);
    if ( GetFirstMate() ) {
      pirate = new( GetFirstMate() );
      pirate->SetLevel( who->GetLevel() * 0.9 );
      pirate->eventMove(environment());
      pirate->eventForce("kill " + who->GetKeyName());
    }
    return 1;
  }
  else return 0;
}

// Logic to determine how ship fights
string eventShipCombat(object *enemies) {
  object pirate;                         
  object vic;                            
  object myship = environment();         
  object ship;                           
  object* crew;                          
  float x;                               
  int piratelevel;                                               

  // Don't kill pirates, if pirate.
  foreach(object e in enemies) {                                 
    if (e) if (e->GetPilot())                                     
      if (GetProperty("pirate") == e->GetPilot()->GetProperty("pirate"))
        enemies -= ({ e }); 
  }

  // wander around if everything's dead.                                                              
  if(sizeof(enemies) == 0) { return ::eventShipWander(); }       

  // pick random ship
  ship = enemies[random(sizeof(enemies))];                     
  x = (100.0 * myship->GetDamagePoints()) / myship->GetMaxDamagePoints();
  x = to_int(x); x -= ShipWimpy; x += CaptainAggressiveness;             

  // shoot if we're not running
  if (random(200) < x) { /* I am going to attack! */                       
    // Send boarder, if we have boarders
    if ( !random(5) && GetBoarder() ) {  
      vic = ship->GetPilot();                                                
      if (!vic) { return ::eventShipCombat(enemies); }                       
      pirates = filter(pirates, (: $1 :) );                                  
      pirates = filter(pirates, (: living :) );                              
      if (sizeof(pirates) < 5) {                                             
        piratelevel = vic->GetLevel();                               
        pirate = new( GetBoarder() );     
        if(piratelevel > GetMaxLevel() ) { piratelevel = GetMaxLevel(); }
        if(piratelevel < GetMinLevel() ) { piratelevel = GetMinLevel(); }                                                
        pirate->SetLevel( piratelevel * 0.9 + random(5) );                                  
        pirate->eventMove(myship);                                           
        pirates += ({ pirate });                                             
        call_out( (: call_other, pirate,
          "eventForce", "out" :), 2 );        
        call_out( (: call_other, pirate, "eventForce",
          "board " + ship->GetName() :), 2 );
        if (pirate->GetCombatStartVerb()) {
          call_out( (: call_other, pirate, "eventForce", 
            pirate->GetCombatStartVerb() + " " + vic->GetKeyName() :), 2 );
        } else {
          call_out( (: call_other, pirate, "eventForce", 
            "kill " + vic->GetKeyName() :), 2 );
        }
        return "yell take the ship men, leave no survivors! ";                                 
      }                                                                                        
    }

    // even the passenger gets in trouble!                                                   
    /// send a chum sailor to harrass a passenger, if we have one                                            
    if (!random(5) && GetPassengerAttacker() ) {                                                                        
      crew = filter(all_inventory(ship), (: playerp($1) :));                                 
      vic = crew[random(sizeof(crew))];                                                      
      if(vic != ship->GetPilot() && sizeof(pirates) < 5) {                                                          
        piratelevel = vic->GetLevel();                                                 
        pirate = new( GetPassengerAttacker() );                  
        if(piratelevel > ship->GetPilot()->GetLevel() )                                      
          { piratelevel = ship->GetPilot()->GetLevel(); }                                    
        if(piratelevel > GetMaxLevel() ) { piratelevel = GetMaxLevel(); }                                        
        pirate->SetLevel( piratelevel * 0.9 + random(3) );                                                      
        pirate->eventMove(myship);
        pirates += ({ pirate });
        call_out( (: call_other, pirate, "eventForce",
          "out" :), 2 );
        call_out( (: call_other, pirate, "eventForce",
          "board " + ship->GetName() :), 2 );
        if (pirate->GetCombatStartVerb()) {
          call_out( (: call_other, pirate, "eventForce", 
            pirate->GetCombatStartVerb() + " " + vic->GetKeyName() :), 2 );
        } else {
          call_out( (: call_other, pirate, "eventForce", 
            "kill " + vic->GetKeyName() :), 2 );
        }
        return "yell take the ship men, leave no survivors! ";
      } 
    }
  }
  return ::eventShipCombat(enemies);
}

// ship out there. do i hate it?
int eventEncounterShip(object ship) {
  object targ;                       
  int piratelevel;                   

  targ = ship->GetPilot();
  if (!targ) { return ::eventEncounterShip(ship); }

  if(targ->GetProperty("pirate") == GetProperty("pirate")){                 
    return 0;                                      
  }

  piratelevel = targ->GetLevel();        
  if(piratelevel > GetMaxLevel() ) { piratelevel = GetMaxLevel(); }  
  if(piratelevel < GetMinLevel() ) { piratelevel = GetMinLevel(); }  

  // there's a small range of values between curbstompable and curbstomping
  SetLevel( piratelevel + random(3) - random(3) );                  
  return ::eventEncounterShip(ship);  
}

// pirate will not level below this
void SetMinLevel(int level) {
  if (minLevel > 0) {
    minLevel = level;
  }
}
int GetMinLevel() {
  return minLevel;
}

// pirate will level up to this
void SetMaxLevel(int level) {
  if (maxLevel > 0 ) {
    maxLevel = level;
  }
}
int  GetMaxLevel() {
  return maxLevel;
}

// boarder attacks enemy pilot
int SetBoarder(string filename) {
  boarder = filename;
}
string GetBoarder() {
  if (boarder == "") return 0;
  return boarder;
}

// first mate guards the ship captain when boarded
int SetFirstMate(string filename) {
  firstMate = filename;
}
string GetFirstMate() {
  if (firstMate == "") return 0;
  return boarder;
}

// swabby assaults PASSENGERS on an enemy ship
int SetPassengerAttacker(string filename) {
  passengerAttacker = filename;
}
string GetPassengerAttacker() {
  if (passengerAttacker == "") return 0;
  return passengerAttacker;
}

// A lot of pirates like to start combat with "backstab"
// or "disarm". This allows that to be set if you want
// a backstabby guy. defaults to "kill".
int SetCombatStartVerb(string verb) {
  combatStartVerb = verb;
}
string GetCombatStartVerb() {
  if (combatStartVerb == "") return "kill";
  return combatStartVerb;
}

