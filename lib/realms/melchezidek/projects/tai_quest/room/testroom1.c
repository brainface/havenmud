


#include <lib.h>
#include "/domains/baria/areas/pyramid/pyramid.h"
inherit LIB_ROOM;

int PreEnter(string dir);

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("Testing Etc");
  SetLong("This is a test room. Here are test stuffs."
            );
 
  SetExits( ([ 
              "east" : "/realms/melchezidek/workroom.c",
          ]) );
  SetInventory( ([ 
                  P_OBJ + "/stela" : 1, 
              ]) );
  SetItem( ([
         "pillar"   : P_ROOM "/blurry",
    ]) );
  AddEnter( "pillar", P_ROOM + "/blurry", (: PreEnter :) );
}

int PreEnter(string dir) {
  write("As you try to enter the pillar, you're bumped by two "
        "guardians coming out from it!");
  AddInventory( P_NPC + "/mazatl", 1);
  AddInventory( P_NPC + "/tlaloc", 1);
  return 0;
}

