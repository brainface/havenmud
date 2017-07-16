#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Prasanna");
   SetClimate("temperate");
  SetDomain("Valley");
   SetShort("the city square");
   SetLong("The city square is laid out in a precise hexagon. Runes or "
           "symbols are incised in a ring around the central fountain, cut "
           "deeply and flawlessly into the rock. The echoes of the fountain "
           "play against a veritable jungle of lush greenery, out of place "
           "in the extreme on this otherwise barren mountaintop. Broad "
           "avenues lined with buildings both ethereally lovely and "
          "suprisingly sturdy span away in the cardinal directions. "
/*
          "To the north, a veritable palace with a gleaming teardrop-shaped dome "
          "rises above its surroundings. To the west the city gates "
          "glisten in bronze glory, while Tai-Verdana Avenue continues "
          "to the east. A large building rises directly to the east."
*/
          "To the west, the city gates glisten in bronze glory, while a large "
          "building rises directly to the east."
  );
   SetItems( ([ 
      ({ "echoes","echo" }) :
         "The splashing water in the fountain creates eerie echoes here.",
      ({ "mountaintop" }) :
         "The city resides upon the top of a huge mountain.",
      ({ "buildings" }) :
         "The buildings of the city are distinctly beautiful, all built "
         "around the obvious idea that here, beauty is law.",
      ({ "building","building to the east" }) :
         "The large building to the east looks well maintained despite its "
         "age, and is big enough to be a cathedral.", 
      ({ "ring" }) :
         "The runes around the fountain form a ring, simple, yet beautiful.",
      ({ "palace","estate" }) :
         "This is the home of Maeralin, the patriarch and leader of Prasanna.",
      ({ "teardrop-shaped dome","dome" }) :
         "The towering dome of the Ishraq estate dwarfs the rest of the "
         "city.",
      ({ "city square","square" }) :
         "The town square, the meeting place and center of Prasanna. ",      
      ({ "precise hexagon","hexagon" }) :
         "A six-sided geometrical shape, much like the shape of the square",
      ({ "runes","rune","symbols","symbol" }) :
         "These markings seem mainly artistic, and decorative, but perhaps "
         "they hide some deeper meaning...",
      ({ "rock" }) :
         "This is the rock that the fountain is carved from.",
      ({ "avenues","avenue","street","streets" }) :
         "The streets here are a work of art in itself, and are very smooth and "
         "easy to travel upon.",
      ({ "lush greenery","jungle","greenery" }) : 
         "These rows of flowers and shrubs were precisely planted to make the "
         "city a wondrous and beautiful place. ",
      ({ "gates","gate" }) : 
         "These gates are large bronze doors, built to keep would-be invaders "
         "at bay.",
      ({ "doors","door" }) :
         "These thick bronze gates look capable of withstanding any attack.",
      ({ "city","town" }) : 
         "This is the sprawling city of Prasanna, and seems to glow as the "
         "light hits it. The buildings are elegant and inviting.",
   ]) );
   SetExits( ([ 
      "west" : PR_ROOM "/talver3",
   ]) ); 
   SetEnters( ([
      "building" : PR_ROOM "/baths" ]) );
   SetInventory( ([ PR_OBJ + "/mainfountain" : 1 ]) );
}

