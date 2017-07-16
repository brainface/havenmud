
#include <lib.h>
#include "../shrine.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a path leading to a shrine");
  SetLong("As the path continues on towards the shrine"
          " the density of the fog increases. From"
          " what can be seen through the fog, the path"
          " looks as though it has fallen on bad times"
          " with broken stones and weeds growing through"
          " the center. Directly to the south the shrine"
          " is visible through the fog. The entrance"
          " to the shrine is and arch that is made of a"
          " beautiful white marble stone. There is a"
          " black lacquer sign hanging from the arch. ");
  SetItems( ([
          ({ "path", "stone", "stones", "weeds"}) :
          "The path here has seemingly been neglected"
          " and shows signs of aging. The stones that"
          " were once neatly arranged to border the"
          " path are broken or missing and weeds"
          " sprout in random spots along the path.",
          ({ "fog" }) :
          "The fog here is very thick and unnatural.",
          ({ "shrine", "arch" }) :
          "The shrine is a small and modest affair with"
          " a large white marble arch for an entry way."
          " There is a black lacquer sign hanging from"
          " the arch.",
          ({ "sign" }) :
          "The sign reads, \"The Shrine of the Ancients\"",
          ]) );
  SetItemAdjectives( ([
          "path" : ({ "broken", "neglected" }),
          "fog" : ({ "unnatural", "thick" }),
          "shrine" : ({ "small", "modest" }),
          "arch" : ({ "white", "marble" }),
          "sign" : ({ "black", "lacquer" }),
          ]) );                 
  SetSmell( ([
          "default" : "The brisk odor of a cold wind lingers.",
       ]) );
  SetListen( ([
          "default" : "The sound of distant moaning"
                      " reaches here.",
        ]) );
  SetExits( ([
           "south" : SHRINE_ROOM "antechamber",
           "north" : SHRINE_ROOM "room2",
           "west" : SHRINE_ROOM "room5", 
           "east" : SHRINE_ROOM "room11",
        ]) );
  SetInventory( ([
           SHRINE_NPC "ghost1" : 2,
           SHRINE_NPC "ghost2" : 1,
        ]) );
}
