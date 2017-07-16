#include <lib.h>
inherit LIB_ITEM;
 
static void create() {
   item::create();
   SetKeyName("playpen buster");
   SetShort("a playpen buster");
   SetId( ({ "buster","b" }) );
   SetAdjectives( ({ "playpen","pp" }) );
   SetLong("This will make it possible to get out of the pp.  ha!");
}
 
void init() {
   ::init();
   add_action("leave","leave");
}
 
int leave() {
   environment(this_player())->eventDestruct();
   this_player()->eventMove("/realms/amelia/workroom");
}
 
eventDestruct() {
   if( (environment(this_object()) != find_living("morgoth")) ) {
      ::eventDestruct();
   }
   return 0;
}
