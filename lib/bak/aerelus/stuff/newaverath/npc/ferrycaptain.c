#include <lib.h>
#include <domains.h>
inherit LIB_SHIPCAPTAIN;

static void create() {
  ::create();
  SetKeyName("Jean-Luc Vernier");
  SetId( ({ "ferrycaptain", "captain", "jean-luc", "jean", "vernier", 
  	"averath_person" }) );
  SetShort("Jean-Luc Vernier the Ferry Captain");
  SetLong(
    "The ferry boat captain looks perfectly bored in his work.  So bored that "
    "sympathy for him comes fast and hard to anyone who views his plight."
    "He is completely bald."
  );
  SetAdjectives( ({ "ferry" }) );

  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Avera");
  SetReligion("Aetarin");  
  AddCurrency("ducats", random(100));
  SetMorality(0);
  SetClass("fighter");
  SetClass("sailor");
  SetSkill("sailing", 1, 1);
  SetLevel(25);
  
  SetShipWanderPath(SOUTHERN_COAST_TOWNS "haven/room/wharf", 
    AVERATH_TOWNS "averath/room/wharf");
  SetFirstCommands("board ferry");
  SetDirection(1);
  SetLimit(1);
  
  SetAction(6, ({ "!say Dolphins off the port bow!" }) );  
}
