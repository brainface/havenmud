#include <lib.h>
#include <std.h>
#include <domains.h>
inherit LIB_SHIPCAPTAIN;

static void create() {
  ::create();
  SetKeyName("Tai fisherman");
  SetShort("a Tai peasant fisherman");
  SetId( ({ "peasant", "fisherman" }) );
  SetAdjectives( ({ "tai", "peasant" }) );
  SetRace("human");
  SetTown("Tairi");
  SetBaseLanguage("Tai");
  SetClass("sailor"); /* I'm cheating here. */
  SetLevel(8);
  SetLong(
    "This lowly fisherman sails the Tai sea plying his trade."
    );
  SetGender("male");
  SetCaptainAggressiveness(0);
  SetShipWimpy(40);
  SetShipWander(1);
  SetInventory( ([
    STD_FISHING "pole" : "wield pole",
    ]) );
  SetAction(5, ({ "fish with my first pole" }) );
}
