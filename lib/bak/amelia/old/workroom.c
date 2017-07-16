#include "/realms/amelia/room/itemsschtuff.h"
#include <lib.h>
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort("Amelia's Workroom");
  SetLong("A large window overlooks the muezzin town Soleil, "
          "and a huge sunroof above lets in lots and lots of "
          "light.  A blooming lilac bush "
          "is placed to the southern side of the room, and "
          "little furry things leap around and play on the "
          "floor.  A simple rocking chair sits next to the "
          "window, with a small clipboard floating next to it.");
   SetItems(ITEMSSCHTUFF);
  SetSmell( ([
               "default" : "The sweet smell of lilacs "
                  "fills the air.",
          ]) );
   SetObviousExits(implode(keys(ITEMSSCHTUFF), ", "));
  SetExits( ([ "up" : "/domains/heaven/room/sage",
               "down" : "/domains/heaven/room/olympus" ]) );
   SetEnters(ITEMSSCHTUFF);
  SetInventory( ([
                   "/realms/duuktsaryth/npc/thing" : 1,
              ]) );
  SetProperty("no attack",1);
}
 
int CanReceive(object who) {
   if(who->GetKeyName()=="amelia") {
      return 1;
   }
   else if(who->GetKeyName()=="syra") {
      return 1;
   }
   else if(who->GetKeyName()=="morgoth") {
      return 1;
   }
   else if(who->GetKeyName()=="fuzzy") {
      return 1;
   }
   else if(who->GetKeyName()=="furry") {
      return 1;
   }
   else if(who->GetKeyName()=="zaxan") {
      return 1;
   }
   else if(who->GetKeyName()=="furry thing") {
      return 1;
   }
   else if(who->GetKeyName()=="popple") {
      return 1;
   }
   else if(archp(who)) {
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
   if(!archp(this_player())) {
      message("other_action","" + this_player()->GetCapName() +
              " attempts to dest something, but something stops them "
              "just in time.",this_object());
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
