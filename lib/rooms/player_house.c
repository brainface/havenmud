/* Player Houses for a new millenia
 * Duuk
 * 2/24/2006
 */
#include <lib.h>
#include <save.h>
#include <daemons.h>
inherit LIB_ROOM;

string *Owners;
int Bid;
string Bidder;
string LocalCurrency;
string LotID;

string *GetOwners();

static void create() {
  ::create();
  Bid = 0;
  Owners = ({ });
  SetClimate("indoors");
  SetAmbientLight(35);
}

void SaveBuilding() {
  if (!LotID) return;
  unguarded( (: save_object, SAVE_ESTATES + "/" + LotID + __SAVE_EXTENSION__ :) );
  return;
}

void LoadBuilding() {
  if (!LotID) return;
  unguarded( (: restore_object, SAVE_ESTATES + "/" + LotID + __SAVE_EXTENSION__ :) );
  return;
}

string SetLotID(string str) {
  LotID = str;
  LoadBuilding();
  SaveBuilding();
}

string GetLotID() { return LotID; }

string *SetOwners(string *o) {
  if (!arrayp(o)) o = ({ o });
  Owners = o;
  SaveBuilding();
  return Owners;
}

string *GetOwners() {
  return Owners;
}

int SetBid(int x) {
  Bid = x;
  SaveBuilding();
  return Bid;
}

string SetBidder(string x) {
  Bidder = x;
  SaveBuilding();
  return Bidder;
}

int GetBid() { 
  return Bid;
}

string GetBidder() {
  return Bidder;
}

string SetLocalCurrency(string s) {
  LocalCurrency = s;
  SaveBuilding();
  return LocalCurrency;
}

string GetLocalCurrency() {
  if (!LocalCurrency) LocalCurrency = CURRENCY_D->GetTownCurrency(GetTown());
  return LocalCurrency;
}

int CanBid(object who, int amount) {
  if (!GetLotID()) {
    who->eventPrint("This building doesn't seem to be for sale right now.");
    return 0;
  }
  if (sizeof(GetOwners())) {
    who->eventPrint("This building already has an owner.");
    return 0;
  }
  if (GetBid() > amount) {
    who->eventPrint("That bid isn't high enough to beat the current bid of " +
                    GetBid() + " " + GetLocalCurrency() + ". You'll have to bid "
                    "higher if you want to beat " + capitalize(GetBidder()) + " and win!");
    return 0;
  }
  if (GetBidder() == who->GetKeyName()) {
    who->eventPrint("Bidding against yourself is foolish.");
    return 0;
  }
  return 1;
}

int eventBid(object who, int amount) {
  send_messages( ({ "bid" }),
    "$agent_name $agent_verb " + amount + " " + GetLocalCurrency() + " on this building.",
    who, 0, this_object() );
  SetBid(amount);
  SetBidder(who->GetKeyName());
  CHAT_D->eventSendChannel("Bid", "reports", capitalize(who->GetKeyName()) + " has bid " +
                           GetBid() + " " + GetLocalCurrency() + " for " + LotID + " in " +
                           GetTown() );
  return 1;
}

string SetHouseId(string  u) {
  /* This function is used in old player houses and is a signifier of old code.
   * This is my nifty way of making them not break while also not using them as
   * buildings for sale.
   */
  SetShort("an abandoned building");
  SetLong(
    "This disused building is empty and obviously forgotten. Someday, should "
    "the town government choose, it will be for sale to the citizens of the "
    "town. For now though, it sits idle and forlorn."
    );
  return "";
}