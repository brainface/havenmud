#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetProperty("no steal", 1);
  SetProperty("no teleport", 1);
  SetClimate("indoors");
  SetAmbientLight(20);
  SetNewsgroups( ({ "magic.announcements" }) );
  SetShort("grymxoria Mage research room");
  SetLong(
    "This is the room where the Grymxoria mages research "
    "new spells. The walls are lined with shelves of books and "
    "potions. On one wall is a board where the mages can post "
    "ideas for new spells."
  );
  SetProperty("no magic", 1);
  SetItems( ([
    ({ "shelf", "shelves" }) : "Shelves filled with magic tomes and potions",
    ({ "books" }) : "Many books of magic.",
    ({ "potions" }) : "Glass bottles of potions and ingredients with "
    "exotic names such as 'Eye of Newt', 'Dragon's Claw', and 'Dead "
    "Man's Toe'.",
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([
    "north" : G_ROOM +"library1b",
  ]) );
}
