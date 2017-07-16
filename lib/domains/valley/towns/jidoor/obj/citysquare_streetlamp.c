#include <lib.h>
inherit LIB_ITEM;

int eventReadSign(string msg, string lang, object who);

static void create() {
  item::create();
  SetKeyName("streetlamp");
  SetShort("a streetlamp with a small sign swinging from it");
  SetId( ({ "sign","streetlamp","lamp","sign on streetlamp",
            "sign on lamp","streetlight","light","sign on streetlight"
            "sign on light" }) );
  SetAdjectives( ({ "small","swinging"}) );
  SetLong((query_night() ? SetLong("The streetlamp is a metal pole "
    "outstretching from the City Hall on southwestern side of the "
    "street. At the very end of it is a small glowing sphere that "
    "casts a brillant but soft blue light upon the city square. "
    "Hanging from the streetlamp is a small wooden sign with writing "
    "on it is hanging from it.") : SetLong("The streetlamp is a metal "
    "pole outstretching from the City Hall on southwestern side of "
    "street. At the very end of it is a small clear sphere that "
    "apparently casts light upon the city square at night. Hanging "
    "from the streetlamp is a small wooden sign with writing on it "
    "is hanging from it.") ));
  SetProperty("history", "The streetlamps of Jidoor were an invention "
          "and gift from a wise sprite by the name of Navan.");
  SetProperty("magic", "The streetlamp is unquestionably enimating "
          "the residue of enchantment magic.  It appears that at night "
          "the streetlamp automatically ignite their own light source "
          "and in the morning, automatically shut off.");
  SetMaterial( ({ "metal","wood" }) );
  SetPreventGet("The streetlamp is too high up and bolted to the "
                "side of Jidoor's City Hall.");
  SetRead("default", (: eventReadSign :) );
  SetMass(500);
  SetValue(0);
  SetRadiantLight((query_night() ? SetRadiantLight(40) : 
                  SetRadiantLight(0) ));
}

int eventReadSign(string msg, string lang, object who) {

who = this_player();
lang = "Sprith";
msg = "   Jidoor's City Square\n";
msg += "   Intersection of Mage and Magildan Avenues\n\n";
msg += "   North: Mage Avenue North:\n";
msg += "      Healing Shop, Cemetery, Temple Ruins,\n";
msg += "      Mystic's Crescent and residential area.\n";
msg += "   East: Magildan Avenue East\n";
msg += "      Jidoor City Inn, Post Office,\n";
msg += "      Mystic's Crescent and Luna's Shop\n";
msg += "   West: Magildan Avenue West\n";
msg += "      Jidoor City Bank, General Store, Gem Shop, \n";
msg += "      and the Kailie Bazaar\n";
msg += "   South: Mage Avenue South\n";
msg += "      Great Library of Jidoor, Jidoor City Pub\n";
msg += "      and the city gates.\n";

   if (this_player()->GetSleeping()) { 
   message("whatever", "You are asleep!", who);
   return 0;
   }

   if((this_player()->GetLanguageLevel(lang)) > 0) {
   msg = translate(msg, this_player()->GetLanguageLevel(lang));
   message("whatever", "The sign reads: \n"+msg+"", who);
    return 1;
   }
   else {
   message("whatever", "You do not recognize the language.", who);
   return 0;
   }
}
