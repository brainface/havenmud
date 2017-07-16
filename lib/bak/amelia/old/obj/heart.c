#include <lib.h>
inherit LIB_ITEM;
inherit LIB_LISTEN;
inherit LIB_SMELL;
inherit LIB_TOUCH;

string dacolor;

static void create() {
   string *color = ({ ({ "%^GREEN%^","green","%^B_GREEN%^" }),
                     ({ "%^BLUE%^","vibrant blue","%^B_BLUE%^" }),
                     ({ "%^ORANGE%^","orange","%^B_ORANGE%^" }),
                     ({ "%^RED%^","pink","%^B_RED%^", }),
                     ({ "%^YELLOW%^","yellow","%^B_YELLOW%^" }),
                     ({ "%^MAGENTA","purple","%^B_MAGENTA%^" }),
                  })[random(6)];
   item::create();
   dacolor = color[1];
   SetKeyName("heart");
   SetShort("a candy heart");
   SetId( ({ "heart","candy" }) );
   SetAdjectives( ({ "candy","heart" }) );
   SetLong(color[0] + "The " + color[1] + " candy heart "
           "looks almost too good to eat.  The chalky "
           "appearance is made precious by the message "
           "engraved in deep red writing.");
   SetMass(1);
   if(color[1] == "pink") {
      color[2] = "";
   }
   SetRead(color[2] + "%^RED%^ " +
           ({ "i love u","u r great","#10",
              "be mine","yes","sweetie",
              "cutie-pie","love",
              "%^BLUE%^:%^YELLOW%^-%^RED%^)",
              "love","cool dude","smile",
              "i like u","pretty","kiss",
              "kiss me" })[random(16)] +
              " %^RESET%^");
   SetSmell("The heart smells like nothing but "
            "sweetness and chalk.");
   SetListen("A little voice from deep within the "
             "heart cries out " + color[0] + 
             "'Eat Me, Eat Me!'%^RESET%^  Another "
             "voice begs you to give the heart "
             "to your lover or close friend.");
   SetTouch("The little candy is hard and a little "
            "rough, but mostly smooth.  There are "
            "deep indentations where the lettering "
            "is.");
}

void init() {
   ::init();
   add_action("eat","eat");
}

int eat(string arg) {
   object ob = new(base_name(this_object()));
   if(!arg || arg == "" || arg != "heart") return 0;
   send_messages("devour","$agent_name $agent_verb "
                "a small, " + dacolor + " candy "
                "heart.",this_player(),0,
                environment(this_player()));
   message("","The heart tastes delicious and leaves "
           "you begging for more.",this_player());
   ob->eventMove(environment(this_object()));
   message("","Another heart appears!  Your wishes "
           "have been answered.",this_player());
   eventDestruct();
   return 1;
}
