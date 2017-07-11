// Eclat only check taken out
// per Duuk, this is dumb
#include <lib.h>
inherit LIB_ROOM;
#include "../hospital.h"

int PreExit();
int PreExit2();

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(45);
   SetShort("the waiting room");
   SetLong("The hospital walls have been painted a bold white, and the "
           "ceiling and floor and similarly colored.  In fact, "
           "everything here is white, including the receptionist "
           "desk and the patient chairs and the tables with strange "
           "odds and ends on them.  A door in the east wall leads out, "
           "while doorways to the north and south lead into the rest of "
           "the hospital.");
   SetItems( ([
                ({ "white doorways","doorways","doorway",
                   "door","openings","opening" }) :
                   "The walls to the north and the south have circular "
                   "openings in them, designed so that people could "
                   "be carried through with ease.",
                ({ "receptionist desk","desk" }) :
                   "The desk is used by the recptionist for welcoming "
                   "patients and getting them doctors and beds and "
                   "treatment.  It is white, just like the rest of the "
                   "room.",
                ({ "patient chairs","patient chair","chair","chairs" }) :
                   "The chairs are clearly for the patients that must "
                   "wait in line for the receptionist when it is a "
                   "busy day.  They also appear to be for the visitors "
                   "who have come looking for friends or relatives, "
                   "planning to cheer their day with a comfortable "
                   "face.",
                ({ "white tables","white table","table","tables" }) :
                   "Every three or four chairs, there is a white "
                   "table with a few items of amusement on it.  "
                   "These odds and ends are varied, but all seem "
                   "like the type that would keep people calm and "
                   "unfrustrated.",
                ({ "odds and ends","odds","ends","end","odd","toys",
                   "toy","puzzle","puzzles" }) :
                   "The white tables are topped off with some "
                   "odds and ends of various peculiar natures.  "
                   "Many look like toys or puzzles.",
                ({ "eclat hospital","hospital" }) :
                   "The hospital was built years ago by the Eclat monks "
                   "from the monastery.  It was quite a trip, but they "
                   "worked hard and trained a number of clerics and "
                   "monks to come and heal the sick muezzins and other "
                   "beings that have come to plead for help.",
                ({ "waiting room","room" }) :
                   (: GetLong :),
                ({ "white walls","white wall","walls","wall",
                   "hospital walls","hospital wall","ceiling",
                   "floor" }) :
                   "The walls of the hospital shine a perfect white, "
                   "accompanied by the ceiling and floor.  There are "
                   "openings in the north and south wall that lead into "
                   "the rest of the hospital, and a door in the "
                   "east wall that leads back out into the harsh "
                   "world.  Hardly visible except for the light they "
                   "cast are rows of little golden balls along the "
                   "corners made by the joining of the ceiling and "
                   "walls.",
                ({ "rows of little golden balls","row of little golden "
                   "balls","row","rows","little golden balls","balls",
                   "little golden ball","ball","golden ball",
                   "golden balls","little balls","little ball",
                   "rows of balls","row of balls","row of little balls",
                   "rows of little balls","row of golden balls","rows of "
                   "golden balls" }) :
                   "The balls are tiny things, and appear almost "
                   "ornamental, but light the room brillantly.",
           ]) );
   SetItemAdjectives( ([
                         "white doorways" : ({ "white","circular" }),
                         "rows of little golden balls" : ({ "neat",
                               "rows of","row of","little","golden" }),
                         "white walls" : ({ "white","hospital","clean" }),
                         "white tables" : ({ "white","hospital","clean" }),
                         "patient chairs" : ({ "white","hospital","clean",
                                               "patient" }),
                    ]) );
   SetListen( ([
                 "default" : "Groans can be heard from the north and "
                    "south, but all is calm here.",
            ]) );
   SetSmell( ([
                "default" : "The room smells fresh and clean.",
           ]) );
   SetDoor("out",H_ROOM + "door");
   AddExit("south",H_ROOM + "r5", (: PreExit :) );
   AddExit("north",H_ROOM + "r2", (: PreExit :) );
   AddExit("out",H_ROOM + "start", (: PreExit2 :) );
   SetInventory( ([
                    H_NPC + "heal_zoa" : 1,
			  H_NPC + "patient" : 3,
               ]) );
}

int PreExit() {
   object receptionist;
   if(immortalp(this_player())) return 1;
/*
   if(this_player()->GetReligion() == "Eclat") {
      return 1;
   }
   if(this_player()->GetProperty("noleavehospital")) return 1;
   else {
      receptionist = present("receptionist", this_object());
      if( (receptionist) && (living(receptionist)) ) {
         receptionist->eventForce("speak in Oiseau Hey!  You can't "
                                  "go in there.  We have to protect "
                                  "our patients, after all.  Only "
                                  "the Eclats may go in.");
         return 0;
      }
   }
*/
   return 1;
}

int PreExit2() {
   if(this_player()->GetProperty("noleavehospital")) return 0;
   return 1;
}

