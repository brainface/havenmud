#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a very large chamber");
  SetLong("A large chamber, it extends out of sight to the south. In the "
          "middle of the chamber there is a large subteranian lake of crystal "
          "clear water, something large appears to be moving in the depths. "
          "Huge stalactites hang from the ceiling and equally "
          "huge stalagmites stretch up from the floor. Where the two meet, "
          "giant pillars are formed. Two tunnels branch off of this part of the "
          "chamber, one to the north and one to the southwest. An evil "
          "darkness flows up out of the depths.");
  SetExits( ([
          "north" : U_ROOM + "room9b",
          "south" : U_ROOM + "room4b",
          "southwest" : U_ROOM + "room6b"]) );
  SetItems( ([
          "chamber" : "A very large chamber, it extends out of sight to the "
          "north. There is a large lake in the center of the chamber.  Huge "
          "stalactites hang from the ceiling and equally huge stalagmites "
          "stretch from the floor. Where they meet they form gigantic pillars.",
          ({ "lake", "large lake", "subteranian lake", "large subteranian lake" }) :
          "A large subteranian lake that occupies the center of the chamber. "
          "The water is crystal clear but the lake is so deep the bottom can "
          "not be seen. Near the surface small bulging eyed blind fish can be "
          "seen swimming about. Something appears to be moving in the "
          "depths.",
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
         "default" : "The air has a foul smell."]) ); 
 SetListen( ([
         "default" : "Everything is completely silent except for a maddening "
         "dripping sound."]) );
  call_out( "RoomAction", 10 );
  }
void RoomAction() {
  tell_object(this_object(), "A shadow glides across the depths of the "
  "lake. Small ripples and a small swell follow in its wake.");
  call_out( "RoomAction", (random(40)+20));
  }
