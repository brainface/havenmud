#include <lib.h>
#include "../durgoroth.h"


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetShort("the east of the fountain in Durgoroth");
  SetLong("To the east the ruins of the library are completely"
          " inaccessable due to a large amount of rubble, but"
          " seems to have survived the destruction of the"
          " city rather well. There is; however,"
          " a way to the north leading around the ruins of the"
          " library. To the west the town square can be seen"
          " with it's distinctive fountain as a landmark. Between"
          " here and the town square, a roofless wreck of a building"
          " lies, blocking the way.");
  SetItems( ([
          ({ "library", "remains", "horizon", "towers" }) :
             "The remains of the various buildings such"
             " as the library and towers mar the horizon"
             " with their asymmetrical shapes, providing"
             " a bleak and chaotic appearance to this"
             " desolate ruin.",
          ({ "buildings", "ruins" }) :
             "The buildings here all lie in ruin after what"
             " must have been a mighty struggle. They appear"
             " to have been blasted apart from the insides"
             " scattering masonry wood and metal all around.",
          ({ "wood", "masonry", "metal", "debris", "litter" }) :
             "The debris that litters the ground is of varying"
             " shapes, sizes, and materials. It covers"
             " everything making it difficult to navigate"
             " through the ruins.",
          ({ "square", "town square", "fountain" }) :
             "To the west, beyond a ruin, the town square and fountain can"
             " be seen.",
          ({ "building", "office","wreck","post office","roofless wreck" }) :
             "A sign dangling listlessly from above the doorframe bears "
             "a faded painting of a bag of letters."
          ]) );
  SetSmell( ([
          "default" : "All throughout this area the smell"
          " of dried blood permeates.",
          ]) );
  SetListen( ([
          "default" : "The distant rustling of survivors"
          " picking through the ruins can be heard",
          ]) );
  SetInventory( ([
          ]) );
  SetExits( ([
          "west" : DURG_ROOM "fountain",
          "north" : DURG_ROOM "road06",
          ]) );
  SetEnters( ([
          "building" : DURG_ROOM "postoffice",
          ]) );
}

