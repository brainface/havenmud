//Illura@haven
//d4
//Nov 2010
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../oil.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("a hulking carcass");
  SetLong(
    "The only sight for miles along the horizon other than "
    "the rusty black sands is an enormous, decaying "
    "carcass of a long forgotten animal that once wandered "
    "here and was stuck in the shifting soils. Few predators "
    "have chanced by this feast in such a barren place, "
    "but much of it has sunk away. You can make out a few "
    "long bones, a massive horned head, and tentlike wings. "
    "The rest is too covered with sludge."
  );
  SetExits( ([
    "north" : OIL_ROOM "/d3",
    "south" : OIL_ROOM "/d5",
    "west" : OIL_ROOM "/c4",
    "east" : OIL_ROOM "/e4"
  ]) );
  SetItems( ([
    ({"carcass", "animal"}) : "It's hard to make out what this creature once was, but it was as big as a house and probably twice as nasty.",
    ({"oil", "sand", "sands", "soil", "sludge"}) : "The shifting oil ocean is all you can see in any direction from this landmark.",
    ({"bone", "bones"}) : "The bones are bleached white where they are not covered with black ooze.",
    ({"head"}) : "The horned head is weathered away and covered with ooze. It is also as big as a small cow.",
    ({"wing", "wings"}) : "The wings are shredded and useless. The poor beast could not use them to lift itself out of the ocean, nor can you use them to follow your dreams."
  ]) );
  SetItemAdjectives( ([
    "carcass" : ({"hulking", "enormous", "decaying", "long", "forgotten"}),
    "sands" : ({"rusty", "black", "shifting"}),
    "bone" : ({"long"}),
    "head" : ({"massive", "horned"}),
    "wing" : ({"tentlike"})
  ]) );
  SetListen( ([
    "default" : "The only sound is the deadly slow shift of the ooze.",
  ]) );
  SetSmell( ([
    "default" : "Nothing smells worse than thousand years dead monster.",
  ]) );
}
