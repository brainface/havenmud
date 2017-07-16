#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

string doRead();

static void create() {
	::create();
	SetKeyName("note"); // note, paper
	SetShort("a rolled note");
	SetAdjectives( ({ "rolled" }) );
	SetLong("This is a rolled up note, perhaps you could read it?");
	SetRead( (: doRead :) );
	SetVendorType(VT_TREASURE);
	SetProperty("history", "This note has been lost at sea for years."
			" It was written by an enslaved rower on a long"
			" forgotten vessel bound for Parva.");
}

string doRead() {
	object who = this_player();
	if((who->GetLanguage("Eltherian") > 80+random(20))) {
		who->eventPrint("You unroll the note and begin reading:\n\n"
				"Years ago, there was a story for making"
				" stories. The story began as a story and"
				" never ended. This is the never ending"
				" story.");
		return "";
	}
	who->eventPrint("The letters all look like gibberish to you.");
	return "";
}
