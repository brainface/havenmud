//
// /lib/player_shop.c
// The Player Shop Inheritable
// Version 0.5 Created by Duuktsaryth@Haven
// Heavily Modified by Zaxan@Haven
// Version: 3.0
//
// Modified by Gaby to allow inns not 
// associated to towns to be bought
// Gabriel@Haven 10/16/99


#include <lib.h>
#include <save.h>
#include <daemons.h>

inherit LIB_ROOM;

#include "include/player_shop.h"

mapping Meat = ([
  "Weak" : 0,
  "Medium" : 0,
  "Strong" : 0,
]);

mapping MeatCost = ([
   "Weak" : 0,
   "Medium" : 0,
   "Strong" : 0,
]);

mapping SaleCost = ([ ]);

mapping ShopInfo = ([ 
  "Name" : "an unowned inn",
  "Owner" : "none",
  "CurrentBidder" : "none",
  "CurrentBid" : 0,
  "Funds" : 0,
  "ShopId" : "unregistered",
  "ShopLong" : "This is a large, empty room that will someday "
               "make a fine shop of some kind. For now, it is undecorated.",
]);
/* ShopInfo has the following arguments:
 *  Name (string what)
 *  Owner (string who)
 *  CurrentBidder (string who)
 *  CurrentBid (int amount)
 *  Funds (int amount)
 *  ShopId (string what)
 *  ShopLong (string desc)
 */

mapping PayOut = ([ ]);
/*  Shows how much the inn is paying for corpses.
 *  In race : amount
 */

private mapping Inv = ([ ]);
/* Controls Inventory */

private mapping SaleInv = ([ ]);
/* Holds the items for sale */

private string Curr = "imperials";
private int Points = 0;
private int Mad = 0;
private int innkeep = 0;
/* Miscellaneous Global Variables */

/****************************** The Beef *******************************/
static void create() {
   room::create();
   SetProperty("no bump",1);
   SetClimate("indoors");
   SetAmbientLight(40);
   SetExits( ([
      "out" : "/domains/haven/room/ir2",
   ]) );
}

void init() {
   object inn;
   room::init();
   restore_object(SAVE_PSHOPS + GetShopId() );
   LoadInventory();
   if( (GetInnkeep()) &&
     (!present("innkeeper", this_object())) ) {
      inn = new(LIB_PSHOP_INN);
      inn->SetLocalCurrency(GetLocalCurrency());
      inn->SetRace(Towns[GetTown()]);
      inn->eventMove(this_object());
      inn->RemoveLanguage(inn->GetNativeLanguage());
      inn->SetLanguage(Languages[GetTown()], 100, 1);
   }
   if (GetOwner() == "none") {
      add_action("bid", "bid");
   }
   if ( GetOwner() == this_player()->GetKeyName()) {
      add_action("setup", "setup");
      add_action("inv", "inv");
      add_action("report", "report");
      add_action("set", "set");
      add_action("make", "make");
      add_action("funds", "funds");
      add_action("remove", "remove");
      add_action("price", "price");
      add_action("command_list", "command");
      add_action("command_list", "commands");
   }
}

/**************************  Data Functions ****************************/

int reset(int count) {
   object inn;

   room::reset(count);
   if( (GetInnkeep()) &&
       (!present("innkeeper", this_object())) ) {
      inn = new(LIB_PSHOP_INN);
      inn->SetLocalCurrency(GetLocalCurrency());
      inn->SetRace(Towns[GetTown()]);
      inn->eventMove(this_object());
      inn->RemoveLanguage(inn->GetNativeLanguage());
      inn->SetLanguage(Languages[GetTown()], 100, 1);
   }
}



int SetInnkeep(int x) {
   innkeep = x;
   save_object(SAVE_PSHOPS + GetShopId());
   return innkeep;
}

int GetInnkeep() {
   return innkeep;
}

int SetMeatCost(string type, int cost) {
   type = capitalize(type);
   if( (type != "Weak") && (type != "Medium") && (type != "Strong") ) {
      return 0;
   }
   MeatCost[type] = cost;
   save_object(SAVE_PSHOPS + GetShopId());
   return MeatCost[type];
}

int GetMeatCost(string type) {
   type = capitalize(type);
   return MeatCost[type]; 
}

int SetSaleCost(string item, int cost) {
   if(!SaleInv[item]) { return 0; }
   SaleCost[item] = cost;
   save_object(SAVE_PSHOPS + GetShopId());
   return SaleCost[item];
}

int AddSaleCost(string item, int cost) {
   if(!SaleCost[item]) { return 0; }
   SaleCost[item] += cost;
   save_object(SAVE_PSHOPS + GetShopId());
   return SaleCost[item];
}

