// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../karak.h"

inherit LIB_FISHING;

static void create() {
  ::create();
  SetProperty("coastal", 1);
  SetShort("the shores of the Ruined Sea");
  SetLong(
    "The dirt road through Karak ends here, at the shores of the "
    "Ruined Sea. Darkened waters, tinged with red, extend to all "
    "horizons. The turbulent waters offer no solace to the wounded "
    "soul and the dark deep of the ocean offers no guarantee of "
    "riches. To the north lies the town of Karak, and beyond that "
    "the road from Haven to the Crystal Reaches. A small building sit to "
    "the east, displaying a sign that suggests it is an inn."
  );
  SetItems( ([
    ({ "shore", "shores" }) : (: GetLong :),
    ({ "road" }) : "This dirt road leads north, to Karak.",
    ({ "ocean", "sea", "water" }) : "Waves roil the waters of the Ruined "
    "Sea, tossing its blood-tinged waters upon the shore. Spray "
    "from the waves launches in to the air and perfumes it with "
    "tangy salt.",
    ({ "inn", "building" }) : "The building to the east appears to be an inn.",
  ]) );
  SetItemAdjectives( ([
    "shore" : ({ "ruined", "sea", "of", "the" }),
    "road" : ({ "dirt", "karak", "north" }),
    "ocean" : ({ "ruined", "turbulent", "darkened", "blood-tinged", "dark",
    "darkened", "deep", "red", "blood" }),
    "inn" : ({ "small", "east", "eastern" }),
  ]) );
  SetListen( ([
    "default" : "The roar of the ocean waves echos through the area."  
  ]) );
  SetSmell( ([
    "default" : "The salty tang of the ocean fills the air."
  ]) );
  SetInventory( ([
    KARAK_NPC + "ship_trainer"  : 1,
    KARAK_NPC + "ship_seller"   : 1,
    KARAK_NPC + "leader_viking" : 1,
  ]) );
  SetEnters( ([
    ({ "inn", "building" }) : KARAK_ROOM + "player_inn",
  ]) );
  SetExits( ([
    "north" : KARAK_ROOM + "rd6",
    "south" : INNERSEA_VIRTUAL + "ocean/-68,-2",
  ]) );
  SetSpeed(5);
  SetFish( ([
    DIR_STD "fish/guppy" : 100,
    DIR_STD "fish/trout" : 50,
    DIR_STD "fish/boot" : 1,
    ]) );
  SetChance(25);
  SetMaxFishing(4);
}
