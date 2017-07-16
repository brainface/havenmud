#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the Shrine of the Kylin Knights-Templar");
  SetClimate("indoors");
  SetTown("Glimmerdin");
  SetProperty("no conjuring", 1);
  SetProperty("no teleport", 1);
  SetAmbientLight(30);
  SetExits( ([
    "out" : G_ROOM "cemetery",
    ]) );
  SetLong(
    "This fine shrine is an intricately carved, very detailed structure that "
    "glistens with the glory and pride of Glimmerdin's religious warriors, "
    "the Knight-Templars of Glimmerdin. The floor of the shrine is a smooth "
    "rock that is polished to a high sheen, its flawless surface a display of "
    "dedication to the faith. Along the walls are banners and tapestries of the "
    "many victories of the Knights-Templar of Kylin."
    );
  SetItems( ([
    ({ "banner", "banners", "tapestry", "tapestries" }) :
      "The tapestries display the glory of the Knights.",
    ]) );
  SetSmell( ([
    "default" : "The shrine has a clean, pleasant smell.",
    ]) );
  SetListen( ([
    "default" : "Somehow, there is an echo of martial music here.",
    ]) );
  SetInventory( ([
    G_NPC "temple_guard" : 2,
    G_NPC "kuthan"       : 1,
    ]) );
}