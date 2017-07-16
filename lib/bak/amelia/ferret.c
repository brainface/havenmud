#include <lib.h>
inherit LIB_NPC;

int Life = 1000;
string Creator;
void destme();
int SetLife(int mrow);
string SetCreator(string who);
int CheckCreator();
int AddTame();
int FollowSomeone(string str);
int Dance(string str);
int StopFollow(string str);
int StealStuff(object dud, string blank, string str);
string GetCreator();
int CheckStatus();

static void create() {
   npc::create();
   SetKeyName("ferret");
   SetShort("an albino ferret");
   SetId( ({ "ferret" }) );
   SetAdjectives( ({ "albino" }) );
   SetLong("Beady red eyes shine out from a pinkish face covered in white fur.  "
	"The ferret's sinuous body is long and skinny, with four short legs "
	"balanced on four small claws holding him up.");
   SetRace("rodent","ferret");
   SetClass("animal");
   SetSkill("stealing",1,1);
   SetLevel(20);
   SetGender("male");
   SetAction(3, ({
                   "!emote sniffs the ground furiously.",
                   "!emote raises his nose and smells the air.",
                   "!emote stands on his hind legs and pokes his nose "
			"at the air.",
                }) );
   set_heart_beat(1);
   AddTame();
   Creator = "amelia";
   Life = 5000000;
}

void heart_beat() {
     Life--;
     if (!Life) destme();
}

void destme() {
    if (environment(this_object())) {
        message("system","The ferret hops back into the wilderness.",
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
    return (Creator == this_player()->GetKeyName());
}

string GetCreator() {
    return Creator;
}

int AddTame() {
    AddCommandResponse("follow",(:FollowSomeone:));
    AddCommandResponse("stop",(:StopFollow:));
    AddCommandResponse("dance",(:Dance:));
    AddCommandResponse("steal",(:StealStuff:));
    AddCommandResponse("check", (:CheckStatus:));
    return 1;
}

int FollowSomeone(string str) {
    if(!CheckCreator()) {
       send_messages( ({ "sniff" }), "$agent_name $agent_verb at $target_name "
		"quizzically.", this_object(), this_player(),
		environment(this_object()));
       return 1;
    }
    eventForce("follow " + Creator);
    this_player()->eventForce("lead " + GetKeyName());
    send_messages( ({ "hop" }),"$agent_name $agent_verb around $target_possessive_noun "
		"feet, sniffing.",this_object(),this_player(),environment(this_object()));
    return 1;
}

int Dance(string str) {
    if(!CheckCreator()) {
       send_messages( ({ "sniff" }), "$agent_name $agent_verb at $target_name "
		"quizzically.", this_object(), this_player(),
		environment(this_object()));
       return 1;
    }
    send_messages( ({ "jump","grasp" }), "$agent_name $agent_verb "
	"into the air, trying to grab at $target_name with his small paws.  Clapping "
	"his paws with every leap, $agent_nominative finally $agent_verb ahold "
	"of $target_possessive_noun nose.",this_object(),
	this_player(),environment(this_object()));
    return 1;
}

int StopFollow(string str) {
    if(!CheckCreator()) {
       send_messages( ({ "sniff" }), "$agent_name $agent_verb at $target_name "
		"quizzically.", this_object(), this_player(),
		environment(this_object()));
       return 1;
    }
    send_messages( ({ "start" }),"$agent_name $agent_verb sniffing the ground "
		"away from $target_possessive_noun "
		"feet.",this_object(),this_player(),environment(this_player()));
    eventForce("follow " + GetKeyName());
    return 1;
}

int StealStuff(object dud, string blank, string str) {
   string blah, name;
   object target;
    if(!CheckCreator()) {
       send_messages( ({ "sniff" }), "$agent_name $agent_verb at $target_name "
		"quizzically.", this_object(), this_player(),
		environment(this_object()));
       return 1;
    }
   if(!str) { this_player()->eventPrint("You need to ask ferret to steal from <person>."); }
   sscanf(str,"from %s",name);
   if(!name || !(target = present(name, environment(this_object())))) {
      sscanf(str,"%s from %s",blah, name);
      if(!name || !(target = present(name, environment(this_object()))))  {
         this_player()->eventPrint("You cannot steal from someone who is not here.");
         return 1;
      }
   }
   if(this_object()->GetStaminaPoints() < 10) {
	this_player()->eventPrint("Your ferret is too tired for such skullduggery.");
        return 1;
   }

   this_player()->eventPrint("Your ferret attempts to steal from " +
		capitalize(name) + ".");
   eventForce("steal money from " + name);
   if(GetCurrencies() != ({ })) {
      foreach(string bleh in GetCurrencies()) {
         eventForce("give " + GetCurrency(bleh) + " " + bleh + " to " + Creator);
      }
      this_player()->eventPrint("Your ferret was successful!");
      return 1;
   }
   this_player()->eventPrint("Your ferret failed to steal anything.");
   return 1;
}

int CheckStatus() {
    if(!CheckCreator()) {
       send_messages( ({ "sniff" }), "$agent_name $agent_verb at $target_name "
		"quizzically.", this_object(), this_player(),
		environment(this_object()));
       return 1;
    }
    this_player()->eventPrint("Your " + GetKeyName() + " has " + GetHealthPoints() +
		" of " + GetMaxHealthPoints() + " health points, " +
		GetMagicPoints() + " of " + GetMaxMagicPoints() + " mana points, and "
		+ to_int(GetStaminaPoints()) + " of " + to_int(GetMaxStaminaPoints()) 
		+ " stamina points.");
    return 1;
}