int GetSaleCost(string item) { return SaleCost[item]; }

mapping SetInventory(mapping mp) { 
   foreach(string key, mixed val in mp) {
      if( key[<2..] == ".c" ) key = key[0..<3];
      if( key[0] != '/' ) key = "/" + key;
      Inv[key] = val;
   }
   save_object(SAVE_PSHOPS + GetShopId());
   LoadInventory();
   return Inv;
}

mapping GetInventory() { return Inv; }

mapping AddInventory(string key, mixed val) {
   Inv[key] = val;
   save_object(SAVE_PSHOPS + GetShopId());
   LoadInventory();
   return Inv;
}

mapping RemoveInventory(string key) {
   map_delete(Inv, key);
   save_object(SAVE_PSHOPS + GetShopId());
   LoadInventory();
   return Inv;
}

mapping SetSaleInventory(mapping mp) {
   foreach(string key, mapping stuff in mp) {
      foreach(int val, string file in stuff) {
         SaleInv[key] = ([ "number" : val, "filename" : file ]);
      }
   }
   save_object(SAVE_PSHOPS + GetShopId());
   return SaleInv;
}

mapping GetSaleInventory() { return SaleInv; }

varargs mapping AddSaleInventory(string key, int val, string file) {
   if(!SaleInv[key]) {
      SaleInv[key] = ([ "number" : val, "filename" : file ]);
   } else SaleInv[key]["number"] += val;
   if(file) {
      SaleInv[key]["filename"] = file;
   }
   save_object(SAVE_PSHOPS + GetShopId());
   return SaleInv;
}

mapping RemoveSaleInventory(string key) {
   map_delete(SaleInv, key);
   save_object(SAVE_PSHOPS + GetShopId());
   return SaleInv;
}

static void LoadInventory() {
   string array file_names;
    
   file_names = map(all_inventory(this_object()), (: base_name :));
   foreach(string item, int count in Inv) {
      if( count < 0 ) { // Unique object
         object ob;

         ob = unique(item, -count); // -count is # of days between clones
         if( ob ) ob->eventMove(this_object());
      } else {
         count -= sizeof(filter(file_names, (: $1 == $(item) :)));
         if (count > 0)
            while( count-- ) {
            object ob = new(item);
            ob->eventMove(this_object());
         }
      }
   }
}

int SetMad(int x) {
   Mad = x;
   save_object(SAVE_PSHOPS + GetShopId());
   return Mad;
}

int AddMad(int x) {
   Mad += x;
   save_object(SAVE_PSHOPS + GetShopId());
   return Mad;
}

int GetMad() {
   return Mad;
}

int SetMeat(string type, int amount) {
   type = capitalize(type);
   if( (type != "Weak") && (type != "Medium") && (type != "Strong") ) {
      return 0;
   }
   Meat[type] = amount;
   save_object(SAVE_PSHOPS + GetShopId());
   return Meat[type];
}

int AddMeat(string type, int x) {
   type = capitalize(type);
   if( (type != "Weak") && (type != "Medium") && (type != "Strong") ) {
      return 0;
   }
   Meat[type] += x;
   save_object(SAVE_PSHOPS + GetShopId());
   return Meat[type];
}

int GetMeat(string type) {
   type = capitalize(type);
   return Meat[type];
}

int SetMeatPoints(int x) {
   Points = x;
   save_object(SAVE_PSHOPS + GetShopId());
   return Points;
}

int GetMeatPoints() {
   return Points;
}

int AddMeatPoints(int x) {
   Points += x;
   save_object(SAVE_PSHOPS + GetShopId());
   return Points;
}

string GetShopId() {
   return ShopInfo["ShopId"];
}

string SetOwner(string who) {
   ShopInfo["Owner"] = who;
   save_object(SAVE_PSHOPS + GetShopId());
   return who;
}

string GetOwner() {
   return (ShopInfo["Owner"]);
}

string SetShopId(string what) {
   ShopInfo["ShopId"] = what;
   restore_object(SAVE_PSHOPS + GetShopId());
   save_object(SAVE_PSHOPS + GetShopId());
   return what;
}

string SetLocalCurrency(string curr) {
   if(member_array(curr, ECONOMY_D->__QueryCurrencies()) == -1) {
      return Curr;
   } else {
      Curr = curr;
      save_object(SAVE_PSHOPS + GetShopId());
      return Curr;
   }
}

string GetLocalCurrency() {
   return Curr;
}

string GetShort() {
   return (ShopInfo["Name"]);
}

string GetLong() {
   return (ShopInfo["ShopLong"]);
}

