// Mahkefel 2010
//   lizardman "ferry captain"
//   raids lloryk, then returns
#include <lib.h>
#include <daemons.h>
#include <domains.h>

inherit LIB_SHIPCAPTAIN;

int eventCheckPlayer();
int checkHostile(object who);

object *pirates;

static void create() {
  ::create();
  SetKeyName("izzik");
  SetShort("Izzik the Raider (lizardman)");
  SetId( ({ "izzik","raider","lizardman" }) );
  SetAdjectives( ({ "izzik","the","raider","lizardman" }) );
  SetRace("lizardman");
  SetClass("viking");
  SetSkill("projectile combat",1,1);
  SetLevel(15);
  SetGender("male");
  SetLong(
    "This vicious looking lizardman seems ready for a fight. "
    "He occasionally glances at a simple compass and eagerly "
    "watches the shoreline."
  );
  SetAction(5, ({
    "!yell To Lloryk! The halflings won't know what hit them!",
    "!yell Grab a spear and ready to fight!",
  }) );
  SetCaptainAggressiveness(110);
  SetCombatAction(25, ({
    "!throw second javelin",
  }) );
  SetEncounter( (: eventCheckPlayer :) );
  SetFirstCommands( ({
    "board canoe",
    "wield first javelin",
    "yell Lloryk is ripe for plunder! Board and join the fight!",
  }) );
  SetAction(10, ({ "!board first canoe" }) );
  SetInventory( ([
    INNERSEA_ENCOUNTERS "obj/javelin" : 4,
  ]) );
  SetShipWanderPath(
    CRYSTAL_REACHES_TOWNS "gwonish/room/gw01",
    CRYSTAL_REACHES_TOWNS "lloryk/room/wharf"
  );
  pirates = ({ });
}

int eventEncounterShip(object ship) {
  object targ;
  int piratelevel;
  targ = ship->GetPilot();
  if (!targ) { return ::eventEncounterShip(ship); }
  if (!checkHostile(targ)) return 0;
  return ::eventEncounterShip(ship);
}

int eventCheckPlayer() {
  object who = this_player();
  return checkHostile(who);
}

int checkHostile(object who) {
  if( who->GetRace() == "halfling" 
    || who->GetTown() != "lloryk")
  {
    SetAttack(who);
    return 1;
  }
  else return 0;
}

string eventShipCombat(object *enemies) {
  object pirate;
  object vic;
  float x;
  object myship = environment();
  object ship;
  int piratelevel;
  foreach(object e in enemies) {
   if (e) if (e->GetPilot())
   if (e->GetPilot()->GetProperty("pirate")) enemies -= ({ e });
  }
  if(sizeof(enemies) == 0) { return ::eventShipWander(); }
    ship = enemies[random(sizeof(enemies))];
    x = (100.0 * myship->GetDamagePoints()) / myship->GetMaxDamagePoints();
    x = to_int(x); x -= ShipWimpy; x += CaptainAggressiveness;
  if (random(200) < x) { /* I am going to attack! */
   if (!random(5)) {
    vic = ship->GetPilot();
    //if (!vic) { return ::eventShipCombat(enemies); }
    pirates = filter(pirates, (: $1 :) );
    pirates = filter(pirates, (: living :) );
    if (sizeof(pirates) < 5) {
      piratelevel = 10;
      pirate = new( INNERSEA_ENCOUNTERS "lizardcanoe/liz_boarder" );
      pirate->SetLevel( piratelevel );
      pirate->eventMove(myship);
      pirates += ({ pirate });
      call_out( (: call_other, pirate, "eventForce", "out" :), 2 );
      call_out( (: call_other, pirate, "eventForce", "board " + ship->GetName() :), 2 );
      if (vic) call_out( (: call_other, pirate, "eventForce",
        "throw second spear at " + vic->GetKeyName() :), 2 );
      return "yell take the ship men, leave no survivors! ";
    }
   }
  }
  return ::eventShipCombat(enemies);
}

