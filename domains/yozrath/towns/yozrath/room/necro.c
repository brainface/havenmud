#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "out" : YOZRATH_VIRTUAL "desert/64,32",
    ]) );
  SetInventory( ([
    YOZRATH_VIRTUAL "npc/necro" : 1,
    ]) );
  SetShort("inside a dingy black tent");
  SetLong(
    "This tent is small and filled with books, chests, and the other "
    "accoutrements of a crazed old desert sage. The floor of the tent "
    "is dusted in various components for research, including dead "
    "lizards and some things that look surprisingly bone-like."
    );
  SetItems( ([
    ({ "book", "books" }) : "The books are bound in black.",
    ({ "chest", "chests" }) : "The chests are heavy and closed.",
    ({ "lizard", "lizards" }) : "These lizards are quite stiff and dead.",
    ({ "bone", "bones" }) : "Best not to think about where these bones started.",
    ]) );
  SetSmell("The tent has a sickly-sweet smell of death and roses.");
}
