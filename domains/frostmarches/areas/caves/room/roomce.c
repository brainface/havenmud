#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("underground");
SetDomain("FrostMarches");
    SetShort("a ravine with a cave mouth");
    SetLong("This is a wind worn ravine heading north.  Small tufts "
            "of grass are trampled here.  A single boulder is "
            "lying down here.  Many muddy footprints enter and leave "
            "a cave entrance to the south.  "
            "There is about an inch of snow on the ground.  The stone "
            "around the entrance is worn from many footsteps.");
    SetItems( ([
      ({"stone"}) :
        "The stone is worn smooth from footsteps.",
      ({"muddy footprints", "footprints", "ground", "footprint",
        "small footprint", "small footprints", "small muddy footprint",
        "small muddy footprints"}) :
        "There are many small muddy footprints leading into the cave mouth.",
      ({"snow", "powder snow", "powdery snow", "dry snow"}) :
        "There is about an inch of dry powdry snow on the ground.",
      "boulder" :
        "This is a small boulder about one and a half foot across. "
        "It is covered in snow.",
      ({"grass", "tuft of grass", "tuft", "tufts"}) :
        "Some careless creature has trampled what little grass grows here.",
      ({"ravine", "worn ravine", "wind worn ravine", "ice"}) :
        "This ravine has been fractured by ice and worn by the wind for "
        "ages.",
      ({"cave", "cave entrance", "mouth", "cave mouth", "entrance",
        "bottom"}) :
       "This is a relativly small cave entrance, about three feet across "
       "by four feet tall.  The bottom of it is worn from many footsteps, "
       "easily worn in the greyish sedimentary rock.",
      ({"grey rock", "greyish rock", "rock", "sedimentary rock", 
        "greyish sedimentary rock."}) :
        "This is a soft stone, easily worn by water or chisel.",
         ]) );
    SetListen( ([
       "default" : "The occasional voice speaking gobyshkin comes from the cave.",
            ]) );
    SetSmell( ([
       "default" : "A foul odor eminates from the cave mouth.",
            ]) );
    SetExits( ([
      "north" : CAVES_ROOM + "roomo3",
            ]) );
    SetEnters( ([
      ({"cave", "south cave"}) : CAVES_ROOM "cavee.c",
             ]) );
}
