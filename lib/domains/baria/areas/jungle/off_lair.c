/*  Off the lair room */
#include <lib.h>
inherit LIB_ROOM;
  object coins;

int BeenDone;
void DoSearch();

static void create() {
  ::create();
  SetShort("a treasure room in Kysanth's lair");
  SetClimate("underground");
  SetDomain("Baria");
  SetExits( ([
      "up" : "lair",
    ]) );
  SetLong("This is a large room that was once guarded by "
          "the dragon Kysanth. Her lair lies up from here.");
  SetProperty("login", "/domains/baria/virtual/jungle/-8,6");
  SetProperty("no teleport", 1);
  SetProperty("no magic", 1);
  SetItems( ([
      "room" : (: GetLong :),
          ]) );         
  SetSearch( ([ "room" : (: DoSearch :) ]) );        
 }

varargs void reset(int count) {
   room::reset();
   coins = new(LIB_PILE);
   coins->SetPile("chits", 260000 + random(260000));
   coins->eventMove(this_object());
  BeenDone =0;
  }
void DoSearch() {
  if (BeenDone) {
     message("other_action",
         this_player()->GetCapName() + " searches around.",
            this_object(), this_player() );
      message("blah", "You do not notice anything special.", this_player());
       return;
         }
    new("/domains/baria/areas/jungle/obj/scroll2")->eventMove(this_player());
   message("other_action",
       this_player()->GetCapName() + " searches around.",
         this_object(), this_player() );
  BeenDone = 1;
  message("blah", "You find a scroll!", this_player());
   }
