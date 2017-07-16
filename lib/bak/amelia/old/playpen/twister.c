#include <lib.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("tongue twister");
   SetShort("a tongue twister");
   SetId( ({ "tongue twister","twister","tongue" }) );
   SetLong("The tongue twister is a strange device that "
           "twists tongues and ties them in knots while "
           "people trying saying things like 'toy boat' "
           "and 'red leather yellow leather.'  It floats "
           "gentle in the air around your head, ready to "
           "twist your words into what you did not mean to "
           "say.");
   SetMass(0);
   SetValue(0);
}

void init() {
   ::init();
   add_action("tonguepook","tonguepook");
   add_action("pook","pook");
   add_action("shine","shine");
   add_action("glow","glow");  //mesmorizing?
   add_action("colorblind","colorblind");
   add_action("blowbubbles","blowbubbles");
}

int shine(string arg) {
   return 0;
}

int glow(string arg) {
   return 0;
}

int pook(string arg) {
   object target;
   if(this_player()->GetKeyName()!="amelia") {
      return 0;
   }
   if(!arg) return 0;
   if(target = present(arg,environment(this_player()))) {
      message("my_action","You pook",this_player());
   }
   return 0;
}

int tonguepook(string arg) {
   object target;
   if(this_player()->GetKeyName()!="amelia") {
      return 0;
   }
   if(!arg) return 0;
   if(target = present(arg,environment(this_player()))) {
      message("my_action","You pook " + target->GetCapName() +
              "'s tongue back into " + possessive(target) + " mouth.",
              this_player());
      message("environment",this_player()->GetCapName() + " pooks "
              + target->GetCapName() + "'s tongue.",
              environment(this_player()),({ target,this_player() }));
      message("other_action",this_player()->GetCapName() + " pooks "
              "your tongue.",target);
      return 1;
   }
   else return 0;
}

int colorblind(string arg) {
   object target;
   if(!arg) return 0;
   if(target = present(arg,environment(this_player()))) {
      message("my_action","You blind " + target->GetCapName() + " with "
              "a dazzling display of colors!",this_player());
      message("other_action",this_player()->GetCapName() + " blinds "
              + target->GetCapName() + " with a dazzling display of "
              "colors!",environment(this_player()),({ this_player(),
              target }));
      message("other_action",this_player()->GetCapName() + " %^B_BLACK%^"
              "%^RED%^b%^ORANGE%^l%^YELLOW%^i%^GREEN%^n%^BLUE%^d"
              "%^CYAN%^s %^MAGENTA%^y%^WHITE%^o%^RED%^u %^ORANGE%^c"
              "%^YELLOW%^o%^GREEN%^l%^BLUE%^o%^CYAN%^r%^MAGENTA%^f"
              "%^WHITE%^u%^RED%^l%^ORANGE%^l%^YELLOW%^y%^GREEN%^!"
              "%^BLUE%^!%^CYAN%^!%^MAGENTA%^!%^WHITE%^!%^RED%^!"
              "%^ORANGE%^!%^YELLOW%^!%^GREEN%^!%^BLUE%^!%^RESET%^",
              target);
      return 1;
   }
   return 0;
}

int blowbubbles(string arg) {
   object target;
   if(!arg) {
      message("my_action","You blow some beautiful translucent %^YELLOW%^m"
              "%^BLUE%^u%^MAGENTA%^l%^RED%^t%^YELLOW%^i%^BLUE%^-"
              "%^MAGENTA%^c%^RED%^o%^YELLOW%^l%^BLUE%^o%^MAGENTA%^r"
              "%^RED%^e%^YELLOW%^d %^BLUE%^b%^MAGENTA%^u%^RED%^b"
              "%^YELLOW%^b%^BLUE%^l%^MAGENTA%^e%^RED%^s%^RESET%^, "
              "which settle down onto the floor and slowly start "
              "popping.",this_player());
      message("other_action",this_player()->GetCapName() + " blows "
              "some beautiful translucent %^YELLOW%^m%^BLUE%^u%^MAGENTA%^l"
              "%^RED%^t%^YELLOW%^i%^BLUE%^-%^MAGENTA%^c%^RED%^o%^YELLOW%^l"
              "%^BLUE%^o%^MAGENTA%^r%^RED%^e%^YELLOW%^d %^BLUE%^b"
              "%^MAGENTA%^u%^RED%^b%^YELLOW%^b%^BLUE%^l%^MAGENTA%^e"
              "%^RED%^s%^RESET%^, which settle down onto "
              "the floor and slowly start popping.",
              environment(this_player()),this_player());
      return 1;
   }
   if(target = present(arg,environment(this_player()))) {
      message("my_action","You blow some bubbles at " +
              target->GetCapName() + " and they slowly settle around "
              + possessive(target) + " shoulders, popping gently.",
              this_player());
      message("other_action",this_player()->GetCapName() + " blows "
              "some bubbles at " + target->GetCapName() + " and they "
              "slowly settle around " + possessive(target) + " shoulders, "
              "popping gently.",environment(this_player()),({ target,
              this_player() }) );
      message("other_action",this_player()->GetCapName() + " blows "
              "some bubbles at you and they slowly settle around your "
              "shoulders, popping gently.",target);
      return 1;
   }
   return 0;
}

