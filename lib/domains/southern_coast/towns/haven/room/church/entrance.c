//
// Filename: entrance.c
// Entrance to the Kylin Church
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(40);
   SetShort("entrance to the main Temple of Kylin");
   SetExits( ([
      "out" : "../holy_path/hp1",
      "east" : "sanctuary",
      "north" : "hospice",
   ]) );
   SetLong("The Temple of Kylin is a huge and imposing building of marble "
           "and other stonework. It rises into the air, being second in "
           "height only to the Grand Library. Its white walls and columns "
           "appear designed to humble the greatest of mortals looking "
           "upon it, for they are dedicated to the service of Duuktsaryth, "
           "the Kylin Lord of Order. Arranged neatly around the walls are "
           "small niches, each set with a source of light and radiating "
           "its soft glow into the room, making the room very well lit with "
           "no windows. Farther to the east lies the main sanctuary, while "
           "to the north lies a room which seems to be a hospice of some "
           "kind.");
  SetItems( ([
     ({ "temple", "temple of kylin", "church", "building" }) :
        (: GetLong :),
     ({ "wall", "walls", "marble", "stoneworkings" }) :
        "The walls of the room are marble and other stoneworkings.",
     ({ "column", "columns" }) :
        "These huge columns rise high through the church.",
     ({ "light", "source", "light source", "lights", "sources",
        "light sources", "glow" }) : 
        "These are too bright to look directly at, but seem to be soft "
        "and gentle if not stared at exclusively.",
     ({ "niche", "niches", "groove", "grooves" }) :
        "These niches serve as grooves for light sources.",
     ({ "hospice" }) :
        "The hospice is a place of healing which can be seen from here.",
     ({ "sanctuary" }) :
        "The main sanctuary is a huge place with many pews and altars.",
     ({ "pew", "pews", "altar", "altars" }) :
        "The main sanctuary to the east contains many pews and altars.",
     ({ "window", "windows" }) :
        "Although this room has no windows, it is still illuminated well.",
   ]) );
   SetItemAdjectives( ([
      "sanctuary" : ({ "main" }),
      "column" : ({ "white", "huge" }),
      "building" : ({ "huge", "imposing" }),
      "niche" : ({ "small" }),
      "glow" : ({ "soft" }),
   ]) );
   SetSmell( ([
      "default" : "The air has mixed scents of healing herbs and incense.",
   ]) );
   SetListen( ([
      "default" : "Chants and intonations fill the air.",
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 18:37:40 1999. */
