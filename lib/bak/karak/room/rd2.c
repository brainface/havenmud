#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("Ahriman's Passage");
  SetObviousExits("east, west");
  SetExits( ([
                 "east" : K_ROOM + "/rd1",
                 "west" : K_ROOM + "/rd3" ]) );
  SetDayLong("This is an open area just west of the massive stone gate "
             "To the west, the street known as Ahriman's Passage "
             "continues into the distance. "
             "The buildings here are very well built "
             "of strong granite reinforced with iron.  The road here is "
             "mostly a dark grey cobblestone, with the occasional odd stone "
             "made of an ivory colored substance.  Immediately to your "
             "east is the mighty and imposing gate of Karak-Varn. "
             "Lying by the roadside is the Leather Boyz Place."
             );
  SetNightLong("This area is scantily lit by a couple of torches suspended "
               "far above your head.  The entire area is covered in dank "
               "shadows, but the city gate can still be seen to the east. "
               "Lying by the roadside is the Leather Boyz Place."
               );
  SetItems( ([
    "place" : "The Leather Boyz Place is a place that sells (and gives away) leather armour.",
    ]) );
  SetSmell("The smell of curing hides comes from the leather place.");
  SetEnters( ([
    "place" : "/domains/crystal_reaches/areas/leatherstore/leatherstore",
    ]) );
}
            
