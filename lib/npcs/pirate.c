// mahkefel 2011:
//  AI include for more complicated ship encounters
//  essentially existing behaviors torn out of files
//  and put into 1 include, to make building these dudes
//  easier.

// These guys will not fight/sink:
//   coreligionists,
//   townsfolk,
//   or people with high rep in their towns.

// The also will not fight dudes:
//   less than 2/3 their level, or 1/3 again higher level than them.
//   (This is less to be newbie friendly and more to encourage passengers--
//    dudes spawning for the awesome ship captain won't fight his passengers,
//    chum cabin boys won't fight the awesome sea dog.)

#include <lib.h>

inherit LIB_SHIPCAPTAIN;

// eh, a fun message to greet friendlies.
string HailMessage = "Fair winds and cheap rum!";
string SetHailMessage(string words) {return HailMessage = words;}
string GetHailMessage() {return HailMessage;}

// do i scuttle the ship when it starts going
//  down? (merchant captains)
int ScuttlesShip = 0;

// increase this to make these dudes level
// above the player. At some point, high
// values become annoying and impossible
// +10 is doable, +25 is curbstomp
private int EncounterDifficulty;
void SetEncounterDifficulty(int level);
int  GetEncounterDifficulty();

// keeps track of boarders, to prevent
// 47 small goden pirates from piling up
object *pirates;

// pirate will not level below this
private int minLevel = 1;
void
SetMinLevel(int level);
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

// A lot of pirates like to start combat with "backstab"
// or "disarm". This allows that to be set if you want
// a backstabby guy. defaults to "kill".
private string combatStartVerb = "kill";
int    SetCombatStartVerb(string verb);
string GetCombatStartVerb();

// functions to limit the amount of boarders dude sends
// this is the Maximum TOTAL.
private int maxBoarders = 0;
private int sentBoarders = 0; // 1 if we've ever sent boarders.
void SetMaxBoarders(int number);
int GetMaxBoarders();

static void create() {
  ::create();
  SetEncounter( (:eventCheckPlayer:) );
  //SetProp(pirate) should equal whatever like, allegiance they have.
  // so liek merchants might be SetProperty("pirate","merchant")
  // godens would all be SetProperty("pirate","goden"), etc.
  // it's extremely redundant and should probably be removed, but it's
  // useful if something would have no town or religion (undead ships)
  SetProperty("pirate","pirate"); //gets all confused if there's no default here.
  pirates = ({ });
}

