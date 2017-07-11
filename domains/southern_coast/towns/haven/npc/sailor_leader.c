#include <lib.h>
#include "../haven.h"
#include <std.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetTown("Haven");
  SetLimit(1);
  SetRace("elf");
  SetGender("male");
  SetClass("sailor");
  SetMorality(100);
  SetLevel(20);
  SetKeyName("Padagon");
  SetId( ({ "padagon", "sailor", }) );
  SetAdjectives( ({ "elven", "ocean" }) );
  SetShort("Padagon the Elven Ocean Sailor");
  SetLong(
    "Padagon is a stately elf. His stories of the sea regale "
    "the young of the town, and some even elect to take up the life of "
    "the sea."
    );
  SetPlayerTitles( ([
    "newbie" : "the Seafarer",
    "mortal" : "the Waverunner",
    "hm"     : "Captain $N",
    "legend" : "the Sunrise of the Sea",
    "avatar" : "the Flowing Wave",
    ]) );
  SetCurrency("imperials", 30 + random(30) );
  SetInventory( ([
    STD_WEAPON + "slash/longsword" : "wield longsword",
    ]) );
  SetFreeEquipment( ([
    STD_WEAPON "slash/longsword" : 1,
    ]) );
}
