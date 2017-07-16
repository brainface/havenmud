#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the Imperial Forum");
  SetLong("This large town square is home to the Imperial Forum. "
          "It is here that citizens come to speak to the rulers of "
          "the Empire and seek redress. Massive stone benches are "
          "spread around the square, some raised above others, so "
          "that all can see and hear the discussions. "
          "There is a small booth here that serves as a mail "
          "station and post office.");
  SetItems( ([
    ({ "bench", "benches" }) : "The benches are made of stone and, "
         "while uncomfortable, offer the best vantage on the "
         "proceedings.",
    ({ "booth", "office", "station" }) : "The post office is "
         "a small booth that citizens can send and receive "
         "mail from.",
    ]) );
  SetItemAdjectives( ([
    "booth" : ({ "small", "post", "mail" }),
    ]) );
  SetExits( ([
    "east" : ROME_ROOM "vi05",
    ]) );
  SetSmell( ([
    "default" : "The Forum smells faintly of large groups of humans.",
    ]) );
  SetListen( ([
    "default" : "The acoustics of the Forum allow echoes of even whispers.",
    ]) );
  SetNewsgroups( ({ "ooc" }) );
  SetInventory( ([
    ROME_NPC "bard" : 1,
    ROME_NPC "sage" : 1,
    ]) );
  SetEnters( ([
    "booth" : ROME_ROOM "post",
    ]) );
}
