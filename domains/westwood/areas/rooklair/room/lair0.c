#include <lib.h>
inherit LIB_ROOM;
#include "../rook.h"

int BeenDone;
string DoSearch();
object imperials;
object bloodgems;
object rupies;
object senones;
object koken;
object rounds;
object cuicui;
object crystals;
 
static void create() {
  int pot1 = (random(5) + 1);
  int pot2 = (random(3) + 1);
  int pot3 = (random(3) + 1);
  int gem1 = (random(10) + 1);
  int gem2 = (random(5) + 1);
  int crys1 = (random(5) + 1);
  int powd1 = (random(3) + 1);
  int moss1 = (random(2) + 1);
  ::create();
  
  SetShort("Rook's treasure room");
  SetLong("This room appears to be the treasure room for Rook.  "
    "The room is her most closely guarded secret and only by her "
    "death would someone be allowed in here.  A large waterfall "
    "cascades from the ceiling at the end of the room to the "
    "floor.  Large columns formed from a stalagmite meeting "
    "stalagtite circle all around the room.  Glistening moisture "
    "covers everything.");
  SetItems( ([
    ({"room"}) : (: GetLong :),
    ({"column","columns","stalagmite","stalagtite"}) : "Columns "
      "are formed from the stalagmites and stalagtites forming "
      "then meeting each other in the middle.  They are large "
      "in diameter and very damp in appearance.",
    ({"moisture"}) : "The moisture from the waterfall covers "
      "everything in the room.",
    ({"waterfall"}) : "A large waterfall cascades down from the "
      "ceiling of the room to the floor.  The water is clear and "
      "pure.",
  ]) );
  SetItemAdjectives( ([
    "moisture" : ({"glistening"}),
    "waterfall" : ({"cascading","large"}),
  ]) );
  SetClimate("underground");
  SetAmbientLight(0);
  SetSmell( ([
    "default" : "The rooms smells of greed and old treasures.",
  ]) );
  SetListen( ([
    "default" : "The sound of water cascading down echos "
      "throughout the room.",
  ]) );
  SetExits( ([
    "southeast" : R_ROOM + "lair9",
  ]) );
  SetProperty("login", R_ROOM + "lair8");
  SetProperty("no teleport", 1);
  SetProperty("no magic", 1);
  SetSearch( ([ "room" : (: DoSearch :) ]) ); 
  SetInventory( ([
  ]) );
}

varargs void reset(int count) {
   room::reset();
  imperials = new(LIB_PILE);
  imperials->SetPile("imperials", 25000 + random(200000));
  imperials->eventMove(this_object());
  rupies = new(LIB_PILE);
  rupies->SetPile("rupies", 50000 + random(100000));
  rupies->eventMove(this_object());
  bloodgems = new(LIB_PILE);
  bloodgems->SetPile("bloodgems", 50000 + random(100000));
  bloodgems->eventMove(this_object());
  crystals = new(LIB_PILE);
  crystals->SetPile("crystals", 50000 + random(50000));
  crystals->eventMove(this_object());
  senones = new(LIB_PILE);
  senones->SetPile("senones", 50000 + random(10000));
  senones->eventMove(this_object());
  koken = new(LIB_PILE);
  koken->SetPile("koken", 50000 + random(10000));
  koken->eventMove(this_object());
  rounds = new(LIB_PILE);
  rounds->SetPile("rounds", 50000 + random(10000));
  rounds->eventMove(this_object());
  cuicui = new(LIB_PILE);
  cuicui->SetPile("cuicui", 50000 + random(10000));
  cuicui->eventMove(this_object());
  BeenDone =0;
  }
string DoSearch() {
  if (BeenDone) {
     message("other_action",
         this_player()->GetCapName() + " searches around.",
            this_object(), this_player() );
       return "You do not notice anything special.";
         }
    new(R_OBJ + "scroll_case")->eventMove(this_player());
   message("other_action",
       this_player()->GetCapName() + " searches around.",
         this_object(), this_player() );
  BeenDone = 1;
   return "You find a scroll case!";
   }
