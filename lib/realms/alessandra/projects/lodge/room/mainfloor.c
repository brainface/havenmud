#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

static void create () {
  room::create();
  
  SetAmbientLight(30);
  SetClimate("indoors");
  SetShort("inside an abandoned lodge");
  SetLong(
     "Covered in dust and cobwebs, this lodge looks as though it has "
     "been deserted, if not for a fire roaring in the fireplace and "
     "footprints disturbing the dust. What was once, probably, a "
     "cozy room is now more like the scene of a battle. Tables and "
     "chairs overturned and broken lay scattered across the room, a "
     "rather comfortable looking couch near the fireplace the only "
     "furniture left in one piece. A plaque resting against the wall "
     "above the fireplace gives an uneasy feeling. There are stairs "
     "leading both upwards and downwards."
     );
  SetSmell( ([
     "default" : "The room smells strongly of dust and smoke.",
     ]) );
  SetListen( ([
     "default" : "The crackling of the fire can be heard.",
     ]) );
  SetItems( ([
     ({"room"}) : (:GetLong:),
     ({"tables","table"}) : "These tables lay scattered and overturned, "
       "some broken roughly in half, others boasting large cracks and "
       "dents.",
     ({"chair","chairs"}) : "Broken into pieces, these chairs are "
       "completely useless, except maybe for firewood.",
     ({"fire"}) : "The fire is good sized, and the ash pile up suggests "
       "it has been burning for quite awhile. It provides a good deal "
       "of light for the room.",
     ({"fireplace"}) : "The fireplace is made from the same stone as the "
       "lodge, with a large fire burning brightly in it. It is completely "
       "covered in soot as though the fire had been burning for days on "
       "end.",
     ({"soot","ash"}) : "A pile lays in the pit of the fire, and covers "
       "everything it touches in a black layer.",
     ({"stone","stones"}) : "Square reddish stones make up the lodge and "
       "fireplace.",
     ({"plaque","head"}) : "The plaque is a trophy of some sort, an elven "
       "head mounted on it. Frozen on its face is a look of terror, likely "
       "the elf died in this very room.",
     ({"couch"}) : "Sitting in front of the fireplace, this couch looks "
       "very comfortable, though not very clean. Dust and soot lightly "
       "cover it, along with a few stains.",
     ({"stain","stains"}) : "Darkened with time, it is impossible to tell "
       "what the stains are from.",
     ({"wall","walls"}) : "Though made of a thick stone, these walls have "
       "obviously seen many battles. Dents and chips scar the surface of "
       "the otherwise smooth stone.",
     ({"ground","floor"}) : "The floor is made of a rough wood. Dust and "
       "soot covers it in most places, except for a few scuffled footprints.",
     ({"stairs"}) : "Made of a rough wood, these sturdy looking stairs lead "
       "upwards as well as down to a basement.",
     ({"footprint","footprints"}) : "Footprints disturb the dust and soot, "
       "looking to be those of several large people.",
     ({"dust"}) : "A thin layer of dust covers everything in this room.",     
     ]) );
  SetItemAdjectives( ([
     "table" : ({"broken"}),
     "chair" : ({"broken"}),
     "fire" : ({"roaring"}),
     "couch" : ({"comfortable"}),
     "walls" : ({"scarred","dented","chipped"}),
     "stairs" : ({"sturdy"}),
     "stone" : ({"red"}),
     ]) );
  SetInventory( ([
     ]) );
  SetExits( ([
     "down" : L_ROOM + "basement.c",
     "up" : L_ROOM + "hallway.c",
     "out" : L_ROOM + "outside19.c",
     ]) );

}
