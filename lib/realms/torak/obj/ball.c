#include <lib.h>
#include <daemons.h>

inherit LIB_ITEM;
inherit LIB_REMOTEDESCRIPTION;

int gaze(string args);
string gazed = "";

 static void create() {
  ::create();
  SetKeyName("ball");
  SetId( ({ "ball", "crystal ball" }) );
  SetShort("a %^WHITE%^BOLD%^crystal ball%^RESET%^");
  SetLong("This crystal ball is very smooth and perfectly round. "
    "A hazey cloud of glittering colors and lights swirl about inside "
    "of it. Perhaps if you were to <gaze into ball> you would see something.");
  SetMass(0);
}

void init() {
  ::init();
  add_action("gaze", "gaze");
  }

int gaze(string args) {
  /*if (this_player()->GetKeyName() != "torak") {
    message("system", "This isn't your toy.", this_player() );
    return 1;
  }*/

  if (!args) {
    message("system", "Try <gaze into ball> this time.", this_player() );
    return 1;
  }
 
  
  if (args == "into ball") { 
    object *allrooms = objects( (: $1->GetClimate() && !vehiclep($1) :) );
    allrooms = filter(allrooms, (: strsrch(base_name($1), "/domains/")==0 :) );
    allrooms = filter(allrooms, (: strsrch(base_name($1), "/domains/staff/")!=0 :) );
    allrooms = filter(allrooms, (: strsrch(base_name($1), "/domains/estates/")!=0 :) );
    allrooms = filter(allrooms, (: !$1->GetProperty("ocean") :) );
    gazed = (allrooms[random(sizeof(allrooms))]);
    message("system", "You gaze into the crystal ball.", this_player() );
    message("system", GetRemoteDescription( base_name(gazed) ), this_player() );
    return 1;
  }

  return 0;
}
