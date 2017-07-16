#include <lib.h>
inherit LIB_ITEM;
inherit LIB_READ;

int CheckTown();
string CheckLang();

static void create() {
   item::create();
   SetKeyName("key");
   SetShort("a small key");
   SetId( ({ "key","ditmar_gate_key" }) );
   SetAdjectives( ({ "gate","gates","ditmar","small" }) );
   SetLong("Some writting has been etched into the side of this small, "
           "plain key.");
   SetMass(4);
   SetValue(0);
   SetDestroyOnSell(1);
   SetDamagePoints(30);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(30);
   SetRepairSkills( ([
                       "metal working" : 0,
                  ]) );
   SetPreventDrop( (: CheckTown :) );
   SetProperty("magic","The key is tuned to the Gates of Ditmar.  It "
               "will not let people who live there get rid of it.");
   SetProperty("history","The key belongs to some citizen of Ditmar, some marn, "
               "or some mar.  Keys are given out to the citizens, marn, and mar "
               "upon their approach of the gate.");
   SetRead( (: CheckLang :) );
}

string CheckLang() {
   object who = this_player();
      if(who->GetLanguageLevel("Marin") > 50+random(20)) {
      who->eventPrint("The writting in the key reads: /n"
                      "%^MAGENTA%^DITMAR GATE KEY%^RESET%^");
      return "";
   }
   who->eventPrint("The writting is in a language who do not know well enough to "
          "read.");
   return "";
}

int CheckTown() {
   if(this_player()->GetTown() == "Ditmar") {
      this_player()->eventPrint("This key is the only way back into "
                                "Ditmar.  It won't let you get rid of "
                                "it, but sticks to you as you try to let "
                                "go.");
      return 0;
   }
   return 1;
}