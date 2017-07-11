#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside a magnificent tent");
  SetExits( ([
    "out" : SOUTHERN_COAST_VIRTUAL "havenroad/22,0",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetInventory( ([
    ]) );
  SetLong(
    "Within the large tent sits a small cookfire over which a pot of truly "
    "delicious elven stew is cooking. Along the edge of the tent is a small "
    "but comfy looking sleeping pallet. Thin silk banners line the walls, "
    "evidence of missions completed in ages past."
    );
  SetItems( ([
    "stew" : "The elven stew looks appealing.",
    ]) );
  SetItemAdjectives( ([
    "stew" : ({ "elven", "truly", "delicious" }),
    ]) );
  SetSmell( ([
    "default" : "The elven stew fills the air with its tasty aroma.",
    "stew"    : "The stew smells wonderful.", 
    ]) );
}
  