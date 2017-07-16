#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Prasanna");
  SetDomain("Valley");
   SetClimate("temperate");
   SetShort("Tal-Verdana Avenue");
   SetLong("The avenue continues deeper into the city, as do the lush "
           "gardens. Now visible are a number of broad archways that stretch "
           "over and across the streets. Each one seems to be inscribed with a "
           "word or two in a strange language, and make no sense. Yet the "
           "style and skill with which they are carved simply adds to the "
           "mystery surrounding the ancient city. A small building sits just "
           "to the south of the road, with the door ajar, while to the east, "
           "the avenue continues.");
   SetItems( ([ 
      ({ "broad archways","broad archway","archways","archway" }) : 
         "These are more masterfully carved arches, with mysterious foreign "
         "inscriptions.",
      ({ "inscriptions","inscriptions" }) :
         "These inscriptions were carved long ago, but the language is "
         "far too foreign to ascertain their meanings.",
      ({ "avenue" }) :
         "Tal-Verdana avenue continues to the east, and the west.",
      ({ "lush gardens","lush garden","gardens","garden" }) : 
         "The gardens line the streets, and surround every building. The plants "
         "give the area a feeling of vibrance and life.",
      ({ "streets","street" }) :
         "The streets here are a work of art in itself, and are very smooth and "
         "easy to travel upon.",
      ({ "road" }) : 
         "This is Tal-Verdana Avenue, it traverses the city from east to west. ",
      ({ "lush rows", "rows" }) : 
         "These rows of flowers and shrubs were precisely planted to make the "
         "city a wondrous and beautiful place. ",
      ({ "city","town" }) : 
         "This is the sprawling city of Prasanna, and seems to glow as the "
         "light hits it. The buildings are elegant and inviting.",
      ({ "door" }) :
         "This is the door to a small buidling. It is open.",
      ({ "small building","building" }) :
         "This is a small building with the door wide open.",
   ]) );
   SetExits( ([ 
     "east" : PR_ROOM "/talver3",
      "west" : PR_ROOM "/talver1",
   ]) );
   SetEnters( ([ 
      "building" : PR_ROOM "/empty" ]) );
}

