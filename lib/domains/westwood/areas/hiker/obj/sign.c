#include <lib.h>
inherit LIB_ITEM;

string DaRead();

static void create() {
   item::create();
   SetKeyName("sign");
   SetShort("an old sign");
   SetId( ({ "sign" }) );
   SetAdjectives( ({ "old","trail","hiker" }) );
   SetLong("The sign is in front of the trail to the northwest.  "
           "Some faded paint is on it.");
   SetRead( (: DaRead :) );
   SetPreventGet("It is attached firmly to the ground.");
   SetMaterial( ({ "metal" }) );
}

string DaRead() {
   object who = this_player();
   if(who->GetLanguageLevel("Oiseau") > 60+random(20)) {
      who->eventPrint("The sign reads:\n"
             "%^GREEN%^WESTWOOD HIKING TRAIL\n"
             "Northwest%^RESET%^");
      return "";
   }
   who->eventPrint("You cannot understand the language on the sign well enough to "
          "read it.");
   return "";
}
