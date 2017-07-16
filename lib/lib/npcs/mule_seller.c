#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_NPC;

string Mule;
float CostModifier;
mapping Costs;

int PurchaseMule(object who, string what);

string SetMule(string x) { 
  object mule = new(x);
  if (!mule) {
    error("**Non-loading SetMule!");
    return "";
  }
  AddRequestResponse( mule->GetKeyName() , (: PurchaseMule :) );
  mule->eventDestruct();
  return Mule = x; 
}

string GetMule()         { return Mule;     }

string GetMuleString() {
  object mule = new(GetMule());
    
  if (!mule) {
    error("**Non-loading GetMule()");
    return "";
  }
  return mule->GetKeyName();
}

float SetCostModifier(float f) { return CostModifier = f; }
float GetCostModifier()        { return CostModifier;     }

int GetCost(object who) {
    int cost, mod;
    float comparison;
    // this person has already checked on this object
    if( Costs[who]) {
	    return Costs[who];
      }
    cost = 1000 * CostModifier;
    mod = who->GetSkillLevel("bargaining");
    if (!mod) mod = 1;

    comparison = GetSkillLevel("bargaining") / mod;
    if (who->GetCharisma() > 35) comparison -= 0.05;
    if (who->GetCharisma() > 50) comparison -= 0.05;
    if (who->GetCharisma() > 75) comparison -= 0.05;
    if (who->GetCharisma() > 100) comparison -= 0.05;
    if (who->GetCharisma() > 115) comparison -= 0.05;
    if (comparison < 1.0) comparison = 1.0;
    if (comparison > 3.0) comparison = 3.0;
    if (who->GetTestChar())  debug("Comp: " + comparison);
    cost = to_int(cost * comparison);
    
    
    cost = to_int(cost * currency_rate(CURRENCY_D->GetTownCurrency(GetTown())));
    if (cost < 1) cost = 1;
    Costs[who] = cost;
    return cost;
}

static void create() {
  ::create();
  SetMule(STD_NPC "mule");
  CostModifier = 1.0;
  Costs = ([]);
  SetRequestResponses( ([ "default" : (: PurchaseMule :) ]) );
}

void eventGreet(object who) {
  eventForce("speak You could <ask " + GetKeyName() + " for " + GetMuleString() + "> or <request " + GetMuleString() + " from " + GetKeyName() + ">");
  eventForce("speak I would charge you " + GetCost(who) + " " + CURRENCY_D->GetTownCurrency(GetTown()) + " for " + add_article(GetMuleString()) + ".");
}

int PurchaseMule(object who, string what) {
  string currency = CURRENCY_D->GetTownCurrency(GetTown());
  int cost;
  object mule;
  
  if (what != GetMuleString()) {
   eventForce("speak You could <ask " + GetKeyName() + " for " + GetMuleString() + "> or <request " + GetMuleString() + " from " + GetKeyName() + ">");
   eventForce("speak I would charge you " + GetCost(who) + " " + CURRENCY_D->GetTownCurrency(GetTown()) + " for " + add_article(GetMuleString()) + ".");
   return 1;
  }
  cost = GetCost(who);
  if (who->GetCurrency(currency) < cost) {
    eventForce("speak I'd charge you " + cost + " " + currency + " for a " + GetMuleString() + ".");
    eventForce("speak Which, I might add, you do not have.");
    return 1;
  }
  mule = new(Mule);
  if (!mule) {
    eventForce("speak I seem to be out of " + pluralize(GetMuleString()) + " right now. Come back later.");
    return 1;
  }
  mule->eventMove(environment());
  who->AddCurrency(currency, -cost);
  mule->SetOwner(who->GetKeyName());
  eventForce("speak Here you go " + who->GetCapName() + ", " + add_article(GetMuleString()) + " just for you.");
  mule->eventForce("sign sadly");
  mule->eventForce("follow " + who->GetKeyName());
  who->eventForce("lead " + mule->GetKeyName());
  return 1;
}