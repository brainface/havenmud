#include <lib.h>
inherit LIB_POST_OFFICE;
#include "../soleil.h"

static void create() {
   post_office::create();
   SetTown("Soleil");
   SetClimate("indoors");
   
   SetAmbientLight(50);
   SetShort("the post office");
   SetLong("To one side of the room is an area write mail and "
           "send mail and pick up mail, while other mail-related "
           "paraphernalia is scattered about the room on the tops "
           "of the smooth wooden counters and tall stools.  A staircase "
           "leads down into the townhall and bank.");
   SetItems( ([
                ({ "downward staircase","stairs","stair","town hall",
                   "townhall","hall","bank" }) :
                   "The staircase leads down to the townhall and "
                   "bank.",
                ({ "post office","room","office" }) :
                   (: GetLong :),
                ({ "mail writting area","area","mail",
                   "mail-related paraphernalia","paraphernalia",
                   "tops","top","smooth wooden counters","tall stools",
                   "smooth wooden counter","tall stool","stool","stools",
                   "smooth counters","smooth counter","wooden counters",
                   "wooden counter","counter","counters","ink" }) : 
                   "Everything having to do with mail is strewn about "
                   "the room and across the counters, and some ink "
                   "has been spilled upon the stools.   At the end "
                   "of each day or so, Aegri Portare, the banker, goes "
                   "and sends out the old mail and collects all the new.  "
                   "The mail system can be accessed by typing <mail> and "
                   "then pressing return.",
           ]) );
   SetObviousExits("down");
   SetExits( ([
                "down" : S_ROOM + "townhall",
           ]) );
}
