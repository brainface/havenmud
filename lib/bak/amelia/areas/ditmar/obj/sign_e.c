#include <lib.h>
inherit LIB_ITEM;
inherit LIB_READ;

string DaRead();

static void create() {
   item::create();
   read::create();
   SetKeyName("sign");
   SetShort("a small sign in front of the south cave");
   SetId( ({ "sign","sign in front of the south cave" }) );
   SetAdjectives( ({ "small","ditmar","south" }) );
   SetLong("The sign sits in front of the southern cave.  There is "
           "some writting on it.");
   SetRead( (: DaRead :) );
   SetPreventGet("It is attached firmly to the ground.");
   SetMaterial( ({ "metal" }) );
}

string DaRead() {
   object who = this_player();
   if(who->GetLanguageLevel("Marin") > 60+random(20)) {
      who->eventPrint("The sign reads:/n"
                      "%^MAGENTA%^GENERAL STORE:/n"
                      "South%^RESET%^");
      return "";
   }
   who->eventPrint("You cannot understand the language on the sign well enough to "
          "read it.");
   return "";
}