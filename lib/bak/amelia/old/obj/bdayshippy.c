#include <lib.h>
inherit LIB_ITEM;
inherit LIB_SMELL;
inherit LIB_TOUCH;
inherit LIB_LISTEN;

static void create() {
   item::create();
   SetKeyName("cake");
   SetShort("a birthday cake");
   SetId( ({ "cake" }) );
   SetAdjectives( ({ "bday","birthday","chocolate","raspberry" }) );
   SetLong("Yummm, this cake looks like a very tasty chocolate "
           "sort, and it appears like there might be raspberry "
           "filling inside!  A little aura around it suggests "
           "that it is especially for Zaxan, since he turned 18 "
           "just a few moments ago.");
   SetTouch("It feels just like it should, did you think it wouldn't?  "
            "Now unless you're Zaxan, get your dirty paws off of "
            "it!");
   SetSmell("A hint of raspberries mixes with the chocolate smell "
            "of the cake.");
   SetListen("Cakes don't sound like much of anything, unless they're "
             "really old and have something growing on them (eewww!).  "
             "Luckily, this one fits neither condition, and "
             "has no sound.");
}

void init() {
   ::init();
   add_action("eat","eat");
}

int eat(string arg) {
   if(arg != "cake") return 0;
   if(this_player()->GetCapName() != "Zaxan") return 0;
   send_messages("devour","$agent_name $agent_verb a "
                 "cake!",this_player(),0,environment(this_player()));
   find_living("zaxan")->eventPrint("The cake is scrumptious.  And "
               "even though it seemed like you ate it all, it "
               "appears that there is still more!");
   return 1;
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}

string GetListen(string str) {
   return listen::GetListen(str);
}