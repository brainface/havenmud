//mahkefel '10: gave unique description
#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <domains.h>
inherit LIB_SHIPCAPTAIN;

static void create() {
  ::create();
  SetRace("goden");
  SetGender("male");
  SetClass("rogue");
  SetClass("sailor");
  SetLevel(1);
  SetKeyName("pirate");
  SetId( ({ "pirate" }) );
  SetShort("a small goden pirate");
  SetAdjectives( ({ "goden", "small" }) );
  SetLong(
    "This goden sailor is of relatively short stature, but he possesses "
    "a nervous agility and lithe build that suggest him a dangerous combatant "
    "in close quarters."
  );
  SetAction(1, ({
    "!emote stares around confidently.",
    "!emote eyes your purse.",
  }) );
  SetCurrency("crystals", 500 + random(500) );
  SetInventory( ([
    INNERSEA_ENCOUNTERS + "obj/rigging_knife" : "wield knife",
    INNERSEA_ENCOUNTERS + "obj/motley_breeches" : "wear breeches",
  ]) );
  SetCaptainAggressiveness(80);
  SetResistance(ALL_PHYSICAL, "medium");
  SetResistance(ALL_ELEMENTS|MAGIC,"high");
  SetProperty("pirate", 1);
  SetShipWander(1);
  SetCurrency("senones", 20000);
}

// level self when encountering player
int eventEncounterShip(object ship) {
  object targ;
  int piratelevel;

  targ = ship->GetPilot();
  if (!targ) { return ::eventEncounterShip(ship); }
  if(targ->GetProperty("pirate")){
    return 0;
  }

  piratelevel = targ->GetLevel() * 0.667;
  if(piratelevel > 180 ) { piratelevel = 180; }
  SetLevel( piratelevel + 25 );
  return ::eventEncounterShip(ship);
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
    if (!vic) { return ::eventShipCombat(enemies); }
    piratelevel = vic->GetLevel() * 0.667;
    pirate = new( "/domains/innersea/encounters/pirate/piratemen" );
    if(piratelevel > 180 ) { piratelevel = 180; }
    pirate->SetLevel( piratelevel + 5);
    pirate->eventMove(myship);
    call_out( (: call_other, pirate, "eventForce", "out" :), 2 );
    call_out( (: call_other, pirate, "eventForce", "board " + ship->GetName() :), 2 );
    call_out( (: call_other, pirate, "eventForce", "backstab " + vic->GetKeyName() :), 3 );
    return "Yell take the ship men, leave no survivors! ";
   }
  }
  return ::eventShipCombat(enemies);
}

