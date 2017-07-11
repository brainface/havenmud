/*
 A small clearing, caused by logging
 It's got a kobold.
 Should be tied to the path up arcanith mountain
*/
#include <lib.h>

#include "../fence.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arctic");
  SetDomain("Frostmarches");
  //hyphen in snow-filled doesn't seem to work with SetItemAdjective
  SetShort("a snow filled clearing on the side of a mountain");
  SetDayLong(
    "A large open space lies here, surrounded by a fairly dense forest of "
    "small evergreens. Hoofprints in the snow mark a path through stumps "
    "and underbrush, leading to the east, where a building can be seen. "
    "The rising mountain dominates the view to the northeast."
  );
  SetNightLong(
    "A large open space lies here, surrounded by a dark forest of small "
    "evergreens. Hoofprints in the snow mark a faint path through stumps "
    "and underbrush, leading deeper into the forest. Some torchlight can "
    "be seen through the trees to the east. The view of the night sky to "
    "the northeast is blocked by the shadow of a large mountain."
  );
  SetItems( ([
    ({"space","clearing"}) :
      (: GetLong :),
    ({"ground"}):
      "Hoofprints in the snow mark a faint path through stumps and "
      "underbrush, leading deeper into the forest.",
    ({"evergreens","trees","forest","pines"}) : 
      "The pine trees bordering the clearing are mostly small and "
      "stunted, but a few tower over their neighbors.",
    ({"underbrush","weeds"}):
      "A few weeds pierce the snow defiantly.",
    ({"stumps"}) :
       "The clearing is filled with the stumps of felled pine trees.",
    ({"trail"}) : 
      "The main trail up the mountain lies to the west.",
    ({"path"}):
      "Someone has cut a path here through the underbrush. Hoofprints are "
      "the only marking.",
    ({"hoofprints","marking","kobolds"}):
      "These small hoofprints were probably left by kobolds.",
    ({"torch","torchlight", "building","cabin"}):
      "There appears to be a log cabin to the east.",
    ({"mountain","shadow","faint glow","top","glow"}) :
      "The rising mountain dominates the view to the northeast. Oddly, a "
      "faint glow can be seen near the top.",
    ({"snow","ice"}) :
      "Snow and ice coat everything in sight.",
    ({"felled trees","felled pine trees"}):
      "Only the rotting stumps remain.",
  ]) );
  SetItemAdjectives( ([
    "building" : ({"small"}),
    "bushes" : ({"hardy"}),
    "cabin" : ({"log"}),
    "evergreens" : ({"small","stunted","small","stunted","pine","dense"}),
    "hoofprints" : ({"small"}),
    "mountain" : ({"large","rising"}),
    "space": ({"large","open","snow","filled"}),
    "stumps" : ({"rotting"}),
    "trail" : ({"main"}),
  ]) );
  SetListen( ([
    "default" : "A goat bleats in the distance.",
  ]) );
  SetSmell( ([
    "default" : "The smell of rotting wood fills the air.",
  ]) );
  SetInventory( ([
    FENCE_NPC "brash_student.c" : 1,
  ]) );
  SetExits( ([
    "west" : "/domains/frostmarches/towns/arcanith/room/mountain2",
    "east" : FENCE_ROOM "practice_field.c",
  ]) );
 
}

