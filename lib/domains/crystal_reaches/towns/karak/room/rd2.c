// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

int PreExit();

static void create() {
  room::create();
  SetShort("the Karak Road");
  SetLong(
    "This is the northern edge of the city of Karak. From here "
    "a dirt road leads north towards the main road between Haven "
    "and the Crystal Reaches. It also continues south, to the city "
    "of Karak. A matched pair of buildings stand to either side "
    "of the road, their entrances facing towards each other. They "
    "differ from the wooden buildings of the rest of Karak in "
    "being formed mostly of stone, with a parapet along the edge of "
    "the roof, designed to protect archers."
  );
  SetItems( ([
    ({ "road" }) : "This is a simple and plain dirt road which connects "
    "the city of Karak with the main road from Haven to the Crystal "
    "Reaches.",
    ({ "buildings", "barracks" }) : "Rather than being built of plain "
    "wood, as most of Karak is, this pair of buildings was constructed "
    "of stone and appear more fortified than the others. Given their "
    "location and construction, these are probably the city barracks, "
    "designed for defense of the town. Above the entrance to the eastern "
    "one is an axe, while the western one bears the symbol of a rock that "
    "has been split in half.",
    ({ "axe", "rock", "symbol", "symbols" }) : "These symbols represent "
    "the orc's view of themselves, as the axe which can cleave all of "
    "their enemies in two. Because of their love of assaulting fortified "
    "cities, their enemies are most often represented as a rock which "
    "is split asunder.",
    ({ "east barracks", "eastern barracks", "east building", 
    "eastern building", "axe barracks" }) : "The eastern half of the "
    "paired barracks is identical to the western one, except for the "
    "symbol of an axe displayed above its entrance.",
    ({ "west barracks", "western barracks", "west building", 
    "western building", "rock barracks" }) : "The western half of the "
    "paired barracks is identical to the eastern one, except for the "
    "symbol of a shattered rock displayed above its entrance.",
  ]) );
  SetItemAdjectives( ([
    "road" : ({ "dirt", "plain", "simple", "main", "karak", "connecting" }),
    "buildings" : ({ "pair", "of", "paired", "stone", "nearby", "matched",
    "fortified" }),
    "axe" : ({ "entrance", "carved", }),
  ]) ),
  SetSmell( ([
    "default" : "Dirt stirred up from the road hangs in the air.",
  ]) );
  SetListen( ([
    "default" : "Occasional grunts and clangs rent the air, seeming to come "
    "from the barracks on either side of the road.",
  ]) );
  SetInventory( ([
    KARAK_NPC + "soldier" : 2,
  ]) );
  SetExits( ([
    "south" : KARAK_ROOM + "rd3",
  ]) );
  SetEnters( ([
    "east barracks" : KARAK_ROOM + "barracks_e",
    "west barracks" : KARAK_ROOM + "barracks_w",
  ]) );
  AddExit("north", KARAK_ROOM + "rd1.c", (:PreExit :) );
}


int PreExit() {
  if (this_player()->id("karak_wander")) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}

