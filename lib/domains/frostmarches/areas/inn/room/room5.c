#include "../inn.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a very pleasent room");
  SetAmbientLight(35);
  SetDayLong("The sun beams in through the windows in the wall illuminating "
             "the room with an almost holy light.  Compared to the rest of "
             "the inn, this room is amazingly well built.  The planks that "
             "make up the floor fit together seemlessly and seem to glow with "
             "beauty.  The bed next to the north wall looks soft and "
             "luxurious, like it was made for a king.  There is a strong, "
             "sturdy table next to the west wall.  The room would seem to fit "
             "in better in a palace than such a simple inn as this.");
  SetNightLong("A lantern on the table containing a large, powerful flame "
               "fills the room with a beautiful, glowing light and accents "
               "its excellent construction.  The floor is seemless and smooth "
               "and refuses to make even the slightest creak.  There is a bed "
               "set against the north wall that looks very inviting and "
               "suggests that sleeping in it would ease any harsh night and "
               "supply the occupant with wonderful dreams.");
  SetItems( ([ 
                "sun" : "Why would anyone want to stare at the sun?",
             ({ "almost holy light", "holy light", "light" }) :
                "The light is glorious, as if it were of the gods "
                "themselves.",
             ({ "walls", "north wall", "wall" }) :
                "The walls seem quite nicely constructed.",
             ({ "seemless and smooth floor", "seemless floor",
                "smooth floor", "nearly perfect floor", "floor", "planks",
                "plank" }) :
                "The floor is nearly perfect.",
             ({ "excellent construction", "construction" }) :
                "The construction of this room is excellent.",
             ({ "lantern", "lamp", "large powerful flame", "large flame",
                "powerful flame", "flame" }) :
                "The lantern's flame fills the room with light.",
             ({ "amazingly luxurious bed", "soft luxurious bed", "soft bed",
                "luxurious bed", "inviting bed", "bed" }) :
                "The bed looks amazingly luxurious.  Not even a king would "
                "scoff at the thought of sleeping in it.",
             ({ "strong sturdy table", "strong table", "sturdy table",
                "table" }) :
                "This is a very well built table.  One could put almost "
                "anything on it without breaking it.",
             ({ "windows", "window", "sky" }) :
                "The windows look out towards the sky."
             ]) );
  SetInventory( ([ I_NPC + "/joseph" : 1 ]) );
  SetClimate("indoors");
  SetObviousExits("south");
  SetExits( ([ "south" : I_ROOM + "/hall3" ]) );
}
