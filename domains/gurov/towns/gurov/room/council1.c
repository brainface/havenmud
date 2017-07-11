#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "out"  : GUROV_ROOM "nr3",
    "west" : GUROV_ROOM "council2",
    ]) );
  SetInventory( ([
    GUROV_NPC "sage" : 1,
    ]) );
  SetLong(
    "The Council of Nobles building serves as the center for news of the "
    "Principality and also as the basis for foreign studies. Around the "
    "council hall are various bookshelves which seem to house books of "
    "scholars from all of Kailie. Several large chairs are arranged neatly "
    "in ways to support the comfort of the various nobles."
    );
  SetSmell("The books give the room a musty smell.");
  SetNewsgroups( ({ "town.gurov" }) );
  SetListen("The council building has a gentle murmur of discussion.");
  SetShort("inside the Council of Nobles building");  
  SetClimate("indoors");
  SetAmbientLight(35);
}