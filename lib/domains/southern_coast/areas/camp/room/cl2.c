#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetNightLight(10);
  SetShort("a clearing");
  SetObviousExits("west, southwest, southeast, north");
  SetExits( ([
    "west"      : CAMP_ROOM + "/cl1",
    "southwest" : CAMP_ROOM + "/cl3",
    "southeast" : CAMP_ROOM + "/cl4",
    "north"     : CAMP_ROOM + "/entrance",
    ]) );
  SetDayLong("The path opens into a full sized clearing here, with \n"
             "paths leading into clearings in many directions.  To the \n"
             "south there are some tents which seem to house some of the \n"
             "people that live here.");
  SetNightLong("To the south, there are some fires which indicate that \n"
               "even at night this camp is full of life.  To the north \n"
              "a path leads away from the camp.");
  SetInventory( ([
    CAMP_NPC + "/bowbandit" : 1,
    CAMP_NPC + "/dog" : 3,
    ]) );
  SetSmell( ([
            "default" : "There is a slight odor of dog refuse here.",
             ]) );
  SetListen( ([
             "default" : "There are many sounds of life coming from the south.",
               ]) );
  }
