//
// The Masters' Training Hall
// Filename: masters_hall
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include "../haven.h"
#include <lib.h>

inherit LIB_ROOM;

//int GuildCheck();

static void create() {
   ::create();
   SetClimate("indoors");
   SetAmbientLight(45);
   SetShort("the Grand Masters' Training Hall");
   SetExits( ([
      "west" : "training_hall",
   ]) );
//   AddExit("up", "havenmage_room", (: GuildCheck :) );
   SetListen( ([
      "default" : "The hum of masters of the art resounds into the air.",
   ]) );
   SetSmell( ([
      "default" : "The scent of death is on the air.",
   ]) );
   SetProperty("no bump", 1);
   SetLong("This large hall is the training room of the Greatest Mages "
           "of Kailie. Scripted on the walls are words of wisdom from "
           "the oldest and most revered Mages ever to have lived. Those "
           "born of Elven blood mingle here with those of Humans and "
           "other lesser races. Here in this place, it seems, the only "
           "discrimination is by Mastery of the Art. To the west lies "
           "the central hall of the Library.");
   SetItems( ([
      ({ "wisdom", "words", "word" }) : 
         "The words are too faint to be read, but the names are not.",
      ({ "name", "names" }) : 
         "Yossarian, Zane, Zorander, Alhana, Yanna.",
      ({ "hall" }) :
         "The central hall of the Library lies to the west.",
   ]) );
   SetItemAdjectives( ([
      "hall" : ({ "central" }),
   ]) );
   SetInventory( ([
      H_NPC + "alhana" : 1,
   ]) );
}

string GetLong() {
   if (this_player()->GetGuild() == "havenmage") {
      return (room::GetLong() + "\n%^YELLOW%^There is a glowing "
              "staircase leading up.%^RESET%^");
   } else return ::GetLong();
}

/*string GetObviousExits() {
   if(this_player()->GetGuild() == "havenmage") {
      return ::GetObviousExits();
   } else {
      return ("%^BLUE%^BOLD%^" + implode(GetExits() - ({ "up" }), ", ") + 
              "%^RESET%^" );
   }
}

int GuildCheck() {
   if(this_player()->GetGuild() == "havenmage" ||
     creatorp(this_player()) ) {
      return 1;
   } else {
      message("system", "You go nowhere at all.", this_player() );
      return 0;
   }
}
*/

/* Approved by Duuktsaryth on Sun Apr 25 19:21:53 1999. */
