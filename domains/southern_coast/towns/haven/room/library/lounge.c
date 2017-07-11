//
// The Library's Lounge
// Filename: lounge.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;
int BeenDone;
void DoSearch();

static void create() {
   room::create();
   SetShort("a lounge in the Library");
   SetExits( ([
      "south" : "entrance",
   ]) );
   SetClimate("indoors");
   SetAmbientLight(40);
   SetLong("Furniture lies tastefully arranged in here, each piece positioned "
           "to assist the room to the fullest in its function as a place "
           "where the horrors of magical training can be forgotten for a few "
           "brief moments. The various chairs and sofas sit facing a large "
           "but empty fireplace which is obviously more for aestethics "
           "than for practical use. A few books lie on neatly coordinated "
           "tables, but it is obvious from their positions that they are "
           "for show and not to be touched.");
   SetItems( ([
      ({ "book", "books" }) : 
         "The books are light reading having little to do with magic.",
      ({ "table", "tables" }) : 
         "The oaken tables make for sturdy support of the books.",
      ({ "chair", "chairs" }) : 
         "These are upholstered chairs built to hold one average "
         "massing elf.",
      ({ "sofa", "sofas" }) : 
         "The sofas are upholstered seating designed to support a "
         "relaxing mage or two.",
      ({ "furniture" }) :
         "The furniture here consists of various chairs and sofas "
         "around the room.",
      ({ "fireplace" }) : 
         "The fireplace has obviously never been used, judging from "
         "its spotless appearance.",
   ]) );
   SetItemAdjectives( ([
      "book" : ({ "magical" }),
      "table" : ({ "oaken", "oak" }),
      "chair" : ({ "upholstered" }),
      "sofa" : ({ "upholstered" }),
      "fireplace" : ({ "large", "empty" }),
   ]) );
   SetSearch( (["books" : (: DoSearch :) ]) );
   SetSmell( ([
      "default" : "The smells of old books and soft velvet are in the air.",
   ]) );
   SetListen( ([
      "default" : "The sounds of quiet chatter fill the room.",
   ]) );
   SetInventory( ([
      H_NPC + "student" : 2,
   ]) );
}


varargs void reset(int count) {
   room::reset();
  BeenDone = 0;
  }
void DoSearch() {
  if (BeenDone) {
      message("blah", "You don't find a thing.", this_player());
      return;
         }
    new(H_OBJ + "/scroll1")->eventMove(this_player());
  BeenDone = 1;
  message("blah", "You find a scroll!", this_player());
   }
/* Approved by Duuktsaryth on Sun Apr 25 19:21:29 1999. */
