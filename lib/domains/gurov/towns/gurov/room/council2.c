#include <lib.h>
inherit LIB_POST_OFFICE;
#include "../gurov.h"

static void create() {
   post_office::create();
   SetTown("Gurov");
   SetClimate("indoors");
   
   SetAmbientLight(50);
   SetShort("the post office");
   SetLong("To one side of the room is an area write mail and "
           "send mail and pick up mail, while other mail-related "
           "paraphernalia is scattered about the room on the tops "
           "of the smooth wooden counters and tall stools. \n"
           "Type <mail> to access mail or <news> for the board.");
   SetItems( ([
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
                   "has been spilled upon the stools. "
                   "The mail system can be accessed by typing <mail> and "
                   "then pressing return.",
           ]) );
   SetExits( ([
                "east" : GUROV_ROOM "council1",
           ]) );
}
