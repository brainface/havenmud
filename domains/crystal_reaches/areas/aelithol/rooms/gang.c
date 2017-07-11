#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("around some gangue piles");
    SetDomain("Crystal Reaches");
    SetLong(
      "Stone from a nearby mine has been piled up between hills. "
      "The stone has long since lost the moisture from the "
      "interiors of the earth and turned to a gray, dusty "
      "stone. The piles have been made excessively high and "
      "are starting to level off and nearly fill the entire space "
      "between the two hills here. An obvious trail curves to "
      "the northwest around the piles."
    );
    SetItems( ([
      ({"piles", "pile"})  :  (: GetLong :),
      ({"grass", "grasses"})  :
      "The brown grass is a wild grass native to the area.",
      ({"stone", "stones", "gangue"})  :
      "Gangue from the mines have been piled here recently.",
      "mine"  :
      "The piles of gangue indicate the close proximity of a mine.",
      ({"hill", "hills"})  :
      "The hills are steep and rocky.",
      ({"top", "tops"})  :
      "The tops of the hills and rounded.",
      "trail"  :
      "A well trodden trail curves around the gangue piles to the "
      "northwest",
    ]) );
    SetItemAdjectives( ([
      "stones"    :  ({"gray", "dark", "dusty", "old"}),
      "top"    :  "rounded", 
      "hill"    :   ({"steep", "rocky"}),
      "mine"  :  "nearby",
      "trail"    :  ({"well trodden", "used", "frequented"}),
    ]) );
    SetSmell( ([
      "default"  :  "There is little smell.",
    ]) );
    SetListen( ([
      "default"  :  "Grass whispers at it waves in the breeze.",
    ]) );
    SetInventory(([
       NPCS + "/yminer2" : 1 
    ]));
    SetExits( ([
      "south"  :  ROOMS + "/mouth.c",
      "northwest"   :   ROOMS + "/gang2.c",
    ]) );
}
