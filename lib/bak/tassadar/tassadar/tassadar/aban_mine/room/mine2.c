/* mine2.c for Abandoned Mine
   Tassadar@Haven
   21SEP04
*/

#include <lib.h>
#include "../mine.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(10);
    SetClimate("underground");
    SetShort("an abandoned mine");
    SetDayLong(
        "The mine opens up to a round room here. "
        "The walls are cut sharply from the surrounding rock, and "
        "covered in scrape marks. Sunlight is refracted into "
        "the mine from a long quartz vein in the ceiling, illuminating "
        "the room. The air here moves in short gusts, as the wind is "
        "pulled into the mine.");
    SetNightLong(
        "The mine opens up to a round room here. "
        "The walls are cut sharply from the surrounding rock, and "
        "covered in scrape marks. Millions of tiny phosphoritic "
        "specks adorn the walls giving the room a soft orange glow. The "
        "air here moves in short gusts as the wind is pulled into the "
        "mine.");
   SetItems( ([ 
        ({"room", "mines", "mine", "mountain"}) : (: GetLong :),
        ({"rock", "wall", "ceiling", "walls", "floor", "ground", "stone"}) :
        "The mine is carved out of a solid grey stone with angular "
        "layers sloping down to the south.",
        ({"vein", "light", "opening", "sunlight"}) :
        "The vein of quartz in the ceiling allows some light to come in.",
        ({"specks", "speck"}) :
        "There are millions of tiny phosphoritic specks on the walls and "
        "ceiling that have stored refracted sunlight to glow in the dark.",
        ({"chips", "scratches", "marks"}) :
        "There are countless scratches and chips in the walls made by the "
        "tools of a miner.",
        ({"wind", "air"}) :
        "The air is invisible to the naked eye.",
      ]) );
    SetItemAdjectives( ([
        "mine"   :  ({"dark", "damp", "gray"}),
        "light"  :  ({"dim"}),
        "rock"   :  ({"solid", "hard", "grey", "layered", "angular"}),
        "speck"  :  ({"phosphoratic", "tiny", "glowing"}),
        "wall"   :  ({"solid", "cut", "round", "sharply"}),
        "marks"  :  ({"scrape", "countless"}),
        "vein"   : ({"thin", "long", "illuminating", "quartz"}),
        "air"    : ({"moving", "pulled", "gusting"}),
      ]) );
    SetSmell( ([
        "default"  :  "The air is filled with the smell of sulfur and "
                      "rock dust.",
      ]) );
    SetListen( ([
        "default"  :  "It is extremely quiet.",
      ]) );
    SetInventory( ([ 
        MINE_NPC "bat" : random(5),
        MINE_NPC "newt" : random(5),
        MINE_NPC "miner" : 1,
        MINE_NPC "rat" : random(5),
     ]) );
    SetExits( ([
        "north"  :  MINE_ROOM "mine1", 
      ]) );
}
