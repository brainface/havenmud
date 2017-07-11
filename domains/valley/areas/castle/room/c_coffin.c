#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(5);
   SetShort("inside a coffin");
   SetLong("Whatever dead thing used to inhabit this coffin has "
           "been removed, but it has left trace signs on the "
           "innards of the coffin.  A few scraps of fabric "
           "have remained in side, tarnished beyond all usefullness.  "
           "The lid to the coffin is the covering for the only "
           "exit; it heads out.");
   SetItems( ([
                ({ "inside a coffin","coffin","innards","innard" }) :
                   (: GetLong :),
                ({ "scraps of fabric","scrap of fabric","scraps"
                   "scrap","fabric" }) :
                   "The fabric looks like missing threads and torn "
                   "corners of a fancy burial garmet.",
           ]) );
   SetExits( ([
                "out" : VC_ROOM + "/c_side1",
           ]) );
}