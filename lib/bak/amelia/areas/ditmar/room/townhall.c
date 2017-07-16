#include <lib.h>
inherit LIB_ROOM;
#include "ditmar.h"

static void create() {
   room::create();
   SetTown("Ditmar");
   SetClimate("indoors");
   SetAmbientLight(10);
   SetShort("Ditmar Townhall");
   SetLong("The Ditmar Townhall is round in shape, with the walls, "
           "ceiling, and floor carefully smoothed and polished.  " 
           "The stone has been worked to form furniture, giving the "
           "weary space to rest if they wish it.  The cave goes out to "
           "the rest of the Ditmar to the north, and the post office "
           "is up from here.");
   SetItems( ([
                ({ "Ditmar Townhall","ditmar townhall","townhall",
                   "town hall","hall","ditmar","cave","caves" }) :
                   (: GetLong :),
                ({ "cave sides","cave side","sides","side","ceiling",
                   "walls","wall","floor" }) :
                   "The sides of the cave are smooth and clean, the "
                   "dull-grey color muted and plain.",
                ({ "stone furniture","furniture","stone" }) :
                   "The furniture here is made of stone, probably "
                   "carved out of the floor of the townhall itself.",
                ({ "Ditmar Post Office","office","post office",
                   "ditmar post office" }) :
                   "The post office is up from here.",
           ]) );
   SetSmell( ([
                "default" : "The air is damp and metallic, but fresh.",
           ]) );
   SetExits( ([
                "north" : D_ROOM + "/cave_a",
                "up"    : D_ROOM + "/po",
           ]) );
   SetInventory( ([
                    D_OBJ + "/board_t" : 1,
                    D_OBJ + "/map" : 1,
                    D_NPC + "/mayor" : 1,
               ]) );
}