/*    /lib/mayor.c
 *    From the Nightmare V Object Library
 *    Allows players to change their residence on the mud
 *    Created by Descartes of Borg 961019
 *    Version: @(#) mayor.c 1.3@(#)
 *    Last modified: 96/10/20
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_SENTIENT;

static void EvaluateCitizenshipRequest();
static void eventTitle();
void AdvanceSocialRank();
void PurchaseEstate();
void PurchaseKey();

int Tax = 0;
float RealEstate = 1.0;
string LocalCurrency = "gold";
string *TownRanks;

static void create() {
    sentient::create();
    TownRanks = ({
      ({ "Slave", "Slave" }),  /* Placeholder for SocialRank 0 */
      ({ "citizen", "citizen" }),
      ({ "Baron", "Baroness" }),
      ({ "Count", "Countess" }),
      ({ "Marquis", "Marquise" }),
      ({ "Duke", "Duchess" }),
      ({ "Archduke", "Archduchess" }),
      });      
    SetRequestResponses( ([ 
        "citizenship"        : (: EvaluateCitizenshipRequest :),
     ({ "titles", "title" }) : (: eventTitle :),
     ({ "rank", "social rank" }) : (: AdvanceSocialRank :),
     ({ "estate", "estates" }) : (: PurchaseEstate :),
     ({ "key", "keys" })     : (: PurchaseKey : ),
			 "help"                : (: eventForce("speak You can request citizenship, titles, estates or social rank from me.") :),
			 "default"             : (: eventForce("speak You can request citizenship, titles, estates or social rank from me.") :) 
		]));
}

void eventGreet(object who) {
  eventForce("speak You could <ask " + GetKeyName() + " for> citizenship, titles, rank, estate or help.");
}

void heart_beat() {
  ::heart_beat();
  if (!random(20)) eventForce("speak You can request citizenship, titles, estates or social rank from me.");
}

mixed CanRequestCitizenship(object who) {
    if( Tax > 0 ) {
	int cost = (currency_rate(LocalCurrency) * Tax);
	
	if( who->GetCurrency(LocalCurrency) < cost ) {
	    eventForce("speak we have a new citizen tax of " + cost + " " +
		       LocalCurrency + ".");
	    return 0;
	}
    }
    if( who->GetTown() == GetTown() ) {
	return "You are already a citizen of " + GetTown() + ".";
    }
		if (who->GetReputation(GetTown()) < -100) {
    	eventForce("speak Why would I allow citizenship to someone as disliked as you?");
    	return 1;
    }    
    return 1;
}

mixed eventRequestCitizenship(object who) {
    who->SetTown(GetTown());
   foreach(string title in who->GetTitles()) {
     who->RemoveTitle(title);
     }
    who->eventPrint("You are now a citizen of " + GetTown() + ".");
    if( Tax > 0 ) {
	int cost = (currency_rate(LocalCurrency) * Tax);
	
	who->AddCurrency(LocalCurrency, -cost);
	AddCurrency(LocalCurrency, cost);
    }
  CHAT_D->eventSendChannel(who->GetKeyName(), "reports", 
     capitalize(who->GetKeyName()) + " is now a citizen of " +
     GetTown() + ".", 1);
    return 1;
}

static void EvaluateCitizenshipRequest() {
    mixed tmp = CanRequestCitizenship(this_player());

    if( tmp != 1 ) {
	if( !tmp ) {
	    eventForce("speak Your request is denied.");
	}
	else {
	    this_player()->eventPrint(tmp);
	}
	return;
    }
    eventRequestCitizenship(this_player());
}

string GetLocalCurrency() {
    return CURRENCY_D->GetTownCurrency(GetTown());
}

static string SetLocalCurrency(string str) {
    return (LocalCurrency = str);
}

int GetTax() {
    return Tax;
}

static int SetTax(int x) {
    return (Tax = x);
}

string *SetTownRanks(string *m) {
  return TownRanks = m;
}

string *GetTownRanks() { return TownRanks; }

string GetTownRank(string gender, int level) {
  int x = 0;
  if (gender == "female") x = 1;
  return (string)TownRanks[level][x];
}

static void eventTitle() {
   object who = this_player();
   int i;
   if (who->GetTown() != GetTown()) {
      eventForce("speak You don't live here, get away from me!");
      return;
     }
   who->AddTitle("of " + GetTown());
   i = who->GetSocialRank();
   while (i) { who->AddRank(GetTownRank(who->GetGender(), i)); i--; }
   eventForce("speak You are entitled to be called " + who->GetCapName() + " of " + GetTown() );
   return;
}

