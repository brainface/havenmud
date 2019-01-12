#include <lib.h>
#include <daemons.h>
inherit LIB_VERB;

static void create() {
    ::create();
    SetVerb("survey");
    SetRules("");
    SetErrorMessage("You can't seem to survey here.");
    SetHelp("Syntax:   survey  \n\n"
      "Allows you to take stock of the surrounding area, noting what "
      "sort of terrain you are in and what sort of resources are "
      "present.");
}

mixed can_survey() {
   object who = this_player();
   object where = environment(who);
   if (who->GetParalyzed()) {
      return "You can do nothing at all.";
   }
   if (who->GetSleeping()) {
      return "An endless dreamscape expands before you!";
   }  
   return 1;
}

mixed do_survey() {
   object who = this_player();
   object room;
   string climate;
   string fishing;
   string farming;
   string mining;
   string ocean;
   
   if ( environment( this_player() )) {
     room = environment(this_player());
   } else {
     return "You are nowhere! Panic!";
   }

   // climate   
   if(room->GetClimate()) {
     climate = room->GetClimate();
     if (climate == "underground") {
       climate = "You are underground.";
     } else if (climate == "indoors") {
       climate = "You are indoors.";     
     } else {
       climate = "The climate is " + climate + ".";
     }
   }

   // mining
   if (room->GetProperty("no mining")) {
      // mining = "You cannot mine here.";
   } else if (room->GetProperty("MinedOut")) {
      mining = "Someone has recently mined here.";     
   } else if (room->GetClimate() == "underground") {
      mining = "This is a good location for mining.";
   }

   // farming
   if (room->GetClimate() == "indoors" || room->GetClimate() =="underground" ) {
     // farming = "You cannot farm here.";
   } else if (room->GetProperty("no farming") || room->GetTown() != "Wilderness") {
      farming = "The soil here is barren.";
   } else if (room->GetProperty("FarmedOut")) {
      farming = "Someone has recently farmed here.";     
   } else {
      farming = "This is a good location for farming.";
   }

   // coast/ocean
   if (room->GetProperty("coastal") ) {
     ocean = "You are on the coast.";
   } else if (room->GetProperty("shallows") ) {
     ocean = "You are in shallow water.";
   } else if (room->GetProperty("ocean") ) {
     ocean = "You are in the deep ocean.";
   }
   
   // needs more info but fishing is terrible
   if (room->GetFish() ) {
     fishing = "There may be some fish here.";
   }  
   
   if (climate) who->eventPrint(climate);
   if (ocean) who->eventPrint(ocean);
   if (mining) who->eventPrint(mining);
   if (farming) who->eventPrint(farming);
   if (fishing) who->eventPrint(fishing);
   
   return 1;
}

