/* out.c for Abandoned Mine
   Tassadar@Haven
   11SEP04
*/

#include <lib.h>
#include "../mine.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("outdoors");
    SetShort("near an opening in the mountain");
    SetDayLong(
        "There is a small hole in the side of the mountain. "
        "The slope of the mountain is quite sharp. There is little "
        "vegetation here, only shrubs and bushes appear randomly. There "
        "are piles of rock lying about the edges of the path. The "
        "path, what is left of it, seems to have not been used for "
        "some time. There is a sheer cliff face above the opening"
        "to the south."
        );
    SetNightLong(
        "There is a slightly sloping very thin path here that "
        "leads to an opening in the mountain side. The mountain "
        "blocks out most of the sky, making the area oppressively "
        "dark. There is a soft orange glow coming from the opening. "
        "There are a few bushes and shrubs at the edge of the path."
        );
   SetItems( ([
        ({"path", "mine", "mountain"})  :  (: GetLong :),
        ({"light", "glow"}) : 
        "There is a soft orange glow coming from the opening.",
        ({"opening", "timbers", "hole"})  :
        "The opening of the mine is framed out in heavy timbers "
        "that hold the vast bulk of the mountains at bay. The opening "
        "is narrow and tall, just enough for a grown human to walk "
        "upright through it.",
        ({"shrub", "shrubs", "bush", "bushes"})  :
        "There are a few small shrubs and bushes just off the path. "
        "They are sickly, and not very green. Their bare branches "
        "are brown and very dry.",
        ({"cliff", "face"}) :
        "The cliff face above the opening stretches up into the sky. "
        "The peak of the mountain cannot be seen from here.",
        ({"pile", "piles", "rock", "rocks", "debris", "stone"}) : 
        "There are many piles of rock debris lying alongside the "
        "path. The piles are of a dark grey stone, and very dirty.",
      ]) );
    SetItemAdjectives( ([
        "opening"  :  ({"tall", "narrow", "small"}),
        "cliff"   :  ({"tall", "stretching", "sheer"}),
        "brush"  :  ({"small", "sickly", "brown"}),
        "piles" :  ({"many", "grey", "dirty"}),
        "path" : ({"narrow", "unused", "slightly", "sloping", "thin", "very"}),
        "glow" : ({"orange", "soft"}),
        "rock" : ({"dark", "grey", "dirty", "pile", "piles", "of"}),
      ]) );
    SetSmell( ([
        "default"  :  "The air is fresh but very dry.",
      ]) );
    SetListen( ([
        "default"  :  "There is a soft sound from the wind howling off "
                      "the cliff.",
      ]) );
    SetEnters( ([ "opening" : MINE_ROOM + "mine1.c",
             ]) );
    SetExits( ([
        "north"  : CRYSTAL_REACHES_VIRTUAL "-10,22",
      ]) );
}
