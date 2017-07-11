// changed by Mahkefel 2010
//    made level to player, up to level 300
//    cleaned up some behavior
//    fucker will only call his minions from the hold on
//      his own damn ship.
//    added awesome weapon
#include <lib.h>
#include <domains.h>
#include <std.h>
#include <damage_types.h>
#include <domains.h>
inherit LIB_SHIPCAPTAIN;
int eventCheckPlayer();
void DoAction();

static void create() {
  ::create();
  SetKeyName("skeletal captain");
  SetShort("a skeletal captain (undead)");
  SetId( ({ "captain", "pirate", "human", "undead" }) );
  SetAdjectives( ({ "pirate", "human", "skeletal", "undead" }) );
  SetRace("human");
  SetClass("viking");
  SetSkill("enchantment", 1, 1);
  SetUndead(1);
   SetLevel(150);
  SetLong(
    "This unsightly creature used to be a human pirate. Now undead, he is "
    "composed almost entirely of bone, save a few scraps of tattered, dead "
    "skin. Lacking any recognizable physical features, he is identifiable as "
    "captain by a black eyepatch over his right eye socket."
    );
  SetGender("male");
  SetCaptainAggressiveness(110);
  SetProperty("undeadpirate", 1);
  SetShipWander(1);
  SetInventory( ([
    DOMAIN_INNERSEA "encounters/undead/captain_cutlass" : "wield shimmering cutlass",
    DOMAIN_INNERSEA "encounters/undead/cutlass" : "wield rusty cutlass",
  ]) );
  SetFirstCommands( ({ "wield all" }) );
  SetCurrency("imperials", 2000);
  SetEncounter( (:eventCheckPlayer:) );
  SetCombatAction(35, (: DoAction :) );
  SetNoCorpse(1);
  SetDie("The pirate turns to dust and disperses on the wind.");
  SetResistance(ALL_PHYSICAL|MAGIC, "medium");
  SetResistance(ALL_ELEMENTS, "high");
  SetResistance(COLD|POISON|HUNGER|DISEASE, "immune");
}

// encounter ships that aren't undead,
// and level self to player level +5 (max 300)
int eventEncounterShip(object ship) {
  object targ;
  int piratelevel;

  targ = ship->GetPilot();
  if (!targ) { return ::eventEncounterShip(ship); }

  if(targ->GetProperty("undeadpirate")){
    return 0;
  }


  piratelevel = targ->GetLevel(); // even a +5 makes this bastard unescapable.
  if(piratelevel < 150) { piratelevel = 150; }
  if(piratelevel > 300) { piratelevel = 300; }
  SetLevel( piratelevel );
  return ::eventEncounterShip(ship);
}

string eventShipCombat(object *enemies) {
  object pirate;
  object vic;
  float x;
  object myship = environment();
  object ship;
    foreach(object e in enemies) {
      if (e) if (e->GetPilot())
        if (e->GetPilot()->GetProperty("undeadpirate")) enemies -= ({ e });
        }
   if(sizeof(enemies) == 0) { return ::eventShipWander(); }
  ship = enemies[random(sizeof(enemies))];
        x = (100.0 * myship->GetDamagePoints()) / myship->GetMaxDamagePoints();
        x = to_int(x); x -= ShipWimpy; x += CaptainAggressiveness;
  if (random(200) < x) { /* I am going to attack! */
   if (!random(3)) {
    vic = ship->GetPilot();
    if (!vic) { return ::eventShipCombat(enemies); }
    pirate = new( "/domains/innersea/encounters/undead/skeletonpirates" );
    pirate->SetLevel( vic->GetLevel() + 5);
    pirate->eventMove(myship);
    call_out( (: call_other, pirate, "eventForce", "out" :), 2 );
    call_out( (: call_other, pirate, "eventForce", "board " + ship->GetName() :), 2 );
    call_out( (: call_other, pirate, "eventForce", "backstab " + vic->GetKeyName() :), 3 );
    return "yell take the ship men, leave no survivors! ";
   }
  }
  return ::eventShipCombat(enemies);
}

varargs int eventDie(object agent) {
  if (agent) agent->AddTitle("the Despoiler of the Black Night");
  return ::eventDie(agent);
}

int eventCheckPlayer() {
    object who = this_player();
    object pirate;
    if (playerp(who)) {
      SetAttack(who);
      pirate = new( DOMAIN_INNERSEA "encounters/undead/skeletonpirates" );
      pirate->SetLevel( who->GetLevel() - 20 );
      pirate->eventMove(environment());
      pirate->eventForce("backstab " + who->GetKeyName());
      return 1;
  }
  else return 0;
}

void DoAction() {
  object who = this_object();
  object pirate;
  if (environment()) {
    if (!environment()->GetKeyname("black night")) {
      return;
    }
  }
  message("enter", "An undead pirate rushes to the aid "
    "of the Captain.", environment(who));
  pirate = new( DOMAIN_INNERSEA "encounters/undead/skeletonpirates" );
  pirate->SetLevel( who->GetLevel() - 20);
  pirate->eventMove(environment());
  call_out( (: call_other, pirate, "eventForce", "yell protect the captain!" :), 2 );
}
