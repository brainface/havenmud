#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;
inherit LIB_SMELL;

void blah();
string FLOWER_COLOR;
string FLOWER_COLORLESS;
int life = 1000;

static void create() {
   item::create();
   switch(random(6)) {
      
      case 0:
      FLOWER_COLOR = "%^RED%^red";
      FLOWER_COLORLESS = "red";
      break;

      case 1:
      FLOWER_COLOR = "%^BLUE%^blue";
      FLOWER_COLORLESS = "blue";
      break;

      case 2:
      FLOWER_COLOR = "%^CYAN%^cyan";
      FLOWER_COLORLESS = "cyan";
      break;

      case 3:
      FLOWER_COLOR = "%^MAGENTA%^magenta";
      FLOWER_COLORLESS = "magenta";
      break;

      case 4:
      FLOWER_COLOR = "%^ORANGE%^orange";
      FLOWER_COLORLESS = "orange";
      break;

      case 5:
      FLOWER_COLOR = "%^YELLOW%^yellow";
      FLOWER_COLORLESS = "yellow";
      break;
   }
   SetKeyName(FLOWER_COLOR + " flower%^RESET%^");
   SetShort("a " + FLOWER_COLOR + " flower%^RESET%^");
   SetId( ({ "flower" }) );
   SetAdjectives( ({ FLOWER_COLORLESS }) );

   SetLong("Joy radiates out of the " + FLOWER_COLOR + " flower%^RESET%^, "
           "adding some happiness to the surrounding area.");
   SetMass(1);
   SetValue(0);
   SetVendorType(VT_TREASURE);
   SetMaterial( ({ "natural" }) );
   SetSmell("Sweet smells permeate the air around the flower.");
   SetProperty("magic","The first time this flower is smelled by "
                       "one who is injured, it will give out a small "
                       "amount of healing.");
   SetProperty("history","This flower was created by an eclat "
               "cleric.");
   SetPreventGet("The flower is rooted into the soil.");
   set_heart_beat(1);
}

void heart_beat() {
   life--;
   if(!life) { blah(); }
}

void blah() {
   send_messages("","A flower disintegrates.",this_object(),0,
                 environment(this_object()));
   eventDestruct();
   return;
}

varargs mixed eventSmell(object who, string str) {
      who->eventCompleteHeal(1);
      who->eventPrint("The joyous smell of the flower fills your body "
                      "with happiness, and then the flower disintegrates.");
   who->eventDisplayStatus();
      eventDestruct();
      return 1;
}
mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
