#include <lib.h>
#include <std.h>
inherit LIB_NPC;

int ShopFunds = 0;
string ShopOwner;
string LocalCurrency = "imperials";
string ShopID;
string *Beverages = ({ });
string BeverageDir = STD_MEAL "alcohol/";

mapping Prices = ([ ]);

void RestoreShop();
void SaveShop();
void LoadBeverages();

static void create() {
  ::create();
  if (ShopID) RestoreShop();
  LoadBeverages();
}

int AddShopFunds(int x) { ShopFunds += x; SaveShop(); return ShopFunds; }
int GetShopFunds() { return ShopFunds; }
int SetShopFunds(int x) { ShopFunds = x; SaveShop(); return ShopFunds; } // Use ONLY by Duuk!

string SetShopOwner(string x) { ShopOwner = x; SaveShop(); return GetOwner(); }
string GetOwner() { return ShopOwner; }

string SetBeverageDir(string x) { BeverageDir = x; return BeverageDir; }
string GetBeverageDir() { return BeverageDir; }

mapping SetPrice(string drink, int price) {
  Prices[drink] = price;
  SaveShop();
  return Prices;
}

int GetPrice(string drink) {
  if (Prices[drink]) return Prices[drink];
  foreach(string bev in Beverages) {
    if (bev->GetKeyName() == drink) return to_int(bev->GetValue() * currency_rate(LocalCurrency));
  }
  return 0;
}

int GetCost(string drink) {
  foreach(string bev in Beverages) {
    if (bev->GetKeyName() == drink) return to_int(bev->GetValue() * currency_rate(LocalCurrency) * 0.66);
  }
}  

void ResetPrices() { Prices = ([ ]); SaveShop(); } // For use ONLY by Duuk!

void SaveShop() {
  if (!ShopID) return;
  save_object(DIR_SAVE "/shops/" + ShopID + ".o");
}

void RestoreShop() {
  if (!ShopID) return;
  restore_object(DIR_SAVE "/shops/" + ShopID + ".o");
}

void LoadBeverages() {
  string *booze = get_dir(BeverageDir + "*.c");
  Beverages = ({ });
  foreach(string b in booze) {
    if (call_other(BeverageDir + b, "GetValue")) Beverages += ({ BeverageDir + b });
  }
}

string *GetBeverages() { return Beverages; }

string SetLocalCurrency(string x) { return LocalCurrency = x; }
string GetLocalCurrency() { return LocalCurrency; }

string SetShopID(string x) { ShopID = x; RestoreShop(); return ShopID; }
string GetShopID() { return ShopID; }

string GetLong() {
  if (!GetOwner() || GetOwner() == "" ) return ::GetLong();
  return capitalize(GetKeyName()) + " works for " + capitalize(GetOwner()) + ". " + ::GetLong();
}

int eventSell(object who, string what) {
  object booze;
  int price;
  foreach(string bev in Beverages) {
    if (bev->GetKeyName() == what) booze = new(bev);
  }
  if (!booze) {
    eventForce("speak I don't sell anything like that! " + what);
    return 1;
  }
  price = GetPrice(what);
  if (price > who->GetCurrency(LocalCurrency)) {
    eventForce("speak Perhaps you'd like something cheaper? I charge " +
               GetPrice(what) + " " + LocalCurrency + " for " + what);
    return 1;
  }
  if (GetShopFunds() < GetCost(what)) {
    eventForce("speak I'm afraid I'm out of " + what + " right now.");
    eventForce("emote looks sheepish.");
    return 1;
    }
  eventForce("speak Sold!");
  send_messages( ({ "sell" }),
    "$agent_name $agent_verb " + booze->GetShort() + " to $target_name.",
    this_object(), who, environment() );
  booze->eventMove(who);
  who->AddCurrency(LocalCurrency, -GetPrice(what));
  AddShopFunds(GetPrice(what));
  AddShopFunds(-GetCost(what));
  return 1;
}

