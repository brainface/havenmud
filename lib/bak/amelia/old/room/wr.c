#include <lib.h>
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort("Amelia's Workroom");
  SetLong("A large window overlooks the muezzin town Soleil, "
          "and a huge sunroof above lets in lots and lots of "
          "light.  A blooming lilac bush is placed to the "
          "southern side of the room, and little furry things "
          "leap around and play on the floor.  A simple rocking "
          "chair sits next to the window, with a small clipboard "
          "floating next to it.");
  SetSmell( ([
               "default" : "The sweet smell of lilacs fills the air.",
          ]) );
  SetObviousExits("none");
  SetExits( ([ "up" : "/domains/heaven/room/sage",
               "down" : "/domains/heaven/room/olympus" ]) );
  SetInventory( ([
                   "/realms/duuktsaryth/npc/thing" : 20,
              ]) );
}
 
int CanReceive(object who) {
   if(who->GetKeyName()=="amelia") {
      return 1;
   }
   else if(who->GetKeyName()=="morgoth") {
      return 1;
   }
   else if(who->GetKeyName()=="karnyth") {
      return 1;
   }
   else if(who->GetKeyName()=="furry thing") {
      return 1;
   }
   else if(!creatorp(who)) return 1;
   else if(sagep(who)) {
      return 1;
   }
   else {
      return 0;
   }
}
 
void init() {
   ::init();
   add_action("dest","dest");
   add_action("call","call");
}
 
int dest() {
   if(this_player()->GetKeyName()=="amelia") return 0;
   if(!sagep(this_player())) {
      message("other_action",this_player()->GetCapName() + " attempts "
              "to dest something, but Amelia stops them just in "
              "time.",this_object());
      return 1;
   }
   else return 0;
}
 
int call(string args) {
   if(archp(this_player())) {
      return 0;
   }
   if(this_player()->GetKeyName()=="amelia") {
      return 0;
   }
   else return 1;
}
