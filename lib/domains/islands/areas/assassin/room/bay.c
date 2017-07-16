#include <lib.h>
#include <std.h>
#include <domains.h>
inherit LIB_FISHING;

static void  create() {
  ::create();
  SetExits( ([
    "east"      : INNERSEA_VIRTUAL "ocean/112,-299",
    "west"      : ISLANDS_AREAS "assassin/room/path1",
    ]) );
  SetClimate("sub-tropical");
  SetShort("the Bay at Assassin Isle");
  SetProperty("coastal", 1);
  SetSpeed(5);
  SetMaxFishing(5);
  SetChance(10);
  SetFish( ([
    DIR_STD "fish/guppy" : 20,
    DIR_STD "fish/trout" :  5,
    ]) );  
  SetDayLong(
    "This sandy bay is a pleasant harbor that appears safe from most "
    "of the storms that plague this area of the ocean. To the west, a "
    "small path leads deeper in to the island, while to the east the "
    "ocean stretchs out endlessly. The sunlight shines down on the "
    "gentle waves, making the island a beautiful sub-tropical paradise."
    );
  SetNightLong(
    "This sandy bay is a pleasant harbor that appears safe from most "
    "of the storms that plague this area of the ocean. To the west, a "
    "small path leads deeper in to the island, while to the east the "
    "ocean stretchs out endlessly. The starlight glitters down on the "
    "gentle waves, making the waves twinkle with their rippling movement."
    );  
  SetSmell("The pleasant smells of the beach mix with the smells of fruits and trees.");
  SetListen("The lapping of the waves on the beach is a calming sound.");
  SetInventory( ([
    ISLANDS_AREAS "assassin/npc/shipseller" : 1,
    ]) );
}
