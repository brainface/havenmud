#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

int PreExit();

static void create() {
  room::create();
  
  SetAmbientLight(10);
  SetClimate("indoors"); 
  SetShort("a creepy basement");
  SetLong(
     "Wooden shelves line the walls of this basement room, some "
     "of them barely hanging in place as the rest lay broken on the "
     "floor. A giant trunk lies off in the corner, surrounded by shards "
     "of broken glass and pieces of rotted wood. The air here is "
     "oppressive, and mixed with the dark and dust, makes the room almost "
     "intolerable. A small trickle of light streams down the staircase "
     "that leads back up into the main part of the lodge."
     );
  SetSmell( ([
     "default" : "The putrid smell of decay and mold are almost smothering.",
     ]) );
  SetListen( ([
     "default" : "The sounds of scrapping on dry wood fill the air.",
     ]) );
  SetItems( ([
     ({"basement","room"}) : (:GetLong:),
     ({"glass","jar","jars"}) : "The edges of the glass are very rugged "
       "and sharp.  The jars seem to have fallen off of the shelves where "
       "they belong.  Slight bits of dust has collected on this glass.",
     ({"wall","walls"}) : "Nothing interesting is found here.  It's cold "
       "and hard. The walls are so old they have start to peel.",
     ({"ground","floor"}) : "Glass has been spread all around.  Other "
       "than that there is nothing to see here.",
     ({"stair","stairs","staircase"}) : "These stairs do not look very "
       "durable. The wood is decayed and has been eatten away at.  One "
       "must be careful to not put too much weight on here.",
     ({"trunk","chest"}) : "This trunk is open. The bottom of the trunk "
       "appears to have been completely clawed and gnawed at, revealing "
       "a pit dug into the very bowels of Kailie.  The trunk certainly "
       "seems large enough to go down in.",
     ]) );
  SetItemAdjectives( ([
     "glass" : ({"sharp","rugged"}),
     "wall" : ({"cold","hard"}),
     "trunk" : ({"large"}),
     ]) );
  SetInventory( ([
     ]) );
  AddEnter("trunk", L_ROOM + "guardroom.c", (: PreExit :));
  SetExits( ([
     "up" : L_ROOM + "mainfloor.c",
     ]) );

}
int PreExit() {
     this_player()->eventPrint("You crawl through the hole in the trunk."); 
     return 1;
}