string SetShopName(string args) {
   ShopInfo["Name"] = args;
   save_object(SAVE_PSHOPS + GetShopId());
   return args;
}

string GetShopName() {
   return (ShopInfo["Name"]);
}

string SetCurrentBidder(string who) {
   ShopInfo["CurrentBidder"] = who;
   save_object(SAVE_PSHOPS + GetShopId());
   return (who);
}

string GetCurrentBidder() {
   return (ShopInfo["CurrentBidder"]);
}

int SetCurrentBid(int amount) {
   ShopInfo["CurrentBid"] = amount;
   save_object(SAVE_PSHOPS + GetShopId());
   return amount;
}

int GetCurrentBid() {
   return (ShopInfo["CurrentBid"]);
}

int AddStoreFunds(int amount) {
   ShopInfo["Funds"] = ShopInfo["Funds"] + amount;
   save_object(SAVE_PSHOPS + GetShopId());
   return (ShopInfo["Funds"]);
}

int GetStoreFunds() {
   return ShopInfo["Funds"];
}

string SetShopDesc(string long) {
   ShopInfo["ShopLong"] = long;
   save_object(SAVE_PSHOPS + GetShopId());
   return (long);
}

string GetShopDesc() {
   return (ShopInfo["ShopLong"]);
}

int SetPayOut(string race, int amount) {
   PayOut[race] = amount;
   save_object(SAVE_PSHOPS + GetShopId());
   return PayOut[race];
}

mapping RemovePayOut(string race) {
   map_delete(PayOut, race);
   save_object(SAVE_PSHOPS + GetShopId());
   return PayOut;
}

int GetPayOut(string race) {
   return (PayOut[race]);
}

mapping GetPayOuts() {
   return (PayOut);
}

mapping GetShopInfo() {
   return (ShopInfo);
}

/**************************  Action Functions ***************************/

/* Bid Controller */

int bid(string amt) {
   string currency = GetLocalCurrency();
   int amount = to_int(amt);

   if (GetOwner() != "none") {
      message("system", "You are unable to bid on the shop right now.",
              this_player() );
      return 1;
   }
  if ((this_player()->GetTown() != GetTown()) && (GetTown() != "Wilderness"))
  {
    message("system", "You are not a citizen of this town!", this_player() );
    return 1;
  }   if(!amount) {
      message("system", "That is less than the current bid of "+
             GetCurrentBid()+" "+currency+" by " +
             capitalize(GetCurrentBidder())+". Please bid higher.",
             this_player());
      return 1;
   }
   if (this_player()->GetNetWorth() < 
       currency_value(amount, GetLocalCurrency()) ) {
      message("system","You don't have that much money!",this_player());
   return 1;
   }
   if (amount < (GetCurrentBid() * 1.04)) { 
      message("system", "The current bid is " + 
              int_to_a(GetCurrentBid()) +" "+currency+". You must at least "
              "bid 105% of that.\nThe minimum bid is " + 
              to_int(GetCurrentBid() * 1.04) + "." +"\nThe current bidder is "
              +capitalize(GetCurrentBidder()) +".",this_player() );
      return 1;
   }
   if (this_player()->GetKeyName() == GetCurrentBidder()) {
      message("system","You don't want to bid against yourself!",
              this_player() );
   return 1;
   }
   SetCurrentBidder(this_player()->GetKeyName());
   SetCurrentBid(amount);
   message("system", "You bid "+amount+" "+currency+" on the "
           "shop.", this_player() );
   save_object(SAVE_PSHOPS + GetShopId());
   return 1;
}

/* Sets prices of meat */

int price(string blah) {
   object who = this_player();
   int i, maxi;

   maxi = sizeof(GetSaleInventory());
   who->eventPrint("------------------------------------------------------\n"
                   "%^CYAN%^BOLD%^"+capitalize(GetShopName())+" price "
                   "configuration.%^RESET%^\n"
                   "------------------------------------------------------\n"
                   "%^GREEN%^BOLD%^1%^RESET%^) Weak meat (Current price = "+
                   GetMeatCost("weak")+")\n"
                   "%^GREEN%^BOLD%^2%^RESET%^) Medium meat (Current price = "+
                   GetMeatCost("medium")+")\n"
                   "%^GREEN%^BOLD%^3%^RESET%^) Strong meat (Current price = "+
                   GetMeatCost("strong")+")");
   for(i=0;i<maxi;i++) {
      who->eventPrint("%^GREEN%^BOLD%^"+(i+4)+"%^RESET%^) "+ 
                      capitalize(keys(GetSaleInventory())[i])+
                      " (Current price = "+
                      GetSaleCost(keys(GetSaleInventory())[i])+")");
   }
   who->eventPrint("%^GREEN%^BOLD%^"+(maxi+4)+"%^RESET%^) Quit\n"
                   "------------------------------------------------------");
   message("prompt", "\nEnter your choice: ", who);
   input_to((: ChoosePriceOption :));
   return 1;
}

