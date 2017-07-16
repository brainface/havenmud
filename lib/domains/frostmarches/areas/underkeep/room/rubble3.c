//
// a watchtower
// by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetShort("a deserted watchtower");
  SetLong(
    "The steps lead up to a deserted watchtower, which is squarish"
    " and has a large amount of dirt and debris scattered around on the"
    " stone floor. The roof, originally an arch, is now more of a flat"
    " roof, compacted down by the weight of the rock and soil above. It"
    " is an amazing feat of engineering that there still is a ceiling."
    " An arched window looks out onto solid rock, and a doorway to the"
    " north has become totally blocked with dirt. A set of stone steps"
    " leads back down below."),
  SetClimate("underground");
  SetAmbientLight(1);
  SetItems( ([
    "watchtower" : (:GetLong:),
    "floor" :
      "The floor is made of stone, cunningly worked to fit without "
      "the use of mortar.",
    ({"roof","arch","ceiling"}) : 
       "The roof looks like it used to be a fantastically"
      " well-built high archway, but the weight of rocks has"
      " crushed it down almost flat. Splintered timbers protrude,"
      " making any incautious sudden movements risky.",
    "steps" : "The stone spiral steps lead back down into the gloom"
      " below.",
    ({"dirt","debris","soil"}) :
      "The dirt and small stones cover the stone floor in a loose carpet",
    ({"rubble","archway","doorway"}) :
      "Loose shale and silt fills the cracks between the chunks of "
      "collapsed masonry.",
    ("window") :
      "All that can be seen is the granite of the solid rock that "
      "lies for miles above.",
    ({"room","watchtower"}) : (:GetLong:),
    ({"solid rock","rock"}) : "The rock looks like granite.",
    ]) );
  SetItemAdjectives( ([
    "watchtower" : ({"deserted","squarish"}),
    "roof" : "flat",
    "floor" : "stone",
    "window" : "arched",
    "room" : ({"squarish","deserted"}),
    "steps" : ({"stone","spiral"}),
    "rock" : "solid",
    ]) );
  SetSmell( ([
    "default" :
      "The air is as musty as a tomb.",
    ]) );
  SetListen( ([
    "default" :
      "No sound can be heard here at the moment.",
    ]) );
  SetInventory( ([
    RNQ_NPC + "skeleton2.c" : 2,
    ]) );
  SetExits( ([
    "down" : RNQ_RM + "tower2.c",
    ]) );
}
