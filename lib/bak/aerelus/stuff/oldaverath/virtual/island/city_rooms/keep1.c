#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create()  {
     room::create();
      SetClimate("indoors");
  SetAmbientLight(35);
     SetShort("Main entrance");
      SetLong("The main entrance to the Duke of Averath's private "
        "residence is cold, musty and dank. A single torch flutters weakly, "
        "struggling to bathe the room in minimal light. The closely fitted "
       "stones that make up the floor are wet and slippery, when they are "
        "not obscured by a once luxurious massive, stained carpet. Once "
        "beautiful tapestries adorn the wall, like flaps of decaying flesh off of "
        "an emaciated corpse.");
     SetItems( ([
        ({ "entrance", "main entrance"}) :
                 "The main entrance, on the whole, is dark, rundown,"
                 "and foreboding.",
         ({ "torch"}):
                 "The torch struggles to light the room, bathing the "
                "room in flickering shadows.",
      ({"stones", "floor" }) : "The stone blocks are covered in dirt that "
            "has been tracked in from outside the keep.",
      ({"carpet", "stained carpet"}) : "The once grand carpet is "
               "dark with caked dirt. The edges are torn and frayed,"
               "the once elegant colors and designs faded with time." ,
      ({ "wall", "walls", "tapestries", "tapestry" }) : "The decayed tapestries "
      "are barely readable, but they appear to hark back to the Duke's "
           "days of greatness.",
           ]) );
     SetItemAdjectives( ([
         "stones" : ({"closely fitted","fitted","wet","slippery"}),
         "floor" : ({"wet","slippery"}),
     ]) );
    SetSmell( ([
                "default" : "The cloying smell of wet stone and " 
                       "earth is detectable. "
                       ]) );
    SetListen( ([
                "default" :  "The faint sound of water dripping "
                    "on stone can be heard. "
             ]) );
     SetExits( ([
          "east" : AVERATH_CITY + "keep2",
          "out" : AVERATH_ISLAND + "0,1,0",
                   ]) );
}
