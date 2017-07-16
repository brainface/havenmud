/*    /realms/haun/areas/mines/rooms/entrance.c
 *    created on 12/20/98
 *    by Haun
 */

#include <lib.h>
#include "../mine1.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(10);
    SetClimate("underground");
    SetShort("a dark cave entrance");
    SetLong("This is a very dark cave that appears to be bored deep"
      " into the earth.  It seems that it has been used by miners recently"
      " who could be the producers of the faint light in the"
      " distance.  The caves are very humid, because of a small"
      " underground stream that is running through the bedrock above."
      "  This water is dripping in various places, interrupting the"
      " silence that lingers in the air.  As the water is falling,"
      " it is filling small holes and cracks in the floor, which is"
      " creating small puddles.");
    SetItems( ([
	"cave"  :  (: GetLong :),
	({"wall", "ceiling", "earth", "walls"}) :
	"The walls of this cave are made of hard, solid rock."
	"  It has a dull, gray color, which has long tan streaks on it" 
	" were water has dripped down the wall.",
	({"entrance"})  :
	"The entrance to the cave is a huge opening in the ground."
	" It has many shrubs and vines covering the entrance, almost"
	" completely concealing it from the outside world.",
	({"light", "distance"})  :
	"In the distance there is a faint light which seems to be" 
	" flickering. The light is very dim and is barely enough to light"
	" the cave.",
	({"stream", "bedrock", "water"})  :
	"There are small holes in the ceiling of this cave which are" 
	" dripping water from a sream the lies above it.",
	({"plants", "shrubs"})  :
	"These plants are scattered about the entrance of the cave."
	"  The shrubs help conceal the entrance, to the cave, from the" 
	" outside world.",
	({"vine", "vines"})  :
	"The vines, which are hanging from the cave entrance, range in" 
	" color from the green to the black and brown hues."
	"  They entangle the entire entrance to the cave, seculding"
	" it from the outside world.",

	({"root", "roots"})  :
	"Roots from trees and plants hang over the entrance of the" 
	" portal.",
	({"holes", "cracks", "puddles"})  :
	"Holes and cracks in the ground, fill with water to form puddles."
	" Most of these holes are small, but some are big enough to trip a"
	" person.  These holes are filling with water that is dripping" 
	" from the ceiling." ,
      ]) );

    SetItemAdjectives( ([
	"cave"    :  ({"dark", "damp", "gray"}),
	"earth"    :  ({"wet", "grey"}),
	"light"  :  ({"dim", "flickering"}),
	"stream"    :  ({"dripping", "underground", "small"}),
	"bedrock"    :  ({"damp", "broken", "shattered"}),
	"entrance"    :  ({"covered", "hidden", "concealed", "wide"}),
	"water"    :  ({"wet", "dripping"}),
	"air"    :  ({"stale", "damp"}),
	"holes"    :  ({"small", "round"}),
	"gashes"    :  ({"long", "deep", "huge"}),        
	"puddles"    :  ({"large", "small", "wet"}),
	"shrubs"    :  ({"green", "brown", "black"}),
	"vines"    :  ({"green", "brown", "black", "entangled"}),
	"vegetation"  :  ({"vile", "twisted", "entangled", "concealing"}),

	"plants"  :  ({"vile", "twisted", "entangled"}),
      ]) );

    SetSmell( ([
	"default"  :  "The smell of stale water lingers in the air",
      ]) );

    SetListen( ([
	"default"  :  "The sound of dripping water is heard.",
      ]) );

    SetExits( ([
	"north"  :  M1_ROOM + "/mine1.c", 
	"up"  :  M1_ROOM + "/start4nww.c",
      ]) );
}
