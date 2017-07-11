// Title: Destroyed Grymxoria Town
// File: church2b.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Central Chapel of the Saahagoth Cathedral
//
// Revision History: 
// Gaby Jan99

#include <lib.h>
#include <domains.h>
#include "../grymxoria.h"
inherit LIB_ROOM;
int PreExit(string dir);
 
static void create() {
    room::create();
    SetShort("the Cathedral of Saahagoth");
    SetClimate("indoors");
    SetDomain("Estergrym");
    SetAmbientLight(20);
    SetExits( ([ "up" : G_ROOM + "church1d",
        "down" : G_ROOM + "church2b"]) );
    AddExit("east", G_ROOM "church3c");
    AddExit("west", G_ROOM "church1c", (: PreExit :) );
    SetLong("A large antechamber in the cathedral of Saahagoth. "
        "The room is long and narrow leading from a large curving "
        "stair case down, to a equally large staircase that leads up "
        "to the basilica. A small door leads off to each side. The "
      "floor seems burnt away by a strange burning "
      "fire which sits in the center of the room.");
    SetTown("Grymxoria");
    SetItems( ([
    "fire" : "This strange fire looks to beckon people to enter it!",
        ({ "stairs", "stair cases", "down stairs", "up stairs" }) :
            "A large curved staircase leading off from this antechamber"]) );
    SetInventory(  ([
/*
	    G_NPC + "daemon" : 3,
*/
	])  );
  SetEnters( ([
    "fire" : DOMAIN_PLANES "virtual/fire/0,0",
  ]) );
    }

int PreExit(string dir) {
    if ( (this_player()->GetSkillLevel("faith")) &&
	    (this_player()->GetReligion(1) == "Saahagoth") ||
        (creatorp(this_player())) )  return 1;
    else {
        write("A magical force prevents you from going that way.");
        return 0;
        }
    }
