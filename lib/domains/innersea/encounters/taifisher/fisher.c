#include <lib.h>
#include <domains.h>
#include <std.h>
#include <daemons.h>
inherit LIB_SHIPCAPTAIN;

static void create() {
  ::create();
  SetKeyName("tai fisherman");
  SetRace("human");
  SetBaseLanguage("Tai");
  SetGender("male");
  SetClass("merchant");
  SetShort("an old Tai fisherman");
  SetId( ({ "fisherman", }) );
  SetAdjectives( ({ "old", "tai" }) );
  SetLevel(10 + random(10));
  SetLong(
    "This local fisherman appears to have nothing more useful except his own fishing skills."
  );
  SetInventory( ([
    STD_FISH "pole" : "wield pole",
    ]) );
  SetAction(10, "!fish with pole");
  SetTown("Tairi");
  SetReligion("Taisoka");
}

