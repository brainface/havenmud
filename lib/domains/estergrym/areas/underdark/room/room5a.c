#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetShort("side of a small mountain");
  SetLong("On the side of a small mountain. The land all around seems "
          "dead. There are no trees, bushes, or animals anywhere. Rising up "
          "in the east is the peak of the mountain. ");
  SetExits( ([
          "south" : U_ROOM + "room2a"]) );
  SetItems( ([
          "land" : "The dead land stretches away into the distance.",
          "mountain" : "A small grey craggy mountain.",
          ({ "peak", "mountain peak" }) : "A tall spire of solid grey rock. "
          "A little bit of snow covers the peak with an icy slick. It would be "
          "extremely dangerous to climb."]) );
  SetSmell( ([
          "default" : "There is a strong smell of dust."]) );
  SetListen( ([
          "default" : "A strong wind whistles over the crags and cliffs of "
          "the mountain."]) );
  SetInventory( ([
          U_NPC + "dazed_dwarf" : 1 ]) );
  }
