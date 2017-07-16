// Title: Durgoroth Town
// File: cave03.c
// Author: Timothy Morris aka Morgoth@Haven
// Date: March 1998
//
//
// Revision History: 
//
// Recreated by Arika - Jan 1999

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
     room::create();
     SetShort("a dark room deep in the cave");
     SetLong("This section of the cave system is not quite "
                  "as neatly hewn as the other sections.  The room "
                  "looks like it was carved out rather rapidly.  There "
                  "is a rough cut exit to the north, and the "
                  "throne room can be seen back to the east.  In one "
                  "corner of the room is a pile of small blankets and "
                  "a stack of tomes of some sort."
                  );
     SetObviousExits("north, east");
     SetClimate("indoors");
     SetDomain("FrostMarches");
     SetAmbientLight(25);
     SetItems( ([
          ({"room","chamber","cave"}) : (: GetLong :),
          ({"pile of small blankets", "pile of blankets","small blankets",
          "blankets"}) : "The blankets in the pile look very old "
               "and they are not extremely clean.  They look like "
               "they've been used more for sitting than for warmth.",
          ({"stack of tomes","tomes","stack"}) : "The stack of books "
               "is made up primarily of religious tomes of Saahagoth, "
               "though a few are written in an arcane language that is "
               "unreadble.",
          ({"throne room"}) : "The throne room can barely be seen "
                "back to the east.  Shadows mask most of it from this "
                "angle though.",
          ]) );
     SetExits( ([
          "east"  : D_ROOM + "/cave03.c",
          "north" : D_ROOM + "/cave07",
          ]) );
     SetInventory( ([
/*
          D_NPC + "/shaman" : 1,
*/
          ]) );
     }
