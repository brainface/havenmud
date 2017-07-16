#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(25);
   SetShort("slave quarters");
   SetLong("Dug into the dirt is this small room, the quarters for "
           "the slaves that serve this castle.  There cannot be many, "
           "as there are few beds, but possibly the servants will "
           "sleep in this room.  One torch lights the area, "
           "placed near the trapdoor and ladder than lead out.");
   SetItems( ([
                ({ "lit torch","torch","ladder" }) :
                   "Near the ladder, close enough to reach out and "
                   "light or extinguish it from there, is a lit "
                   "torch that serves as the room's sole light source.",
                ({ "slave quarters","slave quarter","quarters",
                   "quarter","small room","castle","room","area"
                   "dirt" }) :
                   (: GetLong :),
                ({ "rickety wooden beds","rickety wooden bed","bed","beds",
                   "rickety bed","rickety beds","wooden bed",
                   "wooden beds","warm blankets","warm blankets",
                   "blanket","blankets" }) :
                   "Dirt is rubbed into the rickety wooden beds which "
                   "are enough to service the slaves and occasionally "
                   "the servants of the castle.  However, warm blankets "
                   "lie upon each bed; the Lord provides somewhat for "
                   "his slaves.",
           ]) );
   SetExits( ([
                "up" : VC_ROOM + "/hall2",
           ]) );
   SetInventory( ([
                    VC_NPC + "/slave_m" : 2,
                    VC_NPC + "/slave_f" : 2,
               ]) );
}
