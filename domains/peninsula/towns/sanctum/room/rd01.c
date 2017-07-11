#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Esteros");
	SetExits( ([
          "east" : ROME_ROOM "rd02",
          "south" : ROME_ROOM "bazaar",
          "west" : ROME_ROOM "vi05",
	  ]) );
  SetLong("The Via Esteros continues to the east from here. Directly "
          "to the west, it meets up with the Via Imperialis to form "
          "the center of town. Lying along the north side of the road "
          "is the home and office of the local Moneychanger. The road "
          "is made of smooth pieces of stone for easy travel.");
	SetItems( ([
	  "road" : "The road is made of small to medium sized pieces of stone. "
	           "It continues to the east and west.",
    ({ "stone", "stones" }) : "The stones are normal, but well smoothed, "
             "pieces of rock layed out for ease of travel.",
     ({ "building", "office", "home", "moneychanger", "moneychanger's" }) :
         "The marble and stone building houses the city's primary moneychanger.",
    ]) );
  SetItemAdjectives( ([
    "stone" : ({ "piece", "of", "pieces" }),
    ]) );
  SetEnters( ([
    "building" : ROME_ROOM "bank",
    ]) );
  SetInventory( ([
    ]) );
  SetSmell( ([
    "default" : "The smells of urban life taint the air.",
    ]) );
  SetListen( ([
    "default" : "The sounds of the city are alive and vibrant.",
    ]) );
}	           
