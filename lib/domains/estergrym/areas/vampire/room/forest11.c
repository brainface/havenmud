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
     "The trees are dense despite, for all appearances, being dead and long "
     "spindly branches reach out over the small trail. The density of the "
     "tree branches and the misty fog that rolls through regularly, make it hard "
     "to determine whether it is day or night. The path continues to the north "
     "and southeast, the trees only just making way. The ground here is littered with "
     "dead and brittle leaves much like the rest of the path but have been "
     "trampled in places. There are tracks of some sort of animal here." 
     );
  SetSmell( ([
     "default" : "The smell of upturned earth and old leaves permeates "
     "the air.",
     ]) );
  SetListen( ([
     "default" : "The howling of animals can be heard faintly.",
     ]) );
  SetItems( ([
     ({"path", "pathway", "trail"}) : "Surrounded by dense forest the small "
       "path wends its way to the north and southeast from here. Littered "
       "with dead leaves which have been trampled and scattered, the ground "
       "here has been disturbed by some sort of animal. Strange since the rest "
       "of the path seemed untouched.",
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
       "heavily traveled. The dead and yellowed layer of leaves has been "
       "disturbed at this section of the trail. The tracks seem to suggest "
       "a large animal or several large animals have passed through recently. "
       "At intervals a thin mist of grey fog settles near the ground.",
     ({"leaf", "leaves"}) : "Very few remain on the trees themselves and have found "
       "new home on the forest floor. Ranging from grey to a decayed yellow they "
       "appear to be the most lively part of the forest. Here they have been trampled "
       "and some appear broken or torn.",
     ({"branch", "branches"}) : "Long, spindly and sometimes splintered, the "
       "branches reach out from the tree trunks as if grasping; for what, you "
       "may never know.",
     ({"trunk", "trunks"}) : "The trunks of the dead trees are "
       "battered and worn. Lifeless husks that perhaps shouldn't "
       "still be standing.",
     ({"fog"}) : "Wisps of a grey fog wind gracefully around and between the "
       "trees, occasionally clearing up only to reappear and settle down near "
       "the ground.",
     ({"track", "tracks", "print", "prints"}) : "They appear to be large paw "
       "prints of some sort. There doesn't seem to be any sort of pattern or "
       "clear direction in which they are pointing.",
     ]) );
  SetItemAdjectives( ([
     "path" : ({"sinister", "small", "forest", "littered", "trampled", "traveled", "disturbed"}),
     "forest" : ({"sinister", "dark", "dense", "dead"}),
     "tree" : ({"dense", "dead", "spindly", "menacing"}),
     "face" : ({"menacing", "imaginary"}),
     "trunk" : ({"dead", "battered", "lifeless", "worn"}),
     "ground" : ({"dirt", "earthen", "forest", "packed", "trampled", "traveled", "disturbed"}),
     "leaves" : ({"dead", "brittle", "yellow", "grey", "decayed", "broken", "torn", "scattered"}),
     "branch" : ({"dead", "spindly", "dense", "splintered", "grasping"}),
     "fog" : ({"misty", "rolling", "dense"}),
     "track" : ({"animal", "paw", "large"}),
     ]) );
  SetInventory( ([
     ]) );
  SetEnters( ([
     ]) );
  SetExits( ([
     "north" : VAMP_ROOM + "forest12",
     "southeast" : VAMP_ROOM + "forest10",
     ]) );

}
