#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("a guest room");
   SetLong("A ragged rug is spread out on the stone floor, and some "
           "wall hangings decorate the bare stone walls.  A rustic "
           "bed sits in one corner, a table and a chair in another, but "
           "over all the room is small, plain, and slightly cramped.  To "
           "the east, a non-descript door leads out into the hallway.");
   SetItems( ([
                ({ "ragged rug","rug","stone floor","floor",
                   "wall hangings","hangings","hanging","wall hanging",
                   "bare stone walls","bare stone wall","bare walls",
                   "bare wall","stone walls","stone wall","wall","walls",
                   "rustic bed","bed","table","chair","corner" }) :
                   "All the trappings of this room, from the rug "
                   "to the wall hangings to the bed and table, are "
                   "worn and look to have seen better days--much better "
                   "days!  Most look like they were broken in two "
                   "or ripped some time in the past, and the shoddy "
                   "repairations made them only suitable for a lesser "
                   "guest room in this castle.",
                ({ "guest room","room","corner","small room","plain room",
                   "cramped room","slightly cramped room","hallway",
                   "castle" }) :
                   (: GetLong :),
           ]) );
   SetExits( ([
                "east"  : VC_ROOM + "/hall3",
           ]) );
   SetInventory( ([
                    VC_NPC + "/musician" : 1,
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
