#include <lib.h>
inherit LIB_ITEM;


static void create() {
   item::create();
   SetKeyName("destin");
   SetShort("destin");
   SetId( ({ "destin" }) );
}

void init() {
   ::init();
   add_action("destin","destin");
}

int destin(string args) {
   object array stuff;
   if(!find_living(args)) return 0;
   stuff = all_inventory(find_living(args));
   foreach(object item in stuff) {
      item->eventDestruct();
   }
   return 1;
}

