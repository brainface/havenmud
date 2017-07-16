#include <lib.h>
inherit LIB_ITEM;

string DaRead();

static void create() {
   item::create();
   SetKeyName("sign");
   SetShort("a medium sign");
   SetId( ({ "sign" }) );
   SetAdjectives( ({ "medium","parva" }) );
   SetLong("The sign is tacked up on the building to the north.  "
           "There are arrows on it with words in orange.");
   SetMaterial( ({ "wood" }) );
   SetPreventGet("The sign is firmly attached to the building.");
   SetRead( (: DaRead :) );
}

string DaRead() {
   int blah = 0;
   object who = this_player();
   if(who->GetLanguageLevel("Enlan") > 50+random(20)) blah = 1;
   if(who->GetLanguageLevel("Oiseau") > 70+random(20)) blah = 1;
   if(who->GetLanguageLevel("Eltherian") > 50+random(20)) blah = 1;
   if(blah) {
      who->eventPrint("Next to an arrow pointing north, the "
                      "sign reads:\n"
             "%^ORANGE%^Minkin's Inn%^RESET%^\n"
             "Next to another arrow pointing south, the sign "
             "reads:\n"
             "%^ORANGE%^Pons' Store%^RESET%^");
      return "";
   }
   who->eventPrint("You do not know any of the languages of the sign well enough "
          "to read it.");
   return "";
}
