#include <lib.h>
inherit LIB_ITEM;
inherit LIB_READ;

string DaRead();

static void create() {
   item::create();
   read::create();
   SetKeyName("map");
   SetShort("a map of Ditmar");
   SetId( ({ "map","map of ditmar" }) );
   SetAdjectives( ({ "ditmar" }) );
   SetLong("The map has some general drawings on it, but most of it "
           "is writting.  It spread across a small portion of the wall.");
   SetRead( (: DaRead :) );
   SetPreventGet("It is attached firmly to the wall.");
   SetMaterial( ({ "metal" }) );
}

string DaRead() {
   object who = this_player();
   if(who->GetLanguageLevel("Marin") > 60+random(20)) {
      who->eventPrint("The map gives directions to the prominent "
                      "places in Ditmar and a short description of "
                      "each one.  It reads:  \n"
                      "%^MAGENTA%^Town Hall:  Here.  The mayor and "
                      "town board can be found there.\n"
                      "%^BLUE%^Library:  North, west, and north again.  "
                      "The Spell Board, mage leaders and trainers, and "
                      "sage can be found there.\n"
                      "%^YELLOW%^Barracks:  North, west, and west again.  "
                      "The fighting-based leaders and trainers can be "
                      "found there.\n"
                      "%^GREEN%^Cemetary:  North, west, southwest, and "
                      "east.  Only the dead reside there long.\n"
                      "%^ORANGE%^General Store:  North, west, southwest, "
                      "and south.  The storekeeper sells and buys objects "
                      "of all types.\n"
                      "%^RED%^Ditmar Tavern:  North, west, southwest, west, "
                      "and west again.  The barkeep sells alcoholic beverages "
                      "and basic journey rations.  Rogue and ranger leaders "
                      "tend to frequent that area.\n"
                      "%^MAGENTA%^Ditmar Church of Eclat:  North, west, "
                      "southwest, west, and south.  A wise Eclatish cleric "
                      "teaches the faith within."
                      "%^RESET%^");
      return "";
   }
   who->eventPrint("You cannot understand the language on the sign well enough to "
          "read it.  There are many lines of purple, blue, yellow, "
          "green, orange, and red.");
   return "";
}