#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "north" : GUROV_ROOM "cathedral2",
    "east"  : GUROV_ROOM "cathedral1",
    "west"  : GUROV_ROOM "cathedral4",
    "out"   : GUROV_ROOM "cemetery",    
    ]) );
  SetShort("the Cathedral of Three Gods");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong(
    "The foyer of the Cathedral of Three Gods is a mix of symbols and "
    "taste of the three major religions of Kailie. White marble pillars "
    "line the eastern wall, while the opposite wall is lined in thick "
    "pillars of blackest obsidian. Directly to the north the walls are "
    "something that looks vaguely like a grey stone, but seems to swirl "
    "loosely in some fashion."
    );
  SetItems( ([
    ({ "pillar", "pillars" }) : "The pillars that line the east wall "
            "are made of white marble while those on the left are "
            "made of obsidian.",
    ({ "wall", "walls" }) : "The northern walls are made of a swirling "
            "grey stone.",
    ({ "stone", }) : "The stone is grey and seems to swirl just out of "
               "the line of sight.",
    ({ "marble" }) : "The marble is bright white with colored hues within.",
    ({ "obsidian" }) : "The obsidian is a deep black, deeper than any "
             "rock should ever be.",
    ]) );
  SetItemAdjectives( ([
    "pillar" : ({ "marble", "obsidian", "west", "east", "white", "black" }),
    "wall"   : ({ "grey", "stone", }),
    "stone"  : ({ "grey", "swirling", }),
    "marble" : ({ "white", }),
    "obsidian" : ({ "black" }),
    ]) );
  SetListen("Faint whispers come from the east and west.");
  SetSmell("A funny smell comes from the north.");
}