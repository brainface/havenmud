#include <lib.h>
#include <daemons.h>
inherit LIB_ITEM;
inherit LIB_PULL;

void DoPull(object, string);

static void create() {
	item::create();  
	SetShort("a small lever");
	SetKeyName("lever");
	SetId( ({ "lever" }) );
	SetAdjectives( ({ "small", }) );
	SetLong("This is a small lever. It appears to be approximately gnome-height.");
	SetPull("default", (: DoPull :) );
	SetPreventGet("The lever is firmly connected to the gate.");
	SetInvis(1);
}

void DoPull(object who, string comp) {
	send_messages("pull", "$agent_name $agent_verb a small lever.", who, 0, environment() );
	if (who->GetTown() == "Underland" || creatorp(who)) {
	  environment()->ChangeGateStatus();
	} else {
	  environment()->eventPrint("Nothing of note happens.");
	} 
	return;
}
