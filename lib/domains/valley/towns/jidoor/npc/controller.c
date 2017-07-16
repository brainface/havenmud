// mahkefel may '10
#include <lib.h>   
#include <domains.h>
#include <std.h>
#include "../jidoor.h"
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("rumpel");
  SetShort("rumpel, famed philosopher of Jidoor");
  SetId( ({ "rumpel","philosopher" }) );
  SetAdjectives( ({ "famed","philosopher","of","Jidoor","jidoor" }) );
  SetRace("sprite");
  SetGender("male");
  SetClass("mystic");
  SetLevel(20);
  SetTown("Jidoor");
  SetLong(
    "Rumpel is a philosopher known throughout the land"
    " wherever philosophers are respected and not simply"
    " attacked on sight. Unlike other teachers of Jidoor"
    " who rely on classrooms and libraries for instruction,"
    " Rumpel prefers to send his students out into the world"
    " to learn by experience. One can <ask rumpel"
    " for quests> if they were looking for some adventure."
    );
  SetInventory( ([
    JID_OBJ "/vs_shirt" : "wear shirt",
    JID_OBJ "/vs_slacks" : "wear slacks",
    STD_POLE "/staff" : "wield staff",
  ]) );
  SetCombatAction(25, ({
      "!cast fireball",
      "!cast sphere",
    "!cast terra",
    }) );
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(15, ({
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
  }) );
}

