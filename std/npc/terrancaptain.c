#include <lib.h>
#include <domains.h>
inherit LIB_SHIPCAPTAIN;

static void create() {
  ::create();
  SetKeyName("terran captain");
  SetShort("a terran captain");
  SetId( ({ "captain", "terran" }) );
  SetAdjectives( ({ "terran", }) );
  SetRace("human");
  SetTown("Terran");
 SetClass("sailor");
  SetLevel(80);
  SetLong(
    "This Terran is a contemplative sort, sailing the stars for the glory of Terra."
    );
  SetGender("male");
  SetCaptainAggressiveness(0);
  SetShipWimpy(40);
  SetShipWander(1);
  SetCurrency("credits", 12000);
}
