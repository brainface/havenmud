//Selket@Haven
//2006
#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;
int CheckPC();

static void create() {

  room::create();
  SetShort("inside a stone stable");
  SetClimate("indoors");
  SetAmbientLight(25);
  SetLong(
    "This stone stable is dark from lack of windows. Instead of "
    "the usual tack and bales of hay one might expect to find in "
    "here, a few rotting animal carcasses stand in one corner. "
    "There is a gated pen one could walk into, and an exit back "
    "into the city."
    );
  SetSmell("The scent of death is strong here.");
  SetListen("There is a scuffling coming from the pen.");
  SetItems( ([
    ({ "stable" }) :
       (: GetLong :),
    ({ "carcasses", "carcass" }) :
    "The carcasses are of whole deer and cattle.",
    ({ "pen" }) : 
    "The gate to the pen stands open.",
    ]) );
    AddEnter("pen", U_ROOM "pen", (:CheckPC:) );
  SetExits( ([
    "out" : U_ROOM + "road05",
    ]) );
  }
int CheckPC() {
    if (this_player()->id("troll_wander")) return 0;
      else return 1;
  }
