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
    "The walls of this building form a large, somewhat "
    "triangular space. The interior is lit by dark blue "
    "orbs which are held in recesses set in the corners. "
    "To the south an arched doorway leads to the outer "
    "bailey. A long counter runs in front of the walls, "
    "forming a right angle to the west. Behind the counter, "
    "an array of shelves and hooks hold an assortment of "
    "weapons which appear to be displayed for purchase."
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
    ({ "merchandise", "ware", "wares", "display", "weapons" }) :
    "A assortment of weapons for purchase is on display here. "
    "To the northwest the avaliable wares seem to run to armour "
    "and clothing, while to the west more general items are "
    "arranged.",
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
    "default" : "A distinct scent of cleaning oil marks the air.",
  ]) );
  SetExits( ([ 
    "south" : TARG_ROOM "south_wall6",
    "west" : TARG_ROOM "shop2",
    "northwest" : TARG_ROOM "shop1",
  ]) );
}
