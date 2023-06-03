// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:
// Urien@Haven 12.8.12
// Added Everything

#include <lib.h>        
inherit LIB_ROOM;       
#include "../castle.h"          
 
static void create() 
{
room::create();
SetShort("an abandoned dining hall");
SetLong("This rectangular room is enormous and quite spacious. "
        "A very large oak table which runs the length of the "
		"hall has been tipped on its side and chopped in "
		"numerous sections. Chairs which were once well crafted "
		"now rest in pieces and lay covered in dust. A framed "
		"painting rests on the south wall above the piles of "
		"wood. The eastern wall proudly displays a hand woven "
		"rug which illustrates a story. The west and north "
		"doorways provide exits into the further reaches "
		"of the ruins. A giant gaping hole in the south wall "
		"exposes a section of this hall to the elements outside "
		"overlooking the ruined moat.");
SetItems( ([ ({"room"}) : (:GetLong:),
  ({"table"}): "The table is very long, running the length of the "
    "room.  It is made of a light colored wood and is covered "
    "with a white tablecloth.",
  ({"chair","chairs"}) : "The chairs surrounding the table are "
    "made of wood with a padded seat and back.",
  ({"rug"}) : "The rug hainging on the wall is a mural of a great "
    "battle.  Looking closer it appears to be the last Godswar.  "
    "Lying everywhere across the shattered world are the bodies "
    "of the innocents and fallen gods.",
  ({"painting"}) : "The painting on the wall is of the lands "
    "surrounding the castle.  In the background are the "
    "mountains and to the south are the vast forests.",
]) );
SetItemAdjectives( ([ "room" : ({"simple","dining"}),
  "table" : ({"large"}),
  "chair" : ({"large","highback","high-back"}),
  "rug" : ({"mural"}),
  "painting" : ({"landscape"}),
]) );
SetListen("default","The hall is silent with the times.");
SetSmell("default","The hall smells of old rotten food.");
SetExits( ([
        "north" : RUINS_ROOMS + "center",
        "west" : RUINS_ROOMS + "kitchen",
        ]) );
SetClimate("indoors");
SetAmbientLight(60);
}
