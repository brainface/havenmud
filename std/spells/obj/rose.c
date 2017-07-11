#include <lib.h>
inherit LIB_ITEM;
inherit LIB_SMELL;
inherit LIB_TOUCH;

void blah();
int life = 60;
string ANSI_ALONE;
string COLOR_ALONE;

static void create() {
   item::create();
   switch(random(3)) {

      case 0:
      ANSI_ALONE = "%^YELLOW%^";
      COLOR_ALONE = "yellow";
      break;

      case 1:
      ANSI_ALONE = "%^RED%^";
      COLOR_ALONE = "red";
      break;

      case 2:
      ANSI_ALONE = "";
      COLOR_ALONE = "white";
      break;
   }
   SetKeyName("rose");
   SetShort("a " + COLOR_ALONE + " rose%^RESET%^");
   SetId( ({ "rose", "flower" }) );
   SetAdjectives( ({ COLOR_ALONE, "beautiful" }) );
   SetLong("The beautiful " + ANSI_ALONE + COLOR_ALONE + "%^RESET%^ rose shimmers with joy and love.");
   SetMass(1);
   SetSmell("A delightful aroma exudes from the flower.");
   SetTouch("The petals feel like velvet.");
   SetProperty("magic","When first smelled, the rose gives out a little "
               "healing and sustenance to the sniffer.");
   set_heart_beat(1);
}

void heart_beat() {
   life--;
   if(!life) { blah(); }
}

void blah() {
   send_messages("","A rose disintegrates.",this_object(),0,
                 environment(this_object()));
   eventDestruct();
   return;
}

varargs mixed eventSmell(object who, string str) {
      who->eventCompleteHeal(5);
      if(who->GetFood() < 500 && who->GetDrink() <500) {
      who->AddFood(5);
      who->AddDrink(5);
      }
      who->eventPrint("The joyous smell of the rose fills your body "
                      "with happiness then fades away.");
      eventDestruct();
      return 1;
}
mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
