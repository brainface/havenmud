#include <lib.h>
inherit LIB_ITEM;
inherit LIB_PRESS;

void DoPress();

static void create() {
	item::create();  
	SetShort("a big red button");
	SetKeyName("button");
	SetId( ({ "button" }) );
	SetAdjectives( ({ "big", "red" }) );
	SetLong("This is a big red button. Press it.");
	SetPress("default", (: DoPress :) );
	SetPreventGet("The button is firmly nailed to the wall.");
}

void DoPress() {
	object door;
	
	door = environment()->GetDoor("cabin");  // This is based on the room.  
	                                         // See the room for why.
	door->SetLocked(0);
	send_messages("press", "$agent_name $agent_verb a big red button.",
	           this_player(), 0, environment(this_player()) );
	environment()->eventPrint("The door unlocks with a short *click*.");
	return;
}
