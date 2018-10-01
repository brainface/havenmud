/* 
 * notebook.c
 * A simple test of player-holdable
 * writery thingies.
 * Mahkefel jan 2011
 */
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

private string scribble = "The pages are blank.";
int GetScribble();

static void create() {
  item::create();
  SetKeyName("notebook");
  SetMaterials( ({ "wood" }) );
  AddSave( ({ "scribble" }) );
  SetShort("a wireless notebook");
  SetId( ({ "notebook" }) );
  SetAdjectives( ({ "wireless" }) );
  SetDamagePoints(300);
  SetMass(20);
  SetVendorType(VT_TREASURE);
  SetLong(
   "This is a wireless notebook. It's college ruled and bound with tape. "
   "You could <use notebook to write something>. Alternatively, you could "  
   "read it."
  );
  SetRead( "default", (: GetScribble :) );
  SetValue(60);
  }

mixed eventUse(object me, string args) {
  sscanf(args, "write %s", scribble);
  debug("wrote: " + scribble);
  SetRead( "default", scribble );
  send_messages("scribble",
    "$agent_name $agent_verb something down in $target_name",
    me, this_object(), environment(me));
  return 1;
}

int GetScribble() {
  message( "system", scribble, this_player() );
  return 1;
}
