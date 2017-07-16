#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;
int PreExit(string);

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetProperty("no bump",1);
  SetShort("the Grymxoria Library");
  SetLong(
    "The great library of Grymxoria. Here the knowledge of "
    "countless generations of Nosferatu is stored. The arched "
    "ceiling of the stone block building stretches up far overhead. "
    "Along the walls and in the middle of the huge room are "
    "shelves upon shelves of ancient tomes and books. In one "
    "corner of the room there is a stair case going up."
  );
  SetItems( ([
    ({ "books", "shelves", "book shelves" }) : "Huge shelves "
    "stacked full of books. You see many books on the history "
    "of the Nosferatu, as well as a great many tomes of ancient "
    "knowledge.",
    "ceiling" : "The huge arched ceiling of the stone building.",
    ({ "stair", "stairs", "stair case" }) : "A stone stair case "
    "going up." 
  ]) );
  SetInventory(  ([
    G_NPC "karn" : 1,
    G_NPC "agnod" : 1,
  ])  );
  SetExits( ([ 
    "out" : G_ROOM + "road20" 
  ]) );
  AddExit("up","library1b", (: PreExit :) );
}

int PreExit(string dir) {
  if((this_player()->ClassMember("deathknight")) ||
    (this_player()->GetClass()== "necromancer") ||
    (creatorp(this_player()))) {
      return 1;
    } else {
      write("A strong magical force bars your way.");
      return 0;
  }
}

