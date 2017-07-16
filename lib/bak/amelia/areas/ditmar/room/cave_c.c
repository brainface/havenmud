#include <lib.h>
inherit LIB_ROOM;
#include "ditmar.h"

static void create() {
   room::create();
   SetTown("Ditmar");
   SetClimate("indoors");
   SetAmbientLight(10);
   SetShort("inside Ditmar");
   SetLong("The main cave goes back to the east, with stalagmites and "
           "stalactites lining the edges.  Two smaller caves are to the "
           "west and south; the way to them is clear.  One set of "
           "stalagmites to the north side of the cave looks rather "
           "like a throne.");
   SetItems( ([
                ({ "west cave","cave" }) :
                   "The cave to the west is very plain, but the "
                   "entrance looks very used.  The stone floor is "
                   "not merely polished down to be even; it "
                   "is worn smooth by the traffic that must go through.  "
                   "The west cave certainly is a popular place.",
                ({ "south cave","cave" }) :
                   "Something regal and special seems to be present in "
                   "the south cave; it has a somber atmosphere to it.  "
                   "The path is not so smoothed by feet as the west "
                   "cave, but many have travelled through it.",
                ({ "main cave","cave","ditmar" }) :
                   (: GetLong :),
                ({ "stalagmites and stalactites","stalagmites",
                   "stalagmite","stalactite","stalactites" }) :
                   "The stalagmites and stalactites are against the "
                   "walls or near them, mostly to the north.  One "
                   "group looks like a throne of some sort.  Many " 
                   "others are tinged pale colors.",
                ({ "throne stalagmites","stalagmites","stalagmite" }) :
                   "This set of stalagmites looks like a throne.  "
                   "Larger ones line three sides while shorter ones "
                   "are in the center, melded together like a seat.  "
                   "The ones in the back are even taller, making it "
                   "look like the real back of some sort of chair.  "
                   "They look quite regal.",
           ]) );
   SetListen( ([
                 "default" : "Singing comes from both south and west:  "
                    "Gaudy and drunken to the west; dignified and "
                    "sober to the south.",
                 "west cave" : "The tune to the west is loud and "
                    "full of laughter and crazy fun.  A few different "
                    "languages blend to form the noise.",
                 "south cave" : "The music sounds like pure Marin coming "
                    "from the south in a delightful harmony with a "
                    "cheering melody.",
            ]) );
   SetSmell( ([
                "default" : "A peculiar smell comes from the west cave.",
                "west cave" : "The west cave smells of spilled beer and "
                   "the other, even less pleasant, results of drinking a "
                   "little too much.",
           ]) );
   SetExits( ([
                "east"  : D_ROOM + "/cave_b",
                "south" : D_ROOM + "/church",
                "west"  : D_ROOM + "/bar",
           ]) );
   SetInventory( ([
                    D_OBJ + "/sign_g" : 1,
               ]) );
}