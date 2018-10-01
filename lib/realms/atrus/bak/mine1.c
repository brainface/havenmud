/*    /realms/haun/areas/mines/rooms/mine1.c
 *    created on 12/20/98
 *    by Haun
 */

#include <lib.h>
/*
#include "../mine1.h"
*/
inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(10);
    SetClimate("underground");
    SetShort("a dark cave");
    SetLong("A very large cave lies here in which the light is very dim."
      " Sounds that are transmitted from any source are echoed throughout"
      " the mines, causing the walls and floor to lightly shake."
      "  The floor here is drenched with water, which makes the"
      " rock very slippery.  There seems to be a light mist in the"
      " air, that is entering the cave from above.  A light is"
      " flickering in the distance.");
    SetItems( ([
	({"cave", "mines", "mine"})  :  (: GetLong :),
	({"wall", "ceiling", "earth", "above", "rock", "walls"}) :
	"The walls of this cave are made of hard, solid rock."
	" It has a dull, gray color, which has long tan streaks on it were"
	" water has dripped down the wall.  Sound seems to bounce off"
	" of them.",
	({"entrance"})  :
	"The entrance to this cave is to the south.  The hole which leads"
	" up is barely visible.",
	({"light", "distance"})  :
	"In the distance there is a faint light which seems to be"
	" flickering.  The light is very dim and is barely enough to"
	" light the cave.",
	({"mist", "water"})  :
	"The mist and water is slowly dripping from the ceiling.  The water"
	" is a murky brown color.  Both of these are covering the floor"
	" of the cave, making it very slippery.",
	({"floor", "floors", "puddles"})  :
	"Holes and cracks in the ground, filled with water to form puddles."
	" Water and mist that is coming from the ceiling is covering the"
	" ground making it very wet and slippery.  The floor is made"
	" from rock, and looks identical to the walls, and ceiling." ,
	({"mist"})  :
	"Light mist is entering the room from the stream that lies in the"
	" bedrock above.  It is spraying down lightly in the room, making"
	" the walls and floors wet.",
      ]) );


    SetItemAdjectives( ([
	"cave"    :  ({"dark", "damp", "gray", "large"}),
	"earth"    :  ({"wet", "gray"}),
	"light"  :  ({"dim", "flickering"}),
	"stream"    :  ({"dripping", "underground", "small"}),
	"entrance"    :  ({"covered", "hidden", "concealed", "wide"}),
	"rock"   :  ({"solid", "hard", "grey", "wet", "slippery"}),
	"water"    :  ({"wet", "dripping", "murky", "brown"}),
	"mist"   :  ({"light", "wet"}),
	"air"    :  ({"stale", "damp"}),
	"holes"    :  ({"small", "round"}),
	"puddles"    :  ({"large", "small", "wet"}),
      ]) );

    SetSmell( ([
	"default"  :  "The smell of stale water lingers in the air",
      ]) );
    SetListen( ([
	"default"  :  "The sound of dripping water and mist is heard.",

      ]) );


    SetExits( ([
    "north" : "/realms/tassadar/workroom",

  ]) );
}
