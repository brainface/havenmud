#include <lib.h>
#include <domains.h>
inherit LIB_SHIPCAPTAIN;

static void create() {
  ::create();
  SetKeyName("viking captain");
  SetShort("a viking captain (goden)");
  SetId( ({ "captain", "viking", "goden" }) );
  SetAdjectives( ({ "viking", "goden" }) );
  SetRace("goden");
  SetTown("Keryth");
  SetClass("viking");
  SetLevel(80);
  SetLong(
    "This goden is a fierce killer, sailing the seas looking for plunder."
    );
  SetGender("female");
  SetCaptainAggressiveness(80);
  SetShipWander(1);
  SetLimit(2);
  SetFirstCommands("board first longship");
  SetMorality(-200);
  SetCurrency("senones",40 + random(40));
}
