/*  The new birth room.  Does much nicer, cleaner stuff.
 */
#include <lib.h>
#include <haven.h>
#include <size.h>
#include <damage_types.h>
#include <daemons.h>
#include <std.h>

inherit LIB_ROOM;
void eventStartPlayer(object);

static void create() {
  room::create();
  SetShort("someplace in the ethereal plane");
  SetObviousExits("out");
  SetClimate("indoors");
  SetExits( ([ 
    ]) );
  SetLong("This is a nether place in the ethereal plane.");
}

void init() {
  ::init();
  if(!immortalp(this_player()) && (this_player()->GetTestChar() != 1)) {
    eventStartPlayer(this_player());
  }
}

void eventStartPlayer(object who) {
  string race = who->GetRace();
  string town = who->GetTown();

  if (who->GetSize() == SIZE_MEDIUM) {
  	 new(STD_CLOTHING "pants")->eventMove(who);
     new(STD_CLOTHING "shirt")->eventMove(who);
     new(STD_CLOTHING "shoes")->eventMove(who);
}
  if (who->GetSize() == SIZE_SMALL) {
         new(STD_CLOTHING "small_pants")->eventMove(who);
     new(STD_CLOTHING "small_shirt")->eventMove(who);
     new(STD_CLOTHING "small_shoes")->eventMove(who);
}
  if (who->GetSize() == SIZE_VERY_LARGE) {
     new(STD_CLOTHING "vl_shoes")->eventMove(who);
     new(STD_CLOTHING "vl_shirt")->eventMove(who);
     new(STD_CLOTHING "vl_pants")->eventMove(who);
  }
  if (who->GetSize() == SIZE_LARGE) {
    new(STD_CLOTHING "lg_shirt")->eventMove(who);
    new(STD_CLOTHING "lg_shoes")->eventMove(who);
    new(STD_CLOTHING "lg_pants")->eventMove(who);
  }
     who->eventForce("wear all");
     who->eventMove(SETUP_D->GetCemetery(town));
     who->SetParalyzed(5);
  
  if (race == "gelfling" && (who->GetGender() == "female")) {
    who->AddLimb("left wing", "torso",2,0);
    who->AddLimb("right wing", "torso",2,0);
    who->eventPrint("Being a girl, you grow wings!");
  }  
}
