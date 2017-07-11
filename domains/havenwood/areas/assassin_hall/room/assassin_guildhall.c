#include <lib.h>
#include "/domains/havenwood/towns/parva/parva.h"
#include "/domains/havenwood/areas/assassin_hall/assassin_hall.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetAmbientLight(40);
   SetClimate("indoors");
   SetShort("The Organization Hall");
   SetLong(
     "The guild hall is furnished garishly with plush leather chairs "
     "and sofas. A great table resides in the center of the room, "
     "presumably appreciated for its expansive, if marred, surface. "
     "The floor and ceiling consist of brick supported by syncopated "
     "pillars. A small hole in the brick walls leads east, out toward "
     "the sea. A passage leads off west back into the hidden entrance."
     );
   SetItems( ([
     ({ "chairs", "sofas", "leather chairs" }) : "The plush padded "
            "leather was made by some of the finest craftsmen in Parva.",
     ({ "table", "great table" }) : "The fine surface is marred by knife "
            "gouges and the discoloration's of spilt drinks.",
     ({ "floor", "ceiling", "brick", "pillars"}) : "The bricks were laid "
            "by the finest craftsmen in Parva.",
     ({ "hole" }) : "It's a hole leading out to the sea."
    ]) );
  SetListen("Water can be heard lapping against the dock outside the hall.");     
  SetSmell("The smell of the hall is clean and inviting with an underlying stench of salt water.");
  SetExits( ([
    "east" : AH_ROOM + "corridor1",
    ]) );
  SetInventory( ([
    ]) );
  SetNewsgroups( ({ "guild.twilight" }) );
  SetProperty("no magic", 1);
  SetProperty("no attack", 1);
  SetProperties ( (["no bump" : 1]) );
  SetProperties ( (["no teleport" : 1]) );

}
