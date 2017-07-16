/*    /lib/currency.c
 *    from the Dead Souls LPC Library
 *    handles player bank accounts and carried currency
 *    created by Descartes of Borg 950324
 */


#include <lib.h>

private mapping Currency = ([]);
private mapping Bank     = ([]);

// abstract methods
int CanCarry(int amount);
// end abstract methods

/* ***************  /lib/currency.c driver applies  *************** */

static void create() {
}

/* ***************  /lib/currency.c data manipulation funcs  *************** */

int AddCurrency(string type, int amount) { 
    if( amount + Currency[type] < 0 ) {
	return -1;
    }
    Currency[type] += amount;
    if (!Currency[type]) map_delete(Currency, type);
    return 1;
}

int GetCurrency(string type) { return Currency[type]; }

varargs int GetCurrencyMass(string type) {
  return 0;
}

int AddBank(string bank, string type, int amount) {
  if( !stringp(bank) ) error("Bad argument 1 to AddBank().");
  if( !Bank[bank] ) {
	  if( amount < 1 ) return -1;
	  Bank[bank] = ([ 
	    "open"      : time(), 
	    type        : amount, 
	    "last time" : time(),
	    "last trans": "opened account", 
      "audit"     : identify(previous_object(-1)) 
      ]);
	  return amount;
    }
  if( Bank[bank][type] + amount < 0 ) return -1;
  Bank[bank][type] += amount;
  Bank[bank]["last time"] = time();
  if( amount > 0 ) Bank[bank]["last trans"] = "deposit";
  else Bank[bank]["last trans"] = "withdrawal";
  Bank[bank]["audit"] = identify(previous_object(-1));
  return Bank[bank][type];
}

int GetBank(string bank, string type) {
    if( !Bank[bank] ) return -1;
    else return Bank[bank][type];
}

mapping GetAccountInfo(string bank) {
    if( !Bank[bank] ) return 0;
    else return copy(Bank[bank]);
}

int GetNetWorth() {
    string curr;
    float net_worth;
    int amt;

    foreach(curr, amt in Currency) {
	    float tmp;
	    tmp = currency_rate(curr);
	    net_worth += amt / tmp;
      }
    foreach(string bank, mapping balance in Bank) {
	    foreach(curr, amt in balance) {
	    float tmp;
	    
	    switch(curr) {
        case "last trans": case "last time": case "audit": case "open":
   		    break;
        default:
		      if( (tmp = currency_rate(curr)) < 1 ) break;
		      net_worth += amt / tmp;
		      break;
	      }
	    }
    }
    return net_worth;
}

string array GetCurrencies() { return keys(Currency); }

void ResetBank() { Bank = ([]); }

void ResetCurrency() { Currency = ([]); }

string *GetBanks() { return keys(Bank); }