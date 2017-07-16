#include <lib.h>
#include "../ph.h"
inherit LIB_ROOM;

string Searchme();
int searched = 0;

static void create() {
   room::create();
   searched = 0;
   SetDomain("Havenwood");
   SetShort("a storage room");
   SetClimate("indoors");
   SetTown("Parva");
   SetAmbientLight(20);
   SetLong("Beneath the main part of the Parva Hospital is this storage room, "
           "which holds the supplies for the main rooms above.  A staircase "
           "leads to a hatchway that gives access to the entrance of the "
           "hospital.");
   SetItems( ([
                ({ "storage room","room","hospital","rooms" }) : (: GetLong :),
                ({ "staircase","stairs","stair" }) :
                   "The wooden stairs lead to the rooms above, giving access "
                   "through a hatchway.",
                ({ "hospital supplies","supply","supplies" }) :
                   "The supplies consist primarily of things like "
                   "spare bandages and bedding.",
                ({ "spare bandages","bandages","bandage","bedding" }) :
                   "The spare bandages and bedding are the main supplies "
                   "kept in this storage room.  They are all carefully "
                   "organized by size and condition.",
           ]) );
   SetListen( ([
                 "default" : "The ceiling creaks.",
            ]) );
   SetSmell( ([
                "default" : "A musty scent hangs around the supplies.",
           ]) );
   SetExits( ([
                "up" : PR + "/entrance",
           ]) );
   SetDoor("up",PR + "/hatch");
   SetInventory( ([
                    PN + "/janitor" : 1,
                    PN + "/edoc" : 1,
               ]) );
   SetSearch( ([ "supplies" : (: Searchme :) ]) );
}

string Searchme() {
   object blah;
   if(searched) {
      message("my_action","You don't find a thing.",this_player());
      return "";
   }
   searched = 1;
   blah = new(PO + "/cabinetkey");
   blah->eventMove(this_player());
   message("my_action","You find a brass key under an ancient pile of supplies.",
           this_player());
   return "";
}
