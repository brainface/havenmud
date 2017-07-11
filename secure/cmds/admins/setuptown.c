#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

void InputReligion(string, string);
void InputStartRoom(string, string);
void InputCemetery(string, string);
void InputLanguage(string, string);

mixed cmd(string args) {
	if (!args) {
		this_player()->eventPrint("setup which town?");
		return 1;
		}
	SETUP_D->AddTown(args);
	this_player()->eventPrint("Enter the religion for " + args + ": ");
	input_to( (: InputReligion, args :) );
	return 1;
}

void InputReligion(string town, string religion) {
    if (!religion || religion == "") {
      religion = SETUP_D->GetReligion(town);
      this_player()->eventPrint("Religion unchanged as " + religion);
      }
	SETUP_D->SetReligion(town, religion);
	this_player()->eventPrint("Enter a start room for this town: ");
	input_to( (: InputStartRoom, town :) );
}

void InputStartRoom(string town, string startroom) {
    if (!startroom || startroom == "") {
      startroom = SETUP_D->GetStartRoom(town);
      this_player()->eventPrint("StartRoom unchanged as " + startroom);
      }
	SETUP_D->SetStartRoom(town, startroom);
	this_player()->eventPrint("Enter a cemetery for this town: ");
	input_to( (: InputCemetery, town :) );
}

void InputCemetery(string town, string cemetery) {
    if (!cemetery || cemetery == "") {
      cemetery = SETUP_D->GetCemetery(town);
      this_player()->eventPrint("Cemetery unchanged as " + cemetery);
      }
	SETUP_D->SetCemetery(town, cemetery);
	this_player()->eventPrint("Enter this town's base language: ");
	input_to( (: InputLanguage, town :) );
}

void InputLanguage(string town, string language) {
	if (!language || language == "") {
		language = SETUP_D->GetLanguage(town);
		this_player()->eventPrint("Language unchanged as " + language);
		}
	SETUP_D->SetLanguage(town, language);
	this_player()->eventPrint("Thank you.  Your selections have been saved.");
}

	