void ChoosePriceOption(string args) {
   object who = this_player();
   int option = to_int(args);
   int i, maxi;

   maxi = sizeof(GetSaleInventory());
   if(option == 1) {
      message("prompt", "Enter a valid price for weak "
              "meat <'0' cancels>: ",who);
      input_to((: DoPrice :), "weak");
      return;
   } else if(option == 2) {
      message("prompt", "Enter a valid price for medium "
              "meat <'0' cancels>: ",who);
      input_to((: DoPrice :), "medium");
      return;
   } else if(option == 3) {
      message("prompt", "Enter a valid price for strong "
              "meat <'0' cancels>: ",who);
      input_to((: DoPrice :), "strong");
      return;
   } else if( (option > 3) &&
              (option < (maxi+4)) ) {
      message("prompt","Enter a valid price for "+
              keys(GetSaleInventory())[option-4]+" <'0' cancels>: ",who);
      input_to((: DoSalePrice :), keys(GetSaleInventory())[option-4]);
   } else if(option == (maxi+4)) {
      message("system", "%^RED%^BOLD%^Exited Price "
              "Configuration.%^RESET%^", who);
      return;
   } else {
      message("system", "%^RED%^BOLD%^Invalid Choice!"
              "%^RESET%^\n",this_player());
      this_player()->eventPrint("%^GREEN%^BOLD%^1%^RESET%^) "
                                "Weak meat\n"
                                "%^GREEN%^BOLD%^2%^RESET%^) "
                                "Medium meat\n"
                                "%^GREEN%^BOLD%^3%^RESET%^) "
                                "Strong meat");
      for(i=0;i<maxi;i++) {
         who->eventPrint("%^GREEN%^BOLD%^"+(i+4)+"%^RESET%^) "+ 
                         capitalize(keys(GetSaleInventory())[i]));
      }
      this_player()->eventPrint("%^GREEN%^BOLD%^"+(maxi+4)+"%^RESET%^) "
                                "Quit");
      message("prompt", "\nEnter your choice: ", who);
      input_to((: ChoosePriceOption :));
      return;
   }
}

void DoPrice(string blah, string type) {
   int price = to_int(blah);

   if(price == 0) {
      message("system","%^RED%^BOLD%^Canceled!%^RESET%^",this_player());
      return;
   } else if((!price) || (price < 0)) {
      message("system", "%^RED%^BOLD%^Not a valid "
              "price!\n%^RESET%^",this_player());
      message("prompt", "Enter a price for "+type+" meat "
              "<'0' cancels>: ", this_player());
      input_to((: DoPrice :), type);
      return;
   }
   SetMeatCost(type, price);
   message("system", "%^YELLOW%^BOLD%^"+capitalize(type)+" meat is now "
           "priced at "+price+"%^RESET%^",this_player());
   return;
}

void DoSalePrice(string blah, string item) {
   int price = to_int(blah);

   if(price == 0) {
      message("system", "%^RED%^BOLD%^Canceled!%^RESET%^",this_player());
      return;
   } else if((!price) || (price <0)) {
      message("system", "%^RED%^BOLD%^Not a valid "
              "price!\n%^RESET%^",this_player());
      message("prompt", "Enter a price for "+item+" "
              "<'0' cancels>: ", this_player());
      input_to((: DoSalePrice :), item);
      return;
   }
   SetSaleCost(item, price);
   message("system", "%^YELLOW%^BOLD%^"+capitalize(item)+" is now priced at "
           +price+"%^RESET%^",this_player());
   return;
}

/* The Store Inventory Controller */

int inv(string args) {
   object who = this_player();

   who->eventPrint("---------------------------------------------------\n"
                   "%^CYAN%^BOLD%^Store Inventory Control.%^RESET%^\n"
                   "---------------------------------------------------\n"
                   "%^GREEN%^BOLD%^1%^RESET%^) Add item for sale\n"
                   "%^GREEN%^BOLD%^2%^RESET%^) Remove item for sale\n"
                   "%^GREEN%^BOLD%^3%^RESET%^) Quit\n"
                   "---------------------------------------------------");
   message("prompt", "\nEnter your choice: ", who);
   input_to((: ChooseInvOption :));
   return 1;
}

