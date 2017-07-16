#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("Ahriman's Passage");
  SetObviousExits("east, west");
  SetDayLong("The cobbled street known as Ahriman's Passage continues east "
             "and west here.  The building to the north has a rather grand "
             "facade, and appears to be a church dedicated to Ahriman.  To "
             "the south is a structure of nearly equal splendor, it appears "
             "to be the headquarters of the town guard.");
  SetNightLong("The street is quiet and continues to the east and west into "
               "the darkness.  To the north you can see the soft glow of "
               "candles marking the church of Ahriman.  Through a dark "
               "doorway to the south is the headquarters of the town guard.");
  SetItems( ([
    ({ "cobbled street","street","Ahriman's Passage","Passage" }) :
       (: GetLong() :),
    ({ "quiet street" }) :
       (: GetNightLong :),
    ({ "north building","building","church" }) :
       "The church stands on the northern side of Ahriman's Passage.",
    ({ "splendid structure","structure","headquarters" }) :
       "To the south of Ahriman's Passage, the headquarters of the town "
       "guard stands."
  ]) );
  SetExits( ([
    "east" : K_ROOM + "/rd2",
    "west" : K_ROOM + "/rd4"
  ]) );
  SetEnters( ([
    "church" : K_ROOM + "/church",
    "headquarters"   : K_ROOM + "/mayor"
  ]) );
}
