#include <lib.h>
inherit LIB_ITEM;

string DaRead();

static void create() {
   item::create();
   SetKeyName("sign");
   SetShort("a large sign");
   SetId( ({ "sign" }) );
   SetAdjectives( ({ "large","parva" }) );
   SetLong("The sign is plunged into the ground in the middle "
           "of the path.  There is orange writting on it, "
           "and arrows point in different directions.");
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
             "%^ORANGE%^Fish Store%^RESET%^\n"
             "Next to another arrow pointing south, the sign "
             "reads:\n"
             "%^ORANGE%^Cemetery%^RESET%^");
      return "";
   }
   who->eventPrint("You do not know any of the languages of the sign well enough "
          "to read it.");
   return "";
}
