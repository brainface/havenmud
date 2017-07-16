//
// Summary: a small dwelling
//      Kyla 11-1-97
// Modified by Rhakz - Angel Cazares
// Date: 10/21/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small domestic dwelling");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong("This domestic hut is obviously a small family's living area. "
          "The floor is made of dirt and the furnishing is sparce. Dust "
          "covers everything, and there is a small crib in the corner of "
          "the room. There are a few candles that illuminate the hut "
          "slightly."
         );
  SetTown("Baria");
  SetItems( ([
              ({"hut"}) : (: GetLong :),
              ({"floor"}) : "The floor is simply made of dirt.",
              ({"dust"}) : "The dust covers everything in the room "
                           "and has small fingerprints in it.",
              ({"crib"}) : "This wodden crib is just the right size "
                           "for a small toddler.",
              ({"candles","candle"}) : "Some white candles make this "
                                       "room slightly brighter."
          ]) );
  SetItemAdjectives( ([
                       "crib" : ({"wooden"}),
                       "floor" : ({"dirty"}),
                       "hut" : ({"domestic"}),
                       "candles" : ({"white"})
                   ]) );
  SetInventory( ([
                  BARIA_NPC + "mother" : 1,
                  BARIA_NPC + "child" : 1,
              ]) );
  SetExits( ([
              "out" : BARIA_ROOM + "path7",
          ]) );
  SetSmell( ([ "default" : "This hut smells of food and dirt." ]) );
  SetListen( ([ "default" : "A small child's cries can be heard "
                            "here." ]) );
}

