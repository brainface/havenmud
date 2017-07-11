/*  Level #2 - Chasm - Section #1  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(20);
  SetShort("the ledge overlooking the chasm");

  SetDayLong("Looking off the ledge around the enormously large chasm is a "
             "place of great beauty.  A single shaft of light streams it's "
             "way down through a hole in the ceiling of the chasm cavern.  "
             "The walls sparkling with various gems and large veins of "
             "various metals weave their way across the walls.  As you look "
             "down into the chasm you see a small cloud of mist rising from a "
             "seemingly endless drop into a black darkness.");

  SetNightLong("Here is an enormously large chasm encased within the "
               "mountain.  Looking around there isn't much of note.  The "
               "walls seem to sparkle although it's probably a trick of the "
               "light.  Looking down, darkness swallows up what little light "
               "dares to enter it's realm.");

  SetSmell( ([
    "default"  :  "The smell of water is prevalent here.",
  ]) );

  SetListen( ([
    "default"  :  "A tremendous thundering comes from somewhere below you.",
  ]) );

  SetExits( ([
    "southwest"  :  ROOMLV2 + "/tunnel2c",
    "south"      :  ROOMLV2 + "/chasm2b",
  ]) );
  SetObviousExits("south, southwest");

  SetSearch( ([
    ({ "walls", "wall" })  :  "The walls around you have already been cleared "
       "of anything that is valuable.",
  ]) );

  SetItems( ([
    ({ "chasm", "large chasm", "enormously large chasm" })  :  (: GetLong :),
    ({ "ledge" })  :
       "The ledge you are standing on overhangs an enormously large "
       "underground chasm.  You can see quite a view of the cavern from here.",
    ({ "light", "soft light", "hole", "ceiling" })  :
       "A stream of light breaks through a hole in the ceiling to reveal a "
       "hidden underground wonder of nature, as it reveals the many sights "
       "around you.",
    ({ "walls", "wall", "various gems", "gems", "gem", "various metals",
       "metals", "metal" })  :
       "The walls are lined with all sorts of various gems and metals.  The "
       "gems sparkle in the soft light as the large veins of metal weave "
       "their way across the walls.",
    ({ "small cloud", "mist", "cloud" })  :
       "A small cloud of mist rises out of the darkness below seemingly in "
       "a very slow motion.  Whatever is below is hidden away beneath both "
       "the darkness and the cloud of mist.",
    ({ "endless drop", "down", "drop", "black darkness", "darkness" })  :
       "As you look down you can see a seemingly endless drop in which "
       "darkness absorbs any light that dare to stray into it's realm.  The "
       "bottom of the chasm is no doubt hidden far below you.",
    ({ "bottom" })  :
       "Bottom... what bottom?!  You can't see it through the thick darkness "
       "below.",
  ]) );

}
