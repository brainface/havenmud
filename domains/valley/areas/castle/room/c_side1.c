#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"


static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(20);
   SetShort("inside a burial vault");
   SetLong("Nooks in the walls are filled with the dead bodies of the "
           "noble ancestors who used to inhabit the castle above.  "
           "All are dressed in what used to be fine clothing, tucked "
           "away in the stone tombs below the castle upon their deaths.  "
           "Two stone tables sit in the middle of the room, with "
           "ornate coffins on top of them.  An opening in the stone leads "
           "east.");
   SetItems( ([
                ({ "nooks in the walls","nook in the wall",
                   "nook","nooks","dead bodies","dead body",
                   "body","bodies","corpse","corpses","fine clothing",
                   "clothing","stone tables","stone table","table",
                   "table","coffins","ornate coffin",
                   "ornate coffins","coffin" }) :
                   "The vault for the dead is full of bodies, "
                   "tucked into the nooks in the walls and stuck "
                   "inside one of the coffins on the tables.  "
                   "Delicate artistry was used to design the clothing "
                   "and coffins for these corpses, but they seem to "
                   "not care as they decay.",
                ({ "coffin farthest from opening","coffin" }) :
                   "The coffin has a lid on it that appears to be "
                   "sealed shut.", 
               ({ "stone walls","stone wall","wall","walls",
                   "torch","opening" }) :
                   "One single torch sits in the back of the room, "
                   "mounted up on the stone wall.  An opening leads out "
                   "to the east.",
                ({ "burial vault","small vault","vault","room",
                   "stone tombs","stone tomb","tombs","tomb" }) :
                   (: GetLong :),
           ]) );
   SetExits( ([
                "east" : VC_ROOM + "/c_hall1",
           ]) );
   SetInventory( ([
                    VC_NPC + "/c_shade" : 1+random(3),
               ]) );
}
