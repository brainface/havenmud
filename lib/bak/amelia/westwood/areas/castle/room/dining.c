// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:

#include <lib.h>        
inherit LIB_ROOM;       
#include "../castle.h"          
 
static void create() 
{
room::create();
SetShort("a large dining room");
SetLong("This simple dining room used to see a lot use in the days "
  "before the Godswar.  Now days it is only around for formal "
  "occasions and to entertain kings from other lands.  There is "
  "a large table running down the middle of the room with large "
  "high-back chairs around it.  The only decorations in this room"
  " are a mural rug and a landscape painting.");
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
SetListen("default","The room is silent with the times.");
SetSmell("default","The rooms smells of dust and old foods.");
SetExits( ([
        "north" : C_ROOM + "center",
        "west" : C_ROOM + "kitchen",
        ]) );
SetClimate("indoor");
SetAmbientLight(60);
}
