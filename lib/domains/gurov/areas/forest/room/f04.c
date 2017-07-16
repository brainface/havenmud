#include <lib.h>
#include "../forest.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("deeper within the pine forest");
  SetExits( ([
    "southeast" : FOREST_ROOM "f05",
    "northwest" : FOREST_ROOM "f03",
    ]) );
  SetClimate("sub-arctic");
  SetLong(
    "Deeper within the pine forest the trees become thicker, crowding "
    "closer and leaving less distance between them. A small path seems "
    "to lead off to the northwest even deeper into the forest, while "
    "to the southeast the trees become less dense and the path leads "
    "back to the Gurov Road. The underbrush is fairly clear here, as "
    "this path is still the primary link between the city and the "
    "deep forest where hunters roam."
    );
  SetSmell("Pine sap gives the forest an earthy smell.");
  SetListen("Birds chitter from high in the trees.");
  SetItems( ([
    ({ "tree", "trees" }) : "The trees are denser here.  Their evergreen "
                            "nettles are strewn all about the path.",
    ({ "nettle", "nettles" }) : "The nettles are discarded pine needles.",
    "underbrush" : "The underbrush is loose growing things that are not "
                   "trees.",
    "path" : "The path leads northwest and southeast from here.",
    ]) );
  SetInventory( ([
    FOREST_NPC "deer" : 1,
    ]) );                                
}