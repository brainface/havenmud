//
// Central forecourt
// by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
  inherit LIB_ROOM;

static void create() {
room::create();
 SetShort("main forecourt");
 SetLong("This area appears to have once been a thriving market square, "
         "with abandoned stalls lying overturned. To the north lies the "
         "main entrance to the castle, and smaller archways lie to the "
         "east and west. Directly ahead is the bailey of the castle, "
         "leading in to the heart of the keep. What should have been open"
         " sky above is instead an enormous slab of rock.");
  SetClimate("underground");
  SetAmbientLight(1);
  SetItems( ([
    ({"square","market"}) : "This place looks "
      "like it was abandoned in a hurry. Either that, or something "
      "happened too quickly for them to do anything but panic.",
    ({"arch","archway","archways"}) : "The archways are made "
      "of marble. The one to the north is slightly larger than the"
      " archways to the east and west.",
    ({"stalls","stall"}) : "The stalls would have been used "
      "by vendors to sell a variety of goods. These "
      "goods, including meat and vegetables, have long since rotted.",
    ({"entrance","bailey","keep"}) : "The bailey, the sole entrance to "
      "the keep, oozes a dread sense of forboding. It lies to the north"
      " of here.",
    "forecourt" : (:GetLong:),
    "castle" : "The castle consists of two parts: the outer, where the "
     "townsfolk live, which is mostly blocked up by rubble, and "
     "the keep, where the king, his courtiers, and his soldiers would live.",
    ({"ceiling","rock"}) :
      "A single expanse of some kind of volcanic rock hangs over the "
      "forecourt in a distinctly ominous manner.",
    ]) );
  SetItemAdjectives( ([
    "archways" : ({"small","marble"}),
    "market" : "square",
    "rubbish" : "discarded",
    "stalls" : "abandoned",
    "entrance" : "main",
    ]) );    
  SetListen( ([
    "default" : "There is an almost imperceptible hum, as "
                "if there were people still around",
    ]) );
  SetInventory( ([
    RNQ_NPC + "ghost1.c" : 2,
    ]) );
  SetExits( ([
    "south" : RNQ_RM + "bailey.c",
    "north" : RNQ_RM + "guardhs.c",
    "west" : RNQ_RM + "wcor1.c",
    "east" : RNQ_RM + "ecor1.c",
    ]) );
}