void ChooseInvOption(string args) {
   object who = this_player();
   int option = to_int(args);

   if(option == 1) {
      message("prompt", "Enter an item to add: ",who);
      input_to((: AddInvItem :));
      return;
   } else if(option == 2) {
      message("prompt", "Enter an item to remove: ",who);
      input_to((: RemoveInvItem :));
      return;
   } else if(option == 3) {
      message("system", "%^RED%^BOLD%^Exited Inventory Control %^RESET%^",
              who);
      return;
   } else {
      message("system", "%^RED%^BOLD%^Invalid Choice!%^RESET%^\n",who);
      who->eventPrint("%^GREEN%^BOLD%^1%^RESET%^) "
                      "Add item for sale\n"
                      "%^GREEN%^BOLD%^2%^RESET%^) "
                      "Remove item for sale\n"
                      "%^GREEN%^BOLD%^3%^RESET%^) "
                      "Quit");
      message("prompt", "\nEnter your choice: ", who);
      input_to((: ChooseInvOption :));
      return;
   }
}

void AddInvItem(string item) {
   string name;
   object who = this_player();
   object thing;

   if(!present(item, who)) {
      message("system", "%^RED%^BOLD%^You don't have that!%^RESET%^",who);
      return;
   } else {
        thing = present(item, who);
     if(thing->GetWorn()) {     /* added 20111104 - Melchezidek */
         message("system", "%^RED%^%^BOLD%^You are using that!%^RESET%^", who);
       } else {
         name = base_name(thing);

      AddSaleInventory(thing->GetShort(), 1, name);
      message("system", "%^YELLOW%^BOLD%^"+capitalize(thing->GetShort())+
              " has been added to the store inventory.",who);
      thing->eventDestruct();
	}
      return;
   }
}

void RemoveInvItem(string item) {
   object who = this_player();

   if(!GetSaleInventory()[item]) {
      message("system", "%^RED%^BOLD%^That item is not in the "
              "shop's inventory!%^RESET%^",who);
   } else {
      object thing = new(GetSaleInventory()[item]["filename"]);
      if(GetSaleInventory()[item]["number"] > 1) {
         AddSaleInventory(item, -1);
      } else RemoveSaleInventory(item);
      thing->eventMove(who);
      message("system", "%^YELLOW%^BOLD%^"+capitalize(thing->GetShort())+
              " has been removed from the store inventory.",who);
      return;
   }
}

/* The Innkeeper/Food Maker */

int make(string args) {
   object who = this_player();

   who->eventPrint("-----------------------------------------\n"
                   "%^CYAN%^BOLD%^Innkeeper/Food Maker.%^RESET%^\n"
                   "-----------------------------------------\n"
                   "%^GREEN%^BOLD%^1%^RESET%^) Make innkeeper\n"
                   "%^GREEN%^BOLD%^2%^RESET%^) Make weak meat\n"
                   "%^GREEN%^BOLD%^3%^RESET%^) Make medium meat\n"
                   "%^GREEN%^BOLD%^4%^RESET%^) Make strong meat\n"
                   "%^GREEN%^BOLD%^5%^RESET%^) Quit\n"
                   "-----------------------------------------");
   message("prompt", "\nEnter your choice: ", who);
   input_to((: ChooseMakeOption :));
   return 1;
}

void ChooseMakeOption(string args) {
   object who = this_player();
   int option = to_int(args);

   if(option == 1) {
      MakeInnkeeper();
      return;
   } else if(option == 2) {
      MakeFood("weak");
      return;
   } else if(option == 3) {
      MakeFood("medium");
      return;
   } else if(option == 4) {
      MakeFood("strong");
      return;
   } else if(option == 5) {
      message("system", "%^RED%^BOLD%^Exited Innkeeper/Food "
              "Maker.%^RESET%^",who);
      return;
   } else {
      message("system", "%^RED%^BOLD%^Invalid Choice!%^RESET%^\n",who);
      who->eventPrint("%^GREEN%^BOLD%^1%^RESET%^) "
                      "Make innkeeper\n"
                      "%^GREEN%^BOLD%^2%^RESET%^) "
                      "Make weak meat\n"
                      "%^GREEN%^BOLD%^3%^RESET%^) "
                      "Make medium meat\n"
                      "%^GREEN%^BOLD%^4%^RESET%^) "
                      "Make strong meat\n"
                      "%^GREEN%^BOLD%^5%^RESET%^) "
                      "Quit");
      message("prompt", "\nEnter your choice: ", who);
      input_to((: ChooseMakeOption :));
      return;
   }
}

