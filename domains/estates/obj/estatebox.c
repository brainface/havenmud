#include <lib.h>
#include <daemons.h>
inherit LIB_ITEM;
inherit LIB_PRESS;

mixed DoPress(object who, string component);

static void create() {
  ::create();
  SetKeyName("estate in a box");
  SetDamagePoints(10000);
  SetShort("an estate in a box");
  SetLong(
    "This is a small magical box which will expand to create a mighty "
    "estate. There is a small button on the side clearly marked, \"PRESS "
    "ONLY IN A WIDE, OPEN SPACE\"."
    );
  SetPress("button", (: DoPress :) );
  SetId( ({ "box", }) );
  SetAdjectives( ({ "estate", "in", "a" }) );
  SetValue(100000);
  SetMass(0);
}

int DoPress(object who, string component) {
  object env;
  object key;
  string town;
  if (component != "button") {
    who->eventPrint("Pressing that won't help. Press the button.");
    return 1;
  }
  env = environment();
  if (!env) return 0;
  if (env != who) {
    who->eventPrint("You need to be holding the box to do that.");
    return 1;
  }
  if (!env = environment(env)) return 0;
  
  if ((town = env->GetTown()) == "Wilderness") {
    who->eventPrint("You can only do that in a town.");
    return 1;
  }
  
  if (env->GetClimate() == "indoors") {
    who->eventPrint("Doing that indoors would be just silly.");
    return 1;
  }
  
  if (present("estate", env)) {
    who->eventPrint("Someone else has already set up an estate here.");
    return 1;
  }
  
  CHAT_D->eventSendChannel("ESTATE", "reports", who->GetCapName() + " has placed an estate at " + short_file(base_name(env)));
  write_file("/log/players/estates", who->GetCapName() + " has placed an estate at " + short_file(base_name(env)) + "\n");
  ESTATE_D->AddEstate("/domains/estates/virtual/main_estate/" + town + "/" + capitalize(who->GetKeyName()), base_name(env));
  send_messages( ({ "press" }),
    "$agent_name $agent_verb the tiny button on the estate-in-a-box.",
    who, 0, env);
  env->eventPrint("A huge estate expands and builds itself from the tiny box!");
  if (key = new("/domains/estates/virtual/key/" + town + "/" + capitalize(who->GetKeyName()))) {
    who->eventPrint("A small key magically appears in your hand.");
    key->eventMove(who);
  } else {
    CHAT_D->eventSendChannel("ESTATE", "error", "Failed to create a key for " + who->GetCapName());
  }
  eventDestruct();
  return 1;
}
  
  