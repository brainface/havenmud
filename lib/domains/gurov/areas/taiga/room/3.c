//Illura@haven
//Room 3
//August 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../taiga.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("Within a boreal forest");
  SetLong(
    "Mosses and lichens take the place of grasses in this "
    "taiga that sprang up millenia ago from the permafrost. "
    "Stubborn oak and larch trees hold firmly to the thin soil "
    "that is literally strewn with needles from thousands of "
    "ancient pine and spruce trees. The forest extends in all "
    "directions, some ways perhaps too thick to traverse."
  );
  SetExits( ([
    "north" : TAIGA_ROOM "6",
    "west" : TAIGA_ROOM "2",
  ]) );
  SetItems( ([
    ({"moss", "lichen"}) : "Green mosses and lichens cover the forest floor.",
    "permafrost" : "The soil a few inches down is probably hard-frozen.",
    ({"oak", "larch", "pine", "spruce", "trees"}) : "Old, small-leafed trees grow among the larger firs.",
    "soil" : "A thin layer above permafrost.",
    "needles" : "Pine needles are strewn everywhere."
  ]) );
  SetItemAdjectives( ([
    "soil" : "thin",
    "trees" : ({"ancient", "stubborn"}),
  ]) );
  SetInventory( ([
    TAIGA_NPC + "dormouse" : 3,
    TAIGA_NPC + "weasel" : 2,
  ]) );
  SetListen( ([
    "default" : "Trees block most of the taiga winds.",
  ]) );
  SetSmell( ([
    "default" : "The rich smell of moss cuts through the chill air.",
  ]) );
}
