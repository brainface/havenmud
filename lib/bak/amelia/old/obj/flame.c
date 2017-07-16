#include <lib.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("flame");
   SetShort("a burning flame");
   SetId( ({ "flame" }) );
   SetAdjectives( ({ "burning" }) );
   SetLong("A simple orange glow radiates out from the flame, which is "
           "suspended in the air with no visible energy source or "
           "support.  It flickers happily, almost giggling at times, "
           "and dances around with joy and grace.");
   SetMass(0);
}

void init() {
   ::init();
   add_action("shine","shine");
   add_action("glow","glow");
   add_action("light","light");
   add_action("glimmer","glimmer");
   add_action("twinkle","twinkle");
   add_action("bloom","bloom");
   add_action("glitter","glitter");
   add_action("sparkle","sparkle");
   add_action("flare","flare");
   add_action("blaze","blaze");
}

int glitter() {
   return 0;
}

int sparkle() {
   return 0;
}

int flare() {
   return 0;
}

int blaze() {
   return 0;
}

int bloom(string arg) {
   object target;
   string FLOWER_COLOR;
   switch(random(6)) {
      
      case 0:
      FLOWER_COLOR = "%^RED%^red";
      break;

      case 1:
      FLOWER_COLOR = "%^BLUE%^blue";
      break;

      case 2:
      FLOWER_COLOR = "%^CYAN%^cyan";
      break;

      case 3:
      FLOWER_COLOR = "%^MAGENTA%^magenta";
      break;

      case 4:
      FLOWER_COLOR = "%^ORANGE%^orange";
      break;

      case 5:
      FLOWER_COLOR = "%^YELLOW%^yellow";
      break;
   }
   if(!arg) { 
      message("my_action","You cause a beautiful " + FLOWER_COLOR + " "
              "flower%^RESET%^ to come to life.",this_player());
      message("other_action",this_player()->GetCapName() +
         " causes a beautiful " + FLOWER_COLOR + " flower%^RESET%^ "
         "to come to life.",environment(this_player()),
         this_player());
      return 1;
   }
   if(target = present(arg,environment(this_player()))) {
      message("my_action","You cause a beautiful " + FLOWER_COLOR + " "
              "flower%^RESET%^ to come to life for " +
              target->GetCapName() + ".",this_player());
      message("other_action",this_player()->GetCapName() + " "
              "causes a beautiful " + FLOWER_COLOR + " flower%^RESET%^ to "
              "comr to life for " + target->GetCapName() + ".",
         environment(this_player()),({ target,this_player() })),
      message("other_action",this_player()->GetCapName() + " "
              "causes a beautiful " + FLOWER_COLOR + " flower%^RESET%^ to "
              "come to life for you.",target);
      return 1;
   }
   return 0;
}

int glow(string arg) {
   object target;
   if(!arg) { 
      message("my_action","Your rosy cheeks glow with life.",this_player());
      message("other_action",this_player()->GetCapName() +
         "'s rosy cheeks glow with life.",environment(this_player()),
         this_player());
      return 1;
   }
   if(target = present(arg,environment(this_player()))) {
      message("my_action","You glow rosily at " + 
         target->GetCapName() + ".",this_player());
      message("other_action",this_player()->GetCapName() + " "
         "glows rosily at " + target->GetCapName() + ".",
         environment(this_player()),({ target,this_player() })),
      message("other_action",this_player()->GetCapName() + " "
         "glows rosily at you.",target);
      return 1;
   }
   return 0;
}

int light() {
   return 0;
}

int glimmer() {
   return 0;
}

int twinkle() {
   return 0;
}

int shine(string arg) {
   object target;
   if(!arg) {
      send_messages("shine","$agent_name $agent_verb with an inner "
                    "light of joy and life.",this_player(),0,
                    environment(this_player()));
      return 1;
   }
   if(target = present(arg,environment(this_player()))) {
      send_messages("shine","$agent_name $agent_verb at $target_name "
                    "with an inner light of joy and life.",
                    this_player(),target,environment(this_player()));
      return 1;
   }
   return 0;
}


