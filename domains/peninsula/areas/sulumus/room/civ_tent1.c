// Proximo@Via Imperialis
// 05/30/2003

#include <lib.h>
#include "../sulumus.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetWarmth(53);
  SetAmbientLight(30);
  SetShort("inside of a small canvas tent");
  SetLong(
     "This small canvas tent is a simple structure erected by someone who wished "
     "to use it's shelter. The thick material that makes up this tent blocks "
     "much of the outside world, despite it's lack of a regal appearance. "
     "There is very little furniture within this structure making it look simple "
     "and bland. A small table with three chairs sitting around it is placed as "
     "far away from the flames as possible. A large fire roars in the center of "
     "the tent, with a few bedrolls strewn around the edges of the fire. "
     "Laying upon the ground is the remains of a mixture of herbs. "
  );
  SetItems( ([
     ({ "tent" }) :
     "The material that this tent is composed of is that of a tightly-wrapped "
     "canvas stretched over a wooden frame. This allows for a weather proof "
     "structure, able to withstand many types of weather. ",
     ({ "fire", "hole" }) :
     "A large fire burns brightly in the center of the tent, generating a fair "
     "amount of heat and light for those near its reach. A plume of smoke "
     "from the fire leads straight up into the air and out through the small hole "
     "in the roof. ",
     ({ "bedroll", "bedrolls" }) : "These bedrolls have been intentionally "
     "placed near the fire to gather its warmth. These fur-stuffed leather bedrolls "
     "look to be very warm. ",
     ({ "chair", "chairs" }) : "Sitting around the table stands a set of three "
     "chairs, providing a place for three people to sit and use the table. These "
     "chairs look to have been made from a solid, knotless wood that has a great "
      "deal of strength. ",
     ({ "table" }) : "This wood table looks to have been made from a solid, "
     "knotless wood that has a great deal of strength. ",
     ({ "herbs" }) : "A strange mixture of herbs lay strewn about the ground. "
     "",
  ]) );
  SetItemAdjectives( ([
     "tent" : ({ "canvas" }),
  ]) );
  SetInventory( ([
     S_NPC + "jeweler" : 1,
  ]) );
  SetEnters( ([
  ]) );
  SetSmell( ([
     "default" : "The air smells of a sweet smelling smoke. ",
  ]) );
  SetListen( ([
     "default" : "It is very quiet and calm in here. ",
  ]) );
  SetExits( ([
     "out" : S_ROOM + "sulumus4",
  ]) );
}
