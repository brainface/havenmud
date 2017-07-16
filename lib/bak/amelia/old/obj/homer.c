#include <lib.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("homer");
   SetShort("a homer");
   SetId( ({ "homer" }) );
   SetLong("It's a homer.  type 'home' or 'mhome'.");
}

void init() {
   ::init();
   add_action("home","home");
   add_action("mhome","mhome");
}

int home() {
   this_player()->eventMove("/realms/amelia/workroom");
   return 1;
}

int mhome() {
   this_player()->eventMove("/realms/morgoth/workroom");
   return 1;
}

