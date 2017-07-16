#include <lib.h>
#include <std.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetDomain("FrostMarches");
  SetShort("a cemetery");
  SetTown("Keryth");
  SetClimate("arctic");
  SetExits( ([ "out" : K_ROOM + "/road4" ]) );
  SetLong("The cemetery in Keryth is a strangely pleasant place to be.  It "
          "is a snow blanketed field which sprawls out and must contain "
          "several generations of citizens.  The only exit is back out to "
          "the road.");
  SetItems( ([
    ({ "plesant cemetery", "cemetery", "grassy field", "field" }) :
       (:GetLong:),
    ({ "snow blanket", "snow", "blanket" }) :
       "The undisturbed blanket of snow spreads across this grassy field, "
       "covering the sunken graves.",
    ({ "old worn gravestones", "worn gravestones", "old gravestones",
       "old gravestone", "gravestones", "gravestone", "worn gravestone" }) : 
       "The gravestones look very old.  All but a few of the inscriptions on "
       "them have been worn down.",
    ({ "readable worn inscriptions", "worn inscription", "inscription",
       "inscriptions", "worn inscriptions", "readable inscriptions",
       "readable inscription", "readable worn inscription" }): 
       "The only readable inscription proclaims:  Harriet Trimble, mother "
       "and daughter, wife and friend. She was loved by many.  RIP.",
    ({ "sunken graves", "graves", "grave", "sunken grave", "jagged lines",
       "lines", "plots", "plot" }) :
       "The sunken graves are assembled in jagged lines that stretch to each "
       "end of this field.  Most of the graves have stones at the head of "
       "each plot."
  ]) );
  SetListen( ([
    "default" : "A light breeze whistles across these graves."
  ]) );
  SetInventory( ([
    STD_OBJ "reztotem" : 1,
    K_NPC + "/necromancer" : 1,
  ]) );
}
