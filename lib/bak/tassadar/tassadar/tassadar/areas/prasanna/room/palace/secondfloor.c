#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("prasanna");
   SetClimate("indoors");
   SetShort("the second floor balcony");
   SetLong("The second floor of the palace is lavishly decorated, "
           "perhaps even more-so than the first floor. The floors "
           "are brilliantly polished black marble, with thin white "
           "streaks arching through the stone. A circular balcony "
           "winds around the wide tower, giving view down into the "
           "hallway below. A large hallway on the far side of the "
           "balcony leads deeper into the palace.",);   SetItems( ([
      ({ "floors","floor" }) :
         "The floors here are skillfully crafted from black marble, "
         "and appear to be painstakingly cared for.",
      ({ "marble staircase","staircase","stairs" }) :
         "This marble staircase is beautifully carved from virgin "
         "white marble. It winds it's way down to the first floor of "
         "the palace.",
      ({ "view" }) :
         "You can see down the stairs into the hallway below.", 
      ({ "walls","wall" }) :
         "The walls of the palace are carved from granite, with marble"
         "overlays to add the appearance of sculpture all along ghout "
         "the palace.",
      ({ "long hallway","hallway" }) :
         "This hallway stretches on for quite some way, leading to , "
         "other parts of the palace.",
      ({ "black marble","marble" }) :
         "The marble making up the floors is a deep shade of black, "
         "a few streaks of white moving through it.",
      ({ "palace" }) :
         "The palace of Maeralin is immaculate and beautiful. A warm "
         "breeze drifts through the estate, making it seem almost "
         "inviting.",
      ({ "streaks","streak" }) :
         "Streaks of white glide through the black marble, giving the "
         "floor a slightly lighter appearance.",
   ]) );
   SetExits( ([ 
      "east" : PA_ROOM "/uphall",
      "down" : PA_ROOM "/hallway2", 
   ]) );
   SetListen( ([ 
       "default" : "A calming silence resides in the upper level of "
                   "the palace." 
   ]) );
}

