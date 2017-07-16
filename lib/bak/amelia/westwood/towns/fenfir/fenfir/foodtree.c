#include <lib.h>
inherit LIB_ROOM;
#include "../fenfir.h"
 
static void create() {
  room::create();
  SetDomain("WestWood");
  SetShort("an area in the treetops");
  SetLong("This is a small area amongst the treetops.  The fenfir "
    "trees have large branches here making it easy to move about "
    "from tree to tree.  The tops of the trees obscure the sky but "
    "there is still a soft glow here, creating a lighting that is "
    "easy on the eyes.  Small green lichens cover the length of the "
    "branches.");
  SetItems( ([
    ({"area"}) : (:GetLong:),
    ({"tree","trees","fenfir"}) : "The fenfir trees here are large, "
      "standing defiantly amongst the mountains.  The leaves here "
      "are light green and almost as tall as a halfling.",
    ({"branch","branches"}) : "The fenfir branches are thick, easily "
      "supporting the weight of many people.  A thick layer of white "
      "bark covers the branch and protects it.",
    ({"top","tops","sky"}) : "The tree tops block the sky.",
    ({"lighting","light"}) : "The lighting here is soft blue and "
      "and creates pale shadows that are easy on the eyes.",
    ({"lichen","lichens"}) : "Small green lichens spread about the "
      "length of the tree branches.",
  ]) );
  SetItemAdjectives( ([
    "area" : ({"small"}),
    "tree" : ({"fenfir"}),
    "glow" : ({"soft"}),
    "lichen" : ({"small","green"}),
  ]) );
  SetExits( ([
    "northwest" : "drinktree",
    "southeast" : "misctree",
    "down" : "-4,2",
  ]) );
  SetInventory( ([
    T_NPC + "fooddragon" : 1,
  ]) );
  SetAmbientLight(15);
  SetClimate("temperate");
  SetSmell( ([
    "default" : "The rooms smells of trees and lichen.",
  ]) );
  SetListen( ([
    "default" : "A soft fluttering of wings can be heard mixed amongst "
      "a soft childlike laughter.",
  ]) );
}
