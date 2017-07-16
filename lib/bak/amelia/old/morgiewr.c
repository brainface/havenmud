#include <lib.h>
inherit LIB_ROOM;

int Allowed(object ob);
int shield(string args);
private int shielded = 0;
private string *WhoAllowed = ({ "morgoth","amelia" });

static void create() {
  room::create();
  SetShort("Morgoth's Workroom");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong("You are in the top room of Barad Durgul. Torches dimly light the room. Out of "
    "the four slit windows you can see nothing but darkness. In the middle of the room "
    "there is a black crystal ball set in an ornate stand. On the walls are several "
    "shelves of bottles and books. In one corner is a portal that leads to the heavens.");
  SetExits( ([
    "up" : "/realms/morgoth/dragon_roost",
    "down" : "/realms/amelia/workroom",
    ]) );
  SetItems( ([
    "heaven" : "A portal that leads to the heavens.",
	]) );
  SetEnters( ([
    "heaven" : "/domains/heaven/room/olympus",
    ]) );
  shielded = 0;
  }

void init() {
  room::init();
  add_action("shield", "shield");
  }

int CanReceive(object ob) {
    if (!userp(ob)) return 1;
    if (!Allowed(ob) && !adminp(ob)) {
      message("system",
        "%^GREEN%^A pulsing field of green energy comes up before you and "
        "refuses to letyou pass.%^RESET%^", ob);
      message("system", 
        "%^GREEN%^" + capitalize(ob->GetKeyName()) + " just tried "
        "to get in.%^RESET%^", this_object() );
    }
  else {
    if(find_living("morgoth"))
      message("system",
        "%^BOLD%^RED%^"+ob->GetCapName()+" just entered your workroom.",
        find_living("morgoth"));
    if(present("amelia", this_object()))
          message("system",
            "%^BOLD%^RED%^"+ob->GetCapName()+" just entered the room."
	    "%^RESET%^", find_living("amelia"));
    }
  return Allowed(ob);
  }

int CanRelease(object ob) {
  if (shielded)
  return Allowed(ob);
  else if(userp(ob)) {
    if(find_living("morgoth"))
          message("system",
           "%^BOLD%^RED%^"+ob->GetCapName()+" just left your workroom.",
	    find_living("morgoth"));
    if(present("amelia", this_object()))
          message("system",
            "%^BOLD%^RED%^"+ob->GetCapName()+" just left the room.%^RESET%^",
	    find_living("amelia"));
    return 1;
    }
  else return 1;
  }

int shield(string args) {
  if (this_player()->GetKeyName() != "morgoth" &&
    this_player()->GetKeyName() != "amelia") {
    message("system",
      (shielded ? "The shield is up." : "The shield is down."),
      this_player() );
    return 1;
    }

  if (args == "up") {
    send_messages("raise",
      "$agent_name $agent_verb the shield.",
      this_player(), 0, this_object() );
    return (shielded = 1);
    }
  if (args == "down") {
    send_messages("lower",
      "$agent_name $agent_verb the shield.",
      this_player(), 0, this_object() );
    shielded = 0;
    return 1;
    }
  if (!args) {
    message("system",
      (shielded ? "The shield is up." : "The shield is down."),
      this_player() );
    return 1;
    }
  return 0;
  }

int Allowed(object ob) {
  if (!ob) ob = this_player();
  if (!shielded) return 1;
  if (member_array(ob->GetKeyName(), WhoAllowed) != -1) 
     return 1;
  else return 0;
  }

