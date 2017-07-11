//  Dead forest path to Gothic Manor
//  Alessandra 2013

#include <lib.h>
#include "../vamp.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("outdoors");
  SetShort("a gated manor entrance");
  SetLong(
     "The trees give way at the end of the path here to a large, ornate "
     "iron gate. Beyond the gate appears to be a gravel walk with sprawling "
     "lawns on either side. A fence stretches out into the densely packed forest "
     "to the east and west. Between the trees and the fence there really appears "
     "to be no other way to enter the manor. The ground here is littered with dead "
     "and brittle leaves much like the paths before. The trees on either side of "
     "the path are dense despite, for all appearances, being dead and long spindly "
     "branches reach out over the pathway. The trails heads back towards the southwest."
     );
  SetSmell( ([
     "default" : "The air here is stale and smells of dirt and decay.",
     ]) );
  SetListen( ([
     "default" : "It is absolutely silent here.",
     ]) );
  SetItems( ([
     ({"path", "pathway", "trail"}) : "The path ends here at a large gate. "
       "Either side of the path is surrounded by dense forest and the small "
       "path wends its way bath to the southwest from here. Littered "
       "with dead leaves the ground seems strangely undisturbed.",
     ({"forest"}) : "The trees appear to be mostly dead, long splintered "
       "branches reaching out into the pathway ominously. The forest as a "
       "whole is extremely dense and only the small trail seems to cut "
       "through it. It appears to end at the northern gate.",
     ({"tree", "trees"}) : "The trees appear to be mostly dead, long spindly "
       "branches reaching out into the path ominously. There are hundreds "
       "of them littering the forest and preventing passage in most directions. "
       "At a glance one or two give the impression of menacing faces, but "
       "surely it is a trick of the mind.",
     ({"face", "faces"}) : "At second glance nothing seems amiss.",
     ({"ground", "floor"}) : "The earthen forest floor is well packed as though "
       "heavily traveled at some point, but the dead and undisturbed layer of "
       "leaves would seem to suggest no one has been this way in quite some time. "
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
     ({"gate"}) : "This is not a proper description.",
     ({"fence"}) : "This is not a proper description.",
     ]) );
  SetItemAdjectives( ([
     "path" : ({"sinister", "small", "forest", "littered", "traveled", "undisturbed"}),
     "forest" : ({"sinister", "dark", "dense", "dead"}),
     "tree" : ({"dense", "dead", "spindly", "menacing"}),
     "face" : ({"menacing", "imaginary"}),
     "trunk" : ({"dead", "battered", "lifeless", "worn"}),
     "ground" : ({"dirt", "earthen", "forest", "packed", "traveled", "undisturbed"}),
     "leaves" : ({"dead", "brittle", "yellow", "grey", "decayed"}),
     "branch" : ({"dead", "spindly", "dense", "splintered", "grasping"}),
     "fog" : ({"misty", "rolling", "dense"}),
     "gate" : ({"iron"}),
     "fence" : ({"iron"}),
     ]) );
  SetInventory( ([
     ]) );
  SetEnters( ([
     ]) );
  SetExits( ([
//     "north" : VAMP_ROOM + "courtyard",
     "southwest" : VAMP_ROOM + "forest8",
     ]) );

}
