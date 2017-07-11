// you know what, fuck the "harhar they always kill you" leveling.
// now varies from level +2 to level +9
// -Mahk

#include <lib.h>
#include <daemons.h>
#include <domains.h>
#include <std.h>
inherit LIB_SHIPCAPTAIN;
int eventCheckPlayer();

string *towns = ({ });

static void create() {
  ::create();
  towns = ({ SAILING_D->GetTownArray()[random(sizeof(SAILING_D->GetTownArray()))],
    SAILING_D->GetTownArray()[random(sizeof(SAILING_D->GetTownArray()))] });
  SetKeyName("human captain");
  SetShort("a merchant captain (human)");
  SetId( ({ "captain", "merchant", "human" }) );
  SetAdjectives( ({ "merchant", "human" }) );
  SetRace("human");
  SetClass("sailor");
  //SetClass("merchant"); unavailable multiclass
  SetLevel(125);
  SetLong("This well clothed human merchant is very clean and well kept for "
    "spending most of his time on the sea. He is average size for a human and "
    "has a jagged scar across his left eye which is partially hidden with a "
    "eye patch.");
  SetGender("male");
  SetCaptainAggressiveness(0);
  SetShipWander(1);
  SetShipWimpy(40);
  SetInventory( ([
    INNERSEA_ENCOUNTERS "obj/eyepatch_silk" : "wear eyepatch",
    INNERSEA_ENCOUNTERS "obj/souwester" : "wear souwester",
    INNERSEA_ENCOUNTERS "obj/belaying_pin" : "wield pin",
    //STD_WEAPON + "sword" : "wield sword",
  ]) );
  SetCurrency("imperials", 2000);
  SetShipWanderPath(SAILING_D->GetTownDock(towns[0]), SAILING_D->GetTownDock(towns[1]));
}

string eventShipCombat(object *enemies) {
  float x;
        object myship = environment();
        object ship = enemies[random(sizeof(enemies))];
        x = (100.0 * myship->GetDamagePoints()) / myship->GetMaxDamagePoints();
        x = to_int(x); x += 200;
  if (!myship->GetWeaponSystem()) { return eventShipWander(); } /* I'm unarmed.  I should flee. */
  if (random(200) < x) { /* I am going to attack! */
    return "launch attack on " + ship->GetKeyName();
    }
  return eventShipWander(); /* I don't wanna be here anymore! */
}

int eventEncounterShip(object ship) {
  object targ;
  int piratelevel;

  targ = ship->GetPilot();
  if (!targ) { return ::eventEncounterShip(ship); }
    piratelevel = targ->GetLevel();
    if(piratelevel > 250 ) { piratelevel = 250; }
    SetLevel( piratelevel + random(8) + 2 );
  return ::eventEncounterShip(ship);
}

void heart_beat() {
  ::heart_beat();
  if (GetInCombat()) {
    eventForce("yell Repel the boarders!");
    if (GetHealthPoints() < (GetMaxHealthPoints() * 0.5)) {
      eventForce("yell The ship has fallen!  I'm going down with the ship!");
      eventForce("scuttle");
    }
  }
}

