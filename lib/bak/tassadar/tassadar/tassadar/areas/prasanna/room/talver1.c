#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("temperate");
  SetDomain("Valley");
   SetShort("Tal-Verdana Avenue");
   SetLong("Upon entering through the gates, the city is breathtaking. "
           "Elegant buildings sit in the midst of enrapturing gardens. "
           "All around the streets are lush rows of flowers and assorted "
           "plant life. Most of the flowers and shrubs look to be exotic, "
           "from some far away place. The road continues east to the center "
           "of town.");
   SetItems( ([ 
      ({ "streets","street" }) :
         "The streets here are a work of art in itself, and are very smooth "
         "and easy to travel upon.",
      ({ "gates","gate" }) : 
         "These gates are large bronze doors, built to keep would-be invaders "
         "at bay.",
      ({ "doors","door" }) :
         "These six inch thick bronze doors look impervious to attack.",
      ({ "elegant buildings","elegant building","buildings","building" }) : 
         "The buildings of the city are simply gorgeous, the creations of a "
         "master architect.",
      ({ "enrapturing gardens","gardens","garden" }) : 
         "The gardens line the streets, and surround every building. The "
         "plants give the area a feeling of vibrance and life.",
      ({ "road" }) : 
         "This is Tal-Verdana Avenue, it traverses the city from east to "
         "west. ",
      ({ "lush rows","lush row","rows","row" }) : 
         "These rows of flowers and shrubswere precisely planted to make the "
         "city a wondrous and beautiful place. ",
      ({ "city","town" }) : 
         "This is the sprawling city of Prasanna, and seems to glow as the "
         "light hits it. The buildings are elegant and inviting.",
      ({ "flowers","flower" }) :
         "These are beautiful flowers, mostly orchids and wilds roses, but "
         "many other indistinguishable species litter the gardens as well.",
      ({ "roses","rose" }) :
         "The roses here range in color from white, red, yellow, violet, black, "
          "pink, and blue... to colors unseen anywhere else in the world.",
      ({ "orchids","orchid" }) :
         "The orchids here look untouched by time, and look cared for to "
          "perfection.",  
      ({ "plants","shrubs" }) :
         "These exotic plants are gorgeous and overflowing with green..."
         "giving the city a look of being alive with color.", 
   ]) );
   SetExits( ([ 
      "east" : PR_ROOM "/talver2", 
      "west" : PR_ROOM "/gates",
   ]) );
   SetSmell( ([ 
      "default" : "The scent of flowers is overwhelming here. ",
   ]) );
}

