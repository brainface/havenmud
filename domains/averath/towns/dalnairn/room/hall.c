// Dalnairn
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../dalnairn.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("in the city hall");
  SetNewsgroups( ({ "town.dalnairn" }) );
  SetLong(
    "The Dalnairn city hall is one of the larger buildings in the city. To "
    "one side of the hall, the mayor's desk takes up most of the room. To the "
    "other side lies a small podium from which the mayor addresses the people "
    "when they are gathered. The hall is decorated with paintings of the "
    "city from various perspectives."
  );
  SetItems( ([
  ({ "hall" }) : (: GetLong :),
  ({ "desk" }) : 
    "The mayor's desk is neatly arranged and kept very tidy. Various "
    "papers are stacked on one side of the desk, leaving room to work with.",
  ({ "podium" }) : 
    "This small podium is raised slightly, to allow everyone to see who is "
    "speaking.",
  ({ "paintings" }) : 
    "These paintings each depict the city of Dalnairn from different "
    "perspectives. Some from within, and some from the bottom of the "
    "mountain.",   
  ]) );
  SetItemAdjectives( ([
    "hall" : ({ "city" }),
    "desk" : ({ "mayor's" }),
    "podium" : ({ "small" }),    
  ]) );
  SetInventory( ([  
    DAL_NPC "guard" : 1,
    DAL_OBJ "poster" : 1,
    DAL_NPC "nevin" : 1,  
  ]) );
  SetListen( ([
    "default" : "The city hall is mostly quiet, only the mumbling of a few "
    "voices can be heard.",
  ]) );
  SetSmell( ([
    "default" : "The building smells very clean.",
  ]) );
  SetExits( ([
    "out" : DAL_ROOM "road3",
  ]) );  
}
