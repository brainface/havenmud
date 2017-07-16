#include <lib.h>
#include "../outpost.h"
#include <domains.h>

inherit LIB_ROOM;
int DomainCheck();

static void create() {
  room::create();
  SetShort("inside a wooden gate");
  SetLong("This large wooden gate is the last defense for the Inquisitors of "
          "Kylin. The palisade surrounding the outpost is strengthened by an "
          "earth and stone rampart. A campfire sits alongside the road. The "
          "road heads north towards the ruins of Durgoroth and southward "
          "through the camp to the Durgoroth road. A large construction pit "
          "can be seen to the east. To the west, a tall wooden tower can be "
          "seen." );
  SetAmbientLight(40);
  SetClimate("sub-arctic");
  SetItems( ([
    "gate" : 
      "This large wooden gate is the last defense against the daemon horde "
      "escaping the ruins of Durgoroth",
    ({"outpost", "camp"}) : 
      (: GetLong :),
    ({"palisade", "wall"}) : 
      "This wooden wall, which surrounds the camp, is made of large tree trunks "
      "lashed together. It has been strengthened with an earth and stone rampart.",
    ({"tree", "trunks", "trees"}) :
      "Large tree trunks lashed together protect the camp.",
    ({"earth", "stone", "rampart"}) : 
      "Earth and stone have been piled up against the wooden palisade strengthening "
      "it.",
    ({"fire","campfire"}) : 
      "The campfire along the side of the road keeps invaders warm in this cold "
      "climate.",
    "road" : 
      "The road runs north towards the ruins of Durgoroth and south to the Durgoroth road.",
    "tower" :
      "In the west, a tall dark wooden tower can be seen.",
    "pit" : 
      "A large construction pit can be seen in the east.",
    ]) );
  SetItemAdjectives(( [
    "gate"     : ({"large", "wooden"}),
    "outpost"  : ({"inquisitor", "invader", "invaders"}),
    "palisade" : ({"tall", "wooden"}),
    "tower"    : ({"tall", "dark", "wooden","wood"}),
    "pit"      : ({"construction", "large"}),  

    "road"     : ({"durgoroth"}),
    "tree"     : ({"large"}),
    ]) );
  SetExits( ([
    "south" : OP_ROOM + "south_gate",
    "east"  : OP_ROOM + "staging_area3",
    "west"  : OP_ROOM + "staging_area1",
    ]) );
  AddExit("north", FROSTMARCHES_TOWNS +"durgoroth/room/road01",( :DomainCheck: ));
  SetSmell( ([
    "default" : "The air is filled with the smell of burning wood.",
    ]) );
  SetListen( ([
    "default" :
      "The sound of hammering can be heard in the distance.",
    "fire"    : 
      "The sound of burning wood can be heard snapping and popping.",
    ]) );
  SetInventory( ([
    OP_NPC + "kylin_effigy" : 2,
    OP_NPC + "inquisitor"   : 2,
    OP_OBJ + "sign" :1,
    ]) );
}

int DomainCheck() {
	object guard, player;
  
  player = this_player();
  
  if (guard = present("inquisitor")) {
    if (player->GetInvis() == 0) {
      if ((player->GetLevel() < 120) && (player->GetNationality() != "Durgoroth")) {
        guard->eventForce("yell " 
          "It's your funeral, " + player->GetCapName() + ". Don't expect us to"
          " come and reclaim your bones!"
         );
        } 
        if (player->GetNationality() == "Durgoroth") {
        guard->eventForce("spit");
        guard->eventForce("say Disgusting locals");
       }
       if ((player->GetLevel() >= 120) && (player->GetNationality() != "Durgoroth")) {
       guard->eventForce("yell "
        "Give 'em hell, " + player->GetCapName() + "!");
      }
     }
  return 1;
 }
}
