#include <lib.h>
inherit LIB_ITEM;
inherit LIB_READ;

string DaRead();

static void create() {
   item::create();
   SetKeyName("sign");
   SetShort("a small sign");
   SetId( ({ "sign" }) );
   SetAdjectives( ({ "small","ditmar" }) );
   SetLong("The sign is posted near the falls.");
   SetMaterial( ({ "metal" }) );
   SetPreventGet("The sign is firmly attached to the gates.");
   SetRead( (: DaRead :) );
}

string DaRead() {
   object who = this_player();
   if(who->GetLanguageLevel("Marin") > 70+random(20)) {
      who->eventPrint("The sign reads:/n"
                      "%^MAGENTA%^DITMAR FALLS%^RESET%^");
      return "";
   }
   who->eventPrint("You do not know the language of the sign well enough "
          "to read it.");
   return "";
}