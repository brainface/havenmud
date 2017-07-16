#include <lib.h>
inherit LIB_ITEM;
inherit LIB_READ;

string DaRead();

static void create() {
   item::create();
   SetKeyName("sign");
   SetShort("a large sign");
   SetId( ({ "sign" }) );
   SetAdjectives( ({ "large","ditmar" }) );
   SetLong("The sign is posted on the gates, with lots of writting in "
           "many languages on it.");
   SetMaterial( ({ "metal" }) );
   SetPreventGet("The sign is firmly attached to the gates.");
   SetRead( (: DaRead :) );
}

string DaRead() {
   int blah = 0;
   object who = this_player();
   if(who->GetLanguageLevel("Marin") > 40+random(30)) blah = 1;
   if(who->GetLanguageLevel("Drakem") > 70+random(20)) blah = 1;
   if(who->GetLanguageLevel("Barian") > 60+random(30)) blah = 1;
   if(who->GetLanguageLevel("Runic") > 70+random(20)) blah = 1;
   if(who->GetLanguageLevel("Sprith") > 80+random(10)) blah = 1;
   if(blah) {
      who->eventPrint("The sign reads:\n"
             "%^MAGENTA%^DITMAR%^RESET%^");
      return "";
   }
   who->eventPrint("You do not know any of the languages of the sign well enough "
          "to read it.");
   return "";
}