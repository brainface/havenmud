#include <lib.h>
#include "/domains/havenwood/towns/parva/parva.h"
#include "/domains/havenwood/areas/assassin_hall/assassin_hall.h"

inherit LIB_ROOM;

static void create()
{
   room::create();
   SetTown("Parva");
   SetDomain("HavenWood");
   SetAmbientLight(25);
   SetClimate("indoors");
   SetShort("a dusty hallway");
   SetLong("the dank hallway is comprised of brick walls which support "
                  "a wooden ceiling. The ground is hard packed dirt, slightly "
                  "slippery with condensation. To the east is a well lit room "
                  "and to the west the dark corridor continues.");
   SetItems( ([
                ({ "brick walls", "walls", "wall" }) : "The bricks are a rotting "
                    "black color.",
                ({ "wooden ceiling", "ceiling" }) : "The ceiling is comprised of "
                    "long rotting boards holding up the dirt overhead.",
                ({ "ground", "dirt" }) : "The dirt was long packed solid by the "
                     "feet of many.",
                ({ "dark corridor", "corridor" }) : (:GetLong():)
                 ]) );

   SetListen( ([
                 "default" : "Water stirs faintly to the east."
            ]) );
   SetSmell( ([
                "default" : "The smell of rot is purveyed by the putrid ground "
                                 "underfoot."
           ]) );

   SetExits( ([
                "west"  : AH_ROOM + "underinn",
                "east"  : AH_ROOM + "assassin_guildhall",
           ]) );
  SetProperty("no magic", 1);
  SetProperty("no attack", 1);

     SetProperties ( (["no bump" : 1]) );
     SetProperties ( (["no teleport" : 1]) );
}
