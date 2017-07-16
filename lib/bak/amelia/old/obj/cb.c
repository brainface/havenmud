#include <lib.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("clipboard");
   SetId( ({ "amelia clipboard","clipboard","cb" }) );
   SetShort("Amelia's clipboard");
   SetLong("This is Amelia's Clipboard.");
   SetMass(1);
   SetValue(20);
   SetDamagePoints(5000);
}

void init() {
   item::init();
   add_action("peck","peck");
   add_action("wibble","wibble");
   add_action("lag","lag");
   add_action("breath","breath");
   add_action("possum","possum");
   add_action("bearhug","bearhug");
   add_action("forgive","forgive");
   add_action("curtsey","curtsey");
   add_action("ribpoke","ribpoke");
}

int ribpoke(string arg) {
   object target;
   if(!arg) return 0;
   if(target = present(arg,environment(this_player()))) {
      message("my_action","You poke " + target->GetCapName() + " in "
              + possessive(target) + " bony ribs.",this_player());
      message("other_action",this_player()->GetCapName() + " pokes "
              + target->GetCapName() + " in " + possessive(target) + 
              " bony ribs.",environment(this_player()), ({ this_player(),
              target }) );
      message("other_action",this_player()->GetCapName() + " pokes "
              "you in your bony ribs... and OUCH, that hurt!",
              target);
      return 1;
   }
   return 0;
}

int curtsey(string arg) {
   object target;
   if(!arg) { 
      message("my_action","You curtsey awkwardly.",this_player());
      message("other_action",this_player()->GetCapName() +
         " curtseys awkwardly.",environment(this_player()),
         this_player());
      return 1;
   }
   if(target = present(arg,environment(this_player()))) {
      message("my_action","You curtsey awkwardly before " + 
         target->GetCapName() + ".",this_player());
      message("other_action",this_player()->GetCapName() + " "
         "curtseys awkwardly before " + target->GetCapName() + ".",
         environment(this_player()),({ target,this_player() })),
      message("other_action",this_player()->GetCapName() + " "
         "curtseys awkwardly before you.",target);
      return 1;
   }
   return 0;
}


int forgive(string arg) {
   object target;
   if(!arg) return 0;
   if(target = present(arg,environment(this_player()))) {
      message("my_action","You assume an ecclesiastical expression "
              "and forgive the sins of " + target->GetCapName() + ".",
              this_player());
      message("other_action", this_player()->GetCapName() + " assumes "
              "an ecclessiastical expression and forgives the sins of "
              + target->GetCapName() + ".",environment(this_player()),
              ({ this_player(),target }) );
      message("target", this_player()->GetCapName() + " assumes an "
              "ecclessiastical expression and forgives your sins.",
              target);
      return 1;
   }
   return 0;
}

int bearhug(string arg) {
   object target;
   if(!arg) return 0;
   if(target = present(arg,environment(this_player()))) {
      message("my_action","You give " + target->GetCapName() + " a "
              "huge bear hug.",this_player());
      message("other_action", this_player()->GetCapName() + " gives "
              + target->GetCapName() + " a huge bear hug.",
              environment(this_player()), ({ this_player(),target }) );
      message("target", this_player()->GetCapName() + " gives you a "
              "huge bear hug.",target);
      return 1;
   }
   return 0;
}

int possum() {
//   object target;
   message("my_action","You do your best imitation of a corpse.",
           this_player());
   message("other_action",this_player()->GetCapName() + " does "
           + possessive(this_player()) + " best imitation of a "
           "corpse.",environment(this_player()),this_player());
   return 1;
}

int breath(string arg) {
   object target;
   if(!arg) {
      message("my_action","You hold your breath until you turn %^BOLD%^%^BLUE%^"
              "blue%^RESET%^!",this_player());
      message("other_action",this_player()->GetCapName() + " holds " +
              possessive(this_player()) + " breath until " +
              nominative(this_player()) + " turns %^BOLD%^%^BLUE%^blue%^RESET%^!",
              environment(this_player()),this_player());
      return 1;
   }
   else {
      if(target = present(arg,environment(this_player()))) {
         message("my_action", "You glare angrily at " + target->GetCapName() +
                 " and hold your breath until you turn %^BOLD%^%^BLUE%^"
                 "blue%^RESET%^!", this_player());
         message("other_action", this_player()->GetCapName() + " glares "
                 "angrily at " + target->GetCapName() + " and holds " +
                 possessive(this_player()) + " breath until she turns "
                 "%^BOLD%^%^BLUE%^blue%^RESET%^!", environment(this_player()),
                 ({ this_player(), target }) );
         message("target_action", this_player()->GetCapName() + " glares "
                 "angrily at you and holds " + possessive(this_player()) +
                 " breath until " + nominative(this_player()) + " turns "
                 "%^BLUE%^%^BOLD%^blue%^RESET%^!",target);
         return 1;
      }
   }
   return 1;
}

int peck(string arg) {
   object target;
   if(!arg) return 0;
   if(target = present(arg,environment(this_player()))) {
      message("my_action", "You peck "+ target->GetCapName() +
              " on " + possessive(target) + " cheek.", this_player());
      message("other_action", this_player()->GetCapName() + " pecks "+
              target->GetCapName() + " on " + possessive(target) +
              " cheek.", environment(this_player()),
              ({ this_player(), target }) );
      message("target_action", this_player()->GetCapName() +
              " pecks you on your cheek.", target);
      return 1;
   }
   return 1;
}

int wibble(string arg) {
   object target;
   if(!arg) {
      message("my_action","You wibble around like crazy.",this_player());
      message("other_action",this_player()->GetCapName() + " wibbles "
         "around like crazy.",environment(this_player()),this_player());
      return 1;
   }
   if(target = present(arg,environment(this_player()))) {
      message("my_action", "You wibble around "+ target->GetCapName() +
              " like crazy.", this_player());
      message("other_action", this_player()->GetCapName() + " wibbles "
              "around " + target->GetCapName() + " like crazy.",
              environment(this_player()), ({ this_player(), target }) );
      message("target_action", this_player()->GetCapName() +
              " wibbles around you like crazy.", target);
      return 1;
   }
   return 1;
}

int lag(string arg) {
   object target;
   if(!arg) {
      message("my_action","You lag blahishly.",this_player());
      message("other_action","Amelia lags blahishly.",
         environment(this_player()),this_player());
      return 1;
   }
   if(target = present(arg,environment(this_player()))) {
      message("my_action", "You lag blahishly at "+ target->GetCapName() +
              ".", this_player());
      message("other_action", this_player()->GetCapName() + " lags "
              "blahishly at " + target->GetCapName() + ".",
              environment(this_player()), ({ this_player(), target }) );
      message("target_action", this_player()->GetCapName() +
              " lags blahishly at you.", target);
      return 1;
   }
   return 1;
}
