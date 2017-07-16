// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("the Karak Smithy");
  SetLong(
    "A line of skulls decorates the smithy, mounted high on the "
    "otherwise plain wooden walls. Wooden racks line all sides of "
    "the room, holding weapons in various stages of creation and "
    "repair. A large section of log stands upright at the rear of "
    "the room, apparently designed to allow customers a few practice "
    "swings with their new purchases. A doorway is carved through "
    "the north wall and leads to the armoury, while an opening to "
    "the east connects to the forge."
  );
  SetItems( ([
    ({ "skull", "skulls", "decorations" }) : "On all four sides of "
    "the room, near the top of the wall, are mounted a line of skulls. "
    "Many have visible signs of hacking or crushing damage which "
    "were likely the cause of their death.",
    ({ "racks", "rack", "weapon", "weapons" }) : "Large wooden racks "
    "are lined up along all walls in the smithy. They hold weapons "
    "at various stages of either creation or repair.",
    ({ "log", "section", "post" }) : "A section of log stands upright "
    "near the rear of the room. Chunks are missing from it and slash "
    "marks abound, suggesting it is used by customers to practice with "
    "their newest weapons.",
    ({ "forge" }) : "An opening in the west wall leads to a large forge, "
    "which appears to be shared with the armoury to the north.",
  ]) );
  SetItemAdjectives( ([ 
    "skull" : ({ "line", "of", "decorative", "hacked", "crushed" }),
    "racks" : ({ "large", "weapon" }),
    "log" : ({ "large", "section", "of", "upright", "practice" }),
  ]) );
  SetListen( ([
    "default" : "A crackling wave of heat comes from the forge to the west.",
  ]) );
  SetSmell( ([
    "default" : "Smoke from the nearby forge flavors the air.",
  ]) );
  SetInventory( ([
    KARAK_NPC + "shop_weap" : 1,
  ]) );
  SetProperties( ([
    "metal working" : 1,
    "natural working" : 1,
    "wood working" : 1,
    "leather working" : 1,
    "textile working" : 1,
    "mithril working" : 1,
   ]) );
  SetEnters( ([
    "forge" : KARAK_ROOM + "shop_forge",
  ]) );
  SetExits( ([
    "north" : KARAK_ROOM + "shop_armoury",
    "out"   : KARAK_ROOM + "rd4",
  ]) );
}
