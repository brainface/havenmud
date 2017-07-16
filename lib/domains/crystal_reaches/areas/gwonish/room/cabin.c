#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int gone = 0;

string CheckSage(string useless);


static void create()
{
  room::create();
  SetAmbientLight(35);
  SetClimate("indoors");
SetProperty("no teleport", 1);
  SetShort("a cabin");
  SetLong( "Shadows flicker across the walls creating the illusion of "
           "movement all about the room.  A chest sits in one corner of the "
           "room, far away from the flickering fireplace and a small bed "
           "rests in between.  Much closer to the fireplace a comfortable "
           "looking chair rests upon a cozy looking rug with a footstool at "
           "its feet and a tall reading lamp by its side.  A door to the "
           "south provides the cabins only egress and there are no windows "
           "to be seen." );

  SetItems( ([ ({"wall","walls"}) : "Light flickers off the walls creating "
                      "wild chaotic shadows",
               ({"fireplace","fire"}) : "The only bricks of the entire "
                      "building make up the fireplace and chimney.\nA slow "
                      "heat radiates out from the fireplace.",
               "bed" : "The bed is neatly made.",
               "chair" : (: CheckSage :),
               "chest" : "A simple wooden chest sits open and empty "
               "on the far side of the room.",
               "rug" : "Floral designs weave their way throughout the thick "
                       "rug.",
               ({"stool","footstool"}) : "The worn leather covered footstool "
                      "matches the chair."]) );

  SetExits( ([ "out" : GWONISH + "room/outsidecabin"]) );


  SetDoor("out", GWONISH + "room/cabindoor");

  SetSmell( ([ "default" : "The acrid smell of smoke fills the room."]) );
  SetListen( ([ "default" : "An occasional crackle can be heard from the "
                            "fireplace."]) );
  SetObviousExits("out");
}

string CheckSage(string useless)
{
  if(present("sage"))
  return "A wise old man sits comfortably in an old brown leather chair.";
  else
  return "Impressions mar the seat of the old brown leather chair.";
}