void AdvanceSocialRank() {
  object who = this_player();
  int cost; float rate = currency_rate(GetLocalCurrency());
  int currentrank = who->GetSocialRank();
  int minrep = 0;
  
  if (who->GetTown() != GetTown()) {
    eventForce("speak You should go to your town and leave me alone.");
    return;
    } 
  if (who->GetReputation(GetTown()) < -100) {
    	eventForce("speak Why would I promote someone as disliked as you?");
    	return;
    }
  if (currentrank == 6) {
    eventForce("speak You can't advance your social rank further.");
    return;
  }
  switch(currentrank) {
    case 0: 
      minrep = 0;
      break;
    case 1:
      minrep = 50;
      break;
    case 2:
      minrep = 100;
      break;
    case 3:
      minrep = 250;
      break;
    case 4:
      minrep = 500;
      break;
    case 5: 
      minrep = 1000;
      break;
    default:
      eventForce("speak Your reputation is confusing me!");
      return;
      break;
    } 
  if (who->GetReputation(GetTown()) < minrep) {
  	eventForce("speak You'll need to raise your reputation with " + GetTown() + " before you can advance further.");
  	who->eventPrint("Raising your social rank requires you to have a reputation of " + minrep + " with " + GetTown() + ".");
  	return;
  }
  switch(currentrank) {
    case 0: 
      cost = 5000;
      break;
    case 1:
      cost = 10000;
      break;
    case 2:
      cost = 25000;
      break;
    case 3:
      cost = 100000;
      break;
    case 4:
      cost = 250000;
      break;
    case 5: 
      cost = 500000;
      break;
    default:
      eventForce("speak I can't figure out how much to charge!");
      return;
      break;
    } 
  cost = cost * currency_rate(GetLocalCurrency());
  if (who->GetCurrency(GetLocalCurrency()) < cost) {
    eventForce("speak In order for you to become " + add_article(GetTownRank(who->GetGender(), currentrank + 1)) + 
               ", you would need to pay the city of " + GetTown() + " " + cost + " " + GetLocalCurrency() + ". " +
               "You don't seem to have that. Come back when you're more valuable to the city.");
    return;
  }
  who->SetSocialRank(currentrank +1);
  who->AddCurrency(GetLocalCurrency(), -cost);
  who->AddRank(GetTownRank(who->GetGender(), who->GetSocialRank()));
  who->SetNoRank(0);
  who->SetShort("");
  CHAT_D->eventSendChannel("Rank", "reports", capitalize(who->GetKeyName()) + " is now a " + GetTownRank(who->GetGender(), who->GetSocialRank()) + " in " +
                           GetTown() + ".");
  eventForce("speak Thank you for supporting " + GetTown() + ", " + who->GetRank() + " " + capitalize(who->GetKeyName()));
  return;
}

float SetRealEstate(float f) { return RealEstate = f; }
float GetRealEstate()        { return RealEstate; }

void PurchaseEstate() {
  object who = this_player();
  int cost; 
  float rate = currency_rate(GetLocalCurrency());
  object box;
  
  if (who->GetTown() != GetTown()) {
    eventForce("speak You should go to your town and leave me alone.");
    return;
    } 
  if (ESTATE_D->GetEstate("/domains/estates/virtual/main_estate/" + GetTown() + "/" + capitalize(who->GetKeyName()))) {
    eventForce("speak You already have an estate in " + GetTown() + "!");
    return;
  }
  cost = 100000 * rate * RealEstate;
  if (who->GetCurrency(GetLocalCurrency()) < cost) {
    eventForce("speak You need " + cost + " " + GetLocalCurrency() + " to purchase an estate here.");
    return;
  }
  box = new("/domains/estates/obj/estatebox");
  if (!box) {
    eventForce("speak I am having trouble with box supply. Come back later.");
    return;
  }
  who->AddCurrency(GetLocalCurrency(), -cost);
  box->eventMove(who);
  send_messages( ({ "hand" }),
    "$agent_name $agent_verb $target_name a small box.",
    this_object(), who, environment() );
  return;
}


void PurchaseKey() {
  object who = this_player();
  int cost; 
  float rate = currency_rate(GetLocalCurrency());
  object box;
  
  if (who->GetTown() != GetTown()) {
    eventForce("speak You should go to your town and leave me alone.");
    return;
    } 
  if (!(ESTATE_D->GetEstate("/domains/estates/virtual/main_estate/" + GetTown() + "/" + capitalize(who->GetKeyName())))) {
    eventForce("speak You don't have an estate in " + GetTown() + "!");
    return;
  }
  cost = 1000 * rate * RealEstate;
  if (who->GetCurrency(GetLocalCurrency()) < cost) {
    eventForce("speak You need " + cost + " " + GetLocalCurrency() + " to purchase a new key for your estate here.");
    return;
  }
  box = new("/domains/estates/virtual/key/" + GetTown() + "/" + capitalize(who->GetKeyName()));
  if (!box) {
    eventForce("speak I am having trouble with key supply. Come back later.");
    return;
  }
  who->AddCurrency(GetLocalCurrency(), -cost);
  box->eventMove(who);
  send_messages( ({ "hand" }),
    "$agent_name $agent_verb $target_name a small key.",
    this_object(), who, environment() );
  return;
}

