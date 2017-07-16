#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("prasanna");
   SetClimate("temperate");
   SetShort("the palace garden");
   SetLong("The entrance to the estate of the matriarch Maeralin looks like "
           "the gates to Paradise. Flourishing plant life and "
           "countless exotic flowers crowd the walkway and form a green "
           "base around the statue, which appears to be the centerpiece of "
           "the huge yard. To the north lies the foyer to the main "
           "house, with its beautiful towering arabesque dome.");
   SetItems( ([ 
      ({ "entrance" }) :
         "This is the entrance to the largest estate in the city.",
      ({ "patriarch Maeralin","patriarch" }) :
         "Maeralin... the leader of her family, and the city.",
      ({ "yard","huge yard" }) :
         "This huge yard simply drips of wealth and power.",
      ({ "house" }) :
         "This is the home of Maeralin, the patriarch and leader of Prasanna.",
      ({ "green base","base" }) :
         "The base of the statue here is formed by plants and flowers "
         "crowded together to form a solid green mound.",
      ({ "teardrop-shaped dome","dome","arabesque dome" }) :
         "The towering dome of the Ishraq estate dwarfs the rest of the "
         "city.",
      ({ "flourishing plant life","plant life","exotic flowers","flowers" }) :
         "These are plants and flowers plucked from all corners of the "
         "world, and replanted here for the obvious asthetic qualities.",
      ({ "walkway" }) :
         "The walkway curves proceeds straight towards the house, with several"
         "smallers paths curving off and winding through the garden.",
   ]) );
   SetExits( ([ 
      "north" : PA_ROOM "/estatefoyer", 
      "south" : PR_ROOM "/square",
   ]) ); 
   SetInventory( ([ PR_OBJ + "/eststatue" : 1 ]) );
}
