#include <lib.h>
inherit LIB_ROOM;
#include "../fenfir.h"
 
static void create() {
  room::create();
  
  SetShort("an area in the treetops");
  SetLong("This is a small area amongst the treetops.  The fenfir "
    "trees have large branches here making it easy to move about "
    "from tree to tree.  The tops of the trees obscure the sky but "
    "there is still a soft glow here, creating a lighting that is "
    "easy on the eyes.  Small trinkets are hung about in the "
    "trees, carefully put in places to reflect light about the "
    "leaves.");
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
    ({"trinket","trinkets"}) : "Small trinkets are attached firmly "
      "to the trees, spreading light about the leaves.  They seem to "
      "be magically attached somehow.",
  ]) );
  SetItemAdjectives( ([
    "area" : ({"small"}),
    "tree" : ({"fenfir"}),
    "glow" : ({"soft"}),
    "trinket" : ({"small"}),
  ]) );
  SetExits( ([
    "northwest" : "foodtree",
    "down" : "-3,1",
  ]) );
  SetInventory( ([
    T_NPC + "miscdragon" : 1,
  ]) );
  SetAmbientLight(15);
  SetClimate("temperate");
  SetSmell( ([
    "default" : "The rooms smells of fenrir trees.",
  ]) );
  SetListen( ([
    "default" : "A soft fluttering of wings can be heard mixed amongst "
      "a soft childlike laughter.",
  ]) );
}
