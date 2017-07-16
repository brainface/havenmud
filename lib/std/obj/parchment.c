/*
 * parchment.c
 * A simple test of player-holdable
 * writery thingies.
 * Mahkefel jan 2011
 * I'm using "player_book" as generic ID for these things.
 * So like a special bookcase would only accept ID= "player_book"
 */
#include <lib.h>
#include <daemons.h>
#include <vendor_types.h>
inherit LIB_ITEM;

private string scribble = "The pages are blank.";
int GetScribble();

static void create() {
  item::create();
  SetKeyName("parchment");
  SetMaterials( ({ "wood" }) );
  AddSave( ({ "scribble" }) );
  SetShort("a sheet of parchment");
  SetId( ({ "parchment", "sheet", "player_book" }) );
  SetAdjectives( ({ "sheet","of" }) );
  SetDamagePoints(50);
  SetMass(10);
  SetVendorType(VT_TREASURE);
  SetLong(
   "This is a crumpled sheet of parchment. It could be useful for writing "
   "short notes of no importance. You could <use parchment to write "
   "something>. Alternatively, you could read it."
  );
  SetRead( "default", (: GetScribble :) );
  SetValue(60);
  }

mixed eventUse(object me, string args) {
  sscanf(args, "write %s", scribble);
  CHAT_D->eventSendChannel("Book", "reports", capitalize(this_player()->GetKeyName()) +
    " wrote this down: " + scribble);
  //SetRead( "default", scribble );
  send_messages("scribble",
    "$agent_name $agent_verb something down on $target_name",
    me, this_object(), environment(me));
  return 1;
}

int GetScribble() {
  message( "system", scribble, this_player() );
  return 1;
}

