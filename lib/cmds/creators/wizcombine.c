#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
	string *tmp = ({});
	
	if (!args) { return "Fucking idiot."; }
	if (sizeof(tmp = explode(args, ", ")) != 3) {
		return "You must wizcombine STRING, STRING, TARGETFILE";
	}
  if (tmp[0] == "--d") {
  	ALCHEMY_D->RemoveCombine(tmp[1], tmp[2]);
  	return "Deleted.";
  	}
  ALCHEMY_D->AddCombine(tmp[0], tmp[1], tmp[2]);
  this_player()->eventPrint("Alchemy product added:");
  this_player()->eventPrint(tmp[0] + " + " + tmp[1] + " == " + 
                            ALCHEMY_D->GetCombine(tmp[0], tmp[1]));
  return 1;
}
