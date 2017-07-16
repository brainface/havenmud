#include <lib.h>
#include "../gnome_lab.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a quiet study");
  SetAmbientLight(30);
  SetClimate("indoors");
  SetLong(
	  "The stairs from below open up into the center of a "
	  "study that could hold a small classroom of humans "
	  "standing up. Two small wooden tables are attached "
	  "to the walls along the northern section of this round "
	  "chamber. A bookcase looks to have been built into the "
	  "southern wall. A chandelier is hanging high above the "
	  "study suspended by a single rope.");
  SetItems( ([ 
	  "stairs":
      "These stairs which are carved into the trunk of the "
	  "tree head down into the rest of the house.",
	  ({"room","chamber","study"}) :
	  (:GetLong:),
	  ({"table","tables"}) :
	  "These two tables look to have been built into the walls.",
	  ({"wall","walls","section"}) :
      (:GetLong:),
	  "bookcase" :
	  "The carved wooden bookcase is empty of books.",
	  "chandelier" :
	  "The large chandelier casts a brilliant glow about "
	  "the room.",
	  "rope" :
	  "The thick coarse rope suspends the chandelier well above "
	  "the study.",
	  ]) );
  SetItemAdjectives( ([
	  "table" : ({"wooden","small"}),
	  "bookcase" : "wooden",
	  "room" : "round",
	  "chandelier" : "large",
	  "rope" : ({"thick","coarse"}),
	  ]) );
  SetListen( ([
      "default" : 
	  "The rustling of the wind hitting the house can be heard.",
      ]) );
  SetSmell( ([
      "default" :
	  "The scent of burning oil fills the air.",
      ]) );
  SetInventory( ([
	  G_NPC + "gnome" : 1,
	  ]) );
  SetExits( ([
	  "down" : G_ROOM + "tree1",
	  ]) );
}
