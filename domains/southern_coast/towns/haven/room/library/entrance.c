//
// Filename:entrance.c
// The Entrance of the Grand Library of Haven Town
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("entrance to the Grand Library");
   SetClimate("indoors");
   SetAmbientLight(45);
   SetExits( ([
      "out" : "../imperial_road/ir8",
      "east" : "training_hall",
      "north" : "lounge",
   ]) );
   SetLong("The entrance to the Grand Library of Haven Town is "
           "of itself something to behold. The ceiling towers "
           "overhead, seeming to rival the Heavens for its place "
           "as highest point of the universe. Though life outside "
           "the library continues, the Library itself is stately "
           "and quiet to assist in the studies of young mages from "
           "across Kailie. To the east lie the halls of training, "
           "where new mages go to begin the tests and tortures which "
           "will allow them to learn spells and gain in power. To the "
           "north is a small den which looks like a cozy place to relax. ");
   SetSmell( ([
      "default" : "The scents of old books fill the air.",
   ]) );
   SetListen( ([
      "default" : "The air is still and quiet.",
   ]) );
   SetItems( ([
      ({ "entrance" }) :
         (: GetLong :),
      ({ "ceiling" }) : 
         "The ceiling can barely be seen, it rises so high into the air.",
      ({ "den" }) : 
         "The den seems to be a place of repose.",
      ({ "hall", "halls" }) :
         "The halls to the east are only for those of stout heart.",
      ({ "mage", "mages" }) :
         "The many mages of Haven Town study here.",
   ]) );
   SetItemAdjectives( ([
      "hall" : ({ "training" }),
      "den" : ({ "cozy" }),
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 19:20:21 1999. */
