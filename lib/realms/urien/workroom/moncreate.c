// I clone all my test objs/npcs here
// So I don't ever lose my 'home' command
// Coded the purge daemon to keep me company
// Or just something to kill when I feel like it
// Also serves to test aggro npcs
// Now with more spam!
// Doors added to keep in wandering NPCs

#include <lib.h>
#include <domains.h>

#define WORKROOM    "/realms/urien/"
#define WORKROOMDIR "/realms/urien/workroom/"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arctic");
  SetObviousExits("south");
  SetRadiantLight(20);
  SetShort("northern castle tower");
  SetLong(
          "This portion of the tower is barren. The walls have been "
          "built in a circular shape and the floor has a thin layer "
          "of snow that rests on it. Torches have been placed on the "
          "surface of the wall which illuminate softly. There is no "
          "ceiling in this tower, so snow just pours in from the sky. "
          "The only way out is south through a doorway which contains a "
          "frozen door attached to it. A simple campfire burns slightly "
          "directly in the center of the tower."
         );
  SetExits( ([
            "south"   : WORKROOM "workroom",   
           ]) );
  SetSmell( ([
            "default" : "Cold air assaults the nostrils.",
           ]) );
  SetListen( ([
            "default" : "Flickering of the torches snap and hiss."
           ]) );
  SetInventory( ([ 
             WORKROOMDIR "pdemon" : 1,
             WORKROOMDIR "campfire" :1,
             ]) );
SetItems( ([
     "stones" : "The round grey stones form a circle for the "
                "fire.",
     "wood" : "Wood burns inside the put in the center of the "
              "tower.",
     "walls" : "The walls curve slightly and reach up to no "
               "ceiling. They are frozen solid and have "
               "torches which have been attached to them.",
     "wall" : "There is only one roundish wall which forms into "
              "a circle. It has torches on it.",
     "snow" : "It blankets the ground completely.",
     "torches" : "Several torches have been attached to the "
                 "frozen wall. They are generic wooden torches "
                 "which emit the primitive flame.",
     "torch" : "The torch is made of wood and seems to have "
               "been plucked from nature, set on fire and then "
               "stapled to the wall.",
     "surface" : "The wall surface shimmers slightly from the "
                 "torches. It is frozen solid.",
     "ceiling" : "There is no ceiling, snow falls on you.",
     "doorway" : "It has been made of square blocks of ice which "
                 "border the frozen door.",
     "blocks" : "Square blocks of ice border the doorway to the "
                "south. They are equal in length and border the "
                "door marvelously.", 
     "ground" : "It is covered in snow.",
     "ice"    : "Solid ice overwhelms this entire tower.",
     "tower": (: GetLong :),
     ]) );             
  SetItemAdjectives( ([
    "wall" : ({ "roundish"}),
    "snow" : ({ "white","ground","floor" }),
    "torches" : ({ "wooden","several" }),
    "torch" : ({ "wooden" }),
    "surface" : ({ "wall" }),
    "doorway" : ({ "square","ice" }),
    "blocks" : ({ "square" }),
    "ice" : ({ "solid" }),
  ]) );
   SetDoor( "south", WORKROOMDIR "door1");
}

void heart_beat() {
  string fire;
  ::heart_beat();
  switch(random(5)) {
    case 0:
      fire = "Ice crisps and releases a noisy peal which echo off the walls.";
    break;
    case 1:
      fire = "The campfire burns slowly and flickers on occasion.";
    break;
    case 2:
      fire = "Abruptly, piles of snow collapse in on itself and reduce height.";
    break;
    case 3:
      fire = "The tower stone wall creaks loudly and it echos back and forth.";
    break;
    case 4:
      fire = "Bone chilling wind enters and tosses drifting snow about mixing everywhere.";
    break;
   }
  eventPrint(fire);
}