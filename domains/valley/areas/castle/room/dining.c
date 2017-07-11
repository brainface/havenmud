#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(35);
   SetShort("inside the large dining room");
   SetLong("Long tables fill the room, with wooden chairs neatly lined up "
           "before them.  The door is to the south, leading out into "
           "the rest of the castle, while to the west is a non-descript "
           "door that most likely leads into the servant's corridors.  "
           "Torches are interspersed upon the walls in an even, orderly "
           "fashion, and currently un-lit candles decorate the tables.");
   SetItems( ([
                ({ "stone walls","stone wall","wall","walls","torches",
                   "torch" }) :
                   "The torches are all lit, lighting up the dining room "
                   "to a pleasant setting, for the normal inhabitants.  "
                   "The stone walls have these torches spaced evenly "
                   "along them.",
                ({ "large dining room","dining room","room","castle" }) :
                   (: GetLong :),
                ({ "long tables","wooden chairs","long table","tables",
                   "table","wooden chair","chairs","chair","un-lit candles",
                   "un-lit candle","unlit candles","unlit candle",
                   "candle","candles" }) :
                   "Candles who are without flame make up the centerpieces "
                   "of all the tables, long and bulky, that are scattered "
                   "haphazardly around the dining room.  Chairs are "
                   "set before the tables, pushed into the table in "
                   "an orderly manner.",
           ]) );
   SetExits( ([
                "south" : VC_ROOM + "/hall1",
                "west"  : VC_ROOM + "/someroom",
           ]) );
   SetInventory( ([
                    VC_NPC + "/diner" : 3+random(5),
                    VC_NPC + "/servant" : 1,
               ]) );
}
