// In case something I made breaks or changes,
// I can have fast access to it without diving 
// through directories. This is of course
// for when I can edit the real world, and my 
// areas need to be updated.
// Now with annoying spam!

#define HOMEDIR "/realms/urien/"
#define WORKROOMDIR "/realms/urien/workroom/"

#include <lib.h>
#include <std.h>
#include <dirs.h>

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arctic");
  SetRadiantLight(5);
  SetShort("southern castle tower");
  SetLong(
  "This particular tower ebbs powerful magic energies which "
  "leak from the many cloudy portals. This circular tower "
  "is composed of square cut blocks that rise to no ceiling "
  "and allow the arctic snow to just blow right in. The portals "
  "itself release magical light into this tower."
  );
  SetObviousExits("north, or \"enter <sign list>\"");
  SetExits( ([
     "north" : HOMEDIR "workroom",
  ]) );
  SetItems( ([
  // OOC Stories ONLY -- links to sign
     "area"         : "Example Realm '/std/area/'",
     "hut"          : "Urien's Angel Project - Platypus Bay.",
     "smokeshop"    : "Duuk's idea for Lloryk.",
     "tower"        : "Area planned for missing.",
     "tairi"        : "Rap artists gone wild.",
     "ruins"        : "Adding space to the world.",
     "headquarters" : "Headquarters to Invasion Control Room.",
 // Environment Items 
     "walls" : "In certain sections of the walls are portals "
               "which gateway to different planes of life.",
     "wall" : "The wall is made of pure ice. It is devoid of "
              "any decor except for the portals.",
     "portal": "The portal is a gateway to another world in "
               "Kailie.",
     "portals": "They vary in different appearances and illustrate "
                "different realms that lead to the REAL Kailie.",
     "ceiling": "There isn't one here.",
     "snow": "White snow covers the ground and some of it rests on the "
             "sign in the center of the room.",
     "section": "You are in the section.",
     "tower": (: GetLong :),
     "ice": "Ice dominates everything; large towering walls of "
            "frozen water dominate everything that is real.",
 ]) );
   SetItemAdjectives( ([
    "wall" : ({ "ice","frozen" }),
    "walls" : ({ "ice","frozen" }),
    "portals" : ({ "cloudy" }),
    "portal" : ({ "cloudy" }),
    "snow" : ({ "white" }),
    "ice" : ({ "walls" }),
  ]) );
  SetEnters( ([ 
           "area" : STD_AREA "room/basic",
            "hut" : "/domains/southern_coast/areas/meadow/rooms/meadow13",
      "smokeshop" : "/domains/crystal_reaches/towns/lloryk/room/smokeshop01", 
          "tower" : "/domains/estergrym/areas/tower/room/twer11",
//          "tairi" : "/realms/urien/tairi/room/aroad01", Soon to change
         "ruins"  : "/realms/urien/ruins/room/wizard", 
   "headquarters" : "/realms/urien/invasions/room/headquarters",
             ]) );
  SetSmell( ([
            "default" : "Stagnant freezing cold air rests here."
           ]) );
  SetListen( ([
            "default" : "The portals hum loudly and crackle in energies."
           ]) );
  SetInventory(([ 
             WORKROOMDIR "goliath"  : 1,
             WORKROOMDIR "lunatic"  : 1,
             WORKROOMDIR "snowsign" : 1,
            ]));    
  SetDoor( "north", WORKROOMDIR "door2");
}
void heart_beat() {
  string fire;
  ::heart_beat();
  switch(random(6)) {
    case 0:
      fire = "Ice crisps and releases a noisy peal which echo off the walls.";
    break;
    case 1:
      fire = "Snow falls in from the open tower freely and swirls about.";
    break;
    case 2:
      fire = "The portals crack and hiss loudly pulling in wind from the environment.";
    break;
    case 3:
      fire = "The wooden sign creaks slightly under the weight of the snow from above.";
    break;
    case 4:
      fire = "A single metal on metal scrape is heard which reverberates around the "
             "circular tower.";
    break;
    case 5:
      fire = "Lightning zaps from one portal to another, cracking in energy.";
    break;
   }
  eventPrint(fire);
}