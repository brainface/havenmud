#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("a shadowed plain");
  SetLong("A dead, dry plain. "
         "There is not much of interest here. Nothing can be seen but "
         "the brown land stretching into the "
         "distance. The only interesting feature of this area is a "
         "large dead, blackened tree to the north.");
  SetObviousExits("north, south, east");
  SetExits( ([
          "south" : G_ROOMS+"/room46.c",
          "north" : G_ROOMS+"/room34.c",
          "east" : G_ROOMS+"/room43.c"]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetListen( ([
          "default" : "A squealing sound can be heard nearby."]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but dead grass and dirt rolling away over the horizon.",
          "tree" : "A large, withered, dead tree. "
          "Its blackened limbs stretch up against sky as if it is begging "
          "for mercy."]) );
  }