void MakeInnkeeper() {
   int count;
   int amount = currency_rate(GetLocalCurrency()) * 1000;

   if(GetInnkeep()) {
      message("system", "%^RED%^BOLD%^You already have an "
              "innkeeper!%^RESET%^",this_player());
      return;
   }
   if(amount > GetStoreFunds()) {
      message("system", "%^RED%^BOLD%^Your shop does not "
              "have enough money to buy a innkeeper. It "
              "costs "+amount+" "+GetLocalCurrency()+".%^RESET%^",
              this_player());
      return;
   }
   SetInnkeep(1);
   reset(count);
   AddStoreFunds(-amount);
   message("system", "%^YELLOW%^BOLD%^Innkeeper added!"
           "%^RESET%^",this_player());
   return;
}

void MakeFood(string type) {
   message("prompt","Enter an amount of "+type+" meat to create: ",
           this_player());
   input_to((: ChooseAmount :), type);
   return;
}

void ChooseAmount(string args, string type) {
   int amount = to_int(args);
   int required;

   if((!amount) || (amount < 0)) {
      message("system", "%^RED%^BOLD%^That is not a valid amount!",
              this_player());
      return;
   }
   if(type == "weak") { required = 5*amount; }
   if(type == "medium") { required = 10*amount; }
   if(type == "strong") { required = 15*amount; }
   if(GetMeatPoints() < required) {
      message("system", "%^RED%^BOLD%^You do not have enough "
              "meat points! It costs "+(string)required+
              " points.%^RESET%^",this_player());
      return;
   }
   AddMeatPoints(-required);
   AddMeat(type, amount);
   message("system","%^YELLOW%^BOLD%^"+capitalize(type)+" meat added. "
           "You now have "+GetMeat(type)+" in your store inventory.%^RESET%^",
           this_player());
   return;
}

/* The Funds Controller */

int funds(string useless) {
   object who = this_player();

   who->eventPrint("-----------------------------------------\n"
                   "%^CYAN%^BOLD%^"+capitalize(GetShopName())+" fund "
                   "configuration.%^RESET%^\n"
                   "-----------------------------------------\n"
                   "%^GREEN%^BOLD%^1%^RESET%^) Deposit money\n"
                   "%^GREEN%^BOLD%^2%^RESET%^) Withdraw money\n"
                   "%^GREEN%^BOLD%^3%^RESET%^) Quit\n"
                   "-----------------------------------------");
   message("prompt", "\nEnter your choice: ", who);
   input_to((: ChooseFundsOption :));
   return 1;
}

void ChooseFundsOption(string args) {
   object who = this_player();
   int option = to_int(args);

   if(option == 1) {
      message("prompt", "Enter an amount to deposit "
              "<'0' cancels>: ",who);
      input_to((: DepositFunds :));
      return;
   } else if(option == 2) {
      message("prompt", "Enter an amount to withdraw "
              "<'0' cancels>: ", who);
      input_to((: WithdrawFunds :));
      return;
   } else if(option == 3) {
      message("system", "%^RED%^BOLD%^Exited Funds "
              "Configuration.%^RESET%^",who);
      return;
   } else {
      message("system", "%^RED%^BOLD%^Invalid Choice!"
              "%^RESET%^\n",this_player());
      who->eventPrint("%^GREEN%^BOLD%^1%^RESET%^) "
                      "Deposit money\n"
                      "%^GREEN%^BOLD%^2%^RESET%^) "
                      "Withdraw money\n"
                      "%^GREEN%^BOLD%^3%^RESET%^) "
                      "Quit");
      message("prompt", "\nEnter your choice: ", who);
      input_to((: ChooseFundsOption :));
      return;
   }
}

void DepositFunds(string blah) {
   int amount = to_int(blah);

   if(amount == 0) {
      message("system", "%^RED%^BOLD%^Canceled!%^RESET%^",
              this_player());
      return;
   } else if((!amount) || (amount < 0)) {
      message("system", "%^RED%^BOLD%^Not a valid "
              "amount!\n%^RESET%^",this_player());
      message("prompt", "Enter an amount to deposit "
              "<'0' cancels>: ", this_player());
      input_to((: DepositFunds :));
      return;
   } else if(amount > this_player()->GetCurrency(GetLocalCurrency())) {
      message("system", "%^RED%^BOLD%^You don't have that "
              "many "+GetLocalCurrency()+"!\n",this_player());
      message("prompt", "Enter an amount to deposit "
              "<'0' cancels>: ", this_player());
      input_to((: DepositFunds :));
      return;
   }
   this_player()->AddCurrency(GetLocalCurrency(),-amount);
   AddStoreFunds(amount);
   message("system", "%^YELLOW%^BOLD%^"+ amount +" "+
           GetLocalCurrency()+" deposited.%^RESET%^",this_player());
   return;
}

