#include <lib.h>
#include <domains.h>
inherit LIB_SHIPCAPTAIN;

static void create() {
  ::create();
  SetKeyName("wako captain");
  SetShort("a Tai wako captain (Tairi human)");
  SetId( ({ "captain", "wako", "human", }) );
  SetAdjectives( ({ "Tairi", "tairi", "Tai", "tai", "wako", "human"}) );
  SetRace("human");
  SetTown("Tairi");
  SetReligion("Taisoka");  
  SetBaseLanguage("Tai");
  SetClass("viking");
  SetLevel(30);
  SetLong(
    "A wako is a Tairi pirate.  They have no honor and prey upon unsuspecting "
    "foreigners at sea."
    );
  SetGender("male");
  SetCaptainAggressiveness(80);
  SetShipWander(1);
  SetCurrency("koken", 20000);
}

