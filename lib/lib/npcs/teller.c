/*   /lib/teller.c
 *   from the Dead Souls V Object Library
 *   npc interface which handles banking transactions
 *   created by Blitz@Dead Souls 960105
 *   Version: @(#) teller.c 1.3@(#)
 *   Last Modified: July 10, 2004
 */
 
#include <lib.h>
#include <daemons.h>
#include "include/teller.h"
 
inherit LIB_NPC;
 
string BankName, LocalCurrency;
string *Currencies;
int LocalFee, NonLocalFee, OpenFee;
float ExchangeFee;
 
static void create() {
    npc::create();
    BankName = "Sanctum Trust";
    LocalCurrency = "imperials";
    OpenFee = 5;
    Currencies = ({ "copper", "silver", "electrum", "gold", "platinum" });
    SetCommandResponses( ([
      "default" : (: cmdParse :),
    ]) );
    SetRequestResponses( ([
      "default" : (: cmdParse :),
    ]) );
}
 
string SetBankName(string str) { return (BankName = str); }
 
string SetLocalCurrency(string str) { return (LocalCurrency = str); }
 
int SetLocalFee(int x) { return (LocalFee = x); }
 
int SetNonLocalFee(int x) { return (NonLocalFee = x); }
 
int SetOpenFee(int x) { return (OpenFee = x); }
 
float SetExchangeFee(float x) {
   if (!floatp(x)) x = x * 1.0;
   return ExchangeFee = x;
}
 
mixed SetCurrencies(mixed var) {
    if( arrayp(var) ) {
        if( member_array(LocalCurrency, var) == -1 )
        var += ({ LocalCurrency });
      return (Currencies = var);
    }
    else error("Bad argument 1 to SetCurrencies()");
}
 
int GetLocalFee() { return LocalFee; }
 
int GetNonLocalFee() { return NonLocalFee; }
 
int GetExchangeFee() { return ExchangeFee; }
 
int GetOpenFee() { return OpenFee; }
 
mixed GetCurrencies() { return ECONOMY_D->GetCurrencies(); }
 
string GetBankName() { return BankName; }
 
string GetLocalCurrency() { return LocalCurrency; }
 
mixed CanBank(object who) {
  if( creatorp(who) )
    return "Creators have no need for that.";
  if( !(int)who->GetAccountInfo( GetBankName() ) )
    return "You must request an account first.";
  return 1;
}
 
int AddSurcharge(object who, string currency, int amount) {
    int charge;
    string type;
 
    if( (string)who->GetTown() == GetTown() ) {
        type = "standard";
        charge = GetLocalFee();
    } else {
        type = "non-residential";
        charge = GetNonLocalFee();
    }
    if( !charge ) return amount;
    if( amount > charge ) {
         amount -= charge;
         who->eventPrint(sprintf("The bank retains a %s "
                        "surcharge of %d %s.", type, charge, currency));
         return amount;
    }
    else if( (amount + charge) <= (int)who->GetCurrency(currency) ) {
         who->eventPrint(sprintf("The bank charges you a %s %d %s "
                        "surcharge.", type, charge, currency));
         who->AddCurrency(currency, -charge);
         return amount;
    } else {
         who->eventPrint(sprintf("You are unable to afford the "
                        "%s surcharge of %d %s.", type, charge, currency));
         return 0;
    }
    return amount;
}
 
