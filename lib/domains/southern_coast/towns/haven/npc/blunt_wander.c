#include <lib.h>
#include <domains.h>
#include <std.h>
#include "/domains/southern_coast/towns/haven/haven.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("dwarven adventurer");
  SetShort("a short dwarven adventurer");
  SetId( ({ "dwarf", "adventurer" }) );
  SetAdjectives( ({ "dwarven", "short" }) );
  SetRace("dwarf");
  SetGender("male");
  SetClass("fighter");
  SetLevel(10 + random(10));
  SetLong("This short dwarf seems to be an adventurous type. Out to "
          "earn his way in the great world of Kailie with nothing but "
          "a trusty weapon to help him along his way.");
  SetInventory( ([
    STD_WEAPON "blunt/war-hammer" : "wield hammer",
    STD_CLOTHING "shirt/drab_shirt" : "wear shirt",
    STD_CLOTHING "pant/drab_pants" : "wear pants",
    ]) );
  SetAction(5, ({
    "!hum cheer",
    "!hum cheer", // Added these so he'd pray less often.
    "!hum cheer", // It was spoiling the fun when he did that all the time.
    "!hum cheer", // -Zedd
    "!hum cheer",
    "!whistle",
    "!whistle",
    "!whistle",
    "!whistle",
    "!whistle",
    }) );
  SetWanderSpeed(3);
  SetTown("Glimmerdin");
}

