#include <lib.h>
#include <domains.h>
#include <std.h>
#include <damage_types.h>
inherit LIB_SHIPCAPTAIN;
int eventCheckPlayer();
void DoAction();
object *pirates;

static void create() {
  ::create();
  SetKeyName("handsome captain");
  SetShort("a handsome captain (elf)");
  SetId( ({ "captain", "elf" }) );
  SetAdjectives( ({ "captain", "elf", "handsome" }) );
  SetRace("elf");
  SetClass("sailor");
  SetClass("fighter");
  SetLevel(125);
  SetLong("This tall, sturdy elf has an air of authority that suggests he his a "
    "capable leader, worthy of commanding the crew of his ship. He seems no "
    "stranger to battle, with bulging muscles and a fresh scar on his "
    "forehead.");
  SetGender("male");
  SetSkill("enchantment", 100);
  SetCaptainAggressiveness(110);
  SetProperty("elfcaptain", 1);
  SetShipWander(1);
  SetInventory( ([
    STD_WEAPON + "sword" : "wield sword",
  ]) );
  SetCurrency("imperials", 2000);
  SetEncounter( (:eventCheckPlayer:) );
  SetCombatAction(15, (: DoAction :) ); 
  SetResistance(WATER, "low");
  SetResistance(COLD, "high");
  SetResistance(HEAT, "immune");
  SetResistance(ACID, "high");
  SetResistance(GAS, "high");
  SetResistance(SHOCK, "medium");
  SetResistance(POISON, "high");
  SetResistance(MAGIC, "immune");
  SetResistance(BLUNT, "medium");
  SetResistance(SLASH, "medium");
  SetResistance(PIERCE, "medium");
  SetResistance(HUNGER, "low");
  SetResistance(DISEASE, "medium");
  pirates = ({ });
}

int eventEncounterShip(object ship) {
  object targ;
  targ = ship->GetPilot();
  if(targ->GetNationality() == "Haven" || targ->GetRace() == "elf" || targ->GetReligion() == "Kylin" ){
    return 0;
  }
  if(targ->id("jean-luc")) {
    return 0;
  }
  if(targ->id("chartercaptain")) {
    return 0;
  }
  if(targ->id("ferry captain")) {
    return 0;
  }
  return ::eventEncounterShip(ship);
}

string eventShipCombat(object *enemies) {
  object pirate;
  object vic;
  float x;
  int piratelevel;
  object myship = environment();
  object ship;
    foreach(object e in enemies) {
      if (e) if (e->GetPilot())
        if (e->GetPilot()->GetProperty("elfcaptain")) enemies -= ({ e });
        }
   if(sizeof(enemies) == 0) { return ::eventShipWander(); }
  ship = enemies[random(sizeof(enemies))];
        x = (100.0 * myship->GetDamagePoints()) / myship->GetMaxDamagePoints();
        x = to_int(x); x -= ShipWimpy; x += CaptainAggressiveness;
  pirates = filter(pirates, (: $1 :) );
  pirates = filter(pirates, (: living :) );        
  if (random(200) < x) { /* I am going to attack! */
   if (!random(5)) {
    vic = ship->GetPilot();
    if (!vic) { return ::eventShipCombat(enemies); }
    piratelevel = vic->GetLevel();
    if (sizeof(pirates) < 5) {
      pirate = new( "/domains/innersea/encounters/havenelf/elfmarine");
      if(piratelevel > 150 ) { piratelevel = 150; }
      pirate->SetLevel( piratelevel + 25);
      pirate->eventMove(myship);
      call_out( (: call_other, pirate, "eventForce", "out" :), 2 );
      call_out( (: call_other, pirate, "eventForce", "board " + ship->GetName() :), 2 );
      call_out( (: call_other, pirate, "eventForce", "disarm " + vic->GetKeyName() :), 3 );
      }
    return "Yell take the enemy ship, more ships for the holy fleet! ";
   }
  }
  return ::eventShipCombat(enemies);
}

int eventCheckPlayer() {
    object who = this_player();
    object pirate;
    int piratelevel;
    if (playerp(who)) {
    SetAttack(who);
    piratelevel = who->GetLevel();
    pirate = new( "/domains/innersea/encounters/havenelf/elfmarine");
    if(piratelevel > 150 ) { piratelevel = 150; }
    SetLevel( piratelevel + 25 );
    pirate->SetLevel( piratelevel + 25);
    pirate->eventMove(environment());
    pirate->eventForce("disarm " + who->GetKeyName());
    return 1;
  }
  else return 0;
}

void DoAction() {

        object who = this_object();
        object pirate;
        int piratelevel;
        message("enter", "An elf marine rushes to the aid "
                "of the Captain.", environment(who));
        piratelevel = who->GetLevel();
        pirate = new( "/domains/innersea/encounters/havenelf/elfmarine");
        if(piratelevel > 150 ) { piratelevel = 150; }
        pirate->SetLevel( piratelevel + 25);
        pirate->eventMove(environment());
        call_out( (: call_other, pirate, "eventForce", "yell protect the captain!" :), 2 );
        }
