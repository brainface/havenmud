#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground"); SetWarmth(45);
  SetAmbientLight(20);
  SetShort("a quiet cemetery");
  SetLong(
    "A small round room has been carved out, hewn from the rock of "
    "the surrounding mountain. The ceiling is covered with a light green lichen "
    "which glows, filling the room with ambient light. Grass has been cultivated "
    "in a small patch and is obviously well-maintained. Headstones form orderly "
    "line here, crossing the grass. A small path leads away to the west. Built "
    "into the northern facing is a shrine with a distinctly martial feel."
  );
  SetItems( ([
    "ceiling" :
       "The ceiling is covered with a light green lichen which glows softly and illuminates the cemetery.",
    "lichen" :
      "The lichen glows with a warm light, covering the cemetery in a soft green color.",
    "grass" :
      "This small patch of grass appears to have been recently groomed, as it is even and short.",
    ({"headstone","headstones"}) :
      "Orderly lines of headstones cross the cemetery. Each is formed from a small slab of stone and "
      "with a complex dwarven rune.",
    ({"rune","runes"}) :
      "Each headstone has a dwarven rune carved upon it. The rune is an anchient part "
      "of dwarven culture, its true meaning long ago, during the chaos of the last GodWar.",
    "shrine" :
      "The shrine is the center of the Paladins of Kylin, a sect of cavaliers and "
      "Paladins.",
    ]) );
  SetItemAdjectives( ([
    ]) );
  SetListen( ([
    "default" : "The cemetery is hushed and quiet.",
    ]) );
  SetSmell( ([
    "default" : "A light scent of fresh grass slips through the air.",
    "grass" : "The grass smells newly clipped and fresh.",
    ]) );
  SetProperty("no conjuring",1);
  SetProperty("no teleport",1);
  SetExits( ([
    "west" : G_ROOM "gh_north",
    ]) );
  SetProperty("NoAttack",1);
  SetEnters( ([
    "shrine" : G_ROOM "shrine",
    ]) );
  SetInventory ( ([
    STD_OBJ "reztotem" : 1,
  ]) );
}
