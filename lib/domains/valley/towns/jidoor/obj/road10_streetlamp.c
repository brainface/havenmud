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
    "firmly planted on the southwestern side of the "
    "intersection. At the very end of it is a small glowing sphere "
    "that "
    "casts a brillant but soft blue light upon the intersection. "
    "Hanging from the streetlamp is a small wooden sign with writing "
    "on it is hanging from it.") : SetLong("The streetlamp is a metal "
    "pole firmly planted on southwestern side of intersection. At the "
    "very end of it is a small clear sphere that "
    "apparently casts light upon the intersection at night. Hanging "
    "from the streetlamp is a small wooden sign with writing on it "
    "is hanging from it.") ));
  SetProperty("history", "The streetlamps of Jidoor were an invention "
          "and gift from a wise sprite by the name of Navan.");
  SetProperty("magic", "The streetlamp is unquestionably enimating "
          "the residue of enchantment magic.  It appears that at night "
          "the streetlamp automatically ignite their own light source "
          "and in the morning, automatically shut off.");
  SetMaterial( ({ "metal","wood" }) );
  SetPreventGet("The streetlamp is firmly planted in the ground.");
  SetRead("default", (: eventReadSign :) );
  SetMass(500);
  SetValue(0);
  SetRadiantLight((query_night() ? SetRadiantLight(40) : 
                  SetRadiantLight(0) ));
}

int eventReadSign(string msg, string lang, object who) {

who = this_player();
lang = "Sprith";
msg = "   Intersection of Mage Avenue North and Mystic's Crescent%^RESET%^\n\n";
msg += "   North: The Glade:\n";
msg += "      Healing Shop, Cemetery\n";
msg += "   East: Mystic's Crescent\n";
msg += "      the Hall of Rogues, Merchant's Tower,\n";
msg += "      Magildan's Compound, residential area and the Path of Energy\n";
msg += "   West: \n";
msg += "      Magildan Temple Ruins\n";
msg += "   South: Mage Avenue North\n";
msg += "      City Square, Great Library of Jidoor, \n";
msg += "      Jidoor City Pub, residential area and the city gates.\n";

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
