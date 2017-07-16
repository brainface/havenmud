#include <lib.h>
inherit LIB_ITEM;

string DaRead();

static void create() {
   item::create();
   SetKeyName("sign");
   SetShort("a large sign on the wall");
   SetId( ({ "sign","sign on wall","sign on the wall" }) );
   SetAdjectives( ({ "large","parva" }) );
   SetLong("The sign is nailed on to the building to the west.  "
           "There is orange writting on it.");
   SetMaterial( ({ "wood" }) );
   SetPreventGet("The sign is firmly nailed to the wall.");
   SetRead( (: DaRead :) );
}

string DaRead() {
   int blah = 0;
   object who = this_player();
   if(who->GetLanguageLevel("Enlan") > 50+random(20)) blah = 1;
   if(who->GetLanguageLevel("Oiseau") > 70+random(20)) blah = 1;
   if(who->GetLanguageLevel("Eltherian") > 50+random(20)) blah = 1;
   if(blah) {
      who->eventPrint("The sign reads:\n"
             "%^ORANGE%^Parva Inn%^RESET%^");
      return "";
   }
   who->eventPrint("You do not know any of the languages of the sign well enough "
          "to read it.");
   return "";
}
