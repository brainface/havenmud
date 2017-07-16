#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  
  SetClimate("indoors");
  SetNewsgroups( ({ "ooc", "news.announcements" }) );
  SetAmbientLight(40);
  SetShort("inside the Sheik's Palace");
  SetLong(
    "The intricate tiling from the courtyard carries on through the various "
    "palace rooms, the designs varying to give a unique feel to each space. "
    "This is the main room of the palace where the Sheik deals with all "
    "Yozrathian matters. A carved desk dominates the center of the room. "
    "A small staircase leads up towards the Sheik's private salon and a "
    "large, open archway leads back out to the courtyard."
    );
  SetSmell("The faint scent of palm dates carries in from the courtyard.");
  SetListen("The rustling of papers is soft and low.");
  SetItems( ([
    ({ "room", "space" }) : (:GetLong:),
    ({ "tile", "tiling", "design", "designs" }) : 
       "Intricate tilework covers the wall and floors, colored in elegant "
       "blues, golds and reds.",
    ({ "wall", "walls" }) : 
       "The walls are tiled and have been cleaned and polished to a high "
       "shine.",
    ({ "floor", "ground" }) :
       "The floors are tiled and have been cleaned and polished to a high "
       "shine.",
    ({ "courtyard" }) :
       "The courtyard is to the east, through the archway.",
    ({ "arch", "archway", }) :
       "A large open archway leads back out to the courtyard.",
    ({ "desk" }) :
       "This wooden desk is old looking, but regal and carved with great "
       "detail.",
    ({ "stair", "stairs", "staircase", "case" }) :
       "This small staircase is covered in tile and leads up to a private "
       "salon.",
    ]) );
  SetItemAdjectives( ([
    "tile" : ({ "intricate", "colored", "blue", "yellow", "green", "elegant" }),
    "wall" : ({ "clean", "cleaned", "polished", "tiled" }),
    "floor" : ({ "clean", "cleaned", "polished", "tiled" }),
    "arch" : ({ "large", "open" }),
    "desk" : ({ "wooden", "old", "regal", "carved" }),
    "staircase" : ({ "small" }),
    ]) );
  SetInventory( ([
    YOZRATH_NPC "sheik" : 1,
    ]) );
  SetExits( ([
    "east" : YOZRATH_ROOM "palace",
    "up" : YOZRATH_ROOM "palace2a",
    ]) );
    
}
