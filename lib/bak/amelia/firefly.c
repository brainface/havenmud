#include <lib.h>
inherit LIB_NPC;

int Life = 1000;
string Creator;
void destme();
int SetLife(int mrow);
string SetCreator(string who);
int CheckCreator();
int Dance(string str);
int Land(string str);
string GetCreator();
int FollowSomeone(string str);
int StopFollow(string str);

static void create() {
   npc::create();
   SetKeyName("firefly");
   SetShort("a shining firefly");
   SetId( ({ "firefly" }) );
   SetAdjectives( ({ "shining" }) );
   SetLong("A pair of shimmering wings hang off the glowing body of this small "
	"firefly.  Little sparks of light fall off her wings whenever a breeze "
	"disturbs them.");
   SetRace("insect");
   SetClass("animal");
   SetLevel(1);
   SetGender("female");
   SetAction(3, ({
                   "!emote buzzes around.",
                   "!emote flickers her light.",
                   "!emote does some flips in the air.",
                }) );
   SetRadiantLight(10);
   set_heart_beat(1);
}

void heart_beat() {
     Life--;
     if (!Life) destme();
}

void destme() {
    if (environment(this_object())) {
        message("system","The firefly flits away into the wilderness.",
            environment(this_object()) );
    }
    eventDestruct();
}

int SetLife(int mrow) {
    return Life = mrow;
}

string SetCreator(string who) {
    return Creator = who;
}

int CheckCreator() {
    find_living("amelia")->eventPrint(this_player()->GetKeyName());
    return (Creator == this_player()->GetKeyName());
}

string GetCreator() {
    return Creator;
}

int eventForce(string cmd) {
   if(cmd == "dance") { 
      Dance(cmd);
      return 1;
   }
   if(cmd == "dance") {
      Land(cmd);
      return 1;
   }
   if(CheckCreator()) {
      if( (cmd == "follow") || (cmd == "follow me") ||
	(cmd == "follow " + GetCreator()) ) {
         FollowSomeone(cmd);
         return 1;
      }
      if((cmd == "follow firefly") || (cmd == "stop") ) {
         StopFollow(cmd);
         return 1;
      }
   }
   return ::eventForce(cmd);
}



int Dance(string str) {
    if(!CheckCreator()) {
       send_messages( ({ "look" }), "$agent_name $agent_verb at $target_name "
		"quizzically.", this_object(), this_player(),
		environment(this_object()));
       return 1;
    }
    send_messages( ({ "dance","circle" }), "$agent_name $agent_verb "
	"with twirls and swirls, trying to impress $target_name.  Shimmering "
	"with light, $agent_nominative $agent_verb $target_possessive_noun head tightly, "
	"eventually crashing into $target_possessive nose.",this_object(),
	this_player(),environment(this_object()));
    return 1;
}

int land(string str) {
    if(!CheckCreator()) {
       send_messages( ({ "look" }), "$agent_name $agent_verb at $target_name "
		"quizzically.", this_object(), this_player(),
		environment(this_object()));
       return 1;
    }
    send_messages( ({ "flitter" }), "$agent_name $agent_verb "
	"through the air to $target_name, trustingly landing "
	"on $agent_possessive open hand.",this_object(),
	this_player(),environment(this_object()));
    return 1;
}

int FollowSomeone(string str) {
    send_messages( ({ "buzz" }),"$agent_name $agent_verb over to $target_possessive_noun "
                "shoulder.",this_object(),this_player(),environment(this_object()));
    find_living(Creator)->AddFollower(this_object());
    find_living(Creator)->eventForce("lead " + GetKeyName());
    return 1;
}

int StopFollow(string str) {
    send_messages( ({ "buzz" }),"$agent_name $agent_verb away from $target_possessive_noun "
                "shoulder.",this_object(),this_player(),environment(this_player()));
    find_living(Creator)->RemoveFollower(this_object());
    return 1;
}
