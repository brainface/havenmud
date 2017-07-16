#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../starfire.h"

inherit LIB_ROOM;
int CheckMe();
static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(15);
  SetShort("the temple");
  SetLong(
      "This is a vast chamber with rows and rows of seating. The pews are separated"
      " to allow a large walkway between them. Enormous stone columns support the"
      " ceiling. To the east and west small alcoves can be accessed. There is also a"
      " doorway at the northern end of the apse. The apse itself is a great semi-domed"
      " recession at the northern end of the temple that houses the great Altar. A thin"
      " layer of sand has collected to cover the floor here."
      );
  SetItems( ([
        ({ "sand", "floor", "pile", "piles" }) :
         "The floor is covered with a thin layer of sand. In some spots it has collected"
         " into small piles making it hard to determine any specifics about the"
         " underlying construction.",
	({ "pew", "pews" }) :
	  "There are close to one hundred pews on either side of the walkway. They"
          " are well crafted stone materials and do not look as if they would be"
          " very comfortable to sit on for any period of time, let alone a long"
          " service.",
	({ "walkway", "aisle" }) :
       	  "The walkway is about thirty feet wide. On either side are rows of"
	  " pews made of stone. The stone floor has been worn smooth from years"
	  " of use however, a thin layer of sand covers it.",
	({ "temple", "here", "around", "chamber" }) :
	  (: GetLong :),
	({ "apse", "dome" }) :
	  "The apse is located at the northern end of the temple. It is a"
          " semi-circular recess with a domed top. The ceiling of the dome is"
          " painted with a mural that is too worn and old to make out what"	
	  " it is supposed to depict exactly.",
	({ "column", "columns" }) :
	  "The huge columns that support the ceiling are made of the same"
	  " stone as the floors and walls. They are smooth with bevelled bases."
	  " There are about thirty of them spread evenly throughout the chamber"
	  " in a circular pattern.",
        ({ "alcove", "alcoves" }) :
          "One could access the alcoves by going either east or west from this room.",
        ({ "door", "doorway" }) :
          "On the northern end of the apse there is an arched doorway leading further"
          " north.",
	]) );
  SetItemAdjectives( ([
	"apse"   : ({ "domed", "great", "recessed" }),
	"temple" : ({ "vast", "great", "large" }),
	"column" : ({ "huge", "stone", "enormous", "smooth" }),
        "alcove" : ({ "east", "eastern", "west", "western" }),
        "door"   : ({ "north", "northern", "arched" }),
        "sand"   : ({ "thin", "piled" }),
	]) );
  SetListen( ([
	"default" : "Your footsteps echo throughout the chamber."
	]) );
  SetInventory( ([
//	SF_OBJ "altar" : 1,
	]) );
  SetExits( ([
      "south" : SF_ROOM "room02",
      "east"  : SF_ROOM "room05",
      "west"  : SF_ROOM "room04" 
      ]) );
  AddExit("north", SF_ROOM "room06", (:CheckMe:));
  }

int CheckMe() {
object who;
who = this_player();

if (SF_ROOM "room06"->GetProperty("westlamplit") == 1 && 
    SF_ROOM "room06"->GetProperty("eastlamplit") == 1 &&
    SF_ROOM "room06"->GetProperty("announced") != 1) {

     eventPrint("A rumble comes from the north");
     SF_ROOM "room06"->AddExit("north", SF_ROOM "room07");
     SF_ROOM "room06"->SetProperty("announced", 1);
     return 1;
  }
     return 1;
}
