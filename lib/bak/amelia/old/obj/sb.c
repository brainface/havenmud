#include <lib.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("snowball");
   SetShort("a snowy-white snowball");
   SetId( ({ "snowy-white snowball","white snowball","snowball","snow",
             "ball" }) );
   SetAdjectives( ({ "snowy-white","white","snowy" }) );
   SetLong("A plain white snowball.");
   SetMass(0);
   SetValue(0);
}

void init() {
   ::init();
   add_action("snowball","snowball");
   add_action("sbhit","sbhit");
   add_action("sbmiss","sbmiss");
}

int snowball(string arg) {
   object target;
   if(!arg) return 0;
   if(target = present(arg,environment(this_player()))) {
      switch(!random(5)) {

         case 0:
         this_player()->eventForce("sbhit " + arg);
         break;

         case 1:
         this_player()->eventForce("sbmiss " + arg);
         break;
         }
      return 1;
   }
   return 0;
}

int sbhit(string arg) {
   object target;
   if(!arg) return 0;
   if(target = present(arg,environment(this_player()))) {
      message("my_action","You throw a snowball at " + target->GetCapName() +
              " and it %^BOLD%^%^BLUE%^hits!!!%^RESET%^",this_player());
      message("other_action", this_player()->GetCapName() + " throws a "
              "snowball at " + target->GetCapName() + " and it %^BOLD%^"
              "%^BLUE%^hits!!!%^RESET%^",environment(this_player()),
              ({ this_player(),target }) );
      message("target", this_player()->GetCapName() + " throws a snowball at "
              "you and it %^BOLD%^%^BLUE%^hits!!!%^RESET%^",target);
      return 1;
   }
   return 0;
}

int sbmiss(string arg) {
   object target;
   if(!arg) return 0;
   if(target = present(arg,environment(this_player()))) {
      message("my_action","You throw a snowball at " + target->GetCapName() +
              " and it %^BOLD%^%^RED%^misses.%^RESET%^",this_player());
      message("other_action", this_player()->GetCapName() + " throws a "
              "snowball at " + target->GetCapName() + " and it %^BOLD%^"
              "%^RED%^hits!!!%^RESET%^",environment(this_player()),
              ({ this_player(),target }) );
      message("target", this_player()->GetCapName() + " throws a snowball at "
              "you and it %^BOLD%^%^RED%^misses.%^RESET%^",target);
      return 1;
   }
   return 0;
}
