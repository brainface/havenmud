#include <lib.h>
inherit LIB_FISHING;
#include "../underdark.h"

static void create() {
  fishing::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a very large chamber");
  SetLong("A large chamber, it extends out of sight to the north. In the "
          "middle of the chamber there is a large subteranian lake of crystal "
          "clear water. A small stream flows in from the south into the lake. "
          "Huge stalactites hang from the ceiling and equally huge stalagmites "
          "stretch up from the floor. Where the two meet, giant pillars are "
          "formed. Two tunnels branch off of this part of the chamber, one to "
          "the south and one to the southwest. An evil darkness flows up "
          "out of the depths.");
  SetExits( ([
          "north" : U_ROOM + "room7b",
          "south" : U_ROOM + "room1b",
          "southwest" : U_ROOM + "room3b"]) );
  SetItems( ([
          "chamber" : "A very large chamber, it extends out of sight to the "
          "north. There is a large lake in the center of the chamber with a "
          "small stream flowing into it. Huge stalactites hang from the "
          "ceiling and equaly huge stalagmites stretch from the floor. "
          "Where they meet they form gigantic pillars.",
          ({ "lake", "large lake", "subteranian lake", "large subteranian lake" }) :
          "A large subteranian lake that occupies the center of the chamber. "
          "The water is crystal clear but the lake is so deep the bottom can "
          "not be seen. Near the surface small bulging eyed blind fish can be "
          "seen swimming about.",
          ({ "stream", "small stream" }) : "A small stream, barely more than a "
          "trickle. It flows from the south into the lake.",
          ({ "stalactites", "huge stalactites" }) : "Huge stalactites, formed "
          "by dripping water over thousands of years, hang down from the "
          "ceiling.",
          ({ "stalagmites", "huge stalagmites" }) : "Huge stalagmites, formed "
          "by water dripping from the ceiling above over thousands of years, "
          "reach up from the floor.",
          ({ "pillars", "huge pillars" }) : "Huge pillars formed when a stalactite "
          "and its corresponding stalagmite meed. They are truly a awsome "
          "sight.",
          "tunnels" : "Two small tunnels branch off from this chamber, one "
          "leads to the south, the other leads to the southwest."]) );
 SetSmell( ([
          "default" : "The air has a foul smell to it."]) ); 
 SetListen( ([
          "default" : "There is a sound of running water."]) );
  SetSpeed(8);
  SetFish( ([
     U_OBJ + "fish" : 100,
     U_OBJ + "snail" : 90,
     U_OBJ + "small_kraken" : 30 ]) );
  SetChance(30);
  SetMaxFishing(15);
  }
