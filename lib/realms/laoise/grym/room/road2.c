#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;
int TempExit(string);

static void create() {
  room::create();
  SetTown("Grymxoria");
  SetShort("along the Blood River");
  SetLong(
    "The Blood River runs north and south from here. The city "
    "gates are immediately to the north, and the road runs away "
    "to the south following the river. To the east is the "
    "Grymxoria city barracks. Off to the south, the road comes "
    "to a four way intersection. The stone paved road is smooth "
    "and easy to walk on, but the black paving stones do nothing "
    "to cheer travellers."
  );
  SetItems( ([
   ({ "gate", "gates", }) : "The gates to the city are close "
   "by to the north.",
   ({ "river", }) : "The Blood River flows down the center of "
   "the divided two lane road. It gets its name from the "
   "reddish color of the water from the large amounts of iron "
   "and copper in it.",
   ({ "barracks", "building" }) : "The barracks is an imposing "
   "structure of black stone. The smooth walls rise to an "
   "impressive height, and at the very top gargoyles can be "
   "seen overlooking the city below.",
   ({ "gargoyle", "gargoyles" }) : "The black stone gargoyles "
   "look out over the city with a terrible visage of hate on "
   "their faces.",
   ({ "road" }) : "The road is paved with smooth black stones, "
   "which makes the path easier to walk on, but seems to "
   "reflect no light and makes the town dismal and dark.",
   ({ "stone", "stones" }) : "The black paving stones are smooth "
   "and easy to walk on, but dark and evil looking.",
  ]) );
  SetItemAdjectives( ([
    "gate" : ({ "city" }),
    "river" : ({ "blood" }),
    "road" : ({ "paved", "stone", "paved", "smooth", }),
    "stone" : ({ "black", "smooth", "paving", }),
    ]) );
  SetListen( ([
    "default" : "The river swishes and gurgles eerily.",
    ]) );
  SetExits( ([ 
    "north" : G_ROOM + "road1",
    "south" : G_ROOM + "road6",
    ]) );
  SetEnters( ([ 
    "barracks" : G_ROOM + "barracks1",
    ]) );
  SetInventory( ([
    ]) );
}

