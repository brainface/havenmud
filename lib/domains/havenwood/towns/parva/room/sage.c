#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("within the Sage's Cottage");
  SetExits( ([
    "out" : PARVA_ROOM "wharf0",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetInventory( ([
    PARVA_NPC "sage" : 1,
    ]) );
  SetLong(
    "The inside of this small cottage seems somehow larger than the outside, "
    "and filled with the hodgepodge collections of an eccentric scholar. Huge "
    "volumes coated with the dust of ages stand in towering stacks, under and "
    "around cluttered desks and strange scientific and alchemical instruments. "
    "Scrolls, tablets, and maps are spread along the floors, held in place by "
    "fancy paperweights and barely leaving a pathway around the home."
    );
  SetItems( ([
    ({ "collections", "hodgepodge", "clutter", "instruments" }) : "The stuff seems to be mostly literary in nature, although there are odd random instruments and objects thrown haphazardly around the room.",
    ({ "volumes", "books", "dust" }): "The dusty books are everywhere, and most of them are thick. They seem to be written in several languages.",
    "desks" : "The sturdy wooden desks groan under the weight of so many books and other items.",
    ({ "scrolls", "tablets", "maps", "floors" }) : "The floors are layered with yellowing papers and clay tablets, arrayed in a manner that likely makes sense to the owner of this home.",
    "paperweights" : "Bits of shiny crystal, smooth sea glass, and carved pieces of rare jungle hardwood hold papers in their places.",
    ]) );
  SetItemAdjectives( ([
    "collections" : ({ "strange", "scientific", "alchemical" }),
    "volumes"     : ({ "huge", "ages" }),
    "desks"       : ({ "cluttered" }),
    "paperweights": ({ "fancy" }),
    ]) );
  SetSmell("It smells of ancient dust and decaying paper here.");
}