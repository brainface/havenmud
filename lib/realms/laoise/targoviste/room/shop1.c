// Targoviste
// Laoise
// August 2004

#include <lib.h>
#include <domains.h>
#include "../targoviste.h"
inherit LIB_ROOM;

static void create() 
{
  room::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetTown("Targoviste");
  SetShort("the marketplace of Targoviste");
  SetLong(
    "The northeast wall of this building follows the line "
    "delineated by the inner keep, forming a triangle-shaped "
    "area. Along the west and south walls of this open area runs "
    "a long counter, behind which are shelves and hooks "
    "displaying merchandise. In this area the wares appear to "
    "consist of different types of clothing and armour. Where "
    "the walls form corners small nitches can be seen. An "
    "arched doorway to the west allows exit to the outer bailey."
  );
  SetItems( ([ 
    ({ "counter" }) : 
    "The counter is made of a black-stained wood and is set at "
    "a height comfortable for most giants.",
    ({ "shelf", "shelves" }) : 
    "These shelves run along the wall behind the counter and "
    "are used to display various types of merchandise. Hooks "
    "are set below the shelves, for hanging up and displaying "
    "other items.",
    ({ "hook", "hooks" }) :
    "Large metal hooks are secured firmly to the wall below "
    "the shelves. Various bits of merchandise are hung upon "
    "them for display to consumers.",
    ({ "merchandise", "ware", "wares", "display" }) :
    "Various wares are on display here, most of which seem "
    "to consist of armour and clothing. To the south there "
    "appear to be more general items, while to the southeast "
    "is a display of weapons for sale.",
    ({ "corner", "corners", "nitch", "nitches", "illumnation" }) :
    "Inset in each corner is a small nitch. Within each nitch "
    "floats a small blue flame which illumnates the room.",
    ({ "flame", "light" }) :
    "Examined closely these small flames seem a blend of "
    "contradictions with some parts in nearly frozen stillness "
    "and others in sliding motion.",
    ({ "doorway", "exit" }) :
    "The arched doorway stands to the west and provides an exit "
    "from the marketplace to the outer bailey.",
  ]));
  SetItemAdjectives( ([
    "counter" : ({ "long", "black", "wood", "high", 
      "black-stained" }),
    "shelf" : ({ "display", "merchandise" }),
    "hook" : ({ "large", "metal", "display" }),
    "merchandise" : ({ "various", "displayed", "on", "display" }),
    "nitch" : ({ "small", "illumnated" }),
    "flame" : ({ "small", "blue", "illumnating", "moving", 
      "frozen" }),
    "doorway" : ({ "arched", "exit" }),
  ]) );
  SetListen( ([ 
    "default" : "Various sounds of commerce fill the marketplace.",
  ]) );
  SetSmell( ([
    "default" : "A light smell of cleaning oil perfumes the air.",
  ]) );
  SetExits( ([ 
    "west" : TARG_ROOM "west_wall2",
    "south" : TARG_ROOM "shop2",
    "southeast" : TARG_ROOM "shop3",
  ]) );
}
