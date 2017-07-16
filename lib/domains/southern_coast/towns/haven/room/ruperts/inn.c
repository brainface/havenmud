//
// Rupert's Hole
// Filename: inn.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include <std.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("Rupert's Hole");
   SetClimate("indoors");
   SetAmbientLight(45);
   SetObviousExits("out, up");
   SetExits( ([
      "out" : H_ROOM + "imperial_road/ir4",
      "up" : "inn2",
   ]) );
   SetLong("This inn is one of the finer establishments in Haven Town. "
           "The tables and benches are well kept and the floors are "
           "fairly clean.  There is a set of stairs leading up into "
           "the common sleeping room of the inn.");
   SetSmell( ([
      "default" : "The room smells of good food.",
   ]) );
   SetNewsgroups( ({ "player.general" }) );
   SetListen( ([ 
      "default" : "The din of conversation carries across the room.",
   ]) );
   SetItems( ([
      ({ "inn", "establishment" }) :
         (: GetLong :),
      ({ "table", "tables", "bench", "benches", "furniture" }) :
         "The furniture is well scrubbed and splinter free.",
      ({ "floor", "floors" }) :
         "The floors here are fairly clean.",
      ({ "stairs" }) :
         "These stairs lead up into the sleeping room.",
      ({ "room" }) :
         "The sleeping room can be accessed by going up the stairs.",
   ]) );
   SetItemAdjectives( ([
      "inn" : ({ "finer" }),
      "stairs" : ({ "set of" }),
      "room" : ({ "common", "sleeping" }),
   ]) );
   SetInventory( ([
      H_NPC   + "rupert"  : 1,
      H_NPC     "acrobat" : 1,
   ]) );
}


/* Approved by Duuktsaryth on Tue Apr 27 21:14:35 1999. */
