#include <lib.h>
#include "../path.h"


inherit LIB_ROOM;


static void create()
{
  room::create();
  SetAmbientLight(35);
  SetClimate("indoors");
  SetShort("inside a monument");
  SetLong( "A shrine dominates the building from the far end of the room.  In "
           "spite of the lack of torches the room is very well lit due to the "
           "columnar nature of the walls and the skylights in the ceiling.
");

  SetItems( ([ ({"column","columns"}) :
                      "Broad stone columns make the walls of the building.",
               "shrine" : "The shrine is dedicated to some hero.\nThere is a "
                          "plaque placed on the side of the eight foot "
                          "cubicle shrine.",
               "plaque" : "The plaque dedicates the monument to Rorgard, an "
                          "ancient dwarven hero, who lead a barbarian horde "
                          "to victory over an invasion of lizardmen.",
               "hole" : "The hole is perhaps an inch and a half tall and a "
                        "quarter inch wide.",
               ({"skylight","skylights"}) : "A soft warm glow filters in "
                        "through the overhead port."]) );


  SetExits( ([ "out" : GWONISH + "room/hill"]) );

  SetSmell( ([ "default" : "It smells a bit dusty in here."]) );
  SetListen( ([ "default" : "It is very quiet."]) );
  SetSearch( ([ "shrine" : "Upon careful inspection, a concealed opening "
                           "is found on the back of the shrine.  Some force "
                           "prevents you from opening it, but a small diamond "
                           "shaped hole rests near the edge of the door."]) );
  SetObviousExits("out");
}


