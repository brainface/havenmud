#include <lib.h>
#include <domains.h>
#include "../averath.h";
inherit LIB_SHIPCAPTAIN;

static void create() {
  ::create();
  SetKeyName("ferry captain");
  SetId( ({ "ferrycaptain", "captain", "jean-luc", "jean", "vernier",
        "averath_person" }) );
  SetShort("Jean-Luc Vernier the Ferry Captain");
  SetLong(
    "The ferry boat captain looks perfectly bored in his work.  So bored that "
    "sympathy for him comes fast and hard to anyone who views his plight. "
    "He is completely bald."
  );
  SetAdjectives( ({ "ferry" }) );

  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Avera");
  SetReligion("Aetarin");
  // makes )many) ships not attack--mahkefel 2012
  AddReputation("Haven",550);

  SetMorality(125);
  //SetClass("fighter");
  SetClass("sailor");
  SetLevel(60);
  AddCurrency("ducats", random(100)+100);

  SetShipWanderPath(
    AVERATH_TOWNS "averath/room/wharf",
    SOUTHERN_COAST_TOWNS "haven/room/wharf",
  );
  SetFirstCommands( ({
    "board ferry",
    "yell All aboard!",
  }) );
  SetDirection(1);
  SetLimit(1);

  SetAction(6, ({ "!say Dolphins off the port bow!" }) );
  SetAction(10, ({ "!board first ferry" }) );
  SetInventory( ([
    AVERATH_OBJ "waistcoat" : "wear waistcoat",
    AVERATH_OBJ "cane" : "wield cane",
    AVERATH_OBJ "/hats/bowler" : "wear hat",
  ]) );
}

