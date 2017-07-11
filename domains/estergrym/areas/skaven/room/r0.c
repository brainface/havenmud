#include <lib.h>
#include "../skaven.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetClimate("sub-arctic");
  SetDomain("Estergrym");
  SetAmbientLight(1);
  SetShort("small clearing");
  SetLong("This clearing very much resembles the road it lies"
    " alongside.  A small cave lies hidden in the walls of "
    "the mountain here. Burnt twigs and pebbles dot the scorched earth."    
    " Just behind a withered shrub is a curious pile of rocks."
    " A chilling breeze is blowing in from the north.");                                         
  SetItems( ([
    ({"clearing","small clearing"}) : (:GetLong:),
    ({"road","Estergrym road"}) :
      "The Estergrym road is just to the east of this clearing.",         
    ({"twigs","twig","pebble","pebbles","burnt twigs","burnt twig"}) :
      "A smattering of worthless debris is all about.",
    ({"shrub","withered shrub"}) :
      "A very thin and very dead bit of vegetation.",
    ({"rocks","rock","pile of rocks","pile of rock","curious pile of rocks","curious pile of rock"}) :
      "The pile of rocks is hiding a small cave.",
    ({"cave","small cave"}) :
      "The cave looks dark and foreboding, but can be entered nonetheless."   
          
    ]) );
  SetSmell( ([
    "default" :
      "A burnt smell lingers nearby.",
    
    ]) );
  SetListen( ([
    "default" :
      "The wind is whipping through the wilderness all around. ",
      
    ]) );
    SetExits( ([
        "south" : "/domains/estergrym/virtual/grymxoria_road/5,0"

    ]) );
    AddEnter("cave", S_ROOM + "r1.c");
}