int eventBalance(object who) {
    string str, ret, *tmp;
    mapping mp;
    float val;
    int total;
 
    mp = (mapping)who->GetAccountInfo( GetBankName() );
    if( !mp ) return 0;
    environment()->eventPrint( (string)who->GetName() + " requests "
                   "current balance.", ({ who }) );
    ret = "Your account with "+GetBankName()+" was "
           "opened "+mtime(mp["open"])+".\n";
    ret += "This location's default currency is "+GetLocalCurrency()+".\n\n";
    tmp = filter(keys(mp), (: member_array($1, GetCurrencies()) > -1 :));
    total = 0;
    if( !sizeof(tmp) )
      ret += "You have made no deposits.\n";
    else foreach(str in tmp) {
        if( mp[str] < 1 ) continue;
        ret += sprintf("%-20s : %d\n", str, mp[str]);
        if( str == GetLocalCurrency() ) total += mp[str];
        else if( mp[str] ) {
            if( currency_rate(str) )
            val = mp[str] / currency_rate(str);
            else val = 0;
            if( currency_rate(GetLocalCurrency()) )
              total += to_int( val * currency_rate(GetLocalCurrency()) );
        }
    }
    ret += sprintf("%-20s ----------\n%-22s %d",
                   "", "Total in "+GetLocalCurrency(), total);
    if( mp["last time"] )
      ret += sprintf("\n\nYour last transaction: %s at %s.",
                    mp["last trans"], ctime(mp["last time"]) );
    who->eventPage(explode(ret, "\n"), "info");
    return 1;
}
 
int eventDeposit(object who, string currency, mixed x) {
    int i;
    int amount;
    if (x == "all") {
      amount = who->GetCurrency(currency);
    } else {
      amount = to_int(x);
    }
    if( amount < 1 ) {
        eventForce("speak " + (string)who->GetName() + ", "
                   "you are a moron.");
        return 1;
    }
    if( !currency ) currency = GetLocalCurrency();
    if( !(i = (int)who->GetCurrency(currency)) ) {
        eventForce("speak You are not carrying any "+currency+".");
        return 1;
    }
    if( amount > i ) {
        eventForce("speak You are not carrying that much "+ currency +".");
        return 1;
    }
    who->eventPrint(sprintf("You deposit %d %s into your "
                    "account.", amount, currency));
    environment()->eventPrint((string)who->GetName() + " makes "
                  "a deposit.", ({ who }) );
    who->AddCurrency(currency, -amount);
    who->AddBank(GetBankName(), currency, amount);
    return 1;
}
 
int eventWithdraw(object who, string currency, mixed s) {
    int i, x;
    int amount;
    if (s == "all") {
      amount = who->GetBank(GetBankName(), currency);
    } else {
      amount = to_int(s);
    }
 
    x = amount;
    if( amount < 1 ) {
        eventForce("speak Withdrawing a negative amount is not a prudent "
                "idea, "+ (string)who->GetName() +".");
        return 1;
    }
    if( !currency ) currency = GetLocalCurrency();
    if( !(i = (int)who->GetBank(GetBankName(), currency)) ) {
        eventForce("speak You have no "+currency+" in your account.");
        return 1;
    }
    if( amount > i ) {
        eventForce("speak You do not have that much "+currency+" in your "
                   "account.");
        return 1;
    }
    if( !(amount = AddSurcharge(who, currency, amount)) ) return 1;
    if( (int)who->AddCurrency(currency, amount) < 0 ) {
        eventForce("speak You are unable to carry that "
                   "much "+currency+"!");
        if( x > amount ) {
            who->eventPrint("The bank returns the fee.");
            who->AddCurrency(currency, (amount - x));
        }
        return 1;
    }
    who->AddBank(GetBankName(), currency, -amount);
    who->eventPrint(sprintf("You withdraw %d %s from your account.",
                    amount, currency));
    environment()->eventPrint(sprintf("%s withdraws some %s.",
                             (string)who->GetName(), currency), ({ who }));
    return 1;
}
 
