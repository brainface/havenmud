#include <lib.h>
#include <daemons.h>
#include <domains.h>

inherit LIB_SHIPCAPTAIN;

int eventCheckPlayer();
int checkHostile(object who);

static void create() {
  ::create();
  SetKeyName("marauder");
  SetShort("a lizardman marauder");
  SetId( ({ "lizardman","marauder" }) );
  SetAdjectives( ({ "lizardman" }) );
  SetRace("lizardman");
  SetTown("Gwonish");
  SetClass("viking");
  SetSkill("projectile combat",1,1);
  SetLevel(10);
  SetGender("male");
  SetLong(
    "This young lizardman's black scales are covered in white paint "
    "in the semblance of ribs and bones. His skull-painted face shows "
    "no emotion, certainly not pity or remorse."
  );
  SetCaptainAggressiveness(110);
  SetAction(5, ({
    "!growl",
    "!snarl",
    "!emote gnashes his teeth violently.",
  }) );
  SetCombatAction(25, ({
    "!throw second javelin",
  }) );
  SetEncounter( (: eventCheckPlayer :) );
  SetFirstCommands( ({
    "wield first javelin",
  }) );
  SetInventory( ([
    INNERSEA_ENCOUNTERS "obj/javelin" : 4,
  ]) );
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
    || who->GetTown() == "lloryk")
  {
    SetAttack(who);
    return 1;
  }
  else return 0;
}

