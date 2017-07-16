#include <lib.h>
inherit LIB_ITEM;

int CheckKeyName();

static void create() {
   item::create();
   SetKeyName("translucent bubble");
   SetShort("a beautiful bubble");
   SetId( ({ "bubble","sun","light" }) );
   SetAdjectives( ({ "translucent","beautiful","majestic",
                     "multi-colored","colorful","light","shining",
                     "sun","mini" }) );
   SetLong("This majestic %^YELLOW%^m%^BLUE%^u%^MAGENTA%^l"
           "%^RED%^t%^YELLOW%^i%^BLUE%^-%^MAGENTA%^c%^RED%^o%^YELLOW%^l"
           "%^BLUE%^o%^MAGENTA%^r%^RED%^e%^YELLOW%^d %^BLUE%^b"
           "%^MAGENTA%^u%^RED%^b%^YELLOW%^b%^BLUE%^l%^MAGENTA%^e"
           "%^RESET%^ floats gently in the air, the %^BLUE%^c"
           "%^MAGENTA%^o%^RED%^l%^YELLOW%^o%^BLUE%^r%^MAGENTA%^s%^RESET%^ "
           "playing across the surface in streams of shining light.  "
           "Light radiates from the inside of the bubble, turning the "
           "bubble into a mini sun.");
   SetMass(0.00005);
   SetPreventGet( (: CheckKeyName :) );
}

int CheckKeyName() {
   if(this_player()->GetKeyName()!="amelia") {
      eventDestruct();
      message("my_action","As you lean out to touch the amazing bubble, "
              "it bursts and leaves a slightly sticky residue on your "
              "hand.",this_player());
      message("other_action",this_player()->GetCapName() + " leans out to "
              "touch a beautiful bubble, yet it bursts and dissappears.",
              environment(this_player()),this_player());
      return 1;
   }
   message("other_action",this_player()->GetCapName() + " kneels "
           "down on the floor, and cautiously approaches the "
           "translucent bubble.  Directly underneath it, " +
           nominative(this_player()) + " gently stands, balancing "
           "the bubble on " + possessive(this_player()) + " nose.",
           environment(this_player()),this_player());
   message("my_action","You kneel down on the floor and cautiously "
           "approach the translucent bubble.  When you are directly "
           "underneath it, you gently stand, balancing the bubble on "
           "your nose.",this_player());
   return 1;
}