int eventSet(object who, string what) {
  string to, fr;
  sscanf(what, "%s to %s", what, to);
  sscanf(what, "%s for %s", what, fr);
  if (who->GetKeyName() != GetOwner()) {
    eventForce("speak Sorry, you're not the owner of this establishment.");
    return 1;
    }
  eventForce("speak Setting " + what + " for " + fr + " to " + to);
  if (what == "owner") {
    SetShopOwner(lower_case(to));
    eventForce("speak I now listen only to " + capitalize(to));
    return 1;
  }
  if (what == "price") {
    SetPrice(fr, to_int(to));
    eventForce("speak Set a new price of " + GetPrice(fr) + " for " + fr);
    return 1;
    }
  return 1;
}

void eventReport(object who) {
  string own;
  if (who->GetKeyName() != GetOwner() && !sagep(who)) {
    eventForce("speak I think I'll not be reporting to you.");
    return;
  }
  if (who->GetGender() == "female") own = "Mistress"; else own = "Sir";
  eventForce("speak " + own + ", the tavern funds stand at " + ShopFunds + " " +
             LocalCurrency);
  send_messages( ({ "hand" }),
    "$agent_name $agent_verb over a summary page to $target_name.",
    this_object(), who, environment() );
  who->eventPrint("Shop summary details (in " + LocalCurrency + ") ");
  foreach(string b in Beverages) {
    who->eventPrint("I sell " + b->GetKeyName() + " for " + GetPrice(b->GetKeyName()) +
                    " at a cost to me of " + GetCost(b->GetKeyName()) + 
                    " per serving.");
    }
  who->eventPrint("Owner: " + (GetOwner() ? capitalize(GetOwner()) : "No-one"));
}

int eventDeposit(object who, int amount) {
  if (who->GetKeyName() != GetOwner()) {
    eventForce("speak I'll not be hiding your money for you.");
    return 1;
    }
  if (who->GetCurrency(LocalCurrency) < amount) {
    who->eventPrint("You don't have that much in " + LocalCurrency + ".");
    return 1;
  }
  AddShopFunds(amount);
  who->AddCurrency(LocalCurrency, -amount);
  eventReport(who);
  return ShopFunds;
}

int eventWithdraw(object who, int amount) {
  if (who->GetKeyName() != GetOwner()) {
    eventForce("speak I'll not be giving up my money to you.");
    return 1;
    }
  if (ShopFunds < amount) {
    who->eventPrint("The shop doesn't have that much in " + LocalCurrency + ".");
    return 1;
  }
  AddShopFunds(-amount);
  who->AddCurrency(LocalCurrency, amount);
  eventReport(who);
  return ShopFunds;
}


mixed eventAsk(object who, string args) {
  string action, what;
  string *tmp = ({ });
  sscanf(args, "%s %s", action, what);
  if (!action) action = args;
  if (action == "browse") {
    LoadBeverages();
    tmp = ({ });
    foreach(string bev in Beverages) {
      tmp += ({ bev->GetKeyName() + " for " + GetPrice(bev->GetKeyName()) + " " + LocalCurrency });
      }
    eventForce("speak I sell " + conjunction(tmp, "and"));
    return 1;
  }
  if (action == "sell") return eventSell(who, what);
  
  /* Owner Functions */
  if (action == "set") return eventSet(who, what);
  if (action == "report") return eventReport(who);
  if (action == "deposit") return eventDeposit(who, to_int(what));
  if (action == "withdraw") return eventWithdraw(who, to_int(what));
  eventForce("speak Sorry, you're not speaking intelligently. "
             "You should ask me to browse or ask me to sell something."
             );
  if (GetOwner() == who->GetKeyName()) 
    eventForce("speak You could also ask me to set price for MENUITEM to VALUE, withdraw AMOUNT, "
               "deposit AMOUNT, or report.  You could also ask me to set owner to NAME to sell "
               "the business.");
  return 1;
}
