#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetTown("Glimmerdin"); 
  SetClimate("indoors");
  SetAmbientLight(50);
  SetShort("a large administrative office");
  SetLong(
    "The keep is actually little more than a fortified cavern set off the "
    "center of the Great Hall. Around the room are various banners and "
    "tapestries listing the glories of the various clans of Glimmerdin. "
    "Polished stone walls make for a smooth and seamless looking space, "
    "and this area serves as the center of town administration."
    );
  SetNewsGroups( ({ "town.glimmerdin" }) );
  SetProperty("no teleport",1);
  SetProperty("no conjuring",1);
  SetItems( ([
    ({ "banner", "banner", "tapestry", "tapestries" }) :
       "These banners detail the history of the various clans of Glimmerdin.",
    ({ "wall", "walls" }) :
       "The polished stone walls reflect the light and brighten the room.",
    ]) );
  SetSmell( ([
    "default" : "The room smells of ink and parchment.",
    ]) );
  SetListen( ([
    "default" : "The sounds of commerce flow in from the Great Hall.",
    ]) );
  SetExits( ([
    "out"  : G_ROOM "gh_central",
    "west" : G_ROOM "sage",
    ]) );
  SetInventory(([
    G_NPC "administrator" : 1,
    G_NPC "admin_guard" : 2,
    G_NPC "escort"  : 1,
    G_NPC "equipper" : 1,
  ]) );
}

