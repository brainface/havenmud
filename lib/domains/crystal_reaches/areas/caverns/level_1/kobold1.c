#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(0);
  SetShort("a kobold lair");

  SetLong("This is the center of a kobold lair.  This area seems to have been "
          "made for a defensive position, rather than an intersection. "
          "Although, several small caves lead off in several directions.  It "
          "appears that these caves have been excavated recently, as there "
          "are collapsed sections to the northeast and northwest walls.");

  SetSmell( ([
    "default"  :  "It smells of wet dog and stagnant water here.",
  ]) );

  SetListen( ([
    "default"  :  "From the many caves you hear an irritable yapping echoing "
                  "around you.",
  ]) );

  SetExits( ([
    "north"      :  ROOMLV1 + "/kobold5",
    "east"       :  ROOMLV1 + "/kobold3",
    "southeast"  :  ROOMLV1 + "/kobold4",
    "south"      :  ROOMLV1 + "/kobold2",
    "southwest"  :  ROOMLV1 + "/cave1c",
  ]) );
  SetObviousExits("north, east, south, southeast, southwest");
  SetItems( ([
    ({ "kobold lair", "lair" })  :  (: GetLong :),
    ({ "cave", "caves", "small cave", "small caves" })  :
       "All around there are many small caves leading off to different parts "
       "of the lair.",
    ({ "section", "sections", "collapsed sections", "collapsed section",
       "walls", "northwest wall", "northeast wall", "excavations", "wall",
       "escavation" })  :
       "To the northeast and northwest there are collapsed sections from "
       "recent excavations to expand the lair.  From under the rubble of one "
       "there is a partially decomposed hand reaching out towards you.",
    ({ "partially decomposed hand", "decomposed hand", "hand" })  :
       "The partially decomposed hand reaches out towards you as if to beckon "
       "you to help it out from under it's grave.",
  ]) );
}