void WithdrawFunds(string blah) {
   int amount = to_int(blah);

   if(amount == 0) {
      message("system", "%^RED%^BOLD%^Canceled!%^RESET%^",
              this_player());
      return;
   } else if(!amount || amount < 0) {
      message("system", "%^RED%^BOLD%^Not a valid "
              "amount!\n%^RESET%^",this_player());
      message("prompt", "Enter an amount to withdraw "
              "<'0' cancels>: ", this_player());
      input_to((: WithdrawFunds :));
      return;
   } else if(amount > GetStoreFunds()) {
      message("system", "%^RED%^BOLD%^The shop doesn't have that "
              "many "+GetLocalCurrency()+"!\n",this_player());
      message("prompt", "Enter an amount to withdraw "
              "<'0' cancels>: ", this_player());
      input_to((: WithdrawFunds :));
      return;
   }
   this_player()->AddCurrency(GetLocalCurrency(),amount);
   AddStoreFunds(-amount);
   message("system", "%^YELLOW%^BOLD%^"+ amount +" "+
           GetLocalCurrency()+" withdrawn.%^RESET%^",this_player());
   return;
}

/* Removes a race from payouts */

int remove(string args) {
   if(!args || (args == "")) {
      message("system", "Syntax: remove RACE",this_player());
      return 1;
   } else {
      RemovePayOut(args);
      message("system", capitalize(args)+" removed from "
              "payouts.", this_player());
      return 1;
   }
}

/* Sets a race payout to an amount */

int set(string args) {
   string race, amount;
   int amt;

   if( (!args) || (args == "") ||
       (sscanf(args, "payout for %s to %s", race, amount) != 2)) {
      message("system", "Syntax: set payout for RACE to AMOUNT.",
              this_player() );
      return 1;
   }
   if(to_int(amount) < 0) {
      message("system", "That is not a valid amount!",this_player());
      return 1;
   }
   if( (race != "unique") &&
       (member_array(race, (RACES_D->GetRaces())) == -1) ) {
      message("system",capitalize(race) + " is not a valid race!",
              this_player());
      return 1;
   } else {
      SetPayOut(race, to_int(amount));
      message("system","Payout for " + race + " corpses set "
              "to " + amount + " "+GetLocalCurrency()+".",
              this_player() );
      save_object(SAVE_PSHOPS + GetShopId() );
      return 1;
   }
}

/*  The report Generator */

int report(string useless) {
   object who = this_player();
   int maxi = sizeof(GetPayOuts());
   int x = GetMad();
   string *RaceArray = keys(GetPayOuts());
   string *PriceArray = values(GetPayOuts());
   string *MadArray = ({ "just fine.", "a little angry.",
			"%^RED%^BOLD%^really%^RESET%^ angry!",
			"non-decided." });
  
   who->eventPrint("--------------------------------------------------");
   who->eventPrint("%^CYAN%^BOLD%^Store Report for " 
                   + capitalize(GetShopName()) + ".%^RESET%^");
   who->eventPrint("--------------------------------------------------");
   who->eventPrint("%^GREEN%^BOLD%^Current Funds:%^RESET%^ " 
                   + GetStoreFunds() +" "+GetLocalCurrency()+".");
   who->eventPrint("%^GREEN%^BOLD%^Meat Points:%^RESET%^ " 
                   +GetMeatPoints()+".");
   who->eventPrint("%^GREEN%^BOLD%^Inventory:%^RESET%^ "+GetMeat("weak")+" "
                   "weak meat.\n"
                   "           "+GetMeat("medium")+" medium meat.\n"
                   "           "+GetMeat("strong")+" strong meat.");
   if(!GetInnkeep()) {
      who->eventPrint("%^GREEN%^BOLD%^Innkeeper Status:%^RESET%^ "
                      "No Innkeeper.");
   } else {
      who->eventPrint("%^GREEN%^BOLD%^Innkeeper Status:%^RESET%^ "+
                      capitalize(MadArray[x]));
   }
   who->eventPrint("%^GREEN%^BOLD%^Current Meat Prices:%^RESET%^ "
		   + GetMeatCost("weak") + " for weak meat.");
   who->eventPrint("                     "+ GetMeatCost("medium") + " for "
                   "medium meat.");
   who->eventPrint("                     "+ GetMeatCost("strong") + " for "
                   "strong meat.");
   if(!maxi) {
      who->eventPrint("%^GREEN%^BOLD%^Corpse Payouts:%^RESET%^ None.");
      who->eventPrint("--------------------------------------------------");
      return 1;
   } else {
      RaceArray[0] = "%^GREEN%^BOLD%^Corpse Payouts:%^RESET%^ "
                     + capitalize(RaceArray[0]) + " : " + PriceArray[0];
      for(int i=1; i<maxi; i++) {
         RaceArray[i] = "                " + capitalize(RaceArray[i])
                        + " : " + PriceArray[i];
      }
      who->eventPage(RaceArray);
      who->eventPrint("--------------------------------------------------");
      return 1;
   }
}

