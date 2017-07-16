#include <lib.h>
#include <daemons.h>
inherit LIB_SENTIENT;
#include "../maze.h"

int StartQuest(object);
static void dieffs(object);

static void create() {
  sentient::create();
  SetKeyName("dryad");
  SetId( ({ "dryad" }) );
  SetAdjectives( ({ "mischievous" }) );
  SetShort("a mischievous dryad");
  SetLong("This stunning creature has piercing green eyes that seem to "
    "glow in the darkness of the forest. Her soft, long hair has a slight "
    "green tint. Her perfectly formed figure is awe-inducing to all races. ");      
  SetLevel(50);
  SetRace("dryad");
  SetClass("evoker");
  SetAction(12, ({
    "!winks at you.",
    "!giggles as she casually strokes your body.", 
    "!say You look strong enough to help me! I could think of a few ways of "
    "rewarding someone as cute as you.",
  }) );
  SetTalkResponses( ([
    "help" : (: StartQuest :),
  ]) );
  SetGender("female");
}

int GetLanguageLevel(string w) { return 100; }

int eventAsk(object who, string str) {  
  StartQuest(who);
  return ::eventAsk(who, str);
}

int eventRequest(object who, string str) {
  StartQuest(who);
  return ::eventRequest(who, str);
}

int StartQuest(object who) {  
  string lan;
  lan = who->GetNativeLanguage();
  SetLanguage(lan, 100);
  eventForce("speak in " + lan + " Oh, thank you! There is a scroll buried at "
    "the end of our maze. It contains dreadful magic, reading it would make "
    "even me insane! You should bring it to me, for only I can destroy it.");
  eventForce("speak in " + lan + " If you bring it to me, I will see to it "
    "that you are rewarded.. appropriately.");
  eventForce("grope " + who->GetName());
  eventForce("giggle");
  CHAT_D->eventSendChannel("ForestQuest", "reports", 
    "" + who->GetName() + " starts the forest maze quest. Much frustration "
    "ensues.");  
  return 1;
}

int eventReceiveObject(object ob) {
  string lan;
  int x = ::eventReceiveObject(ob);
  if (x != 1) return x;
  if (base_name(ob) == MAZE_OBJ + "fakescroll")
  {
    debug(this_player()->GetName());    
    call_out( (: dieffs, ob :), 0 );   
    // Give the guy gift of nature.
    new(MAZE_OBJ + "realscroll")->eventMove(this_player());    
    lan = this_player()->GetNativeLanguage();
    SetLanguage(lan, 100);
    eventForce("speak in " + lan + " You did it! Thank you so much. Here, "
      "take this scroll. It contains knowledge that we usually wouldn't "
      "disclose to outsiders. But you have proven yourself worthy!");
    eventForce("pet " + who->GetName());
    if(!(this_player()->GetQuestCompleted("Forest Maze Quest"))) {
      who->AddQuest("the Vagabond of the Wild", "Forest Maze Quest");
    CHAT_D->eventSendChannel("ForestQuest", "reports", 
      "" + this_player()->GetName() + " completed the Forest Maze Quest!");
    return 1;
  }
}

static void dieffs(object ob)
{	
	ob->eventDestruct();
}