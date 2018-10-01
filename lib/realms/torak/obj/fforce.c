#include <lib.h>
#include <daemons.h>

inherit LIB_ITEM;

int fforce(string args);

 static void create() {
  ::create();
  SetKeyName("fforce");
  SetId( ({ "fforce" }) );
  SetShort("the Fforce");
  SetLong("Use the fforce, Luke");
  SetMass(0);
}


void init() {
  ::init();
  add_action("fforce", "fforce");
  }

int fforce(string args) {
  if (this_player()->GetKeyName() != "torak") {
  message("system", "This isn't your toy.", this_player() );
  return 1;
  }

if(args == "duuk"){
  find_player("duuk")->eventMove("/realms/torak/workroom.c");
  find_player("torak")->eventMove("/realms/torak/workroom.c");
  find_player("torak")->SetProperty("marry", 1);
  find_player("duuk")->SetProperty("marry", 1);
  return 1;
  }

if (args == "melchezidek") {
  object fuobject;
  fuobject = new("/realms/mahkefel/obj/disco.c");
  fuobject->eventMove(find_player("melchezidek"));
  find_player("melchezidek")->SetViking(1);
  return 1;
}

if (args == "alessandra") {
  find_player("torak")->SetProperty("marry", 1);
  return 1;
  }

if (args == "torak") {
  object *allrooms = objects( (: $1->GetClimate() && !vehiclep($1) :) );
  allrooms = filter(allrooms, (: strsrch(base_name($1), "/domains/")==0 :) );
  allrooms = filter(allrooms, (: strsrch(base_name($1), "/domains/staff/")!=0 :) );
  allrooms = filter(allrooms, (: strsrch(base_name($1), "/domains/estates/")!=0 :) );
  allrooms = filter(allrooms, (: !$1->GetProperty("ocean") :) );
  find_player("torak")->eventMove(allrooms[random(sizeof(allrooms))]);
  return 1;
  }

if (args == "mahkefel") {
  object fuobject;
  fuobject = new("/realms/mahkefel/obj/disco.c");
  fuobject->eventMove(find_player("mahkefel"));
  return 1;
}

if (args == "dest mahkefel") {
  find_player("mahkefel")->eventDestruct();
  return 1;
}

if (args == "dest alessandra") {
  find_player("alessandra")->eventDestruct();
  return 1;
}
if (args == "here") {
  message("system", "In communist Russia, Here looks at you!", environment() );
  return 1;
}

if (!args) {
  message("system", "you didnt pick an option!",
  this_player() );
  return 1;
  }
return 0;

}
