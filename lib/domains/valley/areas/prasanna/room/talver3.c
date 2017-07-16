#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Prasanna");
  SetDomain("Valley");
   SetClimate("temperate");
   SetShort("Tal-Verdana Avenue");
   SetLong("Here the avenue begins to widen out slightly, and just to the "
           "east lies the town square. There is a strange electricity in the "
           "air here, and it seems to grow stronger in the direction of the "
           "square. The plants here seem to have their own aura, as if they "
           "had evolved their own protection against some unseen enemy over "
           "time. To the west Tal-Verdana Avenue continues toward the city "
          "gates.");
   SetItems( ([  
      ({ "fountain" }) :
         "The central fountain of Prasanna, once a meeting place for the "
         "inhabitants.",
      ({ "town square","square" }) :
         "Directly to the east lies the town square, with a beautiful "
         "fountain and lovely gardens.",      
      ({ "electricity" }) :
         "There is energy in the air here...",
      ({ "aura","protections" }) :
         "There seems to be a degree of protective energy around the plants "
         "and flowers, a field of constantly shifting light around all of "
         "the flora.",
      ({ "unseen enemy","enemy" }) :
         "The wildlife is protecting itself from something, right?",
      ({ "streets","street" }) :
         "The streets here are a work of art in itself, and are very smooth and "
         "easy to travel upon.",
      ({ "road","avenue" }) : 
         "This is Tal-Verdana Avenue, it traverses the city from east to west. ",
      ({ "plants","plant", }) : 
         "These rows of flowers and shrubs were precisely planted to make the "
         "city a wondrous and beautiful place. ",
      ({ "flowers","flower" }) :
         "The flowers here add spice and color to the mood of the city.",
      ({ "shrubs","shrub" }) :
         "These small, oddly shaped plants line the street and give the city "
          "a lively look.",
      ({ "gates","gate" }) : 
         "These gates are large bronze doors, built to keep would-be invaders "
         "at bay.",
      ({ "city","town" }) : 
         "This is the sprawling city of Prasanna, and seems to glow as the "
         "light hits it. The buildings are elegant and inviting.",
   ]) );
   SetExits( ([ 
      "east" : PR_ROOM "/square", 
      "west" : PR_ROOM "/talver2",
   ]) );
}

