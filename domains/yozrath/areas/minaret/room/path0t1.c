#include <lib.h>
#include "../minaret.h"

inherit LIB_ROOM;
int DomainCheck();

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("the path along the spiral minaret");
  SetLong(
    "The path along the minaret is lined with stone and has a "
    "small channel running along side of it, flowing with water "
    "from the top of the minaret.  The minaret itself has been "
    "painted white.  The path leading to the top has a gradual "
    "incline."
  );
  SetItems( ([
    ({ "path", "ground", "stone" }) : 
        "The path is lined with stone and winds its way up the minaret.",
    "minaret" : (: GetLong :),
    "water" : "The water flows down from the top of the "
      "minaret, providing sustenance to an array of flora.",
    "flora" : "The various flora growing upon the minaret "
      "are lush and beautiful.",
    ]) );
  SetItemAdjectives( ([
    "path" : ({ "lined" }),
    "water" : ({ "flowing" }),
    "minaret" : ({ "white" }),
  ]) );
  SetInventory( ([
    MIN_OBJ "/channel" : 1,
    MIN_OBJ "/r_tree" : random(2) +1,
    MIN_OBJ "/r_plant" : random(5)+2,
    ]) );
  SetListen( ([
    "default" : "The babbling sound of water trickles down the minaret.",
    ]) );
  SetSmell( ([
    "default" : "The arid air carries the scent of the sand.",
    ]) );
  AddExit("northwest", "/domains/yozrath/virtual/desert/33,47");
  AddExit("east", MIN_ROOMS "/path1t1", (: DomainCheck :) );
}


int DomainCheck() {
  if (this_player()->GetLevel() <= 124) {
    this_player()->eventPrint("After further review, walking "
      "up the minaret doesn't seem like a good idea.  Yet.");
    return 0;
  }
  return 1;
}
