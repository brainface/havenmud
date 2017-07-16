#include <lib.h>
inherit LIB_ITEM;


static void create() {
   item::create();
   SetKeyName("clonein");
   SetShort("clonein");
   SetId( ({ "clonein" }) );
}

void init() {
   ::init();
   add_action("clonein","clonein");
}

int clonein(string args) {
   object stuff;
   if(!find_living(args)) return 0;
   stuff = new("/std/guild/darkbrotherhood");
   stuff->eventMove(find_living(args));
   return 1;
}

