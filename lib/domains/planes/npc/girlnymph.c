#include <lib.h>
inherit LIB_SENTIENT;
#include "../planes.h"

int ChatLocation(object);

static void create() {
  sentient::create();
  SetKeyName("dryad child");
  SetId( ({ "nymph", "dryad", "child" }) );
  SetAdjectives( ({ "wandering", "dryad", "nymph" }) );
  SetShort("a wandering dryad child");
  SetLong("This mischievous nymph child has fine, firey-red hair "
          "that gently compliments her pale blue eyes.  She appears "
          "to be about thirteen years old, still with a boyish figure, "
          "but looks very strong for her age. ");
  SetRace("nymph");
  SetClass("evoker");
  SetLevel(random(10)+20);
  SetSpellBook( ([
  	"shock"  : 100,
  	"sphere" : 100,
  	]) );
  SetAction(12, ({
    "!trap first thing with bag",
    "!free first thing from bag" 
    "!hum merrily",
    "!say I don't know how anyone could get lost here!",
  	}) );
  SetCombatAction(40, ({
  	"!cast shock",
  	"!cast sphere",
  	}) );
  SetTalkResponses( ([
    "help" : (: ChatLocation :),
    ]) );
//  SetWander(7);
  SetGender("female");
  SetInventory( ([
        PLANE_OBJ + "greendress.c" : "wear dress",
        PLANE_OBJ "bag" : 1,
           ]) );
  SetMorality(250);

}

int GetLanguageLevel(string w) { return 100; }

int eventAsk(object who, string str) {
  ChatLocation(who);
  return ::eventAsk(who, str);
}

int eventRequest(object who, string str) {
  ChatLocation(who);
  return ::eventRequest(who, str);
}

int ChatLocation(object who) {
  object room = environment();
  string path;
  string sX, sY;
  string lan;
  int iX, iY;
  
  if (!room) return 0;
  path = base_name(room);
  
  lan = who->GetNativeLanguage();
  SetLanguage(lan, 100);
  
  if (sscanf(path, "/domains/planes/virtual/forest/%s,%s", sX, sY) != 2) { return 0; }
  iX = to_int(sX); iY = to_int(sY);
  if (iX > 0) sX = "west";  else sX = "east";
  if (iY > 0) sY = "south"; else sY = "north";
  iX = absolute_value(iX); iY = absolute_value(iY);
  
  eventForce("speak in " + lan + " You're probably lost.  Most people that come here are.  You should try to go " + 
             sX + " about " + iX + " leagues and " +  sY + " about " + iY + " leagues. Silly!");
  return 1;
}

  

