/* Torak's workroom */

#include <lib.h>
#include <std.h>
#include <dirs.h>
#include <domains.h>
#include <rooms.h>
#include "torak.h"
 
inherit LIB_FISHING;
inherit LIB_TOUCH;

int Allowed(object ob);
int shield(string args);
private int Shielded = 1;
private string *WhoAllowed = ({ 
  "duuk",
  "snarf",
  "melchezidek",
  "mahkefel",
  "alessandra",
    "torak",
  });

static void create() {
  ::create();
  SetProperty("coastal", 1);
  SetNoClean(1);
  SetSpeed(5);
  SetFish( ([
    DIR_STD "fish/guppy" : 100,
    ]) );
  SetChance(25);
  SetMaxFishing(100);
  SetShort("inside an immense temple by the sea");
  SetLong(
    "The immense temple of stone seperates the beach of a vast sea "
    "from the shifting sand dunes of the desert expanse. "
    "It is a free standing structure, devoid of walls, created from "
    "corinthian columns spaced apart and supporting the roof. A "
    "slab of stone resting upon two smaller stones forms an altar."
  );
  SetClimate("arid");
  SetDomain("Yozrath");
  SetItems( ([
    ({ "bar" }) : "Stabby Lynn's Bar",
    ({ "sea", "wave", "waves", "froth", "foam" }) : "Waves crash upon "
       "on the beach of the desert in a barrage of froth "
       "and foam. The water comes in endlessly from the ocean.",
    ({ "water", "ocean", "horizon" }) : "The blue water of the "
       "ocean continues out until it is indescernable from the horizon.",
    ({ "desert", "sand", "dunes", "dune", "expanse" }) : "The desert seems to be devoid "
      "of life. The dunes shift about methodically as the winds "
      "change.",
    ({ "temple", "structure", "columns", "column" }) : 
      "The temple itself contains no walls that line the perimeter.  "
      "Instead, rows of corinthian columns line the walkways and support "
      "roof.",
    "roof" : "The roof is supported by many corinthian columns to disperse "
     "its immense weight.",
    "altar" : "The simple altar is a large slab of grey stone, supported by two "
      "smaller pieces to support it. The slab is stained an ochre red on the "
      "top, suggestive to its use in a form of sacrifice.",
    ({ "beach" }) : (: GetLong :)
    ]) );
  SetItemAdjectives( ([
    "sea" : ({ "vast" }),
    "water" : ({ "blue" }),
    "temple" : ({ "immense", "stone" }),
    "columns" : ({ "corinthian" }),
    "altar" : ({ "stone" }),
    "sand" : ({ "shifting" }),
  ]) );
  Shielded = 0;
  if(query_night()) {
    SetInventory( ([
      TORAK_NPC "petpony" : 1,
      TORAK_OBJ "clay_pot" : 1,
      TORAK_OBJ "oasis" : 1,
      TORAK_OBJ "rope" :1,
      TORAK_OBJ "painting" : 1,
    ]) );
  } else {
    SetInventory( ([
      TORAK_NPC "petpony" : 1,
      TORAK_OBJ "rope" :1,
      TORAK_OBJ "clay_pot" : 1,
      TORAK_OBJ "oasis" : 1,
      TORAK_OBJ "painting" : 1,
    ]) );
  }
  SetListen( ([
    "default" : "The wind breezes softly through the columns.",
    ]) );
  SetSmell( ([
    "default" : "Incense permeates the temple.",
    ]) );
  SetTouch( ([
  "default" : "A tranquil sacred calm overwhelms the senses.",
    "altar" : "An immeasurable sense of loss overwhelms your soul.",
    ]) );
  SetExits( ([
    "north" : TORAK_ROOM "north_sea",
    ]) );
   SetEnters( ([ 
      "bar" : "/realms/torak/stab_bar/room/stab_bar",
   ]) );
}

void init() {
  ::init();
  add_action("shield", "shield");
  add_action("Check", ({
    "ed", "rm", "update", "quit", "dest", "duc",
    "home", "goto", "call", "eval",
    }) );
}

int CanReceive(object ob) {
  if (!Allowed(ob)) {
    message("system",
      "An invisible immortal just %^RED%^BOLD%^kicked%^RESET%^ you square in the nuts!%^RESET%^", ob);
    ob->eventMoveLiving(ROOM_HELL);
    message("system",
      "%^RED%^You wake in a %^BOLD%^hell%^RESET%^RED%^ of a lot of pain!%^RESET%^", ob);
  if (userp(ob))
    message("system", 
      "%^RED%^" + capitalize(ob->GetKeyName()) + " just tried "
      "to visit uninvited but got %^BOLD%^kicked%^RESET%^RED%^ square in the nuts!%^RESET%^", this_object() );
    }
  else return Allowed(ob);
  }

int CanRelease(object ob) {
  if (Shielded) return 0;
  return 1;
   }

int shield(string args) {
  if (this_player()->GetKeyName() != "melchezidek" &&
      this_player()->GetKeyName() != "duuk" ) {
  message("system",
    (Shielded ? "The shield is up." : "The shield is down."),
     this_player() );
  return 1;
  }

  if (args == "up") {
    send_messages("raise",
      "$agent_name $agent_verb the shield.",
      this_player(), 0, this_object() );
      return (Shielded = 1);
  }
  if (args == "down") {
    send_messages("lower",
      "$agent_name $agent_verb the shield.",
      this_player(), 0, this_object() );
      Shielded = 0;
      return 1;
  }
  if (!args) {
    message("system",
      (Shielded ? "The shield is up." : "The shield is down."),
      this_player() );
      return 1;
  }
  return 0;
}

int Allowed(object ob) {
  if (!ob) ob = this_player();
  if (!Shielded) return 1;
  if (member_array(ob->GetKeyName(), WhoAllowed) != -1) 
    return 1;
  else return 0;
  }

int Check(string args) {
  if (Allowed(this_player())) { return 0; }
  else {
    message("system", "You are prevented by the shield.",
      this_player() );
    return 1;
  }
}

varargs int eventDig(object who, object what) {
  if (!who) {
    debug("Woot No Who! " + identify(what));
    return 1;
  }
  debug(identify(who) + " " + identify(what));
  return 1;
}
