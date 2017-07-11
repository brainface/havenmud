#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("inside a burial vault");
   SetLong("Various hollowed out recesses of the crypt are "
           "unfilled currently, though a few dead bodies lay in "
           "their beds.  A couple of fresh torches light the room, "
           "but flicker slowly in the stirred air, burning towards "
           "extinction.  An opening leads out to the west.");
   SetItems( ([
                ({ "fresh torches","torches","fresh torch","torch" }) :
                   "The torches are fresh and new, burning brightly "
                   "for such a dark area.  It does not seem likely "
                   "that they will be refreshed until another member "
                   "of the nobility of this castle dies.",
                ({ "burial vault","room","vault","opening","crypt",
                   "castle" }) :
                   (: GetLong :),
                ({ "hollowed out recesses","hollowed out recess",
                   "recess","recesses","dead bodies","bodies",
                   "dead body","body","nooks","nook","wall","holes",
                   "hole" }) :
                   "The nooks in the wall were made for the dead, "
                   "and some are even filled.  The bodies that are "
                   "in the holes are fresh, as far as dead bodies go.",
           ]) );
   SetExits( ([
                "west" : VC_ROOM + "/c_hall1",
           ]) );
   SetInventory( ([
                    VC_NPC + "/c_ghoul" : 1,
               ]) );
}
