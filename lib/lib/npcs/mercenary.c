#include <lib.h>
inherit LIB_SENTIENT;

private int HireCost, AttackCost, SaveWanderSpeed;
private string HireCurr, AttackCurr;


void SetHireCost(string curr, int cost);
void SetAttackCost(string curr, int cost);

int cmd_hire();
int cmd_follow();
int cmd_attack(object who, string attack_verb, string arg);
int cmd_leave(object who, string leave_verb, string arg);
int cmd_help();

object Master;

static void create()
{
  ::create();
  SetTalkResponses( ([
    ({"mercenary","merc"}) : "Yes, I am a mercenary.",
    ({"hire","job"})       : "I can be hired for " + HireCost + " "
                             + HireCurr +".  Just ask me to work for you.",
  ]) );
  SetCommandResponses( ([ "work" : (: cmd_hire :) ]) );
  SaveWanderSpeed = 0;
}

void eventGreet(object who) {
  eventForce("speak You could <ask " + GetKeyName() + " to work> to hire me.");
}

string array GetId() {
  string array id;

  id = ::GetId();
  return ({ id..., "mercenary", "merc" });
}

void SetHireCost(string curr, int cost)
{
   HireCost = cost;
   HireCurr = curr;
   return;
}

void SetAttackCost(string curr, int cost)
{
  AttackCost = cost;
  AttackCurr = curr;
  return;
}

int cmd_hire()
{
  if( Master == this_player() )
    return eventForce("say I already work for you!");

  if( this_player()->GetCurrency(HireCurr) < HireCost )
    return eventForce("say You do not have the necessary fee!");

  if( Master )
  {
    eventForce("say ATTENTION!  It appears that I have been bought out.");
    RemoveFriend(Master->GetKeyName());
  }

  this_player()->AddCurrency(HireCurr,-HireCost);
  eventForce("say I am glad to be of service to you.  A few rules:\n"
             "[1] I will do my best to follow you, but occasionally duty "
             "calls and I might slip away to tend my own business.  Just "
             "return to where I left you and ask me to follow you again.\n"
             "[2] If you are attacked by anyone, I will fight be your side.\n"
             "[3] If you order me to, and you have the required cash ("+AttackCost+
             " "+AttackCurr+"), I will attack anyone you ask me to attack.\n"
             "[4] I will repeat these rules if you ask me to help.\n"
             "[5] If you no longer need my services, just ask me to leave.");
  AddCommandResponse("follow", (: cmd_follow :));
  AddCommandResponse("attack", (: cmd_attack :));
  AddCommandResponse("leave", (: cmd_leave :));
  AddCommandResponse("help", (: cmd_help :));

  SaveWanderSpeed = GetWanderSpeed();
  SetWanderSpeed(0);
  Master = this_player();

  eventForce("follow " + lower_case(Master->GetName()));
  Master->eventForce("lead mercenary");
  AddFriend(Master->GetKeyName());
}


int cmd_follow()
{
  if( this_player()->GetName() != Master->GetName() )
    return eventForce("say Do you this I do this for free?  I owe my loyalty "
                      "to my employer, " + Master->GetName() + ".");

  eventForce("I am now following you.");
  eventForce("follow " + lower_case(Master->GetName()));
  Master->eventForce("lead mercenary");
}


int cmd_attack(object who, string attack_verb, string arg)
{
  object target;

  if( this_player()->GetName() != Master->GetName() )
    return eventForce("say Do you think this I do this for free?  I owe my "
                      "loyalty to my employer, " + Master->GetName() + ".");

  if( Master->GetCurrency(AttackCurr) < AttackCost )
    return eventForce("say I'm sorry, but you don't have the cash.");

  if( !target = present(arg) )
    return eventForce("say I don't see the person you wish me to attack.");

  eventForce("follow mercenary");
  eventForce("say Yes sir!");
  eventForce("attack " + lower_case(target->GetName()));
  Master->AddCurrency(AttackCurr,-AttackCost);
}


int cmd_help()
{

  if( this_player()->GetName() != Master->GetName() )
    return eventForce("say Do you think this I do this for free?  I owe my "
                      "loyalty to my employer, " + Master->GetName() + ".");

  eventForce("say I am glad to be of service to you.  A few rules:\n"
             "[1] I will do my best to follow you, but occasionally duty "
             "calls and I might slip away to tend my own business.  Just "
             "return to where I left you and ask me to follow you again.\n"
             "[2] If you are attacked by anyone, I will fight be your side.\n"
             "[3] If you order me to, and you have the required cash ("+AttackCost+
             " "+AttackCurr+"), I will attack anyone you ask me to attack.\n"
             "[4] I will repeat these rules if you ask me to help.\n"
             "[5] If you no longer need my services, just ask me to leave.");
}


int cmd_leave(object who, string leave_verb, string arg)
{

  if( this_player()->GetName() != Master->GetName() )
    return eventForce("say Do you think this I do this for free?  I owe my "
                      "loyalty to my employer, " + Master->GetName() + ".");

  eventForce("say If you ever need my services again, just call.");
  eventForce("follow mercenary");
  SetWanderSpeed(SaveWanderSpeed);
  Master = 0;
  RemoveCommandResponse("follow");
  RemoveCommandResponse("attack");
  RemoveCommandResponse("leave");
}
