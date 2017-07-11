#include <lib.h>
#include <domains.h>
#include <std.h>
#include <damage_types.h>
inherit LIB_SHIPCAPTAIN;
int eventCheckPlayer();

static void create() {
  ::create();
  SetKeyName("elf marine");
  SetShort("an elven marine");
  SetId( ({ "marine", "elf" }) );
  SetAdjectives( ({ "marine", "elf", "elven" }) );
  SetRace("elf");
  SetClass("sailor");
  SetClass("fighter");
  SetLevel(125);
  SetLong("This tall, sturdy elf is covered in blood and scars. He appears to be "
    "tough and is no stranger to battle, with bulging muscles and a fresh scar on his "
    "forehead. On his left breast he has a tattoo of a dragon wrapping around a "
    "balance.");
  SetGender("male");
  SetCaptainAggressiveness(110);
  SetProperty("elfcaptain", 1);
  SetShipWander(1);

  SetInventory( ([
    STD_WEAPON + "sword" : "wield sword",
  ]) );
  SetCurrency("imperials", 2000);
  SetSkill("enchantment", 100);
  SetEncounter( (:eventCheckPlayer:) );
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
}

int eventEncounterShip(object ship) {
  object targ;
  targ = ship->GetPilot();
  if(targ->GetNationality() == "Haven" || targ->GetRace() == "elf" || targ->GetReligion() == "Kylin" ){
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
  if (random(200) < x) { /* I am going to attack! */
   if (!random(5)) {
    vic = ship->GetPilot();
    if (!vic) { return ::eventShipCombat(enemies); }
    piratelevel = vic->GetLevel();
    pirate = new( INNERSEA_ENCOUNTERS + "havenelf/elfmarine" );
    if(piratelevel > 150 ) { piratelevel = 150; }
    pirate->SetLevel( piratelevel + 25);
    pirate->eventMove(myship);
    call_out( (: call_other, pirate, "eventForce", "out" :), 2 );
    call_out( (: call_other, pirate, "eventForce", "board " + ship->GetName() :), 2 );
    call_out( (: call_other, pirate, "eventForce", "disarm " + vic->GetKeyName() :), 3 );
    return "Yell take the enemy ship, destroy the heathens! ";
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
    if(piratelevel > 150 ) { piratelevel = 150; }
    SetLevel( piratelevel + 25 );
    eventForce("disarm " + who->GetKeyName());
    return 1;
  }
  else return 0;
}
