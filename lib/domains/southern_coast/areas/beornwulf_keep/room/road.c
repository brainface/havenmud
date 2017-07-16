#include <lib.h>
#include "path.h"
 
inherit LIB_ROOM;
 
static void create () {
    room::create();
    SetShort("a small stretch of road");
    SetLong("This small stretch of road is an offshoot of the main east-west "
          "road running through Kailie.  The path continues a few more feet "
          "before ending abruptly at a field of grass.  It is clear that "
          "the road has been used more than usual recently, and it has taken "
          "the stress from the repeated use quite badly, judging by the "
          "potholes that cover it.");
    SetItems( ([
          ({ "small stretch of road", "stretch", "small stretch", "road" }) :
           "The road is rough and bumpy.",
          ({ "potholes in road","potholes", "holes","pothole","hole",
             "potholes" }) :
          "There are several potholes covering the road, apparently created "
          "by boots and wheeled vehicles.",
          ({ "pleasant field","field" }) :
          "The field looks pleasant from here.",
          ({ "lush grass","grass" }) :
          "The grass is very lush and dark green.",
          ]) );
    SetExits( ([
           "north" : "/domains/southern_coast/virtual/havenroad/-12,0",
          "south" : BEORN_ROOM + "field1.c",
          ]) );
}
