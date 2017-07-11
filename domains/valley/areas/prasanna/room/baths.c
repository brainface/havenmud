#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("prasanna");
   SetClimate("indoors");
   SetAmbientLight(35);
   SetShort("the ancient baths of prasanna");
   SetLong("The narrow entry opens out into a vast and airy room, filled "
           "with sunshine from skylights above. Colorful mosaics set into "
           "the floor depict every sort of marine life imaginable, winding "
           "in lyric beauty around four enormous sunken marble baths. At the "
           "head of each, four fountains arch out over the now-empty "
           "space. ");
   SetItems( ([ 
      ({ "entry","narrow entry" }) :
         "The entry leading out to the street is oddly constricting, cut in "
         "a keyhole shape that is narrower at the bottom than at the top.",      
      ({ "room","vast airy room" }) :
         "This is the main room of the baths.",
      ({ "sunshine" }) :
         "Sunlight streams in through four skylights set squarely above "
         "each bath.",
      ({ "skylights" }) :
         "These oval spaces in the ceiling are filled with something that "
         "must be harder than glass, to have survived through the "
         "centuries... the light flooding through them is thick with the "
         "dust of time's passage, making each ray seem a tangible and almost "
         "living thing.",
      ({ "mosaics","colorful mosaics" }) :
         "These tiled patterns show sea life both familiar and never before "
         "imagined -- perhaps they come from a time before the Ruined Sea "
         "suffered its terrible fate. Shapes twine and cavort in an "
         "intricate, neverending dance.",
      ({ "baths" }) : 
         "Baths -- Each of these baths could have easily held thirty with "
         "room to spare. Creamy, rose-veined marble is now bare to the "
         "elements, without the steaming, plashing water it must once have "
         "held. Even so, it still retains its peaceful, eminently "
         "comfortable look.",
   ]) );
   SetExits( ([ 
      "out" : PR_ROOM "/square", 
   ]) );
   SetInventory( ([ PR_OBJ + "/fountain1" : 1,
                    PR_OBJ + "/fountain2" : 1,
                    PR_OBJ + "/fountain3" : 1,
                    PR_OBJ + "/fountain4" : 1,
               ]) );
  SetDomain("Valley");
}

