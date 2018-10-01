#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../starfire.h"

inherit LIB_ROOM;

void dump_cash();

static void create() {
  ::create();
  SetClimate("indoors");
  SetShort("the room of spoils");
  SetLong(
      "The walls of this small chamber are made of yellow sandstone"
      " bricks. They are aged with cracks and have been worn smooth."
      " The southern wall houses a small arched exit that has been"
      " covered with vast amounts of soot that expands out of the"
      " entrance and climbs up and around the wall."
      );
  SetItems( ([
      ({ "wall", "walls", "bricks", "sandstone" }) : 
        "The walls are made of yellow sandstone bricks. They show"
        " signs of aging via the cracks on their surface and the"
        " otherwise extremely smooth surface.",
      ({ "crack", "cracks" }) :
        "The sandstone walls are covered in cracks. Clearly they"
        " have been under stress for a considerable amount of time."
        " Even with the ancient appearance, they appear sound.",
      ({ "soot", "arch", "exit", "passage" }) : 
        "The southern exit is an arched doorway presumably composed"
        " of the same yellow bricks that make up the walls. However"
        " the archway is covered in thick black soot that shoots"
        " out of the archway and climbs the southern wall.",
      ({ "sand", "floor", "pile", "piles" }) :
        "The floor is covered with a thin layer of sand. In some spots it has collected"
        " into small piles making it hard to determine any specifics about the"
        " underlying construction.",
      ]) );
  SetItemAdjectives( ([
      "wall"  : ({ "yellow", "sandstone", "brick", "aged", "cracked"}),
      "crack" : ({ "many" }),
      "soot"  : ({ "black", "thick", "climbing", "southern", "arched", 
                   "south", "southern", "small" }),
      "sand" : ({ "thin", "piled", "sandy" }),
      ]) );
  SetExits( ([
      "south"  : SF_ROOM "room07",
      ]) );
  SetInventory( ([
      SF_OBJ "hourglass": 1,
   ]) );
  SetProperty("no teleport", 1);
}

void init() {
  ::init();
  dump_cash();
}

void dump_cash() {
  /* Randomly picked these currencies from help defaults
   * and /might/ be too much money? -mel
   */
  array primary_currencies = ({ "dinar", "imperials" });
  array other_currencies = ({ "senones", "chits", "rounds", "rupies", 
                              "koken", "roni", "crystals", "oros" });

  foreach (string cur in primary_currencies) {
     object pile;
     pile = new(LIB_PILE);
     pile->SetPile(cur, 50000 + random(25000));
     pile->eventMove(this_object());
  }

  foreach (string cur in other_currencies) {
     object pile;
     pile = new(LIB_PILE);
     pile->SetPile(cur, 2500 + random(10000));
     pile->eventMove(this_object());
  }
}
