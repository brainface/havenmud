#include <lib.h>
#include <daemons.h>
inherit LIB_ITEM;
inherit LIB_PRESS;

void DoPress();

static void create() {
	item::create();  
	SetShort("a small silver button");
	SetKeyName("button");
	SetId( ({ "button" }) );
	SetAdjectives( ({ "small", "silver" }) );
	SetLong("This is a small silver button. Press it.");
	SetPress("default", (: DoPress :) );
	SetPreventGet("The button is firmly connected to the counter.");
	SetInvis(1);
}

void DoPress() {
	send_messages("press", "$agent_name $agent_verb a small silver button.",
	           this_player(), 0, environment(this_player()) );
	environment()->eventPrint("A soft chiming noise rustles in the building.");
	CHAT_D->eventSendChannel("Order", "order", 
	  capitalize(this_player()->GetKeyName()) + " has pressed the silver button.");
	return;
}
