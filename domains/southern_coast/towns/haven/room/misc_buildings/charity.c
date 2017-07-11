//
// A Player Inn
// Filename: p_inn2.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("the Elven Aide Charity");
   SetAmbientLight(35);
   SetClimate("indoors");
   SetInventory( ([
     H_NPC "equipper" : 1,
     H_NPC "controller" : 1,
       H_OBJ "donation" : 1, // should be fixed
     H_NPC "escort" : 1,
     ]) );
   SetLong(
     "The Elven Aide Charity is a well run and tightly managed organization "
     "that maintains equipment for young elves (and humans and half-elves) "
     "that need assistance while learning the ways of Kailie. Scattered around "
     "the office are various fishing poles, swords, and other equipment that "
     "anyone would be pleased to have."
     );
   SetSmell("The office has a pleasant and friendly smell.");
   SetListen("The office is peaceful and quiet.");
   SetProperty("no attack", 1);
   SetProperty("no bump", 1);
   SetProperty("no magic", 1);
   SetItems( ([
     ({ "equipment", "pole", "poles", "sword", "swords" }) : 
         "This is all equipment that could be provided should someone be here "
         "to assist.",
     ]) );
   SetExits( ([
     "out" : H_ROOM "merchants_way/mw4",
     "up"  : H_ROOM "misc_buildings/start_room",
     ]) );     
}


/* Approved by Duuktsaryth on Tue Apr 27 21:14:05 1999. */
