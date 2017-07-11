#include <lib.h>
inherit LIB_ITEM;

string DaRead();

static void create() {
   item::create();
   SetKeyName("sign");
   SetShort("a small sign");
   SetId( ({ "sign" }) );
   SetAdjectives( ({ "small","parva" }) );
   SetLong("The sign is plunged into the ground in the middle "
           "of the path.  There is orange writting on it, "
           "and arrows point at the buildings.");
   SetMaterial( ({ "wood" }) );
   SetPreventGet("The sign is firmly entrenched in the ground.");
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
                      "sigh reads:\n"
             "%^ORANGE%^Parva Bank%^RESET%^\n"
             "Next to another arrow pointing south, the sign "
             "reads:\n"
             "%^ORANGE%^Town Hall%^RESET%^");
      return "";
   }
   who->eventPrint("You do not know any of the languages of the sign well enough "
          "to read it.");
   return "";
}
