#include <lib.h>
inherit LIB_ARMOUR;

int CheckPerson();

static void create() {
   armour::create();
   SetKeyName("condom");
   SetShort("a condom for duuk");
   SetId( ({ "condom","condom for duuk" }) );
   SetAdjectives( ({ "duuk","duuktsaryth" }) );
   SetLong("In honor of Duuktsaryth and Dweezel getting married, "
           "the immortal staff felt the need to provide some "
           "Protection.  We've all heard Duuktsaryth's stories "
           "and we're all worried about the virgin Syra.  So, "
           "Lord of Order, would you please put this on before "
           "having sex with the dear?  We don't need mini-duuks "
           "and mini-syras running around.  It's a GodCondom<tm>, "
           "so don't fear using it twice.  Remember, the immortals "
           "love you, but we don't want to be stuck babysitting "
           "for free.");
   SetPreventGet( (: CheckPerson :) );
}
 
void init() {
   ::init();
   add_action("wear","wear");
   add_action("remove","remove");
}
 
int wear(string arg) {
   if(arg != "condom") return 0;
   if(this_player()->GetGender() != "male") {
      message("system","Ummm, condoms don't work on females.  DUH.",
              this_player());
      return 1;
   }
   if(this_object()->GetShort() != "a condom for duuk") {
      message("condom","It's already worn on somebody, sickoid.",
              this_player());
      return 1;
   }
   if(this_player()->GetCapName() == "Duuktsaryth") {
      send_messages( ({ "wear" }),"$agent_name $agent_verb "
                        "a condom.",this_player(),0,
                        environment(this_player()));
      message("condom","Thanks goodness.  I was worried you weren't "
              "going to put me on!  Now, remind Syra to swallow the "
              "pill and then we'll be set.  No babies for you two!",
              this_player());
      this_object()->GetShort("a condom for duuk (worn you know where)");
      return 1;
   }
   message("condom","Don't you see the little 'For Duuk Only' tab on "
           "me?  You'll hurt yourself.  Sheeesh!",this_player());
   return 1;
}

int remove(string arg) {
   if(arg != "condom") return 0;
   if(this_object()->GetShort() == "a condom for duuk") {
      message("condom","Umm, you have to put it on before you can "
              "start removing it.",this_player());
      return 1;
   }
   this_object()->SetShort("a condom for duuk");
   send_messages( ({ "remove" }), "$agent_name $agent_verb a condom.",
                     this_player(),0,environment(this_player()));
   return 1;
}

int CheckPerson() {
   if(this_player()->GetCapName() != "Duuktsaryth") return 0;
   else return 1;
}
