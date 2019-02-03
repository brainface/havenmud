//  Dead forest entrance to Gothic Manor
//  Alessandra 2013-2014

#include <lib.h>
#include "../vamp.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("temperate");
  SetDayLight(-60);
  SetShort("a sinister forest path");
  SetLong(
     "The path continues to the northeast, southeast and southwest, "
     "the trees only just making way. There seems to be a small clearing "
     "just to the southwest. The ground shows no sign that "
     "anyone has traversed it before, dead and brittle leaves "
     "lay undisturbed. The trees are dense despite, for all "
     "appearances, being dead and long spindly branches reach "
     "out over the small pathway. The density of the tree branches "
     "and the misty fog that rolls through regularly, make it hard "
     "to determine whether it is night or day."
     );
  SetSmell( ([
     "default" : "The air smells stale here, like dirt and decayed leaves.",
     ]) );
  SetListen( ([
     "default" : "The soft ringing of bells or chimes is carried in on the wind.",
     ]) );
  SetItems( ([
     ({"path", "pathway", "trail"}) : "Surrounded by dense forest the small "
       "path wends its way to the northeast, southeast and southwest from here. "
       "Littered with dead leaves the ground seems strangely undisturbed. ",
     ({"forest"}) : "The trees appear to be mostly dead, long splintered "
       "branches reaching out into the pathway ominously. The forest as a "
       "whole is extremely dense and only the small trail seems to cut "
       "through it.",
     ({"tree", "trees"}) : "The trees appear to be mostly dead, long spindly "
       "branches reaching out into the path ominously. There are hundreds "
       "of them littering the forest and preventing passage in most directions. "
       "At a glance one or two give the impression of menacing faces, but "
       "surely it is a trick of the mind.",
     ({"face", "faces"}) : "At second glance nothing seems amiss.",
     ({"ground", "floor"}) : "The earthen forest floor is well packed as though "
       "heavily traveled at some point, but the dead and undisturbed layer of "
       "leaves would seem to suggest no one has been this way in quite some time."
       "At intervals a thin mist of grey fog settles near the ground.",
     ({"leaf", "leaves"}) : "Very few remain on the trees themselves and have found "
       "new home on the forest floor. Ranging from grey to a decayed yellow they "
       "appear to be the most lively part of the forest.",
     ({"branch", "branches"}) : "Long, spindly and sometimes splintered, the "
       "branches reach out from the tree trunks as if grasping; for what, you "
       "may never know.",
     ({"trunk", "trunks"}) : "The trunks of the dead trees are "
       "battered and worn. Lifeless husks that perhaps shouldn't "
       "still be standing.",
     ({"fog"}) : "Wisps of a grey fog wind gracefully around and between the "
       "trees, occasionally clearing up only to reappear and settle down near "
       "the ground.",
     ]) );
  SetItemAdjectives( ([
     "path" : ({"sinister", "small", "forest", "littered", }),
     "forest" : ({"sinister", "dark", "dense", "dead",}),
     "tree" : ({"dense", "dead", "spindly", "menacing"}),
     "face" : ({"menacing", "imaginary"}),
     "trunk" : ({"dead", "battered", "lifeless", "worn"}),
     "ground" : ({"dirt", "undisturbed", "earthen", "forest", "packed"}),
     "leaves" : ({"dead", "brittle", "yellow", "grey", "decayed"}),
     "branch" : ({"dead", "spindly", "dense", "splintered", "grasping"}),
     "fog" : ({"misty", "rolling", "dense"}),
     ]) );
  SetInventory( ([
     ]) );
  SetEnters( ([
     ]) );
  SetExits( ([
     "northeast" : VAMP_ROOM + "forest15",
     "southeast" : VAMP_ROOM + "forest13",
     "southwest" : VAMP_ROOM + "gypsycamp",
     ]) );

}