// By default, auto attack any player that shows up
// overwrite this function and call it to prevent i.e.
// Kylin sailors from killing anteky or whatever.
int eventCheckPlayer() {
  object who = this_player();
  object pirate;
  if (playerp(who)) {
    // don't attack citizens or co-religionists
    if (GetReligion() == who->GetReligion()
      && GetReligion() != "agnostic") {
     if(who->GetTestChar()) debug("Not killing believer");
     return 0;
    }
    if (GetTown() == who->GetTown()) {
      if(who->GetTestChar()) debug("Not killing townsman");
      return 0;
    }
    if (who->GetReputation(GetTown()) > 500)  {
      if(who->GetTestChar()) debug("I like this guy!");
      return 0;
    }
    if ( to_float( GetLevel() ) / who->GetLevel() > 1.33 ) {
      if(who->GetTestChar()) debug("This is not a fair fight!");
      eventForce("sneer " + who->GetKeyName());
      return 0;
    }
    if ( to_float( GetLevel() ) / who->GetLevel() < 0.67 )  {
      if(who->GetTestChar()) debug("I Don't wanna die!");
      eventForce("cringe " + who->GetKeyName());
      return 0;
    }
    if (who->GetTestChar()) debug("killing stranger");
    SetAttack(who);
    if ( GetFirstMate() ) {
      pirate = new( GetFirstMate() );
      pirate->SetLevel( to_int(who->GetLevel() * 0.9) );
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
    if ( !random(5) && GetBoarder()
      // if we have a limit to # of boarders total, and aren't over that limit
    && (GetMaxBoarders() == 0 || sentBoarders < GetMaxBoarders() ) ) {
      vic = ship->GetPilot();
      if (!vic) { return ::eventShipCombat(enemies); }
      pirates = filter(pirates, (: $1 :) );
      pirates = filter(pirates, (: living :) );
      if (sizeof(pirates) < 5 ) {
        piratelevel = vic->GetLevel();
        pirate = new( GetBoarder() );
        if(piratelevel > GetMaxLevel() ) { piratelevel = GetMaxLevel(); }
        if(piratelevel < GetMinLevel() ) { piratelevel = GetMinLevel(); }
        pirate->SetLevel( to_int(piratelevel * 0.9) + random(5) );
        pirate->eventMove(myship);
        pirates += ({ pirate });

        call_out( (: call_other, pirate,
          "eventForce", "out" :), 2 );
        call_out( (: call_other, pirate, "eventForce",
          "board first " + ship->GetUniqueVehicleId() :), 2);
        if (pirate->GetCombatStartVerb()) {
          call_out( (: call_other, pirate, "eventForce",
            pirate->GetCombatStartVerb() + " " + vic->GetKeyName() :), 2 );
        } else {
          call_out( (: call_other, pirate, "eventForce",
            "kill " + vic->GetKeyName() :), 2 );
        }
      sentBoarders++;
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
        pirate->SetLevel( to_int(piratelevel * 0.9) + random(3) );
        pirate->eventMove(myship);
        pirates += ({ pirate });
        call_out( (: call_other, pirate, "eventForce",
          "out" :), 2 );

        call_out( (: call_other, pirate, "eventForce",
          "board first " + ship->GetUniqueVehicleId() :), 2);
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

  // don't attack citizens or co-religionists
  if (GetReligion() == targ->GetReligion()
    && GetReligion() != "agnostic") {
    if(targ->GetTestChar()) debug("Not sinking coreligionist");
    eventForce("hail " + ship->GetUniqueVehicleId() + " " + GetHailMessage());
    return 0;
  }
  if (GetTown() == targ->GetTown()) {
    if(targ->GetTestChar()) debug("Not sinking townsman");
    eventForce("hail " + ship->GetUniqueVehicleId() +" " + GetHailMessage());
    return 0;
  }
  if (targ->GetReputation(GetTown()) > 500)  {
    if(targ->GetTestChar()) debug("I like this guy!");
    eventForce("hail " + ship->GetUniqueVehicleId() + " " + GetHailMessage());
    return 0;
  }
  
  if (ship->GetKeyName()=="dinghy") {
    if(targ->GetTestChar()) debug("Ha! You're on a liferaft!");
    eventForce("hail " + ship->GetUniqueVehicleId() + " Ha! You're not worth sinking now!" );
    return 0;	  
  }
  
  if(targ->GetTestChar()) debug("sinking stranger!");
  // mahkefel nov 2011 : changed captain to level depending on sailing,
  //  not level. So dudes not primary sailors don't just sink all the time.
  // Boarders will still equal opposing captains level, cuz they just fight with swords.
  //piratelevel = targ->GetLevel() + EncounterDifficulty;
  piratelevel = targ->GetSkillLevel("sailing") / 2 + EncounterDifficulty;
  if(piratelevel > GetMaxLevel() ) { piratelevel = GetMaxLevel(); }
  if(piratelevel < GetMinLevel() ) { piratelevel = GetMinLevel(); }

  if (targ->GetTestChar(1)) {
    debug("Encountered ship, setting level to: " + piratelevel);
    debug("target's level is: " + piratelevel);
  }

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

// pirate will add this to his level
void SetEncounterDifficulty(int level) {
  EncounterDifficulty = level;
}
int  GetEncounterDifficulty() {
  return EncounterDifficulty;
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
  return firstMate;
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

void heart_beat() {
  ::heart_beat();
  if (ScuttlesShip) {
    if (GetInCombat()) {
      eventForce("yell Repel the boarders!");
      if (GetHealthPoints() < (GetMaxHealthPoints() * 0.5)) {
        eventForce("yell The ship has fallen!  I'm going down with the ship!");
        eventForce("scuttle");
      }
    }
  }
}

// Limits the total # of boarders to ever send.
//   (They're always limited to 5 at once, this is for
//    "I only send 1 boarder, and he's awesome.")
void SetMaxBoarders(int number) {
  if (number > 0 && number < 10) {
    maxBoarders = number;
  }
}

int GetMaxBoarders() {
  return maxBoarders;
}

