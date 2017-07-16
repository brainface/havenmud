#include <lib.h>
inherit LIB_ROOM;
#include "../rook.h"
 
static void create() {
  int pot1 = (random(5) + 1);
  int pot2 = (random(3) + 1);
  int pot3 = (random(3) + 1);
  int gem1 = (random(10) + 1);
  int gem2 = (random(5) + 1);
  int crys1 = (random(5) + 1);
  int powd1 = (random(3) + 1);
  int moss1 = (random(2) + 1);
  object imperials;
  object bloodgems;
  object rupies;
  object senones;
  object koken;
  object rounds;
  object cuicui;
  object crystals;
  room::create();
  SetDomain("WestWood");
  SetShort("Rook's treasure room");
  SetLong("This room appears to be the treasure room for Rook.  "
    "The room is her most closely guarded secret and only by her "
    "death would someone be allowed in here.  A large waterfall "
    "cascades from the ceiling at the end of the room to the "
    "floor.  Large columns formed from a stalagmite meeting "
    "stalagtite circle all around the room.  Glistening moisture "
    "covers everything.");
  SetItems( ([
    ({"room"}) : (:SetLong:),
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
  SetInventory( ([
    R_OBJ + "moss_blood" : moss1,
    R_OBJ + "argonite" : powd1,
    R_OBJ + "lucite" : crys1,
    R_OBJ + "kragnite" : gem1,
    R_OBJ + "ignious" : gem2,
    R_OBJ + "dagger" : 1,
    R_OBJ + "sword" : 1,
    R_OBJ + "pouch" : 1,
    R_OBJ + "chain" : 1,
    R_OBJ + "dark_cloak" : 1,
    R_OBJ + "zap_wand" : 1,
    R_OBJ + "feather" : 1,
    R_OBJ + "potion_hea" : pot1,
    R_OBJ + "potion_poi" : pot2,
    R_OBJ + "potion_ant" : pot3,
    R_OBJ + "grail" : 1,
    R_OBJ + "painting" : 1,
    R_OBJ + "statuette" : 1,
    R_OBJ + "waterfall" : 1,
  ]) );
  imperials = new(LIB_PILE);
  imperials->SetPile("imperials", 5000 + random(10000));
  imperials->eventMove(this_object());
  rupies = new(LIB_PILE);
  rupies->SetPile("rupies", 5000 + random(10000));
  rupies->eventMove(this_object());
  bloodgems = new(LIB_PILE);
  bloodgems->SetPile("bloodgems", 5000 + random(10000));
  bloodgems->eventMove(this_object());
  crystals = new(LIB_PILE);
  crystals->SetPile("crystals", 5000 + random(10000));
  crystals->eventMove(this_object());
  senones = new(LIB_PILE);
  senones->SetPile("senones", 5000 + random(10000));
  senones->eventMove(this_object());
  koken = new(LIB_PILE);
  koken->SetPile("koken", 5000 + random(10000));
  koken->eventMove(this_object());
  rounds = new(LIB_PILE);
  rounds->SetPile("rounds", 5000 + random(10000));
  rounds->eventMove(this_object());
  cuicui = new(LIB_PILE);
  cuicui->SetPile("cuicui", 5000 + random(10000));
  cuicui->eventMove(this_object());
}