int eventExchange(object who, mixed s, string str1, string str2) {
    int i, x, charge, amount;
    float val;
    string *currens = ({ });
    if (str1 == "money" || str1 == "currencies" || str1 == "currency") {
      currens = who->GetCurrencies();
    } else { 
      currens = ({ str1 });
    }
    foreach(string cur in currens) {
      if (s == "all") {
        amount = who->GetCurrency(cur);
      } else {
        amount = to_int(s);
      }
      if( amount < 1 ) {
        eventForce("speak I can't exchange numbers that small!");
        continue;
      }
      if( amount > (int)who->GetCurrency(cur) ) {
        eventForce("speak You do not have that much "+cur+" to exchange.");
        continue;
      }
      if( cur == str2 ) {
        continue;
      }
      val = amount / currency_rate(cur);
      x = to_int( (amount * 0.01) + amount );
      i = to_int( val * currency_rate(str2) );
      if( GetExchangeFee() )
        charge = to_int(i / (100 / GetExchangeFee()));
        else charge = 0;
      if( charge ) i -= charge;
      if( i < 1 ) {
        eventForce("speak " + amount + " " + cur + " isn't even worth one " + str2 + "!");
        continue;
      }
      if( (int)who->AddCurrency(str2, i) < 0 ) {
        eventForce("speak You cannot carry that much "+str2+", " + (string)who->GetName()+".");
        continue;
      }
      who->AddCurrency(cur, -amount);
      who->eventPrint(sprintf("You exchange %d %s for %d %s.", amount, cur, i, str2));
      if( charge )
      who->eventPrint(sprintf("You were charged a %.3f%s fee of %d %s.", GetExchangeFee(), "%", charge, str2) );
      environment()->eventPrint((string)who->GetName()+" exchanges some "+ cur+" for "+str2+".", who);
      }
   return 1;
}
int eventOpenAccount(object who) {
    if( who->GetAccountInfo( GetBankName() ) ) {
        eventForce("speak You already have an account with "+GetBankName()+", " +
                   (string)who->GetName()+"!");
        return 1;
    }
    if( (int)who->GetCurrency( GetLocalCurrency() ) < OpenFee ) {
        eventForce(" speak "+ sprintf("You must have at least %d %s to open "
                   "an account at this branch of %s, %s.", GetOpenFee(),
                   GetLocalCurrency(), GetBankName(), (string)who->GetName()));
        return 1;
    }
    if( OpenFee < 1 ) return 0;
    who->AddCurrency(GetLocalCurrency(), -OpenFee);
    who->AddBank(GetBankName(), GetLocalCurrency(), OpenFee);
    who->eventPrint(sprintf("You deposit %d %s and open an account "
        "with %s.", OpenFee, GetLocalCurrency(), GetBankName()) );
    eventBalance(who);
    environment()->eventPrint((string)who->GetName() + " opens an "
                     "account.", who);
    eventForce("smile "+(string)who->GetKeyName());
    return 1;
}

void eventGreet(object who) {
  eventForce("speak Welcome to " + GetBankName() + ", " + who->GetCapName());
  who->eventPrint("Please see <help banking> for more information.");
}
 
int cmdParse(object who, string cmd, string str) {
    mixed x;
    string s1, s2;
    mixed err;
 
    if( cmd != "account" && stringp(err = CanBank(who)) ) {
        who->eventPrint(err);
        return 1;
    }
    switch(cmd) {
        case "balance" :
            return eventBalance(who);
        break;
        case "deposit" : case "withdraw" :
            if( !str ) {
                eventForce("speak How much of what?");
                return 1;
            }
            if(sscanf(str, "%s %s", x, s1) != 2)
	    {
		eventForce("speak How much of what?");
		return 1;
	    }
            if( member_array(s1, GetCurrencies()) < 0 ) {
              who->eventPrint(s1 + " is not supported here!");
              return 1;
            }
            if( cmd == "deposit" )
              return eventDeposit(who, s1, x);
            else
              return eventWithdraw(who, s1, x);
        break;
        case "exchange" : case "convert" :
            if( !str ) {
                eventForce("speak Exchange what for what?");
                return 1;
            }
            if (sscanf(str, "%s %s for %s", x, s1, s2) != 3)   {
		          if (sscanf(str, "%s %s to %s", x, s1, s2) != 3) 	{
		            eventForce("speak Exchange what for what?");
		            return 1;
		          }
	          }
            return eventExchange(who, x, s1, s2);
        break;
        case "account" :
            return eventOpenAccount(who);
        break;
        default:
            eventForce("speak " + (string)who->GetName() + ", I do not understand what you want.");
            who->eventPrint("Try <help banking> if you are confused.");
 
    }
    return 1;
}
