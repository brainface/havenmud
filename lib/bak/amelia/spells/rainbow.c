#include <lib.h>
inherit LIB_ITEM;
inherit LIB_TOUCH;

int timer = 300;

static void create() {
   ::create();
   SetKeyName("beautiful rainbow");
   SetShort("a beautiful rainbow");
   SetId( ({ "bow","rainbow","rain" }) );
   SetAdjectives( ({ "beautiful" }) );
   SetLong("The rainbow twinkles with the moisture inside of it, "
           "with most of the colors on it showing:  %^RED%^Red"
           "%^RESET%^ first, then %^YELLOW%^yellow%^RESET%^ and "
           "%^GREEN%^green%^RESET%^, and finally %^BLUE%^blue"
           "%^RESET%^ and %^MAGENTA%^violet%^RESET%^.  Orange and "
           "purple are both missing, but it doesn't hurt the overall "
           "effect of seeing a lovely rainbow.  It disappears up into "
           "the sky about halfway through its arc.");
   SetPreventGet("The rainbow is all mist with nothing to grab "
                 "onto.");
   SetProperty("magic","This rainbow was revealed by an Eclat.  It "
               "has some healing properties.");
   set_heart_beat(2);
   SetTouch("derb");
}

eventTouch(object who, string str) {
   who->eventCompleteHeal(40);
   send_messages(({ "try","get" }),"$agent_name $agent_verb to touch "
                 "a rainbow, but $agent_verb more mist than anything "
                 "useful.",who,0,environment(who));
   who->eventPrint("You feel a little healthier.");
   eventDestruct();
}

void heart_beat() {
   timer--;
   if(!timer) {
      send_messages("","The rainbow flickers out of visibility.",
                    this_object(),0,environment(this_object()));
      eventDestruct();
   }
}