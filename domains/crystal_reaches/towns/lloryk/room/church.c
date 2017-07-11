// updated lib chapel 2/june/2017 torak@haven

#include <lib.h>
#include "../path.h"
inherit LIB_CHAPEL;

int PreExit(string dir);

static void create() {
  chapel::create();
  SetShort("The Eclat Temple");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetExits( ([ 
    "out"  : LLORYK "room/uh6",
    "down" : LLORYK "room/mausoleum",
    ]) );
  AddExit("east", LLORYK "room/innertemple", (: PreExit :) );
  SetInventory( ([
      LLORYK + "npc/belwyn" : 1,
      ]) );
  SetLong("Inhabiting the largest hall in Llorykshire, the Eclat Temple "
          "displays magnificence as well as showing humility in its "
          "lack of furnishings. Benches are spaced about the room, angling "
          "towards a plain podium - placed roughly in the center of the "
          "room.  In various parts of the room there are lines and markings "
          "on the floor.  An archway opens to the east and a stairway leads "
          "down.  Set in the north wall is a stone fireplace.");
  SetSmell( ([
    "default" : "The burning wood of the fireplace makes this place home.",
    ]) );
  SetListen( ([
    "default" : "The crackle of the fireplace brings the hall to life.",
    ]) );
  SetTown("Lloryk");
  SetReligion("Eclat");
  SetClasses("cleric");
  SetDeities( ({ }) );
  SetItems( ([ ({ "bench","benches" }) : "The wooden benches are made of "
                   "simple, but sturdy construction.  It looks like they are "
                   "often moved to provide a large open space in the room.",
               ({ "lines","markings" }) : "Concentrated mainly around the "
                   "perimeter of the room, the marking seem to be "
                   "runes of one type or another.",
               ({ "stairway","stairs" }) : "The stairs lead down to the "
                   "church's mausoleum.",
               "podium" : "Made of the same type wood as the benches, the "
                          "podium shows the same simple quality as well.",
              ({"archway","arch"}) : "The archway leads to the inner temple",
              "fireplace" : "The fireplace is warm and inviting.",
             ]) );
  SetItemAdjectives( ([
    "fireplace" : ({ "stone" }),
    ]) );
}


int PreExit(string dir) {
  if (this_player()->GetReligion(1) == "Eclat" ||
      creatorp(this_player())) return 1;
    this_player()->eventPrint("A strong force prevents you from going east.");
   return 0;
}
