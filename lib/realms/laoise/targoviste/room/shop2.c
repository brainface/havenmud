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
  SetDomain("Estergrym");
  SetTown("Targoviste");
  SetShort("the marketplace of Targoviste");
  SetLong(
    "A large counter forms a right angle here, with sections "
    "reaching to the north and east. Set along the wall is a "
    "shelving system which follows the path of the counter. "
    "In this region the avaliable merchandise appears to be of "
    "a general variety, while to the north armour is avaliable "
    "and to the east there is a collection of weapons on display. "
    "Cut in to the walls at each corner are small alcoves which "
    "hold dark blue spheres that faintly illuminate the "
    "surroundings."
  );
  SetItems( ([ 
    ({ "counter" }) :
    "Formed of wood stained a glossy black color the counter "
    "is at a comfortable height for the average giant.",
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
    "A general assortment of merchandise is displayed here. "
    "To the north is a display of armour and clothing while "
    "to the east weapons appear to be avaliable.",
    ({ "corner", "corners", "alcove", "alcove", "illumnation" }) :
    "Inset in each corner is a small nitch. Within each nitch "
    "floats a small blue sphere which illumnates the room.",
    ({ "flame", "light", "sphere" }) :
    "Examined closely these small flames seem a blend of "
    "contradictions, with some parts in nearly frozen stillness "
    "and others in sliding motion.",
    ({ "doorway", "exit" }) :
    "The arched doorway stands to the west and provides an exit "
    "from the marketplace to the outer bailey.",
  ]));
  SetItemAdjectives( ([
    "counter" : ({ "long", "black", "wood", "high", "black-stained" 
      "glossy" }),
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
    "default" : "The faint smell of cleaning oil slips through the air.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "shop1",
    "east" : TARG_ROOM "shop3",
  ]) );
}
