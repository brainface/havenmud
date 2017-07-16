/* mine1.c for Abandoned Mine
   Tassadar@Haven
   11SEP04
*/

#include <lib.h>
#include "../mine.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(10);
    SetClimate("underground");
    SetShort("the entrance to an abandoned mine");
    SetDayLong(
        "This mine is small and the ceiling is low. "
        "The walls are cut sharply from the rock of the mountain. "
        "The walls are covered in scrape marks and "
        "completely round from floor to ceiling. Sunlight filters into "
        "the mine from the opening to the north and illuminates the "
        "area."
        );
    SetNightLong(
        "This mine is small and the ceiling is low. "
        "The walls are cut sharply from the face "
        "of the mountain. The walls are covered in scrape marks and "
        "completely round from floor to ceiling. Light floods in from "
        "farther south. There are a few glowing specks on the walls."
        );
   SetItems( ([
        ({"cave", "mines", "mine", "mountain"}) : (: GetLong :),
        ({"wall", "ceiling", "walls", "floor", "ground", "stone"}) :

        "The mine is carved out of a solid grey stone with angular "
        "layers sloping down to the south.",
        ({"light", "opening", "sunlight", "illumination"}) :
        "The opening of the mine allows some light to come in.",
        ({"specks", "speck"}) :
        "There are a few tiny phosphoritic specks on the walls and "
        "ceiling that have stored refracted sunlight to glow in the dark.",
        ({"chips", "scratches", "marks"}) :
        "There are countless scratches and chips in the walls made by the "
        "tools of a miner.",
      ]) );
    SetItemAdjectives( ([
        "mine"    :  ({"dark", "damp", "gray", "small"}),
        "light"  :  ({"dim", "sun"}),
        "rock"   :  ({"solid", "hard", "grey", "layered"}),
        "speck"  :  ({"phosphoritic", "tiny", "glowing"}),
        "wall"  :  ({"solid", "cut", "round", "sharply", "stone", "grey", 
                     "angular", "layered"}),
        "chips" :  ({"countless", "scrape"}),
        "opening" : ({"narrow"}),
      ]) );
    SetSmell( ([
        "default"  :  "The smell of fresh air drifts in from outside.",
      ]) );
    SetListen( ([
        "default"  :  "Various sounds from outside echo here.",
      ]) );
    SetInventory( ([ 
        MINE_NPC "bat" : random(5),
        MINE_NPC "newt" : random(10),
     ]) );
    SetExits( ([
        "south"  :  MINE_ROOM "mine2", 
        "out"  :  MINE_ROOM "out",
      ]) );
}
