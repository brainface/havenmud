//
// The Common Room of the Inn
// Filename: inn2.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
// Urien - Fixed SetLong -- Added Smell and Listen

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("the common room of the inn");
   SetExits( ([
      "down" : "inn",
      "up" : "inn3",
   ]) );
   SetClimate("indoors");
   SetAmbientLight(30);
   SetLong("This is the common sleeping room of Rupert's Hole, "
           "the finest inn in Haven Town.  The room emanates an "
           "aura of peace that gives even staunch warriors cause "
           "to rest easy.");
   SetSmell( ([
      "default" : "This sleeping room smells pleasant.",
   ]) );
   SetListen( ([ 
      "default" : "Ihere is a relaxing silence in here.",
   ]) );
   SetProperty("no attack",1);
   SetProperty("no bump", 1);
   SetProperty("no magic", 1);
   SetItems( ([
      ({ "hole", "inn" }) :
         "This room is part of Ruper's Hole, the finest inn in " 
         "Haven Town.",
      ({ "aura" }) :
         "This aura of peace cannot be seen, but can be felt.",
      ({ "warrior", "warriors" }) :
         "Many warriors come here to rest their bones.",
   ]) );
   SetItemAdjectives( ([ 
      "hole" : ({ "rupert's" }),
      "aura" : ({ "peace" }),
      "warrior" : ({ "staunch" }),
   ]) );
}


/* Approved by Duuktsaryth on Tue Apr 27 21:14:44 1999. */
