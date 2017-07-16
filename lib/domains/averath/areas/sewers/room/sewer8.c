// Averath Sewers
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../sewers.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(40);
  SetClimate("indoors");
  SetShort("in the Averath sewer system");
  SetLong(
    "The lack of the sewer stream, which remains blocked to the west, has "
    "allowed people to settle here. Sleeping mats are arranged neatly against "
    "the tunnel walls, while chairs and a few wooden tables have been placed "
    "where the stream would usually flow. The area is illuminated by old "
    "wooden torches, each fixed to the walls. This living area continues "
    "east, while to the west the sewer stream flows freely."    
  );
  SetItems( ([
  ({ "sewer", "system", "tunnel", "area" }) : (: GetLong :),  
  ({ "network", "tunnels", "tunnel" }) : "The network of tunnels that make up "
    "the sewer system seem like they were built a long time ago.",  
  ({ "stream", "center" }) : "The stream is blocked to the west, allowing "
    "people to live in this part of the tunnel system.",  
  ({ "walkways" }) : "The stone walkways lie on either side of where the "
    "stream would usually be, providing access to city workers, should the "
    "need arise. ",
  ({ "torches" }) : "The old wooden torches flicker, providing light to "
    "the area.",
  ({ "walls" }) : "Sleeping mats line the walls, whilst wooden torches are "
    "fixed to them, gently illuminating the area.",
  ({ "mats" }) : "The sleeping mats are arranged neatly along the walls, "
    "providing what must be very uncomfortable places to sleep.",
  ({ "chairs" }) : "Numerous chairs are set up by a few wooden tables.",
  ({ "tables" }) : "The tables, placed in the area where the stream would "
    "usually be, act as focal point for daily discussion as well as a place "
    "to eat meals.",
  ]) );
  SetItemAdjectives( ([
    "system" : ({ "sewer" }),    
    "stream" : ({ "filthy" }),
    "walkways" : ({ "stone" }),
    "torches" : ({ "old", "wooden" }),
    "walls" : ({ "stone" }),
    "mats" : ({ "sleeping" }),
    "tables" : ({ "wooden" }),
    "chairs" : ({ "numerous" }),    
  ]) );
  SetInventory( ([    
    SEWERS_NPC "bandit" : 2,
    SEWERS_NPC "bandit2" : 2,
  ]) );
  SetListen( ([
    "default" : "The sound of the trickling stream is faint here.",
  ]) );
  SetSmell( ([
    "default" : "The sewer smells horrible.",    
  ]) );
  SetExits( ([  
    "west" : SEWERS_ROOM "sewer5",
    "east" : SEWERS_ROOM "sewer9",
  ]) );  
}