/* The room setter-upper */

int setup() {
   object who = this_player();

   who->eventPrint("----------------------------------------\n"
		   "%^CYAN%^BOLD%^Store Setup for "+capitalize(GetShopName())+
		   ".%^RESET%^\n"
		   "----------------------------------------\n"
		   "%^GREEN%^BOLD%^1%^RESET%^) Change shop name\n"
		   "%^GREEN%^BOLD%^2%^RESET%^) Change long description\n"
		   "%^GREEN%^BOLD%^3%^RESET%^) Quit\n"
		   "----------------------------------------");
   message("prompt", "\nEnter your choice: ", who);
   input_to((: ChooseSetupOption :));
   return 1;
}

void ChooseSetupOption(string args) {
   object who = this_player();
   int option = to_int(args);

   if(option == 1) {
      who->eventPrint("\n%^CYAN%^BOLD%^Please enter a name "
                      "for this shop <'q' cancels>:%^RESET%^");
      input_to((: SetupShopName :));
      return;
   } else if(option == 2) {
      who->eventPrint("\n%^CYAN%^BOLD%^Please enter a long "
                      "description for this shop <'q' cancels>:%^RESET%^");
      input_to((: SetupShopDesc :));
		return;
   } else if(option == 3) {
      who->eventPrint("\n%^RED%^BOLD%^Exited Setup.%^RESET%^");
      return;
   } else {
      who->eventPrint("%^RED%^BOLD%^Invalid choice!%^RESET%^\n\n"
                      "%^GREEN%^BOLD%^1%^RESET%^) Change shop "
                      "name\n"
                      "%^GREEN%^BOLD%^2%^RESET%^) Change long "
                      "description\n"
                      "%^GREEN%^BOLD%^3%^RESET%^) Quit\n");
      message("prompt", "Enter your choice: ", who);
      input_to((: ChooseSetupOption :));
      return;
   }
}

void SetupShopName(string args) {
	object who = this_player();

   if(args == "q") {
      who->eventPrint("\n%^RED%^BOLD%^Canceled!%^RESET%^");
      return;
   }
   if(!args || (strlen(args) < 5)) {
      who->eventPrint("\n%^RED%^BOLD%^You must have a name at "
                      "least 5 letters long!%^RESET%^\n"
                      "\n%^CYAN%^BOLD%^Please enter a name for "
                      "this shop <'q' cancels>:%^RESET%^ ");
      input_to((: SetupShopName :));
      return;
   }
   SetShopName(args);
   who->eventPrint("\n%^YELLOW%^BOLD%^Shop name set "
                   "to: "+args+"%^RESET%^");
   return;
}

void SetupShopDesc(string args) {
   object who = this_player();

   if(args == "q") {
      who->eventPrint("\n%^RED%^BOLD%^Canceled!%^RESET%^");
      return;
   }
   if((!args) || (strlen(args) < 10)) {
      who->eventPrint("\n%^RED%^BOLD%^You must have a "
                      "description at least 10 letters "
                      "long!%^RESET%^\n");
      who->eventPrint("\n%^CYAN%^BOLD%^Please enter a long "
                      "description for this shop <'q' cancels>:"
                      "%^RESET%^");
      input_to((: SetupShopDesc :));
      return;
   }
   SetShopDesc(args);
   who->eventPrint("\n%^YELLOW%^BOLD%^Shop description set.%^RESET%^");
   return;
}

/* The list of the owner's commands */

int command_list() {
   object who = this_player();

   who->eventPrint("----------------------------------------------------\n"
                   "%^CYAN%^BOLD%^Command List%^RESET%^\n"
                   "----------------------------------------------------\n"
                   "Funds  : Configures shop balance\n"
                   "Inv    : Configures shop inventory\n"
                   "Make   : Makes food or a barkeeper\n"
                   "Price  : Sets the selling price of meat and items\n"
                   "Report : Shows the shop's report summary\n"
                   "Remove : Removes a certain race from your payouts\n"
                   "Set    : Sets payout for corpses of certain races\n"
                   "Setup  : Configures shop options\n"
                   "----------------------------------------------------");
   return 1;